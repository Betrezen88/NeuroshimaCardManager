import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSAttribute 1.0
import core.NSAttributeMod 1.0
import core.NSPageCreator 1.0
import core.NSStatsCreator 1.0

Row {
    property NSAttributeMod attributeMod
    property NSStatsCreator statsCreator: manager.cardCreator.pageCreator(NSPageCreator.STATS)

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
        from: attributeMod.min
        to: attributeMod.max
        value: attributeMod.attribute.value

        up.onPressedChanged: {
            if ( up.pressed ) {
                up.pressed = false
                statsCreator.attributeUp(attributeMod)
            }
        }
        down.onPressedChanged: {
            if ( down.pressed ) {
                down.pressed = false
                statsCreator.attributeDown(attributeMod)
            }
        }
    }

    onAttributeModChanged: {
        attributeName.text = attributeMod.attribute.name
    }
}
