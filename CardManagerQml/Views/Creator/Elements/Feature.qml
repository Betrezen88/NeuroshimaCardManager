import QtQuick 2.0
import QtQuick.Controls 2.12

Column {
    property var feature

    id: main
    height: main.implicitHeight
    
    RadioButton {
        id: button
        text: qsTr("Nazwa cechy")
        font.bold: true
        font.pointSize: 10
    }
    
    Text {
        id: description
        width: main.width
        text: qsTr("Opis")
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }

    onFeatureChanged: {
        button.text = feature.name
        description.text = feature.description
    }

    onWidthChanged: console.log("Feature.onWidthChanged:", width)
}
