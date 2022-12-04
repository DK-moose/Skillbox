import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    visible: true
    minimumWidth: 350
    minimumHeight: 400
    title: qsTr("Moving the circle")

    property int rectSize: 60
    property int margin: 40
    property int distance: 0

    Rectangle {
        id: leftRectangle
        width: rectSize
        height: rectSize
        x: margin
        y: parent.height / 2 - height / 2
        radius: 5
        color: "lightgray"
        border.color: "black"
        border.width: 2

        Text {
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: "move"
            font.family: "FreeMono"
            font.pixelSize: parent.width / 4
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                ball.x += ball.width
                if (ball.x + ball.width >= rightRectangle.x) {
                    ball.state = "CURRENT"
                    ball.state = "START"
                }
            }
        }
    }

    Rectangle {
        id: rightRectangle
        width: rectSize
        height: rectSize
        x: parent.width - width - margin
        y: parent.height / 2 - height / 2
        radius: 5
        color: "lightgray"
        border.color: "black"
        border.width: 2

        Text {
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: "return"
            font.family: "FreeMono"
            font.pixelSize: parent.width / 4
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                ball.state = "CURRENT"
                ball.state = "START"
            }
        }
    }

    Rectangle {
        id: ball
        width: rectSize - 10
        height: rectSize - 10
        x: margin + 5
        y: parent.height / 2 - height / 2
        radius: width / 2
        color: "darkgreen"
        state: "START"

        states: [
            State {
                name: "START"
                PropertyChanges {
                    target: ball
                    x: margin + 5
                }
            },
            State {
                name: "CURRENT"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]

        transitions: [
            Transition {
                from: "CURRENT"
                to: "START"

                NumberAnimation {
                    properties: "x, y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }

            }
        ]
    }

}
