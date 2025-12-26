import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtSignalHub 1.0

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Qt Signal Hub")
    color: "gray"

    ColumnLayout {
        anchors.fill: parent
        spacing: 12
        anchors.margins: 12

        ConnectionView {
            Layout.fillWidth: true;
        }

        FeedView {
            Layout.fillWidth: true;
            Layout.fillHeight: true
            model: messageModel
        }
    }

    Shortcut {
        sequence: "Escape"
        onActivated: Qt.quit()
    }

    Shortcut {
        sequence: "Alt+Return"
        onActivated: mainWindow.visibility = mainWindow.visibility === Window.FullScreen ? Window.Windowed : Window.FullScreen
    }
}
