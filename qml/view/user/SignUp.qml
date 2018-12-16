import QtQuick 2.9
import QtQuick.Controls 2.2
import "../tools"
import models 1.0

Rectangle {
    id: sign_up

    property Loader loader
    property Loader second_loader

    Form {
        id: sign_up_form
        property SignUpForm form: SignUpForm {}

        width: window.width
        height: window.height

        form_header_text: "Регистрация"
        text_main_button: "Отправить"
        text_second_button: "Войти"
        loader: sign_up.loader

        inputs: Component {
            Column {
                id: inputs
                spacing: 6

                MyInput {
                    id: first_name
                    cur_input {
                        onTextChanged: {
                            sign_up_form.form.firstName = cur_input.text;
                        }
                        text: sign_up_form.form.firstName
                    }

                    label: "Имя"
                    input_width: sign_up_form.input_width
                    is_focus: true
                    next_input: last_name.cur_input
                }

                MyInput {
                    id: last_name
                    cur_input {
                        onTextChanged: {
                            sign_up_form.form.lastName = cur_input.text;
                        }
                        text: sign_up_form.form.lastName
                    }

                    label: "Фамилия"
                    input_width: sign_up_form.input_width
                    next_input: username.cur_input
                }

                MyInput {
                    id: username
                    cur_input {
                        onTextChanged: {
                            sign_up_form.form.nickname = cur_input.text;
                        }
                        text: sign_up_form.form.nickname
                    }
                    Connections {
                        target: sign_up_form.form
                        onNicknameErrorsChanged: function(nicknameErrors) {
                            username.output_errors();
                        }
                    }

                    label: "Псевдоним"
                    input_width: sign_up_form.input_width
                    next_input: email.cur_input
                    errors: sign_up_form.form.nicknameErrors
                }

                MyInput {
                    id: email
                    cur_input {
                        onTextChanged: {
                            sign_up_form.form.email = cur_input.text;
                        }
                        text: sign_up_form.form.email
                    }
                    Connections {
                        target: sign_up_form.form
                        onEmailErrorsChanged: function(emailErrors) {
                            email.output_errors();
                        }
                    }

                    label: "Email"
                    input_width: sign_up_form.input_width
                    next_input: password.cur_input
                    errors: sign_up_form.form.emailErrors
                }

                MyInput {
                    id: password
                    cur_input {
                        onTextChanged: {
                            sign_up_form.form.password = cur_input.text;
                        }
                        text: sign_up_form.form.password
                    }
                    Connections {
                        target: sign_up_form.form
                        onPasswordErrorsChanged: function(passwordErrors) {
                            password.output_errors();
                        }
                    }

                    label: "Пароль"
                    input_width: sign_up_form.input_width
                    is_password: true
                    next_input: repit_password.cur_input
                    errors: sign_up_form.form.passwordErrors
                }

                MyInput {
                    id: repit_password
                    cur_input {
                        onTextChanged: {
                            sign_up_form.form.repitPassword = cur_input.text;
                        }
                        text: sign_up_form.form.repitPassword
                    }
                    Connections {
                        target: sign_up_form.form
                        onRepitPasswordErrorsChanged: function(repitPasswordErrors) {
                            repit_password.output_errors();
                        }
                    }

                    label: "Повторите пароль"
                    input_width: sign_up_form.input_width
                    is_password: true
                    next_input: first_name.cur_input
                    errors: sign_up_form.form.repitPasswordErrors
                }
            }
        }

        main_button_callback: function() {
            sign_up_form.form.sendRequest();
            if (sign_up_form.form.validate()) {
                loader.setSource("", {});
            }
        }

        second_button_callback: function() {
            loader.setSource("", {})
            second_loader.setSource("qrc:/view/user/SignIn.qml",
                                            {"loader": second_loader,
                                             "second_loader": loader})
        }
    }
}
