import QtQuick 2.9
import "../tools"

Rectangle {
    id: settings

    property Loader loader

    Form {
        id: settings_form

        width: window.width
        height: window.height

        form_header_text: "Профиль"
        text_main_button: "Отправить"
        is_second_button: false
        loader: settings.loader

        inputs: Component {
            Column {
                id: inputs
                spacing: 6

                MyInput {
                    id: first_name
                    label: "Имя"
                    input_width: settings_form.input_width
                    is_focus: true
                    next_input: last_name.cur_input
                }

                MyInput {
                    id: last_name
                    label: "Фамилия"
                    input_width: settings_form.input_width
                    next_input: username.cur_input
                }

                MyInput {
                    id: username
                    label: "Псевдоним"
                    input_width: settings_form.input_width
                    next_input: email.cur_input
                }

                MyInput {
                    id: email
                    label: "Email"
                    input_width: settings_form.input_width
                    next_input: password.cur_input
                }

                MyInput {
                    id: password
                    label: "Пароль"
                    input_width: settings_form.input_width
                    is_password: true
                    next_input: repit_password.cur_input
                }

                MyInput {
                    id: repit_password
                    label: "Повторите пароль"
                    input_width: settings_form.input_width
                    is_password: true
                    next_input: old_password.cur_input
                }

                MyInput {
                    id: old_password
                    label: "Старый пароль"
                    input_width: settings_form.input_width
                    is_password: true
                    next_input: first_name.cur_input
                }
            }
        }

        main_button_callback: function() {
            loader.setSource("", {});
        }
    }
}
