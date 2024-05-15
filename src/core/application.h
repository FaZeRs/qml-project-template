#pragma once

#include <QCoreApplication>
#include <QtQml>

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
  ~Application();

  [[nodiscard]] int run() const;

  [[nodiscard]] QQmlApplicationEngine* qmlEngine() const;
  [[nodiscard]] Settings* settings() const;

 private:
  static void initializeSentry();
  void registerQmlTypes() const;
  void addFonts();

  Scope<QCoreApplication> m_Application;
  Scope<QQmlApplicationEngine> m_Engine = CreateScope<QQmlApplicationEngine>();
  Scope<Settings> m_Settings = CreateScope<Settings>();
};

}  // namespace room_sketcher
