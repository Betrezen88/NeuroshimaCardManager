import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSFeature 1.0
import core.NSBonus 1.0

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

    ComboBox {
        id: list
        visible: false
        width: (main.width > 250) ? 250 : main.width
    }

    onFeatureChanged: {
        button.text = feature.name
        description.text = feature.description
        list.visible = false;

        if ( feature.hasBonus ) {
            var bonusType = feature.bonus.type
            if ( NSBonus.SKILLPACK === bonusType
                || NSBonus.SKILLPACKPT === bonusType
                || NSBonus.FEATURE === bonusType
                || NSBonus.TOTEM === bonusType) {
                list.visible = feature.bonus.list.length > 1;
                list.model = feature.bonus.list
            }
        }
    }
}
