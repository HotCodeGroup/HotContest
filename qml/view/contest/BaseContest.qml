import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "tools"
import models 1.0

Rectangle {
    id: contest_content
    property StackView current_stack_view
    property int current_contest_id
    property string component_url
    property int state_of_column: 1
    Timer {
        id: timer
    }

    function delay(delayTime, cb) {
        timer.interval = delayTime;
        timer.repeat = false;
        timer.triggered.connect(cb)
        timer.start();
    }

    property StateInfo stateInfo
    Connections {
        target: stateInfo
        onIsLoadingChanged: function (isLoading) {
            if (isLoading) {
                init_loader.setSource("qrc:/view/tools/Loading.qml");
            }
            else {
                init_loader.setSource(component_url, {
                                          "current_contest_stack_view": contest_stack_view,
                                          "current_contest_id": contest_content.current_contest_id
                                      })
            }
//            stateInfo = null;
        }
    }

    Component.onCompleted: {
        if (component_url === "qrc:/view/contest/Contest.qml") {
            stateInfo = M_Contest.state;
            M_Contest.sendRequest(current_contest_id);
        } else if (component_url === "qrc:/view/contest/Participants.qml") {
            stateInfo = ListOfParticipants.state;
            ListOfParticipants.sendRequest(current_contest_id);
        } else if (component_url === "qrc:/view/contest/Results.qml") {
            init_loader.setSource(component_url, {
                                      "current_contest_stack_view": contest_stack_view,
                                      "current_contest_id": contest_content.current_contest_id
                                  })
        }
        right_column.setSource("qrc:/view/contest/tools/RightColumn.qml", {
                                   "current_contest_stack_view": contest_stack_view,
                                   "current_contest_id": contest_content.current_contest_id
                               })
    }

    StackView {
        id: contest_stack_view
        anchors {
            top: contest_header.bottom
            bottom: parent.bottom
            left: left_column.right
            right: right_column.left
            topMargin: parent.height * 0.09
            bottomMargin: parent.height * 0.09
            leftMargin: (parent.width - left_column.width - right_column.width) * 0.07
            rightMargin: (parent.width - left_column.width - right_column.width) * 0.07
        }
        initialItem: Loader {
            id: init_loader
            Component.onCompleted: {
                ListOfShortProblem.sendRequest(current_contest_id);
            }
        }

        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }
        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }
        replaceEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }
    }

    ContestHeader {
        z: 75
        id: contest_header
        anchors.top: parent.top
        width: parent.width
        current_contest_stack_view: contest_stack_view
        current_contest_id: contest_content.current_contest_id
    }

    LeftColumn {
        z: 50
        id: left_column
        anchors{
            left: parent.left
            top: contest_header.bottom
            bottom: parent.bottom
        }
        height: parent.height
        current_contest_stack_view: contest_stack_view
        current_contest_id: contest_content.current_contest_id
    }

    property real column_width: 263
    Rectangle {
        id: hider
        anchors {
            verticalCenter: right_column.verticalCenter
            horizontalCenter: right_column.left
        }
        width: 74
        height: 100
        color: "#FF6347"
        radius: 15

        Image {
            id: arrow_image
            z: 50
            anchors {
                verticalCenter: hider.verticalCenter
                left: hider.left
                leftMargin: 11
            }
            source: "qrc:/icon/double-arrow.svg"
            width: 17
            height: 38
        }



        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {hider.color = "#FF5638"}
            onExited: {hider.color = "#FF6347"}
            onClicked: {
                if (state_of_column === 1) {
                    shift_column_in_right.running = true;
                    delay(100, function() {
                        right_column.setSource("qrc:/view/contest/tools/EmptyRightColumn.qml",
                                                        {"current_contest_stack_view": contest_stack_view,
                                                         "current_contest_id": contest_content.current_contest_id});
                    })
                    state_of_column = 0;
                    arrow_image.rotation = 180;

                }
                else {
                    shift_column_in_left.running = true;
                    state_of_column = 1;
                    arrow_image.rotation = 0;
                    right_column.setSource("qrc:/view/contest/tools/RightColumn.qml",
                                                    {"current_contest_stack_view": contest_stack_view,
                                                     "current_contest_id": contest_content.current_contest_id});
                }
            }
        }

        NumberAnimation {
            id: shift_column_in_right
            target: right_column
            properties: "width"
            from: column_width
            to: 0
            duration: 150
        }

        NumberAnimation {
            id: shift_column_in_left
            target: right_column
            properties: "width"
            from: 0
            to: column_width
            duration: 150
        }
    }

    Loader {
        z: 50
        id: right_column
        anchors{
            right: parent.right
            top: contest_header.bottom
            bottom: parent.bottom
        }
        height: parent.height
    }
}
