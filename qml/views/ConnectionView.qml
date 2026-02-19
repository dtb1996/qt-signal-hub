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
            id: connectionStateText
            text: qsTr("Status: ") + appState.connectionStateText
            font.bold: true
            color: "red"

            states: [
                State {
                    name: "connected"
                    when: appState.connectionState === Connection.State.Connected
                    PropertyChanges {
                        target: connectionStateText
                        color: "green"
                    }
                },

                State {
                    name: "connecting"
                    when: appState.connectionState === Connection.State.Connecting
                    PropertyChanges {
                        target: connectionStateText
                        color: "orange"
                    }
                }
            ]
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
