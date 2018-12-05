import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "../paginator"
import "tools"

Rectangle {
    id: run_report
    property StackView current_contest_stack_view
    property int current_contest_id
    property int current_problem_id
    property int current_submit_id

    ScrollView {
        height: current_contest_stack_view.height + (parent.height * 0.09)
        width: run_report_column.width
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: run_report_column
            spacing: 30

            Text {
                width: run_report.width
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 41
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: qsTr("Best Problem")
            }

            Text {
                width: run_report.width
                font {
                    family: roboto.name
                    pixelSize: 19
                }
                wrapMode: Text.Wrap
                color: "#31000000"
                renderType: Text.NativeRendering
                text: qsTr("Вердикт: Error")
            }

            Rectangle {
                id: open_file_button
                height: 48
                width: open_file.width + 40
                color: "#F3F3F3"
                radius: 10
                Text {
                    id: open_file
                    anchors.centerIn: parent
                    color: "#000000"
                    renderType: Text.NativeRendering
                    font {
                        family: roboto.name
                        pixelSize: 19
                    }
                    text: qsTr("Открыть исходный код")
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {open_file_button.color = "#EEEEEE"}
                    onExited: {open_file_button.color = "#F3F3F3"}
                }
            }

            RunReportTable {
                property real content_width: run_report.width
            }

            Paginator {

            }
        }
    }
}

