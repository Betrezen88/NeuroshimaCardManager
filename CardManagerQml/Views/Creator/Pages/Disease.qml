import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

import core.NSStatsSource 1.0
import core.NSDisease 1.0

Page {
    property NSStatsSource dataSource
    property NSDisease disease

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
                    onClicked: {
                        var val = manager.cardCreator.diceRoll() - 1
                        main.disease = dataSource.diseases[val]
                    }
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
                width: main.width - column.anchors.margins * 2
                text: qsTr("Opis")
                wrapMode: Text.WordWrap
                font.pointSize: 10
            }

            Text {
                id: cure
                width: main.width - column.anchors.margins * 2
                text: qsTr("Lekrstwo")
                wrapMode: Text.WordWrap
                font.pointSize: 10
            }

            Flow {
                property var objects: []

                id: symptoms
                width: main.width - column.anchors.margins * 2
                height: implicitHeight
                spacing: 5
            }
        }
    }

    onDiseaseChanged: {
        diseaseName.text = disease.name
        description.text = "Opis: " + disease.description
        cure.text = "Lekarstwo: " + disease.cure

        for ( var o in symptoms.objects ) {
            symptoms.objects[o].destroy()
        }
        symptoms.objects = []

        for ( var i in disease.symptoms ) {
            var component = Qt.createComponent("../Elements/Symptom.qml")
            var object = component.createObject(symptoms, {
                                                    symptom: disease.symptoms[i]
                                                })
            symptoms.objects.push(object)
        }
    }
}
