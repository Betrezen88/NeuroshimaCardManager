import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

import core.NSStatsSource 1.0
import core.NSPageCreator 1.0
import core.NSStatsCreator 1.0
import core.NSCreationPointsManager 1.0

Page {
    property NSStatsSource dataSource
    property NSStatsCreator statsCreator
    property NSCreationPointsManager pointsManager

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

                OtherSkills {
                    id: column
                    width: cleaverness.width
                    statsCreator: manager.cardCreator.pageCreator(NSPageCreator.STATS)
                }
            }
        }
    }

    onDataSourceChanged: {
        body.difficulties = dataSource.difficulties
        dexterity.difficulties = dataSource.difficulties
        character.difficulties = dataSource.difficulties
        perception.difficulties = dataSource.difficulties
        cleaverness.difficulties = dataSource.difficulties
    }

    onStatsCreatorChanged: {
        body.attribute = statsCreator.attribute("Budowa")
        dexterity.attribute = statsCreator.attribute("Zręczność")
        character.attribute = statsCreator.attribute("Charakter")
        perception.attribute = statsCreator.attribute("Percepcja")
        cleaverness.attribute = statsCreator.attribute("Spryt")
    }

    onPointsManagerChanged: {
        generalPoints.text = "Ogólne: " + pointsManager.freeSkillpoints
        specializationPoints.text = "Specjalizacja: " + pointsManager.specializationSkillpoints
    }

    Connections {
        target: pointsManager
        onFreeSkillpointsChanged: generalPoints.text = "Ogólne: " + value
        onSpecializationSkillpointsChanged: {
            specializationPoints.text = "Specjalizacja: " + value
        }
    }
}
