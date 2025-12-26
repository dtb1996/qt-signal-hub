import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ListView {
    id: feedView
    width: parent.width
    height: parent.height
    model: ListModel {}
    spacing: 4
    clip: true
    reuseItems: true
    delegate: MessageCard {
        width: ListView.view.width
        channel: model.channel
        payload: model.payload
        timestamp: model.timestamp
    }
}

