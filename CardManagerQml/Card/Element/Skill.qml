import QtQuick 2.0

Item {
    property var skill

    id: main

    height: title.height

    Row {
        anchors.fill: main
        anchors.leftMargin: 10
        spacing: 5

        Text {
            id: title
            text: main.skill.name
            textFormat: Text.PlainText
            font.pointSize: 10
            horizontalAlignment: Text.AlignLeft
            width: (main.width / 3)*1.7
        }

        Rectangle {
            width: main.width / 3
            height: title.height
            color: "#fff"
            border.color: "#000"
            border.width: 1
            radius: 5

            Text {
                id: number
                text: main.skill.value
                textFormat: Text.PlainText
                font.pointSize: 9
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
    }
}
