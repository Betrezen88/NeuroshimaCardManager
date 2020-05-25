import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Sections"

Pane {
    property var statsData

    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true


        Row {
            id: row
            anchors.fill: parent
            spacing: 4

            Column {
                id: column1
                spacing: 4

                Personal {
                    id: personal
                }

                Tricks {
                    id: tricks
                    width: personal.width
                }
            }

            Column {
                id: column2
                spacing: 4

                Attribute {
                    id: budowa
                    width: 250
                }

                Attribute {
                    id: dexterity
                    width: 250
                }

                Wounds {
                    id: wounds
                    width: 250
                }
            }

            Column {
                id: column3
                spacing: 4

                Attribute {
                    id: character
                    width: 250
                }

                Attribute {
                    id: perception
                    width: 250
                }

                Modifiers {
                    id: modifiers
                    width: 250
                }
            }

            Column {
                id: column4
                spacing: 4

                Attribute {
                    id: cleaverness
                    width: 250
                }

                OtherSkills {
                    id: otherSkills
                    width: 250
                }
            }
        }
    }

    onStatsDataChanged: {
        personal.personalData = statsData.personal;
        tricks.tricks = statsData.tricks;
        budowa.attribute = statsData.attributes[0];
        dexterity.attribute = statsData.attributes[1];
        character.attribute = statsData.attributes[2];
        perception.attribute = statsData.attributes[3];
        cleaverness.attribute = statsData.attributes[4];
        otherSkills.skills = statsData.otherSkills;
    }

    Component.onCompleted: console.log("Stats.size(h/w):", height, width)
}
