import QtQuick 2.0
import QtQuick.Controls 2.12

import core.view.NSStats 1.0

import "./../Sections"
import "./../Forms"

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
                    onShowWoundForm: _woundForm.open()
                }
            }

            Column {
                id: column3
                spacing: 4

                Attribute {
                    id: character
                    width: row.columnWidth
                    onHeightChanged: _otherSkills.height = (height + perception.height)
                                            - cleaverness.height
                }

                Attribute {
                    id: perception
                    width: row.columnWidth
                    onHeightChanged: _otherSkills.height = (character.height + height)
                                     - cleaverness.height
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
                    onHeightChanged: _otherSkills.height = (character.height
                                            + perception.height) - height
                }

                OtherSkills {
                    id: _otherSkills
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

                        statsData.experience.addExperience( _experiencePoints.text )
                        _experienceForm.close()
                    }
                }
            }
        } // Column

        onClosed: _experiencePoints.clear()

    } // Popup experience

    WoundForm {
        id: _woundForm
        stats: statsData
        modal: true
        height: implicitHeight
        width: implicitWidth
        padding: 5
        anchors.centerIn: parent

        onSendWound: statsData.addWound(location, type, passed)
    }

    onStatsDataChanged: {
        personal.personalData = statsData
        tricks.tricks = statsData.tricks
        budowa.attribute = statsData.attribute("Budowa")
        dexterity.attribute = statsData.attribute("Zręczność")
        character.attribute = statsData.attribute("Charakter")
        perception.attribute = statsData.attribute("Percepcja")
        cleaverness.attribute = statsData.attribute("Spryt")
        _otherSkills.otherSkills = statsData.otherSkills
        experience.experience = statsData.experience
        wounds.stats = statsData
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
