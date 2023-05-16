configure_file("config.h.in" "${CMAKE_BINARY_DIR}/configured_files/include/config.h" ESCAPE_QUOTES)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick QuickControls2 Widgets)
qt_standard_project_setup()

set(SOURCE_FILES
        main.cpp
        core/application.cpp
        core/settings.cpp)
set(QML_FILES qml/main.qml qml/MenuBar.qml qml/AboutDialog.qml)

qt_add_executable(${CMAKE_PROJECT_NAME}
        ${SOURCE_FILES})

qt_add_qml_module(${CMAKE_PROJECT_NAME}
        URI roomsketcher
        VERSION 1.0
        QML_FILES ${QML_FILES}
        RESOURCES qtquickcontrols2.conf
        NO_RESOURCE_TARGET_PATH)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        rs::project_options
        rs::project_warnings
        spdlog::spdlog
        sentry::sentry
        Qt::Core
        Qt::Gui
        Qt::Quick
        Qt::QuickControls2
        Qt::Qml
        Qt::Widgets)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")

include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)
if (ENABLE_CPPCHECK)
  enable_cppcheck(${CMAKE_PROJECT_NAME} ${WARNINGS_AS_ERRORS} "")
endif()
if (ENABLE_CLANG_TIDY)
  enable_clang_tidy(${CMAKE_PROJECT_NAME} ${WARNINGS_AS_ERRORS} "")
endif()
if (ENABLE_INCLUDE_WHAT_YOU_USE)
  enable_include_what_you_use(${CMAKE_PROJECT_NAME})
endif()

# Install the executable into "${CMAKE_INSTALL_PREFIX}/bin".
install(TARGETS ${CMAKE_PROJECT_NAME}
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Generate the deployment script for the target RoomSketcher.
qt_generate_deploy_app_script(
        TARGET ${CMAKE_PROJECT_NAME}
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR)

# Call the deployment script on "cmake --install".
install(SCRIPT ${deploy_script})
