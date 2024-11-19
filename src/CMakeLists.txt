configure_file("config.h.in" "${CMAKE_BINARY_DIR}/configured_files/include/config.h" ESCAPE_QUOTES)

find_package(
  Qt6 REQUIRED
  COMPONENTS Core
             Gui
             Widgets
             Qml
             Quick)

add_subdirectory(core)
add_subdirectory(quick)
add_subdirectory(qml)

qt_standard_project_setup()

set(SOURCE_FILES main.cpp)

set(RESOURCE_FILES
    assets/fonts/font-awesome-regular.otf
    assets/fonts/font-awesome-solid.otf
    assets/fonts/font-awesome-brands.otf
    qtquickcontrols2.conf)

qt_add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

qt_add_resources(
  ${CMAKE_PROJECT_NAME}
  "assets"
  PREFIX
  "/"
  FILES
  ${RESOURCE_FILES})

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE WIN32_EXECUTABLE TRUE)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  PRIVATE libs::project_options
          libs::project_warnings
          libs::core
          quick_widgetsplugin
          myproject_uiplugin)

target_link_system_libraries(
  ${CMAKE_PROJECT_NAME}
  PRIVATE
  Qt::Gui
  Qt::Qml)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")

if(USE_SPDLOG)
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_SPDLOG)
  target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE spdlog::spdlog)
endif()

if(USE_SENTRY)
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_SENTRY)
  target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE sentry::sentry)
endif()

include(static-analyzers)

if(ENABLE_CPPCHECK)
  enable_cppcheck(${CMAKE_PROJECT_NAME} ${WARNINGS_AS_ERRORS} "")
endif()

if(ENABLE_CLANG_TIDY)
  enable_clang_tidy(${CMAKE_PROJECT_NAME} ${WARNINGS_AS_ERRORS} "")
endif()

if(ENABLE_INCLUDE_WHAT_YOU_USE)
  enable_include_what_you_use(${CMAKE_PROJECT_NAME})
endif()

# Install the executable into "${CMAKE_INSTALL_PREFIX}/bin".
install(
  TARGETS ${CMAKE_PROJECT_NAME}
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Generate the deployment script for the target MyProject.
qt_generate_deploy_qml_app_script(
  TARGET
  ${CMAKE_PROJECT_NAME}
  OUTPUT_SCRIPT
  deploy_script
  MACOS_BUNDLE_POST_BUILD
  NO_UNSUPPORTED_PLATFORM_ERROR
  DEPLOY_USER_QML_MODULES_ON_UNSUPPORTED_PLATFORM
  NO_TRANSLATIONS)

# Call the deployment script on "cmake --install".
install(SCRIPT ${deploy_script})
