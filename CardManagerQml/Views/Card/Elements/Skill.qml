import QtQuick 2.9
import QtQuick.Controls 2.12

import core.view.NSSkill 1.0

Row {
    property NSSkill skill

    id: main
    height: _used.height
    spacing: 5

    CheckBox {
        id: _used
        width: 30
        height: 30
        onCheckedChanged: main.skill.used = checked
    }

    Text {
        id: _title
        text: "Skill"
        textFormat: Text.PlainText
        font.pointSize: 10
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        height: main.height
        width: main.width - _used.width - _rect.width - (main.spacing * 4)
    }

    Rectangle {
        id: _rect
        width: 60
        height: _used.height
        color: "#fff"
        border.color: "#000"
        border.width: 1
        radius: 5

        Text {
            id: _number
            text: "0"
            textFormat: Text.PlainText
            font.pointSize: 9
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
    }

    onSkillChanged: {
        _title.text = (skill != null) ? skill.name : ""
        _number.text = (skill != null) ? skill.value : 0
        _used.checked = (skill != null) ? skill.used : false
    }
}
