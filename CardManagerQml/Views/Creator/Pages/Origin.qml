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
            anchors.margins: 5
            spacing: 5
            anchors.fill: parent

            Flow {
                width: main.width - column.spacing * 2
                height: implicitHeight
                spacing: 5

                Text {
                    id: originLabel
                    height: comboBox.height
                    text: qsTr("Pochodzenie:")
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 14
                    font.bold: true
                }

                ComboBox {
                    id: comboBox
                    width: 200
                }

                Text {
                    id: bonus
                    height: originLabel.height
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

            Flow {
                id: features
                width: main.width - column.anchors.margins * 2
                height: features.implicitHeight
                spacing: 5

                Column {
                    id: featuresColumn
                    width: features.width * 0.6
                    height: featuresColumn.implicitHeight

                    Text {
                        id: featuresLabel
                        text: qsTr("Cecha z pochodzenia")
                        font.bold: true
                        font.pointSize: 10
                    }

                    Feature {
                        id: feature
                    }

                    Feature {
                        id: feature1
                    }

                    Feature {
                        id: feature2
                    }
                }

                Image {
                    id: picture
                    width: main.width * 0.3
                    fillMode: Image.PreserveAspectFit
                    source: "file:///c:/Users/Michał/Pictures/Neuroshima Images/hegemonia.PNG"
                    horizontalAlignment: Qt.AlignRight
                }
            }
        }
    }
}
