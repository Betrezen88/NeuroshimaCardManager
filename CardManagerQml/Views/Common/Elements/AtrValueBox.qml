import QtQuick 2.9

import core.NSDifficulty 1.0

Rectangle {
    property NSDifficulty mod
    property int atrValue

    id: main

    width: (40 >= name.implicitWidth) ? 40 : name.implicitWidth
    height: column.height
    radius: 5
    border.width: 2

    Column {
        id: column
        width: parent.width
        height: implicitHeight
        bottomPadding: 3
        topPadding: 3
        spacing: 3

        Text {
            id: name
            width: parent.width
            text: qsTr("Łat.")
            font.pointSize: 10
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: value
            width: parent.width
            text: qsTr("0")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }
    }

    onModChanged: {
        name.text = mod.shortname
        value.text = main.atrValue + mod.value
    }

    onAtrValueChanged: value.text = atrValue + main.mod.value
}
