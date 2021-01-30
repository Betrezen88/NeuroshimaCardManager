import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQml.Models 2.15

import core.NSEquipment 1.0
import core.NSItem 1.0

import "../Elements"
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
        }
    }

    Row {
        width: main.width
        spacing: 5

        ValueRow {
            name: "Leki:"
            value: "11"
        }
        Text{ text:"/"; font.pointSize: 14 }
        ValueRow {
            name: "Żywność:"
            value: "11"
        }
        Text{ text:"/"; font.pointSize: 14 }
        ValueRow {
            name: "Woda:"
            value: "11"
        }
    }

    onEquipmentChanged: {
        itemsList.model = equipment.backpack

        equipment.backpackChanged.connect(function(){
            itemsList.model = equipment.backpack
        })
    }
}
