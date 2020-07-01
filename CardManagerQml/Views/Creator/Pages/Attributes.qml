import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

import core.NSStatsSource 1.0

Page {
    property NSStatsSource dataSource

    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            property var objects: []

            id: attributesCol
            spacing: 5
            anchors.margins: 5
            anchors.fill: parent
        }
    }

    onDataSourceChanged: {
        for ( var i in dataSource.attributes ) {
            var component = Qt.createComponent("../Elements/AttributeRow.qml")
            var object = component.createObject(attributesCol, {
                                                    name: dataSource.attributes[i].name,
                                                    value: 6
                                                })
            attributesCol.objects.push(object)
        }
    }
}
