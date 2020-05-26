import QtQuick 2.0
import QtQuick.Controls 2.12

Row {
    property alias name: label.text
    property alias value: valueBox.value

    id: row
    height: implicitHeight
    spacing: 5
    
    Text {
        id: label
        width: 120
        height: value.height
        text: qsTr("Etykieta")
        font.bold: true
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
    }
    
    SpinBox {
        id: valueBox
    }
}
