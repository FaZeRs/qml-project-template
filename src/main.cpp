#include <singleapplication.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "logger.h"
#include "qt_log.h"
#include "sentry.h"
#include "version.h"

int main(int argc, char* argv[]) {
  Logger::instance();
  SPDLOG_INFO("*** ************* ***");
  SPDLOG_INFO("*** Room Sketcher ***");
  SPDLOG_INFO("*** v: {} ***", version::getVersionString());
  SPDLOG_INFO("*** ************* ***\n");

  // Install Qt Log Message Handler
  qInstallMessageHandler(qtLogMessageHandler);

  initializeSentry();
  auto sentryClose = qScopeGuard([] { sentry_close(); });

  QGuiApplication::setApplicationName("Room Sketcher");
  QGuiApplication::setOrganizationName("Giraffe360");
  QGuiApplication::setApplicationVersion(version::getVersionString());

  SingleApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/src/qml/main.qml")));
  if (engine.rootObjects().isEmpty()) return -1;

  return app.exec();
}
