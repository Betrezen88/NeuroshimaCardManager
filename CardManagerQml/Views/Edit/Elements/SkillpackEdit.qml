import QtQuick 2.12

import core.edit.NSSkillpackEdit 1.0

Rectangle {
    property NSSkillpackEdit skillpackEdit

    id: main
    height: _column.implicitHeight

    border.width: 2
    border.color: "#000"
    radius: 5

    Column {
        id: _column
        spacing: 5

        Text {
            id: _name
            width: main.width
            topPadding: 5
            text: "Skillpack name"
            font.pointSize: 10
            horizontalAlignment: Text.AlignHCenter
        }

        Repeater {
            id: _skills
            delegate: SkillEdit {
                width: main.width
                skillEdit: modelData
            }
        }
    }

    onSkillpackEditChanged: {
        if ( null == skillpackEdit )
            return

        _name.text = skillpackEdit.name
        _skills.model = skillpackEdit.skills
    }
}
