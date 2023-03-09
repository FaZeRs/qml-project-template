qt_add_executable(${CMAKE_PROJECT_NAME}
  ${SOURCE_FILES}
)

qt_add_qml_module(${CMAKE_PROJECT_NAME}
  URI roomsketcher
  VERSION 1.0
  QML_FILES ${QML_FILES}
  RESOURCES qtquickcontrols2.conf
  NO_RESOURCE_TARGET_PATH
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
  spdlog::spdlog
  sentry::sentry
  Qt::Core
  Qt::Gui
  Qt::Quick
  Qt::QuickControls2
  Qt::Qml
  SingleApplication::SingleApplication
)