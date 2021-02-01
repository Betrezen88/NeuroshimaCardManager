﻿import QtQuick 2.12
import QtQuick.Controls 2.12

import core.NSItem 1.0

Rectangle {
    property int index
    property variant item

    signal itemDetails(int index)
    signal equip(int index)
    signal throwBackpackItem(int index)

    id: main
    height: 40
    width: parent.width
    color: "#fff"
    radius: 10
    border.width: 2
    border.color: "#000"
    
    Text {
        id: _name
        padding: 5
        font.pointSize: 12
        visible: text.length > 0
        anchors {
            left: parent.left
            right: _quantity.left
            verticalCenter: parent.verticalCenter
        }
    }

    Text {
        id: _quantity
        width: implicitWidth
        padding: 5
        font.pointSize: 12
        visible: _name.text.length > 0
        anchors {
            right: _button.left
            verticalCenter: parent.verticalCenter
        }
    }

    Button {
        id: _button
        text: "..."
        width: parent.height - 10
        height: parent.height - 10
        visible: _name.text.length > 0
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        
        onClicked: _itemMenu.open()
        
        Menu {
            id: _itemMenu
            
            MenuItem {
                text: "Opis"
                onClicked: main.itemDetails(main.index)
            }

            MenuItem {
                id: _equipMenu
                text: "Wyekwipuj"
                height: visible ? implicitHeight : 0
                onClicked: main.equip(main.index)
            }

            MenuItem {
                id: _consumeMenu
                text: "Użyj"
                height: visible ? implicitHeight : 0
            }

            MenuItem {
                text: "Usuń"
                onClicked: main.throwBackpackItem(main.index)
            }
        }
    }

    onItemChanged: {
        if ( null === item )
            return

        _name.text = item.name
        _quantity.text = item.quantity

        _consumeMenu.visible = item.type === "CONSUMABLE"
        _equipMenu.visible = (item.type === "RANGEDWEAPON"
                            || item.type === "HANDWEAPON")
    }
}
