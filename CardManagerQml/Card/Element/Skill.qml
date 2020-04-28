import QtQuick 2.0

Item {
    property var skill

    id: main

    Row {
        anchors.fill: main
        anchors.leftMargin: 10
        spacing: 5

        Text {
            id: title
            text: "Skill"
            textFormat: Text.PlainText
            font.pointSize: 10
            horizontalAlignment: Text.AlignLeft
            width: (main.width / 3)*1.7

            onHeightChanged: main.height = title.height;
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
                text: "0"
                textFormat: Text.PlainText
                font.pointSize: 9
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
    }

    onSkillChanged: {
        title.text = main.skill.name;
        number.text = main.skill.value;
    }
}
