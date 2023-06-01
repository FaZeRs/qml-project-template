import QtQuick
import QtQuick.Controls
import "." as App

ApplicationWindow {
    title: qsTr("Room Sketcher")
    visible: true
    width: 640
    height: 480

    menuBar: App.MenuBar {
    }

    App.AboutDialog {
        id: aboutDialog
        anchors.centerIn: parent
        parent: Overlay.overlay
    }

    App.OptionsDialog {
        id: optionsDialog
        anchors.centerIn: parent
        parent: Overlay.overlay
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("Hello World")
        onClicked: console.log("Hello World button triggered")
    }
}
