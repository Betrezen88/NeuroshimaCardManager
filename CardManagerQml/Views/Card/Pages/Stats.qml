import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSStats 1.0

import "./../Sections"

Pane {
    property NSStats statsData

    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Row {
            property double columnWidth: 270

            id: row
            anchors.fill: parent
            spacing: 4

            Column {
                id: column1
                spacing: 4

                Personal {
                    id: personal
                    width: row.columnWidth
                }

                Tricks {
                    id: tricks
                    width: row.columnWidth
                }
            }

            Column {
                id: column2
                spacing: 4

                Attribute {
                    id: budowa
                    width: row.columnWidth
                }

                Attribute {
                    id: dexterity
                    width: row.columnWidth
                }

                Wounds {
                    id: wounds
                    width: row.columnWidth
                }
            }

            Column {
                id: column3
                spacing: 4

                Attribute {
                    id: character
                    width: row.columnWidth
                }

                Attribute {
                    id: perception
                    width: row.columnWidth
                }

                Modifiers {
                    id: modifiers
                    width: row.columnWidth
                }
            }

            Column {
                id: column4
                spacing: 4

                Attribute {
                    id: cleaverness
                    width: row.columnWidth
                }

                OtherSkills {
                    id: otherSkills
                    width: row.columnWidth
                    height: (character.height + perception.height)
                            - cleaverness.height
                }

                Experience {
                    id: experience
                    width: row.columnWidth
                    onShowExperienceForm: _experienceForm.open()
                }
            }
        }
    }

    Popup {
        id: _experienceForm
        modal: true
        height: implicitHeight
        width: 300
        padding: 5
        anchors.centerIn: parent

        Column {
            spacing: 5

            Text {
                text: "Dodaj doświadczenie"
                color: "#000"
                font.pointSize: 12
                height: 30
                width: _experienceForm.width
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: _experiencePoints
                width: _experienceForm.width - (_experienceForm.padding * 2)
                placeholderText: "Przyznane doświadczenie"
                validator: IntValidator { bottom: 0; top: 1000 }
            }

            Row {
                spacing: 5

                Button {
                    text: "Anuluj"
                    onClicked: _experienceForm.close()
                }

                Button {
                    text: "Dodaj"
                    onClicked: {
                        if ( _experiencePoints.length === 0 )
                            return

                        statsData.addExperience( _experiencePoints.text )
                        _experienceForm.close()
                    }
                }
            }
        } // Column

        onClosed: _experiencePoints.clear()

    } // Popup

    onStatsDataChanged: {
        personal.personalData = statsData
        tricks.tricks = statsData.tricks
        budowa.attribute = statsData.attributes[0]
        dexterity.attribute = statsData.attributes[1]
        character.attribute = statsData.attributes[2]
        perception.attribute = statsData.attributes[3]
        cleaverness.attribute = statsData.attributes[4]
        otherSkills.skills = statsData.otherSkills
        experience.gathered = statsData.gathered
        experience.spended = statsData.spended
        statsConnections.target = statsData
    }

    Connections {
        id: statsConnections
        ignoreUnknownSignals: true
        function onGatheredChanged(value) {
            experience.gathered = value
        }
    }

    Component.onCompleted: console.log("Stats.size(h/w):", height, width)
}
