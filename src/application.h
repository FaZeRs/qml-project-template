#ifndef APPLICATION_H
#define APPLICATION_H

#include <QCoreApplication>
#include <QtQml>

#include "base.h"

namespace room_sketcher {

class Application {
 public:
  Application(int& argc, char** argv);
  int run();

  QQmlApplicationEngine* qmlEngine() const;

 private:
  static void initializeSentry();

  Scope<QCoreApplication> m_Application;
  Scope<QQmlApplicationEngine> m_Engine;
};

} // namespace room_sketcher

#endif  // APPLICATION_H
