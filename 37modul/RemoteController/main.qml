import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Window {
    id: root
    visible: true
    width: 240
    height: 680
    title: qsTr("Remote controller")

    Rectangle {
        id: back
        width: 240
        height: 680
        radius: 20
        anchors.centerIn: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "white" }
            GradientStop { position: 0.02; color: "black" }
            GradientStop { position: 0.98; color: "black" }
            GradientStop { position: 1.0; color: "white" }
        }

        property int channelFrom: 0
        property int channelTo: 50
        property int channel: 0
        property int tmpChannel: -1

        property int volumeFrom: 0
        property int volumeTo: 60
        property int volume: 0
        property double stepVolume: (volumeTo - volumeFrom) / 10
        property bool sVolume: false
        
        GridLayout {
            id: buttons
            width: parent.width - 10
            height: 5 * width / 3
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            columns: 3
            rows: 5

            MyButton {
                id: button_OnOff
                textButton: "\u2D40"
                buttonCollor: "#9c0000"
                Layout.column: 0
                Layout.row: 0
            }

            MyButton {
                id: button_volume
                textButton: "S"
                Layout.column: 2
                Layout.row: 0
            }

            MyButton {
                id: button_1
                textButton: "1"
                Layout.column: 0
                Layout.row: 1
            }

            MyButton {
                id: button_2
                textButton: "2"
                Layout.column: 1
                Layout.row: 1
            }

            MyButton {
                id: button_3
                textButton: "3"
                Layout.column: 2
                Layout.row: 1
            }

            MyButton {
                id: button_4
                textButton: "4"
                Layout.column: 0
                Layout.row: 2
            }

            MyButton {
                id: button_5
                textButton: "5"
                Layout.column: 1
                Layout.row: 2
            }

            MyButton {
                id: button_6
                textButton: "6"
                Layout.column: 2
                Layout.row: 2
            }

            MyButton {
                id: button_7
                textButton: "7"
                Layout.column: 0
                Layout.row: 3
            }

            MyButton {
                id: button_8
                textButton: "8"
                Layout.column: 1
                Layout.row: 3
            }

            MyButton {
                id: button_9
                textButton: "9"
                Layout.column: 2
                Layout.row: 3
            }

            MyButton {
                id: button_0
                textButton: "0"
                Layout.column: 1
                Layout.row: 4
            }

            GridLayout {
                id: layButtonsChannels
                columns: 1
                rows: 2
                width: parent.width / 3
                height: width
                Layout.column: 0
                Layout.row: 4

                MyButton {
                    id: button_chPlus
                    textButton: "CH +"
                    Layout.row: 1
                    userWidth: parent.width
                    userHeight: parent.height / 2
                }

                MyButton {
                    id: button_chMinus
                    textButton: "CH -"
                    Layout.row: 2
                    userWidth: parent.width
                    userHeight: parent.height / 2
                }
            }

            GridLayout {
                id: layButtonsVolume
                columns: 1
                rows: 2
                width: parent.width / 3
                height: width
                Layout.column: 2
                Layout.row: 4

                MyButton {
                    id: button_volPlus
                    textButton: "VOL +"
                    Layout.row: 1
                    userWidth: parent.width
                    userHeight: parent.height / 2
                }

                MyButton {
                    id: button_volMinus
                    textButton: "VOL -"
                    Layout.row: 2
                    userWidth: parent.width
                    userHeight: parent.height / 2
                }
            }
        }

        Rectangle {
            id: display
            width: buttons.width - 10
            height: button_0.height
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: buttons.bottom
            anchors.topMargin: 20
            anchors.bottomMargin: 10
            radius: parent.radius
            border.color: Qt.rgba(255, 255, 255, 0.2)
            border.width: 2

            GridLayout {
                width: parent.width
                height: parent.height
                columns: 2
                rows: 1

                Item {
                    width: parent.width / 2 - 10
                    height: parent.height
                    Layout.column: 0

                    Label {
                        id: lblChannel
                        anchors.centerIn: parent
                        font.pixelSize: parent.height / 5
                        text: "Channel " + back.channel.toString()
                    }
                }

                Item {
                    width: parent.width / 2 - 10
                    height: parent.height
                    Layout.column: 1

                    Label {
                        id: lblVolume
                        anchors.centerIn: parent
                        font.pixelSize: parent.height / 5
                        text: back.sVolume ? "Volume 0" : "Volume " + back.volume.toString()
                    }
                }
            }
        }
    }
}
