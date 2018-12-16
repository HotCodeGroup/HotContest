import QtQuick 2.0
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    id: user_dropdown_menu

    width: settings_option.width + 40
    height: options_column.height + 10
    color: "#FFFFFF"
    border {
        color: "#31000000"
        width: 1
    }
    radius: 5

    Component {
        Header {
            id: header
        }
    }

    Column {
        id: options_column
        anchors {
            centerIn: user_dropdown_menu
        }

        Rectangle {
            height: 36
            width: settings_option.width + 40
            color: "#00FFFFFF"
            Text {
                id: settings_option
                anchors.centerIn: parent
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 19
                }
                renderType: Text.NativeRendering
                text: "Настройки"

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {settings_option.color = "#FF6347"}
                    onExited: {settings_option.color = "#000000"}
                    onClicked: {
                        header.settings_loader.setSource("qrc:/view/user/Settings.qml",
                                                         {"loader": header.settings_loader});
                        dropdown_menu_loader.setSource("");
                    }
                }
            }
        }

        Rectangle {
            id: horizontal_line
            height: 1
            width: user_dropdown_menu.width - 20
            anchors {
                horizontalCenter: options_column.horizontalCenter
            }
            color: "#31000000";
        }

        Rectangle {
            height: 36
            width: logout_option.width + 40
            color: "#00FFFFFF"
            Text {
                id: logout_option
                anchors.centerIn: parent
                font {
                    weight: Font.Light
                    family: roboto.name
                    pixelSize: 19
                }
                renderType: Text.NativeRendering
                text: "Выйти"

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {logout_option.color = "#FF6347"}
                    onExited: {logout_option.color = "#000000"}
                    onClicked: {
                        User.logout();
                    }
                }
            }
        }
    }
}
