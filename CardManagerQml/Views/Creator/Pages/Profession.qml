import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

Page {
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
                    height: comboBox.height
                    text: qsTr("Profesja:")
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 14
                }

                ComboBox {
                    id: comboBox
                    width: 200
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
                    id: featuresColumn
                    width: (main.width - column.anchors.margins * 2) * 0.6
                    height: featuresColumn.implicitHeight
                    spacing: 5

                    Text {
                        id: featureLabel
                        text: qsTr("Cecha z profesji")
                        font.pointSize: 10
                        font.bold: true
                    }

                    Feature { id: feature1 }

                    Feature { id: feature2 }

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
}
