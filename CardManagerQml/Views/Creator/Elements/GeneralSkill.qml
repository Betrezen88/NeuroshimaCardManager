import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSSkill 1.0

Row {
    property var skills
    property alias current: skillName.currentIndex

    signal spend(int value)
    signal refund(int value)
    signal currentSkillChanged(var object, int index)

    id: main
    height: skillValue.height
    spacing: 5

    ComboBox {
        property int previousIndex: 0

        id: skillName
        width: main.width - main.spacing - skillValue.width
        height: skillValue.height
        textRole: 'name'
        onCurrentIndexChanged: {
            if ( previousIndex !== currentIndex ) {
                skills[previousIndex].setValue(0)
                skills[currentIndex].setValue(skillValue.value)
                main.currentSkillChanged(main, previousIndex)
                previousIndex = currentIndex
            }
        }
    }

    SpinBox {
        id: skillValue
        height: 40
        from: 0
        to: 5
        editable: false

        onValueChanged: main.skills[skillName.currentIndex].setValue(value)

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

    onSkillsChanged: skillName.model = skills
}
