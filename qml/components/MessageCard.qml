import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: card
    height: implicitHeight
    implicitHeight: contentColumn.implicitHeight + 32
    radius: 6
    color: "#333333"
    border.color: "#555555"
    border.width: 1

    property string channel
    property string payload
    property string timestamp

    ColumnLayout {
        id: contentColumn
        spacing: 2
        anchors.centerIn: parent

        Text {
            text: "[" + timestamp + "] " + channel
            font.bold: true
            color: "#ffffff"
        }

        Text {
            text: payload
            color: "#dddddd"
            wrapMode: Text.Wrap
        }
    }
}
