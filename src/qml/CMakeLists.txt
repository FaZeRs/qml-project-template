qt_policy(SET QTP0004 NEW)
qt_policy(SET QTP0001 NEW)

set(QML_FILES
    main.qml
    MenuBar.qml
    AboutDialog.qml
    OptionsDialog.qml
    SettingsTab.qml
    ShortcutsTab.qml
    ShortcutRow.qml
    StatusBar.qml
    FpsCounter.qml
    ToolBar.qml
    ToolButton.qml)

qt_add_library(myproject_ui STATIC)
qt_add_qml_module(
  myproject_ui
  URI
  MyProjectUi
  VERSION
  1.0
  QML_FILES
  ${QML_FILES}
  OUTPUT_DIRECTORY
  MyProjectUi
  RESOURCE_PREFIX
  /)

target_link_system_libraries(
  myproject_ui
  PRIVATE
  Qt::Core
  Qt::Qml)
