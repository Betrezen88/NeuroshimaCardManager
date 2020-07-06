import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSAttribute 1.0

import "./../../Card/Elements" as CardElements

Column {
    property NSAttribute attribute

    id: main
    width: 300
    height: implicitHeight
    spacing: 5
    
    Text {
        id: attributeName
        width: main.width
        text: qsTr("Atrybut")
        font.bold: true
        font.pointSize: 14
    }
    
    CardElements.ValueBoxRow {
        id: valueRow
    }
    
    Column {
        property var objects: []

        id: skillpacks
        width: main.width
        height: implicitHeight
        spacing: 5
    }

    onAttributeChanged: {
        attributeName.text = attribute.name
        valueRow.value = attribute.value

        for ( var o in skillpacks.objecs ) {
            skillpacks.objecs[o].destroy()
        }
        skillpacks.objects = []

        for ( var i in attribute.skillpacks ) {
            var component = Qt.createComponent("Skillpack.qml")
            var object = component.createObject(skillpacks, {
                                                    width: skillpacks.width,
                                                    skillpack: attribute.skillpacks[i]
                                                })
            skillpacks.objects.push(object)
        }
    }
}
