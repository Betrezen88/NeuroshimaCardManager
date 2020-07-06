import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSSkill 1.0

Row {
    property NSSkill skill

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
    }

    onSkillChanged: {
        skillName.text = skill.name
    }
}
