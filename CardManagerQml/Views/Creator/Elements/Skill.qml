import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSSkill 1.0
import core.NSCreationPointsManager 1.0

Row {
    property NSSkill skill

    signal refund(int value)
    signal spend(int value)

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
        from: 0
        to: 5
        editable: false

        onValueChanged: main.skill.setValue(value)

        down.onPressedChanged: {
            if ( down.pressed ) {
                down.pressed = false
                main.refund(skillValue.value)
                decrease()
            }
        }
        up.onPressedChanged: {
            if ( up.pressed ) {
                up.pressed = false
                increase()
                main.spend(skillValue.value)
            }
        }
    }

    onSkillChanged: skillName.text = skill.name
}
