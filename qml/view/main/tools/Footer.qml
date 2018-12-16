import QtQuick 2.9

Rectangle {
    id: footer
    z: 99
    height: 44
    color: "#FFFFFF"

    Rectangle {
        anchors {
            left: parent.left
            bottom: footer.top
            right: parent.right
        }
        width: parent.width
        height: 1
        color: "#31000000"
    }

    Row {
        anchors.centerIn: parent
        spacing: 20

        Text {
            renderType: Text.NativeRendering
            color: "#31000000"
            font {
                family: roboto.name
                pixelSize: 17
            }
            text: qsTr("О нас")
        }

        Text {
            renderType: Text.NativeRendering
            color: "#31000000"
            font {
                family: roboto.name
                pixelSize: 17
            }
            text: qsTr("Обратная связь")
        }
    }
}
