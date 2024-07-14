configure_file("config.h.in" "${CMAKE_BINARY_DIR}/configured_files/include/config.h" ESCAPE_QUOTES)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick QuickControls2 Widgets)
qt_standard_project_setup()

add_subdirectory(quick)

set(SOURCE_FILES
    main.cpp
    core/application.cpp
    core/settings.cpp)

set(QML_FILES
    qml/main.qml
    qml/MenuBar.qml
    qml/AboutDialog.qml
    qml/OptionsDialog.qml
    qml/SettingsTab.qml
    qml/ShortcutsTab.qml
    qml/ShortcutRow.qml
    qml/StatusBar.qml
    qml/FpsCounter.qml
    qml/ToolBar.qml
    qml/ToolButton.qml)

set(RESOURCE_FILES
    assets/fonts/font-awesome-regular.otf
    assets/fonts/font-awesome-solid.otf
    assets/fonts/font-awesome-brands.otf)

set(QUICK_FILES
    quick/keysequenceeditor.h
    quick/keysequenceeditor.cpp)

qt_add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCE_FILES})

qt_add_qml_module(${CMAKE_PROJECT_NAME}
    URI roomsketcher
    VERSION 1.0
    QML_FILES ${QML_FILES}
    RESOURCES qtquickcontrols2.conf
    NO_RESOURCE_TARGET_PATH)

qt_add_resources(${CMAKE_PROJECT_NAME} "assets"
    PREFIX "/"
    FILES ${RESOURCE_FILES}
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    rs::project_options
    rs::project_warnings
)

if(USE_OPENMP)
    find_package(OpenMP)

    if(OpenMP_CXX_FOUND)
        target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
    else()
        message(${WARNING_MESSAGE} "OpenMP requested but library not found")
    endif()
endif()

target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Quick
    Qt::QuickControls2
    Qt::Qml
    Qt::Widgets
    quick_widgetsplugin)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")

if(USE_SPDLOG)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_SPDLOG)
    target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE spdlog::spdlog)
endif()

if(USE_SENTRY)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_SENTRY)
    target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE sentry::sentry)
endif()

# Install the executable into "${CMAKE_INSTALL_PREFIX}/bin".
install(TARGETS ${CMAKE_PROJECT_NAME}
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Generate the deployment script for the target RoomSketcher.
qt_generate_deploy_qml_app_script(
    TARGET ${CMAKE_PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    MACOS_BUNDLE_POST_BUILD
    NO_UNSUPPORTED_PLATFORM_ERROR
    DEPLOY_USER_QML_MODULES_ON_UNSUPPORTED_PLATFORM
    NO_TRANSLATIONS
)

# Call the deployment script on "cmake --install".
install(SCRIPT ${deploy_script})
