﻿import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSAttributeMod 1.0
import core.NSPageCreator 1.0
import core.NSStatsCreator 1.0

Column {
    property NSAttributeMod attributeMod
    property NSStatsCreator statsCreator: manager.cardCreator.pageCreator(NSPageCreator.STATS)
    property var difficulties: []

    id: main
    width: (300 > valueRow.implicitWidth) ? 300 : valueRow.implicitWidth
    height: implicitHeight
    spacing: 5

    onWidthChanged: {
        for (var s in skillpacks.objects) {
            skillpacks.objects[s].width = width
        }
    }
    
    Text {
        id: attributeName
        width: main.width
        text: qsTr("Atrybut")
        font.bold: true
        font.pointSize: 14
    }

    Row {
        property var objects: []

        id: valueRow
        spacing: 5
    }

    Column {
        property var objects: []

        id: skillpacks
        width: main.width
        height: implicitHeight
        spacing: 5
    }

    onAttributeModChanged: {
        attributeName.text = attributeMod.attribute.name

        attributeMod.attribute.valueChanged.connect(function(){
            for ( var ob in valueRow.objects ) {
                valueRow.objects[ob].atrValue = attributeMod.attribute.value
            }
        })

        for ( var o in skillpacks.objecs ) {
            skillpacks.objecs[o].destroy()
        }
        skillpacks.objects = []

        for ( var i in attributeMod.skillpacks ) {
            var component = Qt.createComponent("Skillpack.qml")
            var object = component.createObject(skillpacks, {
                                                    width: skillpacks.width,
                                                    skillpackMod: attributeMod.skillpacks[i]
                                                })
            skillpacks.objects.push(object)

            object.skillUp.connect(function(skillpackMod, skillMod){
                statsCreator.skillUp(skillpackMod, skillMod)
            })
            object.skillDown.connect(function(skillpackMod, skillMod){
                statsCreator.skillDown(skillpackMod, skillMod)
            })
            object.buy.connect(function(skillpackMod){
                statsCreator.buySkillpack(skillpackMod)
            })
            object.sell.connect(function(skillpackMod){
                statsCreator.sellSkillpack(skillpackMod)
            })
        }
    }

    onDifficultiesChanged: {
        for ( var d in difficulties ) {
            var com = Qt.createComponent("../../Common/Elements/AtrValueBox.qml")
            var obj = com.createObject(valueRow, {
                                        mod: difficulties[d],
                                        atrValue: 0
                                       })
            valueRow.objects.push(obj)
        }
    }
}
