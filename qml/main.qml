import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "view/main"
import "view/main/tools"
import models 1.0


Window {
    id: window
    visible: true
    width: 1440
    height: 960
    title: qsTr("HotContest")

    FontLoader {
        id: overpass
        source: "qrc:/font/Overpass-Regular.ttf"
        name: "Overpass"
    }

    FontLoader {
        id: roboto
        source: "qrc:/font/Roboto-Regular.ttf"
        name: "Roboto"
    }

    FontLoader {
        id: roboto_light
        source: "qrc:/font/Roboto-Light.ttf"
        name: "Roboto-Light"
    }

    FontLoader {
        id: font_awesome
        source: "qrc:/icon/FontAwesome.otf"
        name: "FontAwesome"
    }

    property Component short_contests: ShortContests {
        anchors {
            right: parent.right
            left: parent.left
            top: parent.top
            leftMargin: parent.width / 10
            rightMargin: parent.width / 10
            topMargin: 64
        }
        create_loader: create_contest
        current_stack_view: stack_view
    }

    Connections {
        target: ListOfShortContest.state
        onIsLoadingChanged: function (isLoading) {
            if (isLoading) {
                stack_view.replace("qrc:/view/tools/Loading.qml");
            }
            else {
                stack_view.replace(short_contests);
            }
        }
    }

    Loader {
        id: create_contest
        z: 150
        width: window.width
        height: window.height
        anchors {
            top: window.top
            bottom: window.bottom
            left: window.left
            right: window.right
        }
    }

    Rectangle {
        anchors.fill: parent

        Header {
            id: header
            anchors {
                left: parent.left
                top: parent.top
                right: parent.right
            }
            width: parent.width
            current_stack_view: stack_view
        }

        Component.onCompleted: {
            ListOfShortContest.sendRequest();
        }

        StackView {
            id: stack_view
            anchors {
                right: parent.right
                left: parent.left
                bottom: footer.top
                top: header.bottom
            }
            height: window.height - header.height - footer.height

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

        Footer {
            id: footer
            anchors {
                left: parent.left
                bottom: parent.bottom
                right: parent.right
            }
            width: parent.width
        }
    }
}
