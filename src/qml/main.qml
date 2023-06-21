import QtQuick
import QtQuick.Controls
import "." as App

ApplicationWindow {
    id: window
    objectName: "window"
    title: qsTr("Room Sketcher")
    visible: true
    width: 1000
    height: 800
    opacity: settings.windowOpacity

    property int oldWindowVisibility: Window.Windowed

    function toggleFullScreen() {
        if (window.visibility === Window.FullScreen) {
            window.visibility = oldWindowVisibility
        }
        else {
            oldWindowVisibility = window.visibility
            window.visibility = Window.FullScreen
        }
    }

    menuBar: App.MenuBar {
    }

    header: App.ToolBar {
        id: toolBar
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

    App.StatusBar {
        id: statusBar
        parent: ApplicationWindow.window.contentItem
        width: parent.width
        anchors.bottom: parent.bottom
    }
}
