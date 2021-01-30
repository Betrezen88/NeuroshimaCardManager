import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQml.Models 2.15

import core.NSEquipment 1.0

import "../Elements/Equipment"

Column {
    property NSEquipment equipment

    id: main
    spacing: 5

    signal openForm()
    signal showItemDetails(int index)

    Rectangle {
        color: "#000"
        radius: 10
        width: main.width
        height: 30

        Text {
            text: "Plecak / Przy sobie"
            color: "#fff"
            font.pointSize: 14
            anchors.centerIn: parent
        }

        RoundButton {
            text: "+"
            width: parent.height
            height: parent.height
            anchors.right: parent.right
            onClicked: main.openForm()
        }
    }

    ListView {
        id: itemsList
        width: main.width
        height: (40 + spacing) * 18
        clip: true
        spacing: 2

        delegate: BackpackItem {
            index: model.index
            item: equipment.backpackItem(model.index)

            onItemDetails: main.showItemDetails(index)
            onEquip: equipment.equipWeapon(index)
            onThrowBackpackItem: equipment.throwBackpackItem(index)
        }
    }

    Row {
        width: main.width
        spacing: 20

        Column {
            spacing: 5

            Text {
                text: "Leki"
                width: _drugs.width
                font.pointSize: 14
                horizontalAlignment: Text.AlignHCenter
            }
            SpinBox {
                id: _drugs
                from: 0
                to: 30
                onValueChanged: main.equipment.drugs = value
            }
        }

        Column {
            spacing: 5

            Text {
                text: "Żywność"
                width: _food.width
                font.pointSize: 14
                horizontalAlignment: Text.AlignHCenter
            }
            SpinBox {
                id: _food
                from: 0
                to: 30
                onValueChanged: main.equipment.food = value
            }
        }

        Column {
            spacing: 5

            Text {
                text: "Woda"
                width: _water.width
                font.pointSize: 14
                horizontalAlignment: Text.AlignHCenter
            }
            SpinBox {
                id: _water
                from: 0
                to: 30
                onValueChanged: main.equipment.water = value
            }
        }
    }

    onEquipmentChanged: {
        itemsList.model = equipment.backpack
        _drugs.value = equipment.drugs
        _food.value = equipment.food
        _water.value = equipment.water

        equipment.backpackChanged.connect(function(){
            itemsList.model = main.equipment.backpack
        })
    }
}
