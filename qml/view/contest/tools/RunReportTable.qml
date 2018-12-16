import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    property StackView current_contest_stack_view
    property int current_contest_id

    id: run_report_table
    width: content_width
    height: run_report_header.height * (ListOfTestSubmit.size + 1)

    property real head_content_width: max_width_id + max_width_verdict + max_width_time + max_width_memory
    property real free_width: content_width - head_content_width

    property real max_width_id: 0
    property real max_width_verdict: 0
    property real max_width_time: 0
    property real max_width_memory: 0

    Rectangle {
        id: run_report_header
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }

        width: parent.width
        height: 47

        Rectangle {
            z: 50
            height: 1
            width: run_report_header.width
            color: "#50000000"
            anchors {
                bottom: run_report_header.bottom
            }
        }

        Row {
            id: head_row
            anchors {
                left: parent.left
            }

            TableItem {
                id: number
                property real item_width: number.text_width + free_width / 4
                property string content_text: qsTr("#")
                max_width: max_width_id
                Component.onCompleted: {
                    max_width_id = number.max_width
                }
            }

            TableItem {
                id: verdict
                property real item_width: verdict.text_width + free_width / 4
                property string content_text: qsTr("Вердикт")
                max_width: max_width_verdict
                Component.onCompleted: {
                    max_width_verdict = verdict.max_width
                }
            }

            TableItem {
                id: time
                property real item_width: time.text_width + free_width / 4
                property string content_text: qsTr("Время")
                max_width: max_width_time
                Component.onCompleted: {
                    max_width_time = time.max_width
                }
            }

            TableItem {
                id: memory
                property real item_width: memory.text_width + free_width / 4
                property string content_text: qsTr("Память")
                max_width: max_width_memory
                Component.onCompleted: {
                    max_width_memory = memory.max_width
                }
            }
        }
    }

    ListView {
        width: parent.width
        anchors {
            top: run_report_header.bottom
        }
        height: 47 * ListOfTestSubmit.size
        clip: true
        model: ListOfTestSubmit

        delegate: Rectangle {
            id: items
            width: parent.width
            height: 47

            Rectangle {
                z: 50
                height: 1
                width: parent.width
                color: "#31000000"
                anchors {
                    bottom: parent.bottom
                }
            }

            Row {
                anchors {
                    left: parent.left
                }

                TableItem {
                    id: number_item
                    property real item_width: number.width
                    property string content_text: testSubmitId
                    max_width: max_width_id
                    Component.onCompleted: {
                        max_width_id = number_item.max_width
                    }
                }

                TableItem {
                    id: verdict_item
                    property real item_width: verdict.width
                    property string content_text: testVerdict
                    text_color: testVerdict === qsTr("Ok") ? "#2BA500" : "#000000"
                    max_width: max_width_verdict
                    Component.onCompleted: {
                        max_width_verdict = verdict_item.max_width
                    }
                }

                TableItem {
                    id: time_item
                    property real item_width: time.width
                    property string content_text: timeStr
                    max_width: max_width_time
                    Component.onCompleted: {
                        max_width_time = time_item.max_width
                    }
                }

                TableItem {
                    id: memory_item
                    property real item_width: memory.width
                    property string content_text: memoryStr
                    max_width: max_width_memory
                    Component.onCompleted: {
                        max_width_memory = memory_item.max_width
                    }
                }
            }
        }
    }
}

