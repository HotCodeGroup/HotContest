import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "../paginator"
import "tools"

Rectangle {
    id: results
    property StackView current_contest_stack_view
    property int current_contest_id

    ScrollView {
        height: current_contest_stack_view.height + (parent.height * 0.09)
        width: results_column.width
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: results_column
            spacing: 70

            Text {
                width: results.width
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 41
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: qsTr("Турнирная таблица")
            }

            Text {
                width: results.width
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 30
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: qsTr("Идет ремонт...")
            }

        }
    }
}

