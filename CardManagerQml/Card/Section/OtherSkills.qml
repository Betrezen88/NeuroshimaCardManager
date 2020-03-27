import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Element"

Item {
    property variant skills

    id: main
    height: title.height + skillsList.height + 2

    Column {
        anchors.fill: parent
        spacing: 2

        Label {
            id: title
            height: 30
            width: main.width
            text: "Inne umiejętności"
            color: "#fff"
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            background: Rectangle {
                color: "#000"
                radius: 10
            }
        }

        Rectangle {
            width: main.width
            height: 195
            border.color: "#000"
            border.width: 2
            radius: 10

            ListView {
                id: skillsList
                anchors.fill: parent
                anchors.topMargin: 5
                clip: true
                spacing: 2

                delegate: OtherSkill {
                    width: main.width
                    skill: ({ name: name, value: value, attribute: attribute })
                }

                model: ListModel {
                    ListElement { name: "Pilotowanie"; attribute: "Spryt"; value: 1 }
                    ListElement { name: "Żeglowanie"; attribute: "Spryt"; value: 1 }
                    ListElement { name: "Język Hiszpanski"; attribute: "Spryt"; value: 1 }
                }
            }
        }
    }
}
