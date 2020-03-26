import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Element"

Item {
    id: main

    height: personalLabel.height + listBackground.height + 2

    Column {
        anchors.fill: main
        spacing: 2

        Label {
            id: personalLabel
            height: 30
            width: main.width
            text: "Sztuczki"
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
            id: listBackground
            width: main.width
            height: 300

            border.color: "#000"
            border.width: 2
            radius: 10

            ListView {
                id: tricksList
                anchors.fill: parent
                anchors.margins: 4
                spacing: 2
                clip: true

                model: ListModel {
                    ListElement { name: "1, 2, 3 Boom!"; description: "Description" }
                    ListElement { name: "Ośmiornica"; description: "Description" }
                    ListElement { name: "Siekierezada"; description: "Description" }
                    ListElement { name: "Pierwotny instynkt"; description: "Description" }
                    ListElement { name: "Szybki Bill"; description: "Description" }
                    ListElement { name: "Medyk polowy"; description: "Description" }
                    ListElement { name: "Gun fight"; description: "Description" }
                    ListElement { name: "Taranowanie"; description: "Description" }
                    ListElement { name: "Padnij/Powstań"; description: "Description" }
                }

                delegate: Trick {
                    trick: ({name: name, description: description})
                    width: main.width - (tricksList.anchors.margins*2)
                }
            }
        }
    }
}
