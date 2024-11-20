#pragma once

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "base.h"
#include "settings.h"

namespace myproject {

/// @brief The Application class used to manage the application.
class Application {
 public:
  Application(int& argc, char** argv);
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;
  Application(Application&&) = delete;
  Application& operator=(Application&&) = delete;
  ~Application() = default;

  /// @brief Runs the application.
  /// @return The application exit code.
  [[nodiscard]] int run() const;

  /// @brief Returns the QML engine.
  /// @return The QML engine.
  [[nodiscard]] QQmlApplicationEngine* qmlEngine() const;
  /// @brief Returns the settings.
  /// @return The settings.
  [[nodiscard]] Settings* settings() const;

 private:
  /// @brief Initializes Sentry.
  static void initializeSentry();
  /// @brief Registers the QML types.
  void registerQmlTypes() const;
  /// @brief Adds the fonts.
  void addFonts() const;

  QScopedPointer<QGuiApplication> m_Application;
  QScopedPointer<QQmlApplicationEngine> m_Engine{new QQmlApplicationEngine};
  QScopedPointer<Settings, QScopedPointerDeleteLater> m_Settings{new Settings};
};

}  // namespace myproject
