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
            }
        }
    }

    onStatsDataChanged: {
        personal.personalData = statsData;
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
