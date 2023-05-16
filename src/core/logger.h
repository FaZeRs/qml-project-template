#ifndef ROOM_SKETCHER_LOGGER_H
#define ROOM_SKETCHER_LOGGER_H

#include <memory>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#include "base.h"
#include "parameters.h"
#include "singleton.h"

namespace room_sketcher {

class Logger final : public Singleton<Logger> {
 public:
  Logger() { initLogger(); }
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger(Logger&&) = delete;
  Logger& operator=(Logger&&) = delete;
  ~Logger() {
    spdlog::drop_all();  // Release all Loggers
  }

  // Creates SPDLOG logger with multiple sinks (console + file)
  void initLogger() {
    console_sink_ = CreateRef<spdlog::sinks::stdout_color_sink_mt>();
    file_sink_ = CreateRef<spdlog::sinks::basic_file_sink_mt>(parameters::log_path, false);

    console_sink_->set_level(spdlog::level::trace);
    file_sink_->set_level(spdlog::level::trace);

    console_sink_->set_pattern("[%H:%M:%S.%e] [%^%l%$] [t:%t] [%s:%#] %v");
    file_sink_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%#] %v");

    sinks_.emplace_back(console_sink_);
    sinks_.emplace_back(file_sink_);

    logger_ = CreateRef<spdlog::logger>("rs_log", begin(sinks_), end(sinks_));
    logger_->set_level(spdlog::level::trace);
    logger_->flush_on(spdlog::level::warn);  // Flush automatically when warning appears

    spdlog::register_logger(logger_);  // Register Logger
    spdlog::set_default_logger(logger_);
  }

 private:
  Ref<spdlog::logger> logger_;
  Ref<spdlog::sinks::stdout_color_sink_mt> console_sink_;
  Ref<spdlog::sinks::basic_file_sink_mt> file_sink_;
  std::vector<spdlog::sink_ptr> sinks_{};
};  // Logger

}  // namespace room_sketcher

#endif  // ROOM_SKETCHER_LOGGER_H
