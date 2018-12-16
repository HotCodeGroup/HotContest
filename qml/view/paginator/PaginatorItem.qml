import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Rectangle {
    id: item

    property bool is_active: false
    property bool is_last: false
    property bool is_entered: false

    function get_color(is_active, is_entered) {
        var color = ""
        if (is_active) {
            color = "#FF6347"
        }
        else {
            if (is_entered) {
                color = "#F5F5F5"
            }
            else {
                color = "#FFFFFF"
            }
        }
        return color
    }

    height: 25
    width: item_text.width + 20

    Rectangle {
        id: right_line
        z: 150
        height: button.height
        width: is_last ? 0 : 1
        color: "#31000000"
        anchors {
            top: button.top
            bottom: button.bottom
            left: button.right
        }
    }

    Rectangle {
        id: button
        z: 100
        height: 25
        width: item_text.width + 19
        color: get_color(is_active, is_entered)

        Text {
            id: item_text
            anchors {
                centerIn: parent
            }
            color: is_active ? "#FFFFFF" : "#000000"
            font {
                weight: Font.Light
                family: roboto.name
                pixelSize: 14
            }
            renderType: Text.NativeRendering
            text: pag_item_text
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: { is_entered = true}
            onExited: {is_entered = false}
        }
    }
}
