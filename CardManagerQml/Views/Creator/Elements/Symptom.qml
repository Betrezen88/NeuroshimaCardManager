import QtQuick 2.0
import QtQuick.Controls 2.12

Column {
    id: column1
    width: 300
    height: column1.implicitHeight
    spacing: 5
    
    Text {
        id: element1
        width: column1.width
        text: qsTr("Symptomy")
        font.bold: true
        font.pointSize: 11
        horizontalAlignment: Text.AlignHCenter
    }
    
    Text {
        id: element2
        width: column1.width
        text: qsTr("Opis symptomu")
        wrapMode: Text.WordWrap
        font.pointSize: 9
        font.bold: false
        horizontalAlignment: Text.AlignLeft
    }
    
    Text {
        id: element3
        width: column1.width
        text: qsTr("Kary:")
        wrapMode: Text.WordWrap
        font.pointSize: 9
        font.bold: false
        horizontalAlignment: Text.AlignLeft
    }
}
