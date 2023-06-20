import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Templates as T
import QtQuick.Window

import "." as App

ToolBar {
    id: root
    objectName: "toolBar"

    Row {
        id: toolbarRow
        anchors.fill: parent

        App.ToolButton {
            id: fullScreenToolButton
            objectName: "fullScreenToolButton"
            icon.source: "qrc:/assets/icons/expand.svg"
            checkable: true
            checked: window.visibility === Window.FullScreen

            ToolTip.text: qsTr("Toggle fullscreen window")

            onClicked: toggleFullScreen()
        }
    }
}