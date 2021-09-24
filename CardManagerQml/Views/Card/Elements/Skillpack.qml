import QtQuick 2.9

import core.view.NSSkillpack 1.0

Rectangle {
    property NSSkillpack skillpack

    id: main
    height: _column.implicitHeight

    color: "#fff"
    border.color: "#000"
    border.width: 2
    radius: 10

    Column {
        id: _column
        width: main.width
        spacing: 2
        padding: 5

        Text {
            id: _title
            textFormat: Text.PlainText
            font.pointSize: 10
            font.bold: true
            leftPadding: 10
            width: main.width - _column.padding*2
        }

        Repeater {
            id: _skills
            delegate: Skill {
                width: main.width - _column.padding*2
                skill: modelData
            }
        }
    }

    onSkillpackChanged: {
        _title.text = skillpack.name + " (" + skillpack.specializationsShort + ")"
        _skills.model = skillpack.skills
    }
}
