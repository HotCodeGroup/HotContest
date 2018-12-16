import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    id: item
    width: item_width
    height: 47
    clip: true
    property StackView current_contest_stack_view
    property int current_contest_id
    property int current_problem_id
    property int current_submit_id
    property real text_width: item_text.width
    property bool is_link: false
    property string text_color: "#000000"
    property real max_width

    function maxWidth(cur_width) {
        if (cur_width > max_width) {
            max_width = cur_width
        }
    }

//    Connections {
//        target: ListOfTestSubmit.state
//        onIsLoadingChanged: function (isLoading) {
//            if (is_link) {
//                if (isLoading) {
//                    console.log("loading runreport");
//                    current_contest_stack_view.replace("");
//                }
//                else {
//                    current_contest_stack_view.replace("qrc:/view/contest/RunReport.qml",
//                                            {current_contest_stack_view: item.current_contest_stack_view,
//                                             current_contest_id: item.current_contest_id,
//                                             current_problem_id: item.current_problem_id,
//                                             current_submit_id: item.current_submit_id});
//                }
//            }
//        }
//    }

    function runreportController(contest_id, submit_id) {
        ListOfTestSubmit.sendRequest(contest_id, submitId);
        current_contest_stack_view.replace("qrc:/view/contest/RunReport.qml",
                                {current_contest_stack_view: item.current_contest_stack_view,
                                 current_contest_id: item.current_contest_id,
                                 current_problem_id: item.current_problem_id,
                                 current_submit_id: item.current_submit_id});
    }

    Component.onCompleted: maxWidth(item_text.width)

    Text {
        id: item_text
        clip: true
        anchors {
            centerIn: parent
        }
        renderType: Text.NativeRendering
        color: text_color
        font {
            weight: Font.Light
            family: roboto.name
            pixelSize: 17
        }
        wrapMode: Text.Wrap
        text: content_text

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                if (is_link) {
                    item_text.opacity = 0.8
                    item_text.font.underline = true
                }
            }
            onExited: {
                if (is_link) {
                    item_text.opacity = 1
                    item_text.font.underline = false
                }
            }
            onClicked:
                if (is_link) {
                    runreportController(current_contest_id, current_submit_id);
                }
        }
    }

}

