import QtQuick 2.0
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    property var dropdown_menu: dropdown_menu_loader
    property int state_area: 0

    Text {
        id: signIn
        anchors {
            verticalCenter: parent.verticalCenter
            right: parent.right
        }
        renderType: Text.NativeRendering
        color: "#FFFFFF"
        font {
            letterSpacing: -1
            family: roboto.name
            pixelSize: 23
        }
        text: qsTr("Олег Стырт   " + "")

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {signIn.color = "#DCDCDC"}
            onExited: {signIn.color = "#FFFFFF"}
            onClicked: {
                if (state_area === 0) {
                    dropdown_menu_loader.setSource("qrc:/view/main/tools/UserDropdownMenu.qml");
                    state_area = 1;
                } else {
                    dropdown_menu_loader.setSource("");
                    state_area = 0;
                }
            }
        }
    }

    Loader {
        id: dropdown_menu_loader
        anchors {
            top: signIn.bottom
            horizontalCenter: signIn.horizontalCenter
        }
    }
}
