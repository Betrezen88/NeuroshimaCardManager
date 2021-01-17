﻿import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSEquipment 1.0
import core.NSItem 1.0

import "../Sections"
import "../Elements/Equipment"

Pane {
    property NSEquipment equipmentData

    id: main

    ScrollView {
        width: parent.width - 10
        height: parent.height
        clip: true

        Row {
            id: mainRow
            anchors.fill: parent
            spacing: 5

            Column {
                id: first
                spacing: 5

                Armor {
                    id: armor
                    width: mainRow.getWidth()
                }

                Weapons {
                    id: weapons
                    width: mainRow.getWidth()
                }
            }

            Column {
                id: second
                spacing: 5

                Backpack {
                    id: backpack
                    width: mainRow.getWidth()
                    onOpenForm: addForm.open()
                    onShowItemDetails: {
                        itemDescription.itemData = equipmentData.getItemFromBackpack(index)
                        itemDescription.open()
                    }
                }
            }

            function getWidth() {
                return (main.width - mainRow.spacing - 40)/2 < 500
                        ? 500 : (main.width - mainRow.spacing - 40)/2
            }
        }
    }

    ItemAddForm {
        id: addForm
        width: (main.width < 700) ? 500 : main.width * 0.7
        height: main.height * 0.7
        x: (main.width > width) ? (main.width - width) / 2 : 0
        y: 100

        onSendItem: {
            console.log("ItemAddForm.onSendItem()")
            console.log("itemData keys:", Object.keys(itemData))
            console.log("stats keys:", Object.keys(itemData["STATS"]))
            equipmentData.addItemToBackpack(itemData)
        }
    }

    ItemDescription {
        id: itemDescription
        width: (main.width < 700) ? 500 : main.width * 0.7
        height: main.height * 0.7
        x: (main.width > width) ? (main.width - width) / 2 : 0
        y: 100
    }

    onEquipmentDataChanged: {
        backpack.backpackItems = equipmentData.backpack
        connector.target = equipmentData
    }

    Component.onCompleted: console.log("Equipment.size(h/w):", height, width)

    Connections {
        id: connector
        ignoreUnknownSignals: true
        function onBackpackChanged() {
            backpack.backpackItems = equipmentData.backpack
        }
    }
}
