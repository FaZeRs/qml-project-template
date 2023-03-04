SET(QT_DEFAULT_MAJOR_VERSION 6)
set(QAPPLICATION_CLASS QApplication CACHE STRING "Inheritance class for SingleApplication")
add_subdirectory(thirdparty/singleapplication)

set(QT_MINIMUM_VERSION 6.2.4)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

add_subdirectory(thirdparty/sentry-native)
add_subdirectory(thirdparty/spdlog)
