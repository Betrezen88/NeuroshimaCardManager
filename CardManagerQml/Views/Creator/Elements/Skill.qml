import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSSkill 1.0
import core.NSSkillMod 1.0

Row {
    property NSSkillMod skillMod

    signal skillUp(NSSkillMod skillMod)
    signal skillDown(NSSkillMod skillMod)

    id: main
    height: skillValue.height
    
    Text {
        id: skillName
        width: main.width - main.spacing - skillValue.width
        height: skillValue.height
        text: qsTr("Skill Name")
        font.pointSize: 10
        verticalAlignment: Text.AlignVCenter
    }
    
    SpinBox {
        id: skillValue
        height: 40
        from: skillMod.min
        to: skillMod.max
        value: skillMod.skill.value

        down.onPressedChanged: {
            if ( down.pressed ) {
                down.pressed = false
                main.skillDown(skillMod)
            }
        }
        up.onPressedChanged: {
            if ( up.pressed ) {
                up.pressed = false
                main.skillUp(skillMod)
            }
        }
    }

    onSkillModChanged: skillName.text = skillMod.skill.name
}
