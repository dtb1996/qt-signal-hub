import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtSignalHub.Connection 1.0

Item {
    id: connectionPanel
    width: parent.width
    height: 60

    RowLayout {
        anchors.fill: parent
        spacing: 12

        Text {
            text: qsTr("Status: ") + appState.connectionStateText
            font.bold: true
            color: appState.connectionState === Connection.State.Connected  ? "green"  :
                   appState.connectionState === Connection.State.Connecting ? "orange" : "red"
        }

        Button {
            text: qsTr("Connect")
            enabled: appState.connectionState === Connection.State.Disconnected || appState.connectionState === Connection.State.Error
            onClicked: connectionManager.connect()
        }

        Button {
            text: qsTr("Disconnect")
            enabled: appState.connectionState === Connection.State.Connected
            onClicked: connectionManager.disconnect()
        }

        Button {
            text: qsTr("Clear")
            enabled: messageModel.count > 0
            onClicked: messageModel.clear()
        }

        Text {
            text: appState.error !== "" ? qsTr("Error") + appState.error : ""
            color: "red"
        }
    }
}
