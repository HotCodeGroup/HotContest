import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import models 1.0

Rectangle {
    id: loading

    Text {
        anchors {
            centerIn: parent
        }

        font {
            weight: Font.Light
            family: roboto.name
            pixelSize: 41
        }
        wrapMode: Text.Wrap
        renderType: Text.NativeRendering
        text: qsTr("Загрузка...")
    }

}

