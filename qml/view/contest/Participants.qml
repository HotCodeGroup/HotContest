import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "../paginator"
import models 1.0

Rectangle {
    id: participants
    property StackView current_contest_stack_view
    property int current_contest_id

    ScrollView {
        height: current_contest_stack_view.height + (parent.height * 0.09)
        width: participants_column.width
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: participants_column
            spacing: 30

            Text {
                width: participants.width
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 41
                }
                wrapMode: Text.Wrap
                renderType: Text.NativeRendering
                text: qsTr("Список участников")
            }

            Text {
                width: participants.width
                font {
                    letterSpacing: -1
                    family: roboto.name
                    pixelSize: 19
                }
                wrapMode: Text.Wrap
                color: "#31000000"
                renderType: Text.NativeRendering
                text: qsTr("Общее количество: " + ListOfParticipants.size)
            }

            ListView {
                width: participants.width
                height: 50 * ListOfParticipants.size
                clip: true
                model: ListOfParticipants

                delegate: Rectangle {
                    height: 50
                    width: username_text.width
                    clip: true

                    Text {
                        id: username_text
                        anchors {
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                        }

                        renderType: Text.NativeRendering
//                        color: model.m_is_me ? "#FF6347" : "#000000"
                        color: "#000000"
                        font {
                            weight: Font.Light
                            family: roboto.name
                            pixelSize: 20
                        }
                        text: qsTr(participantId + ". " + username)
                    }
                }
            }

            Paginator {

            }
        }
    }
}

