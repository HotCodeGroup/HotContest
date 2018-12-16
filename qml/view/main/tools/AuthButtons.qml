import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    Row {
        anchors {
            verticalCenter: parent.verticalCenter
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
}
