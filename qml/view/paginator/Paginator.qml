import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Rectangle {
    id: paginator
    height: 27
    width: paginator_row.width + 2
    border {
        color: "#31000000"
        width: 1
    }

    Row {
        id: paginator_row
        anchors {
            left: paginator.left
            verticalCenter: paginator.verticalCenter
            leftMargin: 1
        }

        PaginatorItem {
            property string pag_item_text: qsTr("")
        }

        PaginatorItem {
            property string pag_item_text: qsTr("<")
        }

        PaginatorItem {
            property string pag_item_text: qsTr("1")
        }

        PaginatorItem {
            property string pag_item_text: qsTr("2")
            is_active: true
        }

        PaginatorItem {
            property string pag_item_text: qsTr("...")
        }

        PaginatorItem {
            property string pag_item_text: qsTr(">")
        }

        PaginatorItem {
            property string pag_item_text: qsTr("")
            is_last: true
        }
    }
}

