import QtQuick 2.0
import QtQuick.Controls 2.12

import core.view.NSEquipment 1.0

import "../Elements/Equipment"

Column {
    property NSEquipment equipment

    id: main
    spacing: 5
    
    Label {
        id: title
        height: 30
        width: main.width
        text: "Pancerz"
        color: "#fff"
        font.pointSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        background: Rectangle {
            color: "#000"
            radius: 10
        }
    }
    
    Row {
        width: parent.width
        spacing: 5
        
        Column {
            width: parent.width/2 - parent.spacing
            spacing: 5

            ArmorPiece {
                id: _head
                title: "Głowa"
                width: parent.width
                onUnequip: equipment.unequipArmor(item)
                onThrowArmor: equipment.removeArmor(item)
            }

            ArmorPiece {
                id: _rHand
                title: "Prawa Ręka"
                width: parent.width
                onUnequip: equipment.unequipArmor(item)
                onThrowArmor: equipment.removeArmor(item)
            }

            ArmorPiece {
                id: _rLeg
                title: "Prawa Noga"
                width: parent.width
                onUnequip: equipment.unequipArmor(item)
                onThrowArmor: equipment.removeArmor(item)
            }
        }
        
        Column {
            width: parent.width/2 - parent.spacing
            spacing: 5

            ArmorPiece {
                id: _torso
                title: "Tułów"
                width: parent.width
                onUnequip: equipment.unequipArmor(item)
                onThrowArmor: equipment.removeArmor(item)
            }

            ArmorPiece {
                id: _lHand
                title: "Lewa Ręka"
                width: parent.width
                onUnequip: equipment.unequipArmor(item)
                onThrowArmor: equipment.removeArmor(item)
            }

            ArmorPiece {
                id: _lLeg
                title: "Lewa Noga"
                width: parent.width
                onUnequip: equipment.unequipArmor(item)
                onThrowArmor: equipment.removeArmor(item)
            }
        }
    }

    onEquipmentChanged: {
        _head.item = equipment.armorItem(_head.title)
        _torso.item = equipment.armorItem(_torso.title)
        _lHand.item = equipment.armorItem(_lHand.title)
        _rHand.item = equipment.armorItem(_rHand.title)
        _lLeg.item = equipment.armorItem(_lLeg.title)
        _rLeg.item = equipment.armorItem(_rLeg.title)

        equipment.armorChanged.connect(function(){
            _head.item = main.equipment.armorItem(_head.title)
            _torso.item = main.equipment.armorItem(_torso.title)
            _lHand.item = main.equipment.armorItem(_lHand.title)
            _rHand.item = main.equipment.armorItem(_rHand.title)
            _lLeg.item = main.equipment.armorItem(_lLeg.title)
            _rLeg.item = main.equipment.armorItem(_rLeg.title)
        })
    }
}
