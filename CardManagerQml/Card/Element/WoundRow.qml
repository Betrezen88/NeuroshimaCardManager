import QtQuick 2.9

Item {
    property string name
    property string value

    id: main

    height: label.height + 6 + 4

    Row {
        anchors.fill: main
        anchors.margins: 2
        spacing: 2

        Text {
            id: label
            textFormat: Text.PlainText
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            width: 70
        }

        Rectangle {
            border.color: "#000"
            border.width: 2
            radius: 5
            width: main.width - label.width - 10
            height: main.height

            Text {
                id: value
                textFormat: Text.PlainText
                padding: 3
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 10
                anchors.fill: parent
            }
        }
    }

    onNameChanged: {
        label.text = main.name;
    }
    onValueChanged: {
        value.text = main.value;
    }
}
