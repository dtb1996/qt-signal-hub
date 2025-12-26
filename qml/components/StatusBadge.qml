import QtQuick
import QtQuick.Controls

Rectangle {
    id: badge
    width: 12
    height: 12
    radius: 6

    property int state: 0 // 0 = Disconnected, 1 = Connecting, 2 = Connected, 3 = Error

    color: state === 2 ? "green"  :
           state === 1 ? "orange" :
           state === 3 ? "red"    : "gray"
}
