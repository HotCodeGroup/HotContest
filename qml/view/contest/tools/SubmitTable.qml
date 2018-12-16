import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    id: submit_table
    property StackView current_contest_stack_view
    property int current_contest_id

    width: content_width
    height: submit_header.height * (ListOfSubmit.size + 1)

    property real head_content_width: max_width_id + max_width_timestamp + max_width_problem + max_width_verdict + max_width_time + max_width_memory + max_width_test + max_width_points
    property real free_width: content_width - head_content_width

    property real max_width_id: 0
    property real max_width_timestamp: 0
    property real max_width_problem: 0
    property real max_width_verdict: 0
    property real max_width_time: 0
    property real max_width_memory: 0
    property real max_width_test: 0
    property real max_width_points: 0

    Rectangle {
        id: submit_header
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
            width: submit_header.width
            color: "#50000000"
            anchors {
                bottom: submit_header.bottom
            }
        }

        Row {
            id: head_row
            anchors {
                left: parent.left
            }

            TableItem {
                id: number
                property real item_width: max_width_id + free_width / 8
                property string content_text: qsTr("#")
                max_width: max_width_id
                Component.onCompleted: {
                    max_width_id = number.max_width
                }
            }

            TableItem {
                id: timestamp
                property real item_width: max_width_timestamp + free_width / 8
                property string content_text: qsTr("Время отправки")
                max_width: max_width_timestamp
                Component.onCompleted: {
                    max_width_timestamp = timestamp.max_width
                }
            }

            TableItem {
                id: problem
                property real item_width: max_width_problem + free_width / 8
                property string content_text: qsTr("Задача")
                max_width: max_width_problem
                Component.onCompleted: {
                    max_width_problem = problem.max_width
//                    console.log(max_width_problem)
                }
            }

            TableItem {
                id: verdict
                property real item_width: max_width_verdict + free_width / 8
                property string content_text: qsTr("Вердикт")
                max_width: max_width_verdict
                Component.onCompleted: {
                    max_width_verdict = verdict.max_width
                }
            }

            TableItem {
                id: time
                property real item_width: max_width_time + free_width / 8
                property string content_text: qsTr("Время")
                max_width: max_width_time
                Component.onCompleted: {
                    max_width_time = time.max_width
                }
            }

            TableItem {
                id: memory
                property real item_width: max_width_memory + free_width / 8
                property string content_text: qsTr("Память")
                max_width: max_width_memory
                Component.onCompleted: {
                    max_width_memory = memory.max_width
                }
            }

            TableItem {
                id: test
                property real item_width: max_width_test + free_width / 8
                property string content_text: qsTr("Тест")
                max_width: max_width_test
                Component.onCompleted: {
                    max_width_test = test.max_width
                }
            }

            TableItem {
                id: points
                property real item_width: max_width_points + free_width / 8
                property string content_text: qsTr("Баллы")
                max_width: max_width_points
                Component.onCompleted: {
                    max_width_points = points.max_width
                }
            }
        }
    }

    ListView {
        width: parent.width
        anchors {
            top: submit_header.bottom
        }
        height: 47 * ListOfSubmit.size
        clip: true
        model: ListOfSubmit

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
                    property string content_text: submitId
                    text_color: "#0D47A1"
                    is_link: true
                    current_contest_stack_view: submit_table.current_contest_stack_view
                    current_contest_id: submit_table.current_contest_id
                    current_problem_id: problemId
                    current_submit_id: submitId
                    max_width: max_width_id
                    Component.onCompleted: {
                        max_width_id = number_item.max_width
                    }
                }

                TableItem {
                    id: timestamp_item
                    property real item_width: timestamp.width
                    property string content_text: submitTime
                    max_width: max_width_timestamp
                    Component.onCompleted: {
                        max_width_timestamp = timestamp_item.max_width
                    }
                }

                TableItem {
                    id: problem_item
                    property real item_width: problem.width
                    property string content_text: problemId
                    max_width: max_width_problem
                    Component.onCompleted: {
                        max_width_problem = problem_item.max_width
                    }
                }

                TableItem {
                    id: verdict_item
                    property real item_width: verdict.width
                    property string content_text: respCode === 0 ? "Ok" : "Error"
                    text_color: respCode === 0 ? "#2BA500" : "#000000"
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

                TableItem {
                    id: test_item
                    property real item_width: test.width
                    property string content_text: errorTest === 0 ? qsTr("-") : errorTest
                    max_width: max_width_test
                    Component.onCompleted: {
                        max_width_test = test_item.max_width
                    }
                }

                TableItem {
                    id: points_item
                    property real item_width: points.width
                    property string content_text: curPoints
                    max_width: max_width_points
                    Component.onCompleted: {
                        max_width_points = points_item.max_width
                    }
                }
            }
        }
    }
}

