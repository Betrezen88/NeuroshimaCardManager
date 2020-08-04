import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

import core.NSStatsSource 1.0
import core.NSStatsCreator 1.0

Page {
    property NSStatsSource dataSource
    property NSStatsCreator statsCreator

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

    onStatsCreatorChanged: {
        for ( var i in statsCreator.attributes ) {
            var component = Qt.createComponent("../Elements/AttributeRow.qml")
            var object = component.createObject(attributesCol, {
                                                    attribute: statsCreator.attributes[i]
                                                })
            attributesCol.objects.push(object)
        }
    }
}
