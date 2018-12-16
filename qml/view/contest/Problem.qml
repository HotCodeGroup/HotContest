import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "tools"
import "../tools"
import models 1.0

Rectangle {
    id: problem
    property StackView current_contest_stack_view
    property int current_contest_id
    property int current_problem_id

    LoginRequired {
        id: login_decorator
    }

    ScrollView {
        height: current_contest_stack_view.height + (parent.height * 0.09)
        width: problem_column.width
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: problem_column
            spacing: 30

            Text {
                width: problem.width
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 41
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: M_Problem.title

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
                    text: qsTr("Баллы: " + M_Problem.points)
                }

                Text {
                    font {
                        letterSpacing: -1
                        family: roboto.name
                        pixelSize: 19
                    }
                    color: "#31000000"
                    renderType: Text.NativeRendering
                    text: qsTr("Штраф: " + M_Problem.penaltyTry)
                }

                Text {
                    font {
                        letterSpacing: -1
                        family: roboto.name
                        pixelSize: 19
                    }
                    color: "#31000000"
                    renderType: Text.NativeRendering
                    text: qsTr("Ограничение по времени: " + M_Problem.timeLimit + "ms")
                }

                Text {
                    font {
                        letterSpacing: -1
                        family: roboto.name
                        pixelSize: 19
                    }
                    color: "#31000000"
                    renderType: Text.NativeRendering
                    text: qsTr("Ограничение по памяти: " + M_Problem.memLimit + "B")
                }
            }

            Text {
                width: problem.width
                font {
                    family: roboto.name
                    pixelSize: 20
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: M_Problem.description
            }

            Text {
                width: problem.width
                font {
                    letterSpacing: -1
                    family: roboto.name
                    pixelSize: 19
                }
                wrapMode: Text.Wrap
                color: "#31000000"
                renderType: Text.NativeRendering
                text: qsTr("Осталось попыток: " + M_Problem.triesLeft)
            }

            Row {
                spacing: 38

                MyButton {
                    id: select_file_button
                    height: 48
                    isLight: false
                    backgroundColor: "#F3F3F3"
                    onHoverColor: "#EEEEEE"
                    content_text: "Выбрать файл"
                    onClick: function() {
                    }
                }

                Text {
                    anchors.verticalCenter: select_file_button.verticalCenter
                    width: problem.width / 2
                    clip: true
                    font {
                        underline: true
                        family: roboto.name
                        pixelSize: 19
                    }
                    color: "#31000000"
                    renderType: Text.NativeRendering
                    text: qsTr("main.cpp")
                }
            }

            MyButton {
                id: send_file_button
                height: 48
                isLight: false
                textColor: "#FFFFFF"
                content_text: "Отправить"
                onClick: function() {
                    login_decorator.login_required(function() {});
                }
            }

            Component {
                id: submit_table

                SubmitTable {
                    property real content_width: problem.width
                    current_contest_stack_view: problem.current_contest_stack_view
                    current_contest_id: problem.current_contest_id
                }
            }

//            Connections {
//                target: ListOfSubmit.state
//                onIsLoadingChanged: function (isLoading) {
//                    if (isLoading) {
//                        console.log("loading submit");
//                        submit_table_loader.setSource("");
//                    }
//                    else {
//                        submit_table_loader.sourceComponent = submit_table
//                    }
//                }
//            }

            SubmitTable {
                property real content_width: problem.width
                current_contest_stack_view: problem.current_contest_stack_view
                current_contest_id: problem.current_contest_id

                Component.onCompleted: {
                    ListOfSubmit.sendShortRequest(current_contest_id, current_problem_id);
                }
            }

//            Loader {
//                id: submit_table_loader

//                Component.onCompleted: ListOfSubmit.sendShortRequest(current_contest_id, current_problem_id);
//            }

        }
    }
}

