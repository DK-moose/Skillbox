import QtQuick 2.9
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 850
    height: 450
    title: qsTr("Player")

    Rectangle {
        id: videoWindow
        width: parent.width
        height: parent.height - bottomPanel.height
        anchors.top: parent.top
        color: Qt.rgba(0, 0, 0)
    }

    Timer {
        id: timer
        interval: 1000
        repeat: true
        onTriggered: {
            mySlider.val += 1
            if (mySlider.val == mySlider.to)
                stop()
        }
    }

    Rectangle {
        id: bottomPanel
        width: parent.width
        height: 30
        anchors.bottom: parent.bottom
        color: Qt.rgba(0, 0, 0, 0.15)

        GridLayout {
            id: layButtons
            width: parent.height * 5
            height: parent.height
            anchors.left: parent.left
            anchors.leftMargin: 5
            rows: 1
            columns: 5

            property color bColor: Qt.rgba(Math.random() % 256, Math.random() % 256, Math.random() % 256)

            MyButton {
                id: buttonPlay
                iconPath: "file://" + applicationDirPath + "/icons/play.png"
                buttonColor: parent.bColor
                action: "play"
                Layout.column: 0
            }

            MyButton {
                id: buttonPause
                iconPath: "file://" + applicationDirPath + "/icons/pause.png"
                buttonColor: parent.bColor
                action: "pause"
                Layout.column: 1
            }

            MyButton {
                id: buttonStop
                iconPath: "file://" + applicationDirPath + "/icons/stop.png"
                buttonColor: parent.bColor
                action: "stop"
                Layout.column: 2
            }

            MyButton {
                id: buttonLeft
                iconPath: "file://" + applicationDirPath + "/icons/left.png"
                buttonColor: parent.bColor
                action: "rewind"
                Layout.column: 3
            }

            MyButton {
                id: buttonRight
                iconPath: "file://" + applicationDirPath + "/icons/right.png"
                buttonColor: parent.bColor
                action: "forward"
                Layout.column: 4
            }
        }

        MySlider {
            id: mySlider
            width: parent.width - layButtons.width - videoTimer.width - 15
            height: 10
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: layButtons.right
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            from: 0
            to: 150
            val: from
            progressColor: layButtons.bColor

            MouseArea {
                property double tmpVal: mouseX / (parent.width / parent.to)

                anchors.fill: parent
                onMouseXChanged: {
                    parent.val = tmpVal <= 0 ? 0 : tmpVal <= parent.to ? tmpVal : parent.to
                    if (parent.val == parent.to && timer.running)
                        timer.stop()
                }
            }
        }

        Label {
            property int hh: (mySlider.val / 60) / 60
            property int mm: (mySlider.val / 60) % 60
            property int ss: (mySlider.val % 60) % 60

            property string strHH: hh < 10 ? "0" + hh.toString() : hh.toString()
            property string strMM: mm < 10 ? "0" + mm.toString() : mm.toString()
            property string strSS: ss < 10 ? "0" + ss.toString() : ss.toString()

            id: videoTimer
            width: 65
            height: parent.height / 2
            anchors.bottom: mySlider.bottom
            anchors.right: parent.right
            font.pixelSize: height
            color: "black"
            text: strHH + ":" + strMM + ":" + strSS
        }
    }
}
