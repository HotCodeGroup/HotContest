import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    id: left_column
    property StackView current_contest_stack_view
    property int current_contest_id
    property int current_problem_id

    Connections {
        target: M_Problem.state
        onIsLoadingChanged: function (isLoading) {
            if (isLoading) {
                current_contest_stack_view.replace("qrc:/view/tools/Loading.qml");
            }
            else {
                current_contest_stack_view.replace("qrc:/view/contest/Problem.qml",
                                        {current_contest_stack_view: left_column.current_contest_stack_view,
                                         current_contest_id: left_column.current_contest_id,
                                         current_problem_id: left_column.current_problem_id});
            }
        }
    }

    function problemController(current_contest_stack_view, contest_id, problem_id) {
        current_problem_id = problem_id;
        M_Problem.sendRequest(contest_id, problem_id);
    }

    width: 263

    Rectangle {
        z: 75
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.right
        }
        width: 1
        height: parent.height
        color: "#31000000"
    }

    ScrollView {
        anchors {
            fill: parent
        }

        ListView {
            anchors {
                fill: parent
            }
            model: ListOfShortProblem

            delegate: Rectangle {
                width: parent.width
                height: 72

                Rectangle {
                    anchors {
                        left: parent.left
                    }
                    clip: true
                    width: parent.width - points.width
                    height: parent.height

                    Row {
                        anchors {
                            verticalCenter: parent.verticalCenter
                            leftMargin: 12
                            left: parent.left
                        }
                        spacing: 10

                        Text {
                            id: title_problem
                            renderType: Text.NativeRendering
                            color: "#000000"
                            font {
                                family: roboto.name
                                pixelSize: 18
                            }
                            text: qsTr(problemId + ". " + titleStr)

                            MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered: {title_problem.color = "#FF6347"}
                                onExited: {title_problem.color = "#000000"}
                                onClicked: problemController(current_contest_stack_view, current_contest_id, problemId)
                            }
                        }

                        Text {
                            renderType: Text.NativeRendering
                            color: "#2BA500"
                            font {
                                family: roboto.name
                                pixelSize: 18
                            }
                            text: qsTr(isComplite ? "" : "")
                        }
                    }
                }

                Rectangle {
                    id: points
                    anchors {
                        right: parent.right
                    }
                    width: 50
                    height: parent.height

                    Text {
                        anchors {
                            centerIn: parent
                        }
                        renderType: Text.NativeRendering
                        color: "#31000000"
                        font {
                            family: roboto.name
                            pixelSize: 13
                        }
                        text: m_points
                    }
                }
            }
        }
    }
}

