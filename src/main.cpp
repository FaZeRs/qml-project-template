#include <singleapplication.h>

#include <QApplication>

#include "logger.h"
#include "mainwindow.h"
#include "qt_log.h"
#include "sentry.h"

int main(int argc, char* argv[]) {
  Logger::instance();
  SPDLOG_INFO("*** ************* ***");
  SPDLOG_INFO("*** Room Sketcher ***");
  SPDLOG_INFO("*** ************* ***\n");

  // Install Qt Log Message Handler
  qInstallMessageHandler(qtLogMessageHandler);

  initializeSentry();

  SingleApplication app(argc, argv);
  MainWindow window;
  window.show();
  return app.exec();
}
