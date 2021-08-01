import QtQuick 2.9

import core.NSSkillpackMod 1.0

Column {
    property NSSkillpackMod skillpackMod

    id: main

    Text {
        id: _name
        width: main.width
        text: "Skillpack name"
    }

    Column {
        width: main.width
        spacing: 5

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
