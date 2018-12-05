import QtQuick 2.9
import QtQuick.Controls 2.2
import "../../user"

Rectangle {
    id: header
    property StackView current_stack_view

    z: 100
    height: 51
    color: "#FF6347"


    Text {
        id: logo
        anchors {
            verticalCenter: parent.verticalCenter
            leftMargin: 63
            left: parent.left
        }
        renderType: Text.NativeRendering
        color: "#FFFFFF"
        style: Text.Raised
        styleColor:"#000000"
        font {
            family: overpass.name
            pixelSize: 39
        }
        text: qsTr("HotContest")

        MouseArea {
            anchors.fill: parent
//            hoverEnabled: true
//            onEntered: {
//                logo.style = Text.Raised
//                logo.styleColor = "#000000"
//            }
//            onExited: {
//                logo.style = Text.Normal
//            }
            onClicked: current_stack_view.pop(null)

        }
    }

    Row {
        anchors {
            verticalCenter: parent.verticalCenter
            rightMargin: 73
            right: parent.right
        }
        spacing: 20

        Text {
            id: signIn
            renderType: Text.NativeRendering
            color: "#FFFFFF"
            font {
                family: roboto.name
                pixelSize: 23
            }
            text: qsTr("Войти")

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {signIn.font.underline = true}
                onExited: {signIn.font.underline = false}
                onClicked: sign_in_loader.setSource("qrc:/view/user/SignIn.qml",
                                                    {"loader": sign_in_loader,
                                                     "second_loader": sign_up_loader})
            }
        }

        Rectangle {
            width: 2
            height: signIn.height
            anchors {
                bottom: signIn.bottom
            }
        }

        Text {
            id: signUp
            renderType: Text.NativeRendering
            color: "#FFFFFF"
            font {
                family: roboto.name
                pixelSize: 23
            }
            text: qsTr("Регистрация")

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {signUp.font.underline = true}
                onExited: {signUp.font.underline = false}
                onClicked: sign_up_loader.setSource("qrc:/view/user/SignUp.qml",
                                                    {"loader": sign_up_loader,
                                                     "second_loader": sign_in_loader})

           }
        }
    }
    Loader {
        id: sign_in_loader
    }

    Loader {
        id: sign_up_loader
    }
    Loader {
        id: settings_loader
    }
}
