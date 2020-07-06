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

        Row {
            spacing: 10
            anchors.fill: parent
            anchors.margins: 5

            Column {
                width: implicitWidth
                height: implicitHeight + 10
                spacing: 5

                Rectangle {
                    id: skillPointsBox
                    width: 300
                    height: 70
                    color: "#ffffff"
                    radius: 10
                    visible: true
                    border.width: 2

                    Column {
                        id: pointsColumn
                        height: implicitHeight
                        spacing: 5
                        anchors.fill: parent
                        anchors.margins: 5

                        Text {
                            id: label
                            width: pointsColumn.width
                            text: qsTr("Wolne Punkty Umiejętności")
                            font.bold: true
                            font.pointSize: 12
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Text {
                            id: generalPoints
                            text: qsTr("Ogólne: 0")
                            font.pointSize: 10
                        }

                        Text {
                            id: specializationPoints
                            text: qsTr("Specjalizacja: 0")
                            font.pointSize: 10
                        }
                    }
                }

                Attribute { id: body }

                Attribute { id: dexterity }
            }

            Column {
                width: implicitWidth
                height: implicitHeight
                spacing: 5

                Attribute { id: character }

                Attribute { id: perception }
            }

            Column {
                width: implicitWidth
                height: implicitHeight
                spacing: 5

                Attribute { id: cleaverness }
            }
        }
    }

    onDataSourceChanged: {
        body.attribute = dataSource.attribute("Budowa")
        dexterity.attribute = dataSource.attribute("Zręczność")
        character.attribute = dataSource.attribute("Charakter")
        perception.attribute = dataSource.attribute("Percepcja")
        cleaverness.attribute = dataSource.attribute("Spryt")
    }
}
