import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSEquipment 1.0

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
            }

            ArmorPiece {
                id: _rHand
                title: "Prawa Ręka"
                width: parent.width
            }

            ArmorPiece {
                id: _rLeg
                title: "Prawa Noga"
                width: parent.width
            }
        }
        
        Column {
            width: parent.width/2 - parent.spacing
            spacing: 5

            ArmorPiece {
                id: _torso
                title: "Tułów"
                width: parent.width
            }

            ArmorPiece {
                id: _lHand
                title: "Lewa Ręka"
                width: parent.width
            }

            ArmorPiece {
                id: _lLeg
                title: "Lewa Noga"
                width: parent.width
            }
        }
    }

    onEquipmentChanged: {
        equipment.armorChanged.connect(function() {
            _head.item = equipment.getArmor("HEAD")
            _torso.item = equipment.getArmor("TORSO")
            _lHand.item = equipment.getArmor("LEFTHAND")
            _rHand.item = equipment.getArmor("RIGHTHAND")
            _lLeg.item = equipment.getArmor("LEFTLEG")
            _rLeg.item = equipment.getArmor("RIGHTLEG")
        })
    }
}
