import QtQuick 2.0

import "./../Section"

Item {
    property var statsData

    id: main

    height: personal.height + tricks.height + 2
    width: (3*row.spacing)
           + personal.width
           + budowa.width
           + character.width
           + cleaverness.width

    Row {
        id: row
        anchors.fill: main
        spacing: 4

        Column {
            id: column1
            spacing: 4

            Personal {
                id: personal
                //personalData: statsData.personal
            }

            Tricks {
                id: tricks
                //tricks: statsData.tricks
                width: personal.width
            }
        }

        Column {
            id: column2
            spacing: 4

            Attribute {
                id: budowa
                width: 250
//                attribute: statsData.attributes[0]
            }

            Attribute {
                id: dexterity
                width: 250
//                attribute: statsData.attributes[1]
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
//                attribute: statsData.attributes[2]
            }

            Attribute {
                id: perception
                width: 250
//                attribute: statsData.attributes[3]
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
//                attribute: statsData.attributes[4]
            }

            OtherSkills {
                id: otherSkills
//                skills: statsData.otherSkills
                width: 250
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
}
