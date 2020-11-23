import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

import core.NSStatsSource 1.0
import core.NSStatsCreator 1.0
import core.NSCreationPointsManager 1.0

Page {
    property NSStatsCreator statsCreator
    property NSCreationPointsManager pointsManager: manager.cardCreator.creationPointsManager()

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

            Text {
                id: points
                text: "Wolne punkty: 0"
            }
        }
    }

    onStatsCreatorChanged: {
        for ( var i in statsCreator.attributes ) {
            var component = Qt.createComponent("../Elements/AttributeRow.qml")
            var object = component.createObject(attributesCol, {
                                                    attributeMod: statsCreator.attributes[i]
                                                })
            attributesCol.objects.push(object)
        }
    }

    onPointsManagerChanged: {
        points.text = "Wolne punkty: " + pointsManager.attributes
    }

    Connections {
        target: pointsManager
        onAttributesChanged: points.text = "Wolne punkty: " + value
    }
}
