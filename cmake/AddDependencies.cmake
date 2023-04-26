find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick QuickControls2 Widgets)
qt_standard_project_setup()

include(cmake/modules/CPM.cmake)

CPMAddPackage(
  NAME sentry
  VERSION 0.6.0
  GITHUB_REPOSITORY getsentry/sentry-native
  GIT_TAG "0.6.0"
  OPTIONS "SENTRY_BACKEND breakpad" "SENTRY_INTEGRATION_QT ON" "SENTRY_BUILD_TESTS OFF" "SENTRY_BUILD_EXAMPLES OFF"
)
CPMAddPackage("gh:gabime/spdlog@1.11.0")
