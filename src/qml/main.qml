import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

ApplicationWindow {

    visible: true

    //title of the application
    title: qsTr("Room Sketcher")
    width: 640
    height: 480

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

    MessageDialog {
        id: aboutDialog
        title: qsTr("About")
        buttons: MessageDialog.Ok
        text: qsTr("Room Sketcher - Floor Plan Creator")
    }

    Action {
        id: aboutAction
        text: qsTr("About")
        onTriggered: aboutDialog.open()
    }

    menuBar: MenuBar {
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

    Button {
        text: qsTr("Hello World")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}