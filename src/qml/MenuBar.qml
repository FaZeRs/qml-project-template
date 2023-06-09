import QtQuick
import QtQuick.Controls

MenuBar {
    spacing: 10
    
    Action {
        id: newAction
        text: qsTr("New")
        shortcut: settings.newShortcut
        onTriggered: console.log("New action triggered");
    }

    Action {
        id: openAction
        text: qsTr("Open")
        shortcut: settings.openShortcut
        onTriggered: console.log("Open action triggered");
    }

    Action {
        id: saveAction
        text: qsTr("Save")
        shortcut: settings.saveShortcut
        onTriggered: console.log("Save action triggered");
    }

    Action {
        id: saveAsAction
        text: qsTr("Save As")
        shortcut: settings.saveAsShortcut
        onTriggered: console.log("Save As action triggered");
    }

    Action {
        id: quitAction
        text: qsTr("Exit")
        shortcut: settings.quitShortcut
        onTriggered: close()
    }

    Action {
        id: undoAction
        text: qsTr("Undo")
        shortcut: settings.undoShortcut
        onTriggered: console.log("Undo action triggered");
    }

    Action {
        id: redoAction
        text: qsTr("Redo")
        shortcut: settings.redoShortcut
        onTriggered: console.log("Redo action triggered");
    }

    Action {
        id: copyAction
        text: qsTr("Copy")
        shortcut: settings.copyShortcut
        onTriggered: console.log("Copy action triggered");
    }

    Action {
        id: cutAction
        text: qsTr("Cut")
        shortcut: settings.cutShortcut
        onTriggered: console.log("Cut action triggered");
    }

    Action {
        id: pasteAction
        text: qsTr("Paste")
        shortcut: settings.pasteShortcut
        onTriggered: console.log("Paste action triggered");
    }

    Action {
        id: aboutAction
        text: qsTr("About")
        onTriggered: aboutDialog.open()
    }

    Action {
        id: optionsAction
        text: qsTr("Options")
        shortcut: settings.optionsShortcut
        onTriggered: optionsDialog.open()
    }

    Menu {
        title: qsTr("File")
        MenuItem {
            action: newAction                
        }
        MenuItem {
            action: openAction
        }
        MenuItem {
            action: saveAction
        }
        MenuItem {
            action: saveAsAction
        }
        MenuSeparator { }
        MenuItem {
            action: quitAction
        }
    }
    Menu {
        title: qsTr("Edit")
        MenuItem {
            action: undoAction
        }
        MenuItem {
            action: redoAction
        }
        MenuSeparator { }
        MenuItem {
            action: copyAction
        }
        MenuItem {
            action: pasteAction
        }
        MenuItem {
            action: cutAction
        }
    }
    Menu {
        title: qsTr("Tools")
        MenuItem {
            action: optionsAction
        }
    }
    Menu {
        title: qsTr("Help")
        MenuItem {
            action: aboutAction
        }
    }
}