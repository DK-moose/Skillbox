import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtGraphicalEffects 1.0

Item {
    property string textButton: "0"
    property color buttonCollor: Qt.rgba(255, 255, 255, 0.2)
    property int userWidth: (parent.width - 10) / 3
    property int userHeight: (parent.width - 10) / 3

    id: button
    width: userWidth
    height: userHeight

    Rectangle {
        id: buttonImage
        width: userWidth - 10
        height: userHeight - 10
        radius: height / 2
        anchors.centerIn: parent
        color: buttonCollor
        border.width: 1
        border.color: "white"

        gradient: Gradient {
            GradientStop {
                position: 0.95
                color: buttonCollor
            }

            GradientStop {
                position: 1.0
                color: "white"
            }
        }

        Label {
            id: lblButton
            anchors.centerIn: parent
            font.pixelSize: parent.height / 2
            color: "white"
            text: textButton
        }
    }


    NumberAnimation {
        id: pressButton
        target: buttonImage
        property: "scale"
        duration: 100
        from: 1
        to: 0.95
        easing.type: Easing.InOutQuad
    }

    NumberAnimation {
        id: notPressButton
        target: buttonImage
        property: "scale"
        duration: 100
        from: 0.95
        to: 1
        easing.type: Easing.InOutQuad
    }

    Timer {
        id: timerClickButton
        interval: 2000
        onTriggered: {
            if (back.tmpChannel != -1 && back.tmpChannel <= back.channelTo)
                back.channel = back.tmpChannel
            else if (back.tmpChannel != -1 && back.tmpChannel > back.channelTo)
                console.log("Not found channel: " + back.tmpChannel)
            back.tmpChannel = -1
        }
    }

    MouseArea {
        id: maButton
        anchors.fill: parent
        onPressedChanged: {
            if (pressed)
                pressButton.start()
            else
                notPressButton.start()
        }

        onClicked: {
            if (textButton == "CH +")
                back.channel = back.channel + 1 > back.channelTo ? back.channelTo : back.channel + 1
            else if (textButton == "CH -")
                back.channel = back.channel - 1 < back.channelFrom ? back.channelTo : back.channel - 1
            else if (textButton == "VOL +") {
                back.volume = back.volume + back.stepVolume > back.volumeTo ? back.volumeTo : back.volume + back.stepVolume
                back.sVolume = false
            }
            else if (textButton == "VOL -") {
                back.volume = back.volume - back.stepVolume < back.volumeFrom ? back.volumeFrom : back.volume - back.stepVolume
                back.sVolume = false
            }
            else if (textButton == "S")
                back.sVolume = !back.sVolume
            else if (textButton == "\u2D40")
                close()
            else {
                timerClickButton.restart()
                if (back.tmpChannel <= 0)
                    back.tmpChannel = textButton
                else
                    back.tmpChannel = back.tmpChannel + textButton
            }
        }
    }
}
