import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    id: button

    property string backgroundColor: "#FF6347"
    property string onHoverColor: "#FF5638"
    property string textColor: "#000000"
    property string content_text
    property int textPixelSize: 19
    property bool isLight: true
    property var onClick

    height: 34
    width: text_button.width + 40
    color: backgroundColor
    radius: 10
    Text {
        id: text_button
        anchors.centerIn: parent
        color: textColor
        font {
            weight: isLight ? Font.Light : Font.Normal
            family: roboto.name
            pixelSize: textPixelSize
        }
        text: content_text
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {button.color = onHoverColor}
        onExited: {button.color = backgroundColor}
        onClicked: {
            onClick();
        }
    }
}
