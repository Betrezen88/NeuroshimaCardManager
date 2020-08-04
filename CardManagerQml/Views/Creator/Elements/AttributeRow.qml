import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSAttribute 1.0

Row {
    property NSAttribute attribute

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

        onValueChanged: attribute.value = value
    }

    onAttributeChanged: attributeName.text = attribute.name
}
