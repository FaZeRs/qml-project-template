import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    id: root
    objectName: "aboutDialog"
    title: qsTr("About")
    modal: true
    dim: false
    focus: true
    standardButtons: Dialog.Ok

    ColumnLayout {
        spacing: 12

        Label {
            text: qsTr("%1").arg(Qt.application.name)
        }

        Label {
            text: qsTr("Version : %1").arg(Qt.application.version)
        }

        Label {
            text: qsTr("Copyright %1, %2").arg(new Date().getFullYear()).arg(Qt.application.organization)
        }
    }
}
