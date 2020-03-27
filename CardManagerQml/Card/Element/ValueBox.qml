import QtQuick 2.0

Item {
    property string name
    property int value
    property int mod

    id: main

    height: modName.height + fullValue.height + 8

    Rectangle {
        anchors.fill: main
        border.color: "#000"
        border.width: 2
        radius: 5

        Column {
            anchors.fill: parent
            anchors.margins: 3
            spacing: 2

            Text {
                id: modName
                width: main.width-6
                text: main.name
                textFormat: Text.PlainText
                font.pointSize: 7
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: fullValue
                width: main.width-6
                text: fillValue(main.value, main.mod)
                textFormat: Text.PlainText
                font.pointSize: 10
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }

    function fillValue(value, mod) {
        var v = value + mod;
        return (v>0) ? v : 'N'
    }
}
