import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSAttribute 1.0

Column {
    property NSAttribute attribute
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

    onAttributeChanged: {
        attributeName.text = attribute.name

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
