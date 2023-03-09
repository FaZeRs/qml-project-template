#ifndef QT_LOG_H
#define QT_LOG_H

#include "spdlog/spdlog.h"
#include <sentry.h>

// Qt Log Message handler
static void qtLogMessageHandler(QtMsgType type,
                                const QMessageLogContext& context,
                                const QString& msg) {
  QByteArray loc = msg.toUtf8();
  switch (type) {
    case QtDebugMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::debug, loc.constData());
      break;
    case QtInfoMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::info, loc.constData());
      break;
    case QtWarningMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::warn, loc.constData());
      sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_WARNING, "default", loc.constData()));
      break;
    case QtCriticalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::err, loc.constData());
      sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_ERROR, "default", loc.constData()));
      break;
    case QtFatalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::critical, loc.constData());
      sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_FATAL, "default", loc.constData()));
      break;
  }
}
#endif  // QT_LOG_H
