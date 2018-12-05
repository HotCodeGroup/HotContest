import QtQuick 2.9
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import models 1.0

Rectangle {

    property string label
    property real input_width
    property bool is_focus: false
    property bool is_password: false
    property variant errors

    property TextInput cur_input: input_field
    property TextInput next_input

    height: input.height
    width: input.width

    Column {
        id: input

        Text {
            font {
                weight: Font.Light
                family: roboto.name
                pixelSize: 19
            }
            renderType: Text.NativeRendering
            text: label
        }

        Rectangle {
            width: input_width
            height: input_field.contentHeight + 12
            border {
                color: input_field.cursorVisible ? "#60000000" : "#31000000"
                width: 1
            }
            radius: 10

            TextInput {
                id: input_field
                echoMode: is_password ? TextInput.Password : TextInput.Normal
                passwordMaskDelay: is_password ? 400 : undefined
                focus: is_focus
                anchors {
                    fill: parent
                    leftMargin: 13
                }
                verticalAlignment: TextInput.AlignVCenter
                wrapMode: TextInput.Wrap
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 19
                }
                KeyNavigation.tab: next_input
            }
        }

//        ErrorInInput {
//            width: input_width
//            height: 15
//            text_error: errors[0]
//        }
    }
}
