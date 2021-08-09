import QtQuick 2.12

import core.NSSkillpackMod 1.0

Rectangle {
    property NSSkillpackMod skillpackMod

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
                skillMod: modelData
            }
        }
    }

    onSkillpackModChanged: {
        if ( null == skillpackMod )
            return

        _name.text = skillpackMod.skillpack.name
        _skills.model = skillpackMod.skills
    }
}
