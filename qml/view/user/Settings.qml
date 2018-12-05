import QtQuick 2.9
import "../tools"

Rectangle {
    id: settings
    property Loader loader

    z: 150
    width: window.width
    height: window.height
    color: "#99000000"
    MouseArea {
        anchors.fill: settings
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
            id: close
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
            id: settings_rect
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

                Text {
                    id: settings_header
                    font {
                        weight: Font.Light
                        family: roboto.name
                        pixelSize: 36
                    }
                    renderType: Text.NativeRendering
                    text: qsTr("Профиль")
                }

                Column {
                    id: inputs
                    spacing: 6

                    MyInput {
                        id: first_name
                        label: "Имя"
                        input_width: settings_rect.width
                        is_focus: true
                        next_input: last_name.cur_input
                    }

                    MyInput {
                        id: last_name
                        label: "Фамилия"
                        input_width: settings_rect.width
                        next_input: username.cur_input
                    }

                    MyInput {
                        id: username
                        label: "Псевдоним"
                        input_width: settings_rect.width
                        next_input: email.cur_input
                    }

                    MyInput {
                        id: email
                        label: "Email"
                        input_width: settings_rect.width
                        next_input: password.cur_input
                    }

                    MyInput {
                        id: password
                        label: "Пароль"
                        input_width: settings_rect.width
                        is_password: true
                        next_input: repit_password.cur_input
                    }

                    MyInput {
                        id: repit_password
                        label: "Повторите пароль"
                        input_width: settings_rect.width
                        is_password: true
                        next_input: old_password.cur_input
                    }

                    MyInput {
                        id: old_password
                        label: "Старый пароль"
                        input_width: settings_rect.width
                        is_password: true
                        next_input: first_name.cur_input
                    }
                }

                Row {
                    id: buttons

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
                            text: qsTr("Отправить")
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
