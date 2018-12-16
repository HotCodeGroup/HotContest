import QtQuick 2.9
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import models 1.0

Rectangle {
    id: error_in_input
    property variant text_error

    Text {
        font {
            weight: Font.Light
            family: roboto.name
            pixelSize: 15
        }
        clip: true
        renderType: Text.NativeRendering
        text: "◦ " + text_error
    }
}
