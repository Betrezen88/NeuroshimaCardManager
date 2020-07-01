import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSSkillpack 1.0

Rectangle {
    property NSSkillpack skillpack

    id: main
    height: titleRow.height + skillRow.height + skillRow1.height + skillRow2.height + (column3.spacing * 3)
    color: "#ffffff"
    
    Column {
        id: column3
        anchors.fill: parent
        spacing: 5
        
        Row {
            id: titleRow
            width: column3.width
            height: titleRow.implicitHeight
            
            Text {
                id: skillpackName
                width: titleRow.width - titleRow.spacing - checkBox.width
                height: checkBox.height
                text: qsTr("Skillpack Name (W,T)")
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 10
            }
            
            CheckBox {
                id: checkBox
                text: qsTr("Kup")
            }
        }
        
        Row {
            id: skillRow
            width: column3.width
            height: skillRow.implicitHeight
            
            Text {
                id: skillName
                width: skillRow.width - skillRow.spacing - skillValue.width
                height: skillValue.height
                text: qsTr("Skill Name")
                font.pointSize: 10
                verticalAlignment: Text.AlignVCenter
            }
            
            SpinBox {
                id: skillValue
            }
        }
        
        Row {
            id: skillRow1
            width: column3.width
            height: skillRow1.implicitHeight
            Text {
                id: skillName1
                width: skillRow1.width - skillRow1.spacing - skillValue1.width
                height: skillValue1.height
                text: qsTr("Skill Name")
                font.pointSize: 10
                verticalAlignment: Text.AlignVCenter
            }
            
            SpinBox {
                id: skillValue1
            }
        }
        
        Row {
            id: skillRow2
            width: column3.width
            height: skillRow2.implicitHeight
            Text {
                id: skillName2
                width: skillRow2.width - skillRow2.spacing - skillValue2.width
                height: skillValue2.height
                text: qsTr("Skill Name")
                font.pointSize: 10
                verticalAlignment: Text.AlignVCenter
            }
            
            SpinBox {
                id: skillValue2
            }
        }
    }

    onSkillpackChanged: {
        skillpackName.text = skillpack.fullname()
    }
}
