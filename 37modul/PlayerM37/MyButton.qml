import QtQuick 2.0
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Rectangle {
    property string iconPath: ""
    property color buttonColor: "white"
    property string action: ""

    id: thisButton
    width: parent.height - 6
    height: parent.height - 6
    border.color: buttonColor
    radius: 3
    gradient: Gradient {
        GradientStop {
            position: 0.9
            color: buttonColor
        }

        GradientStop {
            position: 1.0
            color: "white"
        }
    }

    Image {
        source: iconPath
        width: parent.width - 6
        height: parent.height - 6
        anchors.centerIn: parent
    }

    NumberAnimation {
        id: hoverOverButton
        target: thisButton
        property: "scale"
        duration: 150
        from: 1
        to: 1.1
        easing.type: Easing.InOutQuad
    }

    NumberAnimation {
        id: notHoverOverButton
        target: thisButton
        property: "scale"
        duration: 150
        from: 1.1
        to: 1
        easing.type: Easing.InOutQuad
    }

    NumberAnimation {
        id: pressButton
        target: thisButton
        property: "scale"
        duration: 150
        from: 1
        to: 0.9
        easing.type: Easing.InOutQuad
    }

    NumberAnimation {
        id: notPressButton
        target: thisButton
        property: "scale"
        duration: 150
        from: 0.9
        to: 1
        easing.type: Easing.InOutQuad
    }

    MouseArea {
        property double speed: 1

        id: actionsButton
        anchors.fill: parent
        hoverEnabled: true
        onEntered: hoverOverButton.start()
        onExited: notHoverOverButton.start()
        onPressedChanged: {
            if (pressed) {
                pressButton.start()
            }
            else {
                notPressButton.start()
            }
        }
        onClicked: {
            if (parent.action == "play")
                timer.start()
            else if (parent.action == "pause")
                timer.stop()
            else if (parent.action == "stop") {
                timer.stop()
                mySlider.val = mySlider.from
            }
            else if (parent.action == "rewind")
                mySlider.val = mySlider.val - 5 >= 0 ? mySlider.val - 5 : 0
            else if (parent.action == "forward") {
                speed = speed + 0.25 <= 2 ? speed + 0.25 : 1
                timer.interval = speed == 1 ? 1000 : timer.interval / speed
            }

            if (parent.action == "forward")
                console.log(parent.action + "(x" + speed + ")")
            else
                console.log(parent.action)
        }
    }
}
