import QtQuick 2.9
import QtQuick.Controls 2.2
import "../tools"

Rectangle {
    id: create_contest
    property Loader loader

    z: 150
    color: "#99000000"
    MouseArea {
        anchors.fill: create_contest
        hoverEnabled: true
        onEntered: {}
        onExited: {}
        onClicked: loader.setSource("", {})
    }

    Rectangle {
        anchors {
            centerIn: parent
        }
        width: 382
        height: components.height  + 76
        radius: 15

        MouseArea {
            anchors.fill: parent
            onClicked: {}
        }

        Rectangle {
            anchors {
                right: parent.right
                top: parent.top
                rightMargin: 20
                topMargin: 20
            }

            Image {
                id: exit
                anchors.centerIn: parent
                source: "qrc:/icon/cancel.svg"
                width: 15
                height: 15

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {exit.opacity = 0.7}
                    onExited: {exit.opacity = 1}
                    onClicked: loader.setSource("", {})
                }
            }
        }

        Rectangle {
            id: create
            anchors {
                leftMargin: 24
                rightMargin: 24
                topMargin: 38
                bottomMargin: 38
                fill: parent
            }

            Column {
                id: components
                spacing: 25

                Column {
                    id: inputs
                    spacing: 6

                    MyInput {
                        id: contest_name
                        label: "Название контеста"
                        input_width: create.width
                        is_focus: true
                    }
                }

                Row {
                    id: buttons
                    spacing: 19

                    Rectangle {
                        id: submit_button
                        height: 34
                        width: textSend.width + 40
                        color: "#FF6347"
                        radius: 10
                        Text {
                            id: textSend
                            anchors.centerIn: parent
                            color: "#FFFFFF"
                            font {
                                weight: Font.Light
                                family: roboto.name
                                pixelSize: 19
                            }
                            text: qsTr("Создать")
                        }

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {submit_button.color = "#FF5638"}
                            onExited: {submit_button.color = "#FF6347"}
                            onClicked: loader.setSource("", {})
                        }
                    }
                }
            }
        }
    }
}
