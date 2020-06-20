import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSFeature 1.0
import core 1.0

Column {
    property var feature
    property ButtonGroup group
    property alias checked: button.checked

    id: main
    height: main.implicitHeight
    
    RadioButton {
        id: button
        ButtonGroup.group: main.group
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
}
