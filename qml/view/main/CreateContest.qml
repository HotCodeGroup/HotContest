import QtQuick 2.9
import QtQuick.Controls 2.2
import "../tools"
import models 1.0

Rectangle {
    id: create_contest

    z: 150
    color: "#00000000"

    property Loader loader

    Form {
        id: create_contest_form

        property CreateContestForm form: CreateContestForm {}

        anchors.fill: parent
        is_header: false
        is_second_button: false
        text_main_button: "Создать"
        loader: create_contest.loader

        inputs: Component {
            Column {
                id: inputs

                MyInput {
                    id: contest_name
                    cur_input {
                        onTextChanged: {
                            create_contest_form.form.title = cur_input.text;
                        }
                        text: create_contest_form.form.title
                    }
                    Connections {
                        target: create_contest_form.form
                        onTitleErrorsChanged: function(titleErrors) {
                            contest_name.output_errors();
                        }
                    }
                    label: "Название контеста"
                    input_width: create_contest_form.input_width
                    is_focus: true
                    errors: create_contest_form.form.titleErrors
                }
            }
        }

        main_button_callback: function() {
            create_contest_form.form.sendRequest();
            if (create_contest_form.form.validate()) {
                loader.setSource("", {})
            }
        }
    }
}
