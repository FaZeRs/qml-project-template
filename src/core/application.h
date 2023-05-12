#ifndef ROOM_SKETCHER_APPLICATION_H
#define ROOM_SKETCHER_APPLICATION_H

#include <QCoreApplication>
#include <QtQml>

#include "base.h"
#include "settings.h"

namespace room_sketcher {

class Application {
 public:
  Application(int& argc, char** argv);
  ~Application();

  int run() const;

  QQmlApplicationEngine* qmlEngine() const;
  Settings* settings() const;

 private:
  static void initializeSentry();
  void registerQmlTypes() const;

  Scope<QCoreApplication> m_Application;
  Scope<QQmlApplicationEngine> m_Engine = CreateScope<QQmlApplicationEngine>();
  Scope<Settings> m_Settings = CreateScope<Settings>();
};

} // namespace room_sketcher

#endif  // ROOM_SKETCHER_APPLICATION_H
