import QtQuick 2.0
import QtQuick.Controls 2.12

Row {
    property var skills
    property int no

    id: main
    height: skillValue.height
    spacing: 5

    ComboBox {
        id: skillName
        width: main.width - main.spacing - skillValue.width
        height: skillValue.height
    }

    SpinBox {
        id: skillValue
        height: 40
    }

    onSkillsChanged: {
        skillName.model = skills
    }

    onNoChanged: {
        skillName.currentIndex = main.no
    }
}
