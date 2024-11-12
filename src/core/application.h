#pragma once

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "base.h"
#include "settings.h"

namespace room_sketcher {

class Application {
 public:
  Application(int& argc, char** argv);
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;
  Application(Application&&) = delete;
  Application& operator=(Application&&) = delete;
  ~Application() = default;

  [[nodiscard]] int run() const;

  [[nodiscard]] QQmlApplicationEngine* qmlEngine() const;
  [[nodiscard]] Settings* settings() const;

 private:
  static void initializeSentry();
  void registerQmlTypes() const;
  void addFonts() const;

  QScopedPointer<QGuiApplication> m_Application;
  QScopedPointer<QQmlApplicationEngine> m_Engine{new QQmlApplicationEngine};
  QScopedPointer<Settings> m_Settings{new Settings};
};

}  // namespace room_sketcher
