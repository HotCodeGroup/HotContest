import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "../paginator"
import "tools"
import models 1.0

Rectangle {
    id: submits
    property StackView current_contest_stack_view
    property int current_contest_id

    ScrollView {
        height: current_contest_stack_view.height + (parent.height * 0.09)
        width: submits_column.width
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: submits_column
            spacing: 70

            Text {
                width: submits.width
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 41
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: qsTr("Список посылок")
            }

            SubmitTable {
                property real content_width: submits.width
                current_contest_stack_view: submits.current_contest_stack_view
                current_contest_id: submits.current_contest_id
            }

            Paginator {

            }

        }
    }
}

