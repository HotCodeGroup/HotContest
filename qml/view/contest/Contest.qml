import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    id: contest
    property StackView current_contest_stack_view
    property int current_contest_id

    ScrollView {
        height: current_contest_stack_view.height + (parent.height * 0.09)
        width: contest_column.width
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: contest_column
            spacing: 30

            Text {
                width: contest.width
                font {
                    weight: Font.Bold
                    family: roboto.name
                    pixelSize: 41
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: M_Contest.title
            }

            Row {
                spacing: 42

                Text {
                    font {
                        letterSpacing: -1
                        family: roboto.name
                        pixelSize: 19
                    }
                    color: "#31000000"
                    renderType: Text.NativeRendering
                    text: qsTr("Дата начала контеста: " + M_Contest.startTime)
                }

                Text {
                    font {
                        letterSpacing: -1
                        family: roboto.name
                        pixelSize: 19
                    }
                    color: "#31000000"
                    renderType: Text.NativeRendering
                    text: qsTr("Дата окончания контеста: " + M_Contest.finishTime)
                }
            }

            Text {
                width: contest.width
                font {
                    family: roboto.name
                    pixelSize: 20
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: M_Contest.description
            }
        }
    }
}

