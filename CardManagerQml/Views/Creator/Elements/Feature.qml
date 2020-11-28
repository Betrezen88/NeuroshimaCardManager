import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSFeature 1.0
import core.NSBonus 1.0

Column {
    property NSFeature feature
    property ButtonGroup group
    property alias checked: button.checked

    id: main
    height: main.implicitHeight

    signal featureSelected(NSFeature feature)
    
    RadioButton {
        id: button
        ButtonGroup.group: main.group
        text: qsTr("Nazwa cechy")
        font.bold: true
        font.pointSize: 10

        onCheckedChanged: {
            if ( checked )
                main.featureSelected(main.feature)
        }
    }
    
    Text {
        id: description
        width: main.width
        text: qsTr("Opis")
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }

    ComboBox {
        id: list
        visible: false
        width: (main.width > 250) ? 250 : main.width

        onCurrentTextChanged: {
            if ( main.feature.hasBonus )
                main.feature.bonus.setName(currentText)
        }
    }

    onFeatureChanged: {
        button.text = feature.name
        description.text = feature.description
        list.visible = false;

        if ( feature.hasBonus ) {
            if ( feature.bonus.list.length > 1 ) {
                list.visible = true
                list.model = feature.bonus.list
            }
        }
    }
}
