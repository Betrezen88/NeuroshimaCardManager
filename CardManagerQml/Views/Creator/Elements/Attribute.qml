import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSAttribute 1.0
Column {
    id: attributeCol
    width: 300
    height: attributeCol.implicitHeight
    spacing: 5
    
    Text {
        id: attributeName
        width: attributeCol.width
        text: qsTr("Atrybut")
        font.bold: true
        font.pointSize: 14
    }
    
    Row {
        id: valuesRow
        width: attributeCol.width
        height: valuesRow.implicitHeight
        spacing: 5
        
        Rectangle {
            id: valueBox
            y: 0
            width: (valuesRow.width - (valuesRow.spacing * 6)) / 7
            height: element1.height + element2.height + column2.spacing + column2.anchors.margins * 2
            color: "#ffffff"
            radius: 5
            border.width: 2
            
            Column {
                id: column2
                spacing: 5
                anchors.fill: parent
                anchors.margins: 3
                
                Text {
                    id: element1
                    width: column2.width
                    text: qsTr("PT")
                    font.pointSize: 8
                    horizontalAlignment: Text.AlignHCenter
                }
                
                Text {
                    id: element2
                    width: column2.width
                    text: qsTr("0")
                    font.pointSize: 10
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
        
    }
    
    Column {
        id: skillpacksCol
        width: attributeCol.width
        height: skillpacksCol.implicitHeight
        
        Rectangle {
            id: skillpack
            width: skillpacksCol.width
            height: row.height + skillRow.height + skillRow1.height + skillRow2.height + (column3.spacing * 3)
            color: "#ffffff"
            
            Column {
                id: column3
                anchors.fill: parent
                spacing: 5
                
                Row {
                    id: row
                    width: column3.width
                    height: row.implicitHeight
                    
                    Text {
                        id: element3
                        width: row.width - row.spacing - checkBox.width
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
        }
    }
}
