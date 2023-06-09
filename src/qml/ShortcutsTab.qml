import QtQml.Models 2.12
import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12

ColumnLayout {
    id: shortcutsTab

    function applyChangesToSettings() {
        for (var i = 0; i < shortcutModel.count; ++i) {
            var row = shortcutModel.get(i)
            if (row.hasChanged) {
                settings[row.shortcutName] = row.newSequence
            }
        }
    }

    function revertToOldSettings() {
        for (var i = 0; i < shortcutModel.count; ++i) {
            var row = shortcutModel.get(i)
            if (row.hasChanged) {
                row.reset()
            }
        }
    }

    Item {
        Layout.preferredHeight: 10
    }

    ScrollView {
        objectName: "behaviourScrollView"
        clip: true

        ScrollBar.horizontal.policy: ScrollBar.AsNeeded

        Layout.fillWidth: true
        Layout.fillHeight: true

        GridLayout {
            columns: 2
            columnSpacing: 12
            width: parent.width

            Repeater {
                model: ObjectModel {
                    id: shortcutModel

                    ShortcutRow {
                        shortcutName: "newShortcut"
                        shortcutDisplayName: qsTr("New Project")
                    }
                    ShortcutRow {
                        shortcutName: "openShortcut"
                        shortcutDisplayName: qsTr("Open Project")
                    }
                    ShortcutRow {
                        shortcutName: "saveShortcut"
                        shortcutDisplayName: qsTr("Save Project")
                    }
                    ShortcutRow {
                        shortcutName: "saveAsShortcut"
                        shortcutDisplayName: qsTr("Save Project As")
                    }
                    ShortcutRow {
                        shortcutName: "quitShortcut"
                        shortcutDisplayName: qsTr("Quit")
                    }
                    ShortcutRow {
                        shortcutName: "undoShortcut"
                        shortcutDisplayName: qsTr("Undo Action")
                    }
                    ShortcutRow {
                        shortcutName: "redoShortcut"
                        shortcutDisplayName: qsTr("Redo Action")
                    }
                    ShortcutRow {
                        shortcutName: "optionsShortcut"
                        shortcutDisplayName: qsTr("Options")
                    }
                    ShortcutRow {
                        shortcutName: "fullScreenShortcut"
                        shortcutDisplayName: qsTr("Toggle fullscreen")
                    }
                }
            }
        }
    }
}