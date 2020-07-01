import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSStatsSource 1.0
import core.NSProfession 1.0
import core.NSHeroData 1.0
import core.NSFeature 1.0

import "./../Elements"

Page {
    property NSStatsSource dataSource

    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            id: column
            height: column.implicitHeight
            anchors.fill: parent
            anchors.margins: 5
            spacing: 5

            Flow {
                id: element
                width: main.width
                height: element.implicitHeight
                spacing: 5

                Text {
                    id: professionLabel
                    height: professionsList.height
                    text: qsTr("Profesja:")
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 14
                }

                ComboBox {
                    id: professionsList
                    width: 200
                    textRole: 'name'
                    onCurrentIndexChanged: {
                        var item = main.dataSource.professions[currentIndex]
                        description.text = item.description
                        quote.text = item.quote
                        image.source = "qrc:/pictures/resources/pictures/professions/"+item.image

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
                                                                    group: professionGroup,
                                                                    checked: parseInt(j) === 0
                                                                })
                            featuresColumn.objects.push(object)
                        }
                    }
                }
            }

            Text {
                id: quote
                width: main.width - column.anchors.margins * 2
                text: qsTr("Cytat profesji")
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                font.italic: true
                font.pointSize: 10
            }

            Text {
                id: description
                width: main.width - column.anchors.margins * 2
                text: qsTr("Opis profesji")
                wrapMode: Text.WordWrap
                font.pointSize: 12
            }

            Flow {
                id: features
                width: main.width - column.anchors.margins * 2
                height: features.implicitHeight
                spacing: 5

                Column {
                    property var objects: []
                    id: featuresColumn
                    width: (main.width - column.anchors.margins * 2) * 0.6
                    height: featuresColumn.implicitHeight + 20
                    spacing: 5

                    ButtonGroup { id: professionGroup }

                    Text {
                        id: featureLabel
                        text: qsTr("Cecha z profesji")
                        font.pointSize: 10
                        font.bold: true
                    }

                    onWidthChanged: {
                        for ( var i in objects )
                            objects[i].width = width
                    }
                }

                Image {
                    id: image
                    width: (main.width - column.anchors.margins * 2) * 0.3
                    fillMode: Image.PreserveAspectFit
                    source: "file:///c:/Users/Michał/Pictures/Neuroshima Professions/Chemik.PNG"
                }
            }

        }
    }

    onDataSourceChanged: {
        professionsList.model = main.dataSource.professions
    }
}
