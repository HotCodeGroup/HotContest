import QtQuick 2.9
import QtQuick.Controls 2.2
import "../tools"
import models 1.0

Rectangle {
    id: sign_up
    property Loader loader
    property Loader second_loader

    function regist_controller() {
        SignUpForm.firstName = first_name.cur_input.text;
        SignUpForm.lastName = last_name.cur_input.text;
        LoginForm.nickname = username.cur_input.text;
        SignUpForm.email = email.cur_input.text;
        LoginForm.password = password.cur_input.text;
        SignUpForm.repitPassword = repit_password.cur_input.text;

        SignUpForm.sendRequest();
        if (SignUpForm.validate()) {
            loader.setSource("", {});
        }
    }

    z: 150
    width: window.width
    height: window.height
    color: "#99000000"

    MouseArea {
        anchors.fill: sign_up
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
            id: signup
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
                    id: signupheader
                    font {
                        weight: Font.Light
                        family: roboto.name
                        pixelSize: 36
                    }
                    renderType: Text.NativeRendering
                    text: qsTr("Регистрация")
                }

                Column {
                    id: inputs
                    spacing: 6

                    MyInput {
                        id: first_name
                        label: "Имя"
                        input_width: signup.width
                        is_focus: true
                        next_input: last_name.cur_input
                    }

                    MyInput {
                        id: last_name
                        label: "Фамилия"
                        input_width: signup.width
                        next_input: username.cur_input
                    }

                    MyInput {
                        id: username
                        label: "Псевдоним"
                        input_width: signup.width
                        next_input: email.cur_input
                    }

                    MyInput {
                        id: email
                        label: "Email"
                        input_width: signup.width
                        next_input: password.cur_input
                    }

                    MyInput {
                        id: password
                        label: "Пароль"
                        input_width: signup.width
                        is_password: true
                        next_input: repit_password.cur_input
                    }

                    MyInput {
                        id: repit_password
                        label: "Повторите пароль"
                        input_width: signup.width
                        is_password: true
                        next_input: first_name.cur_input
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
                            text: qsTr("Отправить")
                        }

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {submit_button.color = "#FF5638"}
                            onExited: {submit_button.color = "#FF6347"}
                            onClicked: {
                                regist_controller();
                                loader.setSource("", {});
                            }
                        }
                    }

                    Rectangle {
                        id: signin_button
                        height: 34
                        width: textSignIn.width + 40
                        color: "#E5E5E5"
                        radius: 10
                        Text {
                            id: textSignIn
                            anchors.centerIn: parent
                            font {
                                weight: Font.Light
                                family: roboto.name
                                pixelSize: 19
                            }
                            text: qsTr("Войти")
                        }

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {signin_button.color = "#E0E0E0"}
                            onExited: {signin_button.color = "#E5E5E5"}
                            onClicked: {
                                loader.setSource("", {})
                                second_loader.setSource("qrc:/view/user/SignIn.qml",
                                                                {"loader": second_loader,
                                                                 "second_loader": loader})
                            }
                        }
                    }
                }
            }
        }
    }
}
