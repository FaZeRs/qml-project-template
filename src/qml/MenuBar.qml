import QtQuick
import QtQuick.Controls

MenuBar {
    spacing: 10
    
    Action {
        id: newAction
        text: qsTr("New")
        shortcut: StandardKey.New
        onTriggered: console.log("New action triggered");
    }

    Action {
        id: openAction
        text: qsTr("Open")
        shortcut: StandardKey.Open
        onTriggered: console.log("Open action triggered");
    }

    Action {
        id: saveAction
        text: qsTr("Save")
        shortcut: StandardKey.Save
        onTriggered: console.log("Save action triggered");
    }

    Action {
        id: saveAsAction
        text: qsTr("Save As")
        shortcut: StandardKey.SaveAs
        onTriggered: console.log("Save As action triggered");
    }

    Action {
        id: quitAction
        text: qsTr("Exit")
        shortcut: StandardKey.Quit
        onTriggered: close()
    }

    Action {
        id: undoAction
        text: qsTr("Undo")
        shortcut: StandardKey.Undo
        onTriggered: console.log("Undo action triggered");
    }

    Action {
        id: redoAction
        text: qsTr("Redo")
        shortcut: StandardKey.Redo
        onTriggered: console.log("Redo action triggered");
    }

    Action {
        id: copyAction
        text: qsTr("Copy")
        shortcut: StandardKey.Copy
        onTriggered: console.log("Copy action triggered");
    }

    Action {
        id: cutAction
        text: qsTr("Cut")
        shortcut: StandardKey.Cut
        onTriggered: console.log("Cut action triggered");
    }

    Action {
        id: pasteAction
        text: qsTr("Paste")
        shortcut: StandardKey.Paste
        onTriggered: console.log("Paste action triggered");
    }

    Action {
        id: aboutAction
        text: qsTr("About")
        onTriggered: aboutDialog.open()
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
        title: qsTr("Help")
        MenuItem {
            action: aboutAction
        }
    }
}