import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSAttribute 1.0
import core.NSCreationPointsManager 1.0

Row {
    property NSAttribute attribute
    property NSCreationPointsManager pointsManager: manager.cardCreator.creationPointsManager()

    id: row
    height: implicitHeight
    spacing: 5
    
    Text {
        id: attributeName
        width: 120
        height: valueBox.height
        text: qsTr("Etykieta")
        font.bold: true
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
    }
    
    SpinBox {
        id: valueBox
        from: 6
        to: 18

        onValueChanged: attribute.value = value
        up.onPressedChanged: {
            if ( up.pressed ) {
                if ( pointsManager.attributes > 0 ) {
                    pointsManager.spendAttributes(1)
                    increase()
                }
                up.pressed = false
            }
        }
        down.onPressedChanged: {
            if ( down.pressed ) {
                down.pressed = false
                pointsManager.refundAttributes(1)
                decrease()
            }
        }
    }

    onAttributeChanged: attributeName.text = attribute.name
}
