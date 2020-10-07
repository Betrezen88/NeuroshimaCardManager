import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSSkill 1.0
import core.NSCreationPointsManager 1.0

Row {
    property NSSkill skill
    property NSCreationPointsManager pointsManager: manager.cardCreator.creationPointsManager()

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

        onValueChanged: {
            console.log("TO DO: add method to modify skill value")
        }

        down.onPressedChanged: {
            console.log("Down clicked", skillValue.value, down.pressed)

            if ( down.pressed ) {
                down.pressed = false
                //refund
                decrease()
            }
        }
        up.onPressedChanged: {
            console.log("Up clicked", skillValue.value, up.pressed)

            if ( up.pressed ) {
                up.pressed = false
                increase()
                //spend
            }
        }
    }

    onSkillChanged: {
        skillName.text = skill.name
    }
}
