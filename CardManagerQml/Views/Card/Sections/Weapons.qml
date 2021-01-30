﻿import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQml.Models 2.15

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
        text: "Broń"
        color: "#fff"
        font.pointSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        background: Rectangle {
            color: "#000"
            radius: 10
        }
    }

    ListView {
        id: weaponsList
        width: main.width
        height: 600
        clip: true
        spacing: 2

        delegate:  WeaponItem {
            width: weaponsList.width
            index: model.index
            item: equipment.weaponAt(model.index)

            onUnequipWeapon: equipment.unequipWeapon(index)
            onThrowWeapon: equipment.throwWeapon(index)
        }
    }

    onEquipmentChanged: {
        weaponsList.model = equipment.weapons

        equipment.weaponsChanged.connect(function(){
            weaponsList.model = equipment.weapons
        })
    }
}
