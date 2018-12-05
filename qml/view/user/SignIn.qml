import QtQuick 2.9
import QtQuick.Controls 2.2
import "../tools"
import models 1.0

Rectangle {
    id: sign_in
    property Loader loader
    property Loader second_loader

    function login_controller() {
        LoginForm.nickname = username.cur_input.text;
        LoginForm.password = password.cur_input.text;

        LoginForm.sendRequest();
        if (LoginForm.validate()) {
            loader.setSource("", {});
        }
    }

    z: 150
    width: window.width
    height: window.height
    color: "#99000000"

    MouseArea {
        anchors.fill: sign_in
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
                    onEntered: {exit.opacity = 0.5}
                    onExited: {exit.opacity = 1}
                    onClicked: loader.setSource("", {})
                }
            }
        }

        Rectangle {
            id: signin
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
                    id: signinheader
                    font {
                        weight: Font.Light
                        family: roboto.name
                        pixelSize: 36
                    }
                    renderType: Text.NativeRendering
                    text: qsTr("Вход")
                }

                Column {
                    id: inputs
                    spacing: 6

                    MyInput {
                        id: username
                        label: "Псевдоним"
                        input_width: signin.width
                        is_focus: true
                        next_input: password.cur_input
                        errors: LoginForm.nicknameErrors
                    }

                    MyInput {
                        id: password
                        label: "Пароль"
                        input_width: signin.width
                        is_password: true
                        next_input: username.cur_input
                        errors: LoginForm.passwordErrors
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
                            text: qsTr("Войти")
                        }

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {submit_button.color = "#FF5638"}
                            onExited: {submit_button.color = "#FF6347"}
                            onClicked: {
                                login_controller();
                            }
                        }
                    }

                    Rectangle {
                        id: signup_button
                        height: 34
                        width: textSignUp.width + 40
                        color: "#E5E5E5"
                        radius: 10
                        Text {
                            id: textSignUp
                            anchors.centerIn: parent
                            font {
                                weight: Font.Light
                                family: roboto.name
                                pixelSize: 19
                            }
                            text: qsTr("Регистрация")
                        }

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {signup_button.color = "#E0E0E0"}
                            onExited: {signup_button.color = "#E5E5E5"}
                            onClicked: {
                                loader.setSource("", {})
                                second_loader.setSource("qrc:/view/user/SignUp.qml",
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
