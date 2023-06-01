import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {
    objectName: shortcutName + "Row"

    Layout.columnSpan: 2

    property string shortcutName
    property string shortcutDisplayName

    Label {
        text: shortcutDisplayName

        Layout.leftMargin: 10
        Layout.fillWidth: true
    }
}