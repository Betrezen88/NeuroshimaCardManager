import QtQuick 2.0
import QtQuick.Controls 2.12

Column {
    id: feature
    width: column1.width
    height: feature.implicitHeight
    
    RadioButton {
        id: featureBtn
        text: qsTr("Nazwa cechy")
        font.bold: true
        font.pointSize: 10
    }
    
    Text {
        id: featureDescription
        width: feature.width
        text: qsTr("Opis")
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
}
