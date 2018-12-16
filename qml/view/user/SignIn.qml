import QtQuick 2.9
import QtQuick.Controls 2.2
import "../tools"
import QtQuick.Window 2.3
import models 1.0

Rectangle {
    id: sign_in

    property Loader loader
    property Loader second_loader

    Form {
        id: sign_in_form

        property LoginForm form: LoginForm {}

        width: window.width
        height: window.height

        form_header_text: "Вход"
        text_main_button: "Войти"
        text_second_button: "Регистрация"
        loader: sign_in.loader

        inputs: Component {
            Column {
                id: inputs
                spacing: 6

                MyInput {
                    id: username
                    cur_input {
                        onTextChanged: {
                            sign_in_form.form.nickname = cur_input.text;
                        }
                        text: sign_in_form.form.nickname
                    }
                    Connections {
                        target: sign_in_form.form
                        onNicknameErrorsChanged: function(nicknameErrors) {
                            username.output_errors();
                        }
                    }

                    label: "Псевдоним"
                    input_width: sign_in_form.input_width
                    is_focus: true
                    next_input: password.cur_input
                    errors: sign_in_form.form.nicknameErrors
                }

                MyInput {
                    id: password
                    cur_input {
                        onTextChanged: {
                            sign_in_form.form.password = cur_input.text;
                        }
                        text: sign_in_form.form.password
                    }
                    Connections {
                        target: sign_in_form.form
                        onPasswordErrorsChanged: function(passwordErrors) {
                            password.output_errors();
                        }
                    }

                    label: "Пароль"
                    input_width: sign_in_form.input_width
                    is_password: true
                    next_input: username.cur_input
                    errors: sign_in_form.form.passwordErrors
                }
            }
        }

        main_button_callback: function() {
            sign_in_form.form.sendRequest();
            if (sign_in_form.form.validate()) {
                User.auth();
                loader.setSource("", {});
            }
        }

        second_button_callback: function() {
            loader.setSource("", {})
            second_loader.setSource("qrc:/view/user/SignUp.qml",
                                            {"loader": second_loader,
                                             "second_loader": loader})
        }
    }
}
