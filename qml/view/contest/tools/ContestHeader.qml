import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    id: contest_header
    property StackView current_contest_stack_view
    property int current_contest_id
    property string url_next
    property StateInfo stateInfo

    Connections {
        target: stateInfo
        onIsLoadingChanged: function (isLoading) {
            if (isLoading) {
                current_contest_stack_view.replace("qrc:/view/tools/Loading.qml");
            }
            else {
                current_contest_stack_view.replace(url_next, {
                                          "current_contest_stack_view": contest_header.current_contest_stack_view,
                                          "current_contest_id": current_contest_id
                                      })
            }
//            stateInfo = ListOfParticipants.state;
        }
    }

    function contestController() {
        stateInfo = M_Contest.state;
        url_next = "qrc:/view/contest/Contest.qml";
        M_Contest.sendRequest(current_contest_id);
    }

    function participantsController() {
        stateInfo = ListOfParticipants.state;
        url_next = "qrc:/view/contest/Participants.qml";
        ListOfParticipants.sendRequest(current_contest_id);
    }

    function submitsController() {
        ListOfSubmit.sendRequest(current_contest_id);
        current_contest_stack_view.replace("qrc:/view/contest/Submits.qml", {
                                  "current_contest_stack_view": contest_header.current_contest_stack_view,
                                  "current_contest_id": current_contest_id
                              })
    }

    function resultsController(current_contest_stack_view, contest_id) {
        current_contest_stack_view.replace("qrc:/view/contest/Results.qml",
                                {current_contest_stack_view: contest_header.current_contest_stack_view,
                                 current_contest_id: contest_id});
    }

    height: 30
    color: "#F3F3F3"

    Row {
        anchors {
            verticalCenter: parent.verticalCenter
            leftMargin: 63
            left: parent.left
        }
        spacing: 63

        Text {
            id: contest
            renderType: Text.NativeRendering
            color: "#000000"
            font {
                weight: Font.Bold
                family: roboto.name
                pixelSize: 17
            }
            text: qsTr("Best contest")

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {contest.font.underline = true}
                onExited: {contest.font.underline = false}
                onClicked: contestController()
            }
        }

        Text {
            id: results
            renderType: Text.NativeRendering
            color: "#000000"
            font {
                family: roboto.name
                pixelSize: 17
            }
            text: qsTr("Турнирная таблица")

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {results.font.underline = true}
                onExited: {results.font.underline = false}
                onClicked: resultsController(current_contest_stack_view, current_contest_id)
            }
        }

        Text {
            id: submits
            renderType: Text.NativeRendering
            color: "#000000"
            font {
                family: roboto.name
                pixelSize: 17
            }
            text: qsTr("Посылки")

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {submits.font.underline = true}
                onExited: {submits.font.underline = false}
                onClicked: submitsController()
            }
        }

        Text {
            id: participants
            renderType: Text.NativeRendering
            color: "#000000"
            font {
                family: roboto.name
                pixelSize: 17
            }
            text: qsTr("Участники")

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {participants.font.underline = true}
                onExited: {participants.font.underline = false}
                onClicked: participantsController()
            }
        }
    }
}
