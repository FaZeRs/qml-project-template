SET(QT_DEFAULT_MAJOR_VERSION 6)
set(QAPPLICATION_CLASS QGuiApplication CACHE STRING "Inheritance class for SingleApplication")
add_subdirectory(thirdparty/singleapplication)

set(QT_MINIMUM_VERSION 6.5.0)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick QuickControls2)
qt_standard_project_setup()

add_subdirectory(thirdparty/sentry-native)
add_subdirectory(thirdparty/spdlog)
