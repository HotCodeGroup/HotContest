import QtQuick 2.9
import QtQuick.Controls 2.2
import "../../user"
import models 1.0

Rectangle {
    id: header
    property StackView current_stack_view
    property Loader sign_in_loader: sign_in_loader
    property Loader sign_up_loader: sign_up_loader
    property Loader settings_loader: settings_loader

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
            hoverEnabled: true
            onEntered: {logo.color = "#DCDCDC"}
            onExited: {logo.color = "#FFFFFF"}
            onClicked: current_stack_view.pop(null)

        }
    }
    Loader {
        id: right_panel_loader
        anchors {
            verticalCenter: parent.verticalCenter
            rightMargin: 73
            right: parent.right
        }

        source: "qrc:/view/main/tools/AuthButtons.qml"

        Connections {
            target: User
            onIsAuthenticatedChanged: function (isAuthenticated) {
                if (isAuthenticated) {
                    right_panel_loader.setSource("qrc:/view/main/tools/UserPanel.qml");
                } else {
                    right_panel_loader.setSource("qrc:/view/main/tools/AuthButtons.qml");
                }
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
