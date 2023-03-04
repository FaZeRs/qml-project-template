qt_add_executable(${CMAKE_PROJECT_NAME} WIN32 MACOSX_BUNDLE
  ${SOURCE_FILES}
  ${FORM_FILES}
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
  WIN32_EXECUTABLE TRUE
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
  spdlog::spdlog
  sentry::sentry
  Qt::Core
  Qt::Gui
  Qt::Widgets
  SingleApplication::SingleApplication
)
