import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Rectangle {
    property StackView current_contest_stack_view
    property int current_contest_id

    ListModel {
        id: message_model

        ListElement {
            m_author: qsTr("Илья Санеев Санеев Санеев Санеев Санеев")
            m_text: qsTr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.")
        }
        ListElement {
            m_author: qsTr("Илья Санеев")
            m_text: qsTr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
        }
        ListElement {
            m_author: qsTr("Илья Санеев")
            m_text: qsTr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.")
        }
        ListElement {
            m_author: qsTr("Илья Санеев")
            m_text: qsTr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
        }
        ListElement {
            m_author: qsTr("Илья Санеев")
            m_text: qsTr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
        }
        ListElement {
            m_author: qsTr("Илья Санеев")
            m_text: qsTr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
        }
        ListElement {
            m_author: qsTr("Илья Санеев")
            m_text: qsTr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
        }

    }

    id: right_column
    width: 263

    Rectangle {
        z: 75
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        width: 1
        height: parent.height
        color: "#31000000"
    }

    ScrollView {
        height: parent.height - send_message.height
        width: parent.width

        ListView {
            anchors {
                fill: parent
            }
            model: message_model

            delegate: Rectangle {
                width: parent.width - 10
                height: message_text.height + author.height + 61
                anchors {
                    left: parent.left
                }
                clip: true

                Column {
                    id: message
                    anchors {
                        topMargin: 20
                        bottomMargin: 20
                        leftMargin: 10
                        left: parent.left
                        fill: parent
                    }
                    spacing: 21
                    Text {
                        id: author
                        renderType: Text.NativeRendering
                        color: "#FF6347"
                        clip: true
                        font {
                            family: roboto.name
                            pixelSize: 19
                        }
                        text: model.m_author
                    }


                    Text {
                        id: message_text
                        width: message.width
                        renderType: Text.NativeRendering
                        color: "#000000"
                        wrapMode: Text.Wrap
                        font {
                            family: roboto.name
                            pixelSize: 16
                        }
                        text: model.m_text
                    }
                }
            }
        }
    }

    Rectangle {
        id: send_message
        width: parent.width
        height: send_message_input.height + send_message_button.height
        anchors {
            bottom: parent.bottom
        }

        Rectangle {
            id: send_message_input
            anchors {
                bottom: send_message_button.top
            }
            width: parent.width
            height: message_input.contentHeight + 20

            Rectangle {
                anchors {
                    bottom: parent.top
                }
                width: parent.width
                height: 1
                color: "#31000000"
            }

            Image {
                id: close
                anchors {
                    right: parent.right
                    top: parent.top
                    rightMargin: 10
                    topMargin: 10
                }
                source: "qrc:/icon/cancel.svg"
                width: 13
                height: 13

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {close.opacity = 0.5}
                    onExited: {close.opacity = 1}
                }
            }

            TextInput {
                id: message_input
                focus: true
                anchors {
                    fill: parent
                    leftMargin: 10
                    rightMargin: 30
                    topMargin: 10
                    bottomMargin: 10
                }
                wrapMode: TextInput.Wrap
                font {
                    family: roboto.name
                    pixelSize: 16
                }
            }
        }

        Rectangle {
            id: send_message_button
            width: parent.width
            height: 50
            anchors {
                bottom: parent.bottom
            }
            color: "#FF6347"

            Text {
                anchors {
                    centerIn: parent
                }
                renderType: Text.NativeRendering
                color: "#FFFFFF"
                font {
                    family: roboto.name
                    pixelSize: 19
                }
                text: qsTr("Отправить")
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {send_message_button.color = "#FF5638"}
                onExited: {send_message_button.color = "#FF6347"}
            }
        }
    }
}

