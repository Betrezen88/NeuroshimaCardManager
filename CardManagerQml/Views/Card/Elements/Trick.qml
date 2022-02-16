import QtQuick 2.9
import QtQuick.Controls 2.5

import core.view.NSTrick 1.0

Rectangle {
    property NSTrick trick

    id: _main

    height: name.height

    border.color: "#000"
    border.width: 2
    radius: 10

    Text {
        id: name
        padding: 5
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }

    MouseArea {
        anchors.fill: _main
        onClicked: _tooltip.open()
    }

    Popup {
        id: _tooltip
        width: parent.width
        height: _column.implicitHeight + 20
        closePolicy: Popup.CloseOnPressOutside
        x: parent.width

        Column {
            id: _column
            anchors.fill: parent
            spacing: 5

            Text {
                id: _title
                text: _main.trick.name
                width: parent.width
                font.bold: true
                font.pointSize: 12
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: _description
                text: "Opis: " + _main.trick.description
                width: parent.width
                font.italic: true
                font.pointSize: 10
                wrapMode: Text.WordWrap
            }

            Text {
                id: _action
                text: "Akcja: " + _main.trick.action
                width: parent.width
                font.pointSize: 10
                wrapMode: Text.WordWrap
            }
        }
    }

    onTrickChanged: name.text = (trick != null) ? trick.name : ""
}
