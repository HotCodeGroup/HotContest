import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "../paginator"
import "../contest"
import models 1.0

Rectangle {

    id: content
    property StackView current_stack_view
    property real contest_item_height: 74
    property Loader create_loader

    function baseController(current_stack_view, contest_id, url) {
        current_stack_view.push("qrc:/view/contest/BaseContest.qml",
                                {current_stack_view: content.current_stack_view,
                                 current_contest_id: contest_id,
                                 component_url: url});
    }

    Column {
        spacing: 88

        Row {
            spacing: content.width - contentTitle.width - addContest.width

            Text {
                id: contentTitle
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 41
                }
                renderType: Text.NativeRendering
                text: qsTr("Список контестов")
            }

            Text {
                id: addContest
                anchors.baseline: contentTitle.baseline
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 25
                }
                renderType: Text.NativeRendering
                text: qsTr("Создать контест +")

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {addContest.color = "#FF6347"}
                    onExited: {addContest.color = "#000000"}
                    onClicked: {
                        create_loader.setSource("qrc:/view/main/CreateContest.qml",
                                                        {"loader": create_loader})
                    }
                }
            }
        }

        ListView {
            id: listContest1
            spacing: 13
            width: content.width
            height: (contest_item_height + 13) * ListOfShortContest.size - 13
            clip: true
            model: ListOfShortContest

            delegate: Rectangle {
                id: contests_item
                width: listContest1.width
                height: contest_item_height
                border {
                    color: "#31000000"
                    width: 1
                }

                Row {
                    anchors {
                        verticalCenter: parent.verticalCenter
                        leftMargin: 45
                        left: parent.left
                    }
                    spacing: 35

                    Text {
                        id: title
                        renderType: Text.NativeRendering
                        color: "#000000"
                        font {
                            weight: Font.Light
                            family: roboto.name
                            pixelSize: 24
                        }
                        text: titleStr

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {title.color = "#FF6347"}
                            onExited: {title.color = "#000000"}
                            onClicked: baseController(current_stack_view, contestId, "qrc:/view/contest/Contest.qml")
                        }
                    }

                    Text {
                        id: descr
                        anchors.baseline: title.baseline
                        renderType: Text.NativeRendering
                        color: isActive ? "#31000000" : "#0D47A1"
                        font {
                            family: roboto.name
                            pixelSize: 19
                        }
                        text: isActive ? qsTr("Активн.") : qsTr("Результат")

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {
                                if (!isActive) {
                                    descr.opacity = 0.8
                                    descr.font.underline = true
                                }
                            }
                            onExited: {
                                if (!isActive) {
                                    descr.opacity = 1
                                    descr.font.underline = false
                                }
                            }
                            onClicked:
                                if (!isActive) {
                                    baseController(current_stack_view, contestId, "qrc:/view/contest/Results.qml")
                                }
                        }
                    }
                }

                Text {
                    id: count
                    anchors {
                        verticalCenter: parent.verticalCenter
                        rightMargin: 20
                        right: parent.right
                    }
                    renderType: Text.NativeRendering
                    color: "#0D47A1"
                    font {
                        family: roboto.name
                        pixelSize: 18
                    }
                    text: qsTr(" x" + countOfParticipants)

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            count.opacity = 0.8
                            count.font.underline = true
                        }
                        onExited: {
                            count.opacity = 1
                            count.font.underline = false
                        }
                        onClicked: baseController(current_stack_view, contestId, "qrc:/view/contest/Participants.qml")
                    }
                }
            }
        }

        Paginator {

        }
    }
}
