import QtQuick 2.0
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Item {
    property int from: 0
    property int to: 100
    property int val: 0
    property color progressColor: "black"
    property int cursorX: width / to * val + height

    id: slider

    Rectangle {
        id: videoTime
        width: parent.width
        height: parent.height / 2
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        radius: 5
        border.width: 1
        border.color: Qt.rgba(0, 0, 0, 0.2)

        Rectangle {
            id: progressVal
            width: slider.cursorX < slider.width ? cursorX : slider.width
            height: parent.height
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            radius: parent.radius
            color: slider.progressColor
        }
    }

    Rectangle {
        id: cursor
        width: slider.height
        height: slider.height
        anchors.verticalCenter: slider.verticalCenter
        x: slider.cursorX < slider.width ? cursorX - width : slider.width - width
        radius: videoTime.radius
        gradient: Gradient {
            GradientStop {
                position: 0.2
                color: slider.progressColor
            }

            GradientStop {
                position: 1.0
                color: "white"
            }
        }
    }
}
