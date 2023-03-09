import QtQuick
import QtQuick.Controls

import "." as App

ApplicationWindow {

    visible: true

    //title of the application
    title: qsTr("Room Sketcher")
    width: 640
    height: 480

    menuBar: App.MenuBar {}

    Button {
        text: qsTr("Hello World")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}