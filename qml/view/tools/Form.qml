import QtQuick 2.9
import QtQuick.Controls 2.2
import "../tools"
import models 1.0

Rectangle {
    id: form

    property bool is_header: true
    property string form_header_text
    property real input_width: form_content.width
    property real form_width: 382
    property bool is_second_button: true
    property string text_main_button
    property string text_second_button

    property Loader loader
    property Component inputs
    property var main_button_callback
    property var second_button_callback

    z: 150
    color: "#99000000"

    MouseArea {
        anchors.fill: form
        hoverEnabled: true
        onEntered: {}
        onExited: {}
        onClicked: loader.setSource("", {})
    }

    Rectangle {
        anchors {
            centerIn: parent
        }
        width: form_width
        height: components.height  + 76
        radius: 15

        MouseArea {
            anchors.fill: parent
            onClicked: {}
        }

        Rectangle {
            id: close
            anchors {
                right: parent.right
                top: parent.top
                rightMargin: 20
                topMargin: 20
            }

            Image {
                id: exit
                anchors.centerIn: parent
                source: "qrc:/icon/cancel.svg"
                width: 15
                height: 15

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {exit.opacity = 0.5}
                    onExited: {exit.opacity = 1}
                    onClicked: loader.setSource("", {})
                }
            }
        }

        Rectangle {
            id: form_content
            anchors {
                leftMargin: 24
                rightMargin: 24
                topMargin: 38
                bottomMargin: 38
                fill: parent
            }

            Column {
                id: components
                spacing: 25

                Component {
                    id: header

                    Text {
                        font {
                            weight: Font.Light
                            family: roboto.name
                            pixelSize: 36
                        }
                        renderType: Text.NativeRendering
                        text: form_header_text
                    }
                }

                Loader {
                    id: header_loader
                    sourceComponent: is_header ? header : null
                }

                Loader {
                    id: inputs_loader
                    sourceComponent: inputs
                }

                Row {
                    id: buttons
                    spacing: 19

                    MyButton {
                        id: submit_button
                        textColor: "#FFFFFF"
                        content_text: text_main_button
                        onClick: function() {
                            main_button_callback();
                        }
                    }

                    Component {
                        id: signup_button

                        MyButton {
                            onHoverColor: "#E0E0E0"
                            content_text: text_second_button
                            backgroundColor: "#E5E5E5"
                            onClick: function() {
                                second_button_callback();
                            }
                        }
                    }

                    Loader {
                        id: second_button_loader
                        sourceComponent: is_second_button ? signup_button : null;
                    }
                }
            }
        }
    }
}
