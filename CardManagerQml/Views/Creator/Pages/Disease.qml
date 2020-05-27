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
            spacing: 5
            anchors.fill: parent
            anchors.margins: 5

            Row {
                width: column.width
                height: implicitHeight
                spacing: 5

                Button {
                    id: randomBtn
                    text: qsTr("Losuj")
                }

                CheckBox {
                    id: professionDisease
                    text: qsTr("Choroby zawodowe")
                }

                Button {
                    id: listBtn
                    text: qsTr("Lista chorób")
                }
            }

            Row {
                width: column.width
                height: implicitHeight
                spacing: 5

                Text {
                    id: label
                    text: qsTr("Wylosowano:")
                    font.bold: true
                    font.pointSize: 14
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: diseaseName
                    text: qsTr("Nazwa choroby")
                    font.pointSize: 14
                    font.bold: false
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Text {
                id: description
                width: column.width
                text: qsTr("Opis")
                wrapMode: Text.WordWrap
                font.pointSize: 10
            }

            Flow {
                width: column.width
                height: implicitHeight
                spacing: 5

                Symptom {
                    id: symptom
                }

                Symptom {
                    id: symptom1
                }

                Symptom {
                    id: symptom2
                }

                Symptom {
                    id: symptom3
                }
            }
        }
    }
}
