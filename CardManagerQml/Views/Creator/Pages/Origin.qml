﻿import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

Page {
    property var heroCreatorData

    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            id: column
            anchors.margins: 5
            spacing: 5
            anchors.fill: parent

            Flow {
                width: main.width - column.spacing * 2
                height: implicitHeight
                spacing: 5

                Text {
                    height: originsList.height
                    text: qsTr("Pochodzenie:")
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 14
                    font.bold: true
                }

                ComboBox {
                    id: originsList
                    width: 200
                    model: main.heroCreatorData.origins
                    textRole: 'name'
                    onCurrentIndexChanged: {
                        var item = main.heroCreatorData.origins[currentIndex]
                        bonus.text = "+"+item.value+" "+item.attribute
                        description.text = item.description
                        picture.source = "qrc:/pictures/resources/pictures/origins/"+item.image

                        if ( 0 < featuresColumn.objects.length ) {
                            for ( var i in featuresColumn.objects )
                                featuresColumn.objects[i].destroy()
                            featuresColumn.objects = []
                        }

                        for ( var j in item.features ) {
                            var component = Qt.createComponent("./../Elements/Feature.qml")
                            var object = component.createObject(featuresColumn, {
                                                                    feature: item.features[j],
                                                                    width: featuresColumn.width
                                                                })
                            featuresColumn.objects.push(object)
                        }
                    }
                }

                Text {
                    id: bonus
                    height: originsList.height
                    text: qsTr("(+1 Budowa)")
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 14
                }
            }

            Text {
                id: description
                width: main.width - column.anchors.margins * 2
                text: qsTr("Opis pochodzenia")
                wrapMode: Text.WordWrap
                font.pixelSize: 12
            }

            Row {
                id: features
                width: main.width - column.anchors.margins * 2
                height: features.implicitHeight
                spacing: 5

                Column {
                    property var objects: []
                    id: featuresColumn
                    width: features.width * 0.6
                    height: featuresColumn.implicitHeight

                    Text {
                        text: qsTr("Cecha z pochodzenia")
                        font.bold: true
                        font.pointSize: 10
                    }

                    onWidthChanged: {
                        for ( var i in objects )
                            objects[i].width = width
                    }
                }

                Image {
                    id: picture
                    width: features.width * 0.3
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/pictures/resources/pictures/origins/appalachy.PNG"
                    horizontalAlignment: Qt.AlignRight
                }
            }
        }
    }
}
