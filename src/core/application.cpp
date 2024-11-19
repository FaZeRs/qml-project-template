#include "application.h"

#include <config.h>
#if USE_SENTRY
#include <sentry.h>
#endif
#if USE_SPDLOG
#include <spdlog/spdlog.h>

#include "logger.h"
#endif

#include <QFontDatabase>
#include <QQmlContext>

#if USE_SPDLOG
static void spdlogMessageHandler(QtMsgType type,
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
#if USE_SENTRY
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_WARNING, "default", loc.constData()));
#endif
      break;
    case QtCriticalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::err, loc.constData());
#if USE_SENTRY
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_ERROR, "default", loc.constData()));
#endif
      break;
    case QtFatalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::critical, loc.constData());
#if USE_SENTRY
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_FATAL, "default", loc.constData()));
#endif
      break;
  }
}
#endif

namespace myproject {

static QScopedPointer<QGuiApplication> createApplication(int& argc,
                                                         char** argv) {
  qDebug() << "config::organization_name" << config::organization_name;
  QCoreApplication::setApplicationName(config::project_name);
  QCoreApplication::setOrganizationName(config::organization_name);
  QCoreApplication::setApplicationVersion(config::project_version);
  return QScopedPointer(new QGuiApplication(argc, argv));
}

Application::Application(int& argc, char** argv)
    : m_Application(createApplication(argc, argv)) {
#if USE_SPDLOG
  Logger::instance();
  qInstallMessageHandler(spdlogMessageHandler);
#else
  qSetMessagePattern(
      "[%{time h:mm:ss.zzz}] [%{type}] [t:%{threadid}] "
      "[%{function}:%{line}] %{message}");
#endif

  qInfo("*** ************* ***");
  qInfo("*** %s ***", config::project_name);
  qInfo("*** v: %s ***", config::project_version);
  qInfo("*** ************* ***\n");

#if USE_SENTRY
  initializeSentry();
  auto sentryClose = qScopeGuard([] { sentry_close(); });
#endif

  registerQmlTypes();
  addFonts();

  m_Engine->rootContext()->setContextProperty("settings", m_Settings.get());
  m_Engine->load(QUrl(QStringLiteral("qrc:/MyProjectUi/main.qml")));
  if (m_Engine->rootObjects().isEmpty()) qWarning("Failed to load main.qml");
}

int Application::run() const { return m_Application->exec(); }

QQmlApplicationEngine* Application::qmlEngine() const { return m_Engine.get(); }

Settings* Application::settings() const { return m_Settings.get(); }

void Application::initializeSentry() {
#if USE_SENTRY
  constexpr double sample_rate = 0.2;
  sentry_options_t* options = sentry_options_new();
  sentry_options_set_symbolize_stacktraces(options, true);
  sentry_options_set_dsn(options, parameters::sentry_dsn);
  sentry_options_set_database_path(options, ".sentry-native");
  sentry_options_set_release(options, config::project_version);
  sentry_options_set_traces_sample_rate(options, sample_rate);
  sentry_init(options);
#endif
}

void Application::registerQmlTypes() const { qRegisterMetaType<Settings*>(); }

void Application::addFonts() const {
  QFontDatabase::addApplicationFont(":/assets/fonts/font-awesome-regular.otf");
  QFontDatabase::addApplicationFont(":/assets/fonts/font-awesome-solid.otf");
  QFontDatabase::addApplicationFont(":/assets/fonts/font-awesome-brands.otf");
}

}  // namespace myproject
