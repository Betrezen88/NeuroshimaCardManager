import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

import core.NSStatsSource 1.0
import core.NSOrigin 1.0
import core.NSOriginBonus 1.0
import core.NSHeroData 1.0
import core.NSFeature 1.0
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
                    width: 250
                    textRole: 'name'
                    onCurrentIndexChanged: {
                        var item = main.dataSource.origins[currentIndex]
                        description.text = item.description
                        picture.source = "qrc:/pictures/resources/pictures/origins/"+item.image

                        statsCreator.setOrigin(item.name, item.description)

                        bonusValue.text = "+"+item.bonus.value
                        bonusList.model = item.bonus.attributes

                        if ( 0 < featuresColumn.objects.length ) {
                            for ( var i in featuresColumn.objects )
                                featuresColumn.objects[i].destroy()
                            featuresColumn.objects = []
                        }

                        for ( var j in item.features ) {
                            var component = Qt.createComponent("./../Elements/Feature.qml")
                            var object = component.createObject(featuresColumn, {
                                                                    feature: item.features[j],
                                                                    width: featuresColumn.width,
                                                                    group: originGroup,
                                                                })
                            object.featureSelected.connect(function(feature){
                                statsCreator.setOriginFeature(feature)
                            })
                            object.checked = parseInt(j) === 0
                            featuresColumn.objects.push(object)
                        }
                    }
                }

                Text {
                    id: bonusValue
                    height: originsList.height
                    text: qsTr("+1")
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 14
                }

                ComboBox {
                    id: bonusList
                    height: originsList.height
                    width: 150
                    font.bold: true
                    font.pointSize: 14
                    onCurrentTextChanged: {
                        statsCreator.setOriginBonus(currentText, 1)
                    }
                }
            }

            Text {
                id: description
                width: main.width - column.anchors.margins * 2
                text: qsTr("Opis pochodzenia")
                wrapMode: Text.WordWrap
                font.pointSize: 12
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
                    height: featuresColumn.implicitHeight + 20

                    ButtonGroup { id: originGroup }

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
                    horizontalAlignment: Qt.AlignRight
                }
            }
        }
    }

    onDataSourceChanged: {
        originsList.model = main.dataSource.origins
    }
}
