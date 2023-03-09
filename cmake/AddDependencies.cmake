SET(QT_DEFAULT_MAJOR_VERSION 6)
set(QAPPLICATION_CLASS QGuiApplication CACHE STRING "Inheritance class for SingleApplication")
add_subdirectory(thirdparty/singleapplication)

set(QT_MINIMUM_VERSION 6.5.0)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick QuickControls2)
qt_standard_project_setup()

Include(FetchContent)

FetchContent_Declare(
  sentry
  GIT_REPOSITORY https://github.com/getsentry/sentry-native.git
  GIT_TAG        0.6.0
  GIT_SUBMODULES external/libunwindstack-ndk external/breakpad external/third_party/lss
)
FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/refs/tags/v1.11.0.tar.gz)

FetchContent_MakeAvailable(sentry spdlog)