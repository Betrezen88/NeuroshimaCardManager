import QtQuick 2.9

Item {
    property var modifier

    id: main

    height: source.height

    Row {
        anchors.fill: parent
        spacing: 2

        Text {
            id: source
            font.pointSize: 10
            padding: 2
        }

        Rectangle {
            height: main.height
            width: main.width - source.width - value.width - 4
        }

        Text {
            id: value
            font.pointSize: 10
            padding: 2
        }
    }

    onModifierChanged: {
        source.text = modifier.source;
        value.text = modifier.value + "%"
    }
}
