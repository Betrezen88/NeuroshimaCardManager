import QtQuick 2.0
import QtQuick.Controls 2.12

import "../Sections"

Pane {
    id: main

    ScrollView {
        width: parent.width - 10
        height: parent.height
        clip: true

        Row {
            id: mainRow
            anchors.fill: parent
            spacing: 5

            Column {
                id: first
                spacing: 5

                Armor {
                    id: armor
                    width: mainRow.getWidth()
                }

                Weapons {
                    id: weapons
                    width: mainRow.getWidth()
                }
            }

            Column {
                id: second
                spacing: 5

                Backpack {
                    id: backpack
                    width: mainRow.getWidth()
                }
            }

            function getWidth() {
                return (main.width - mainRow.spacing - 40)/2 < 500
                        ? 500 : (main.width - mainRow.spacing - 40)/2
            }
        }
    }

    Component.onCompleted: console.log("Equipment.size(h/w):", height, width)
}
