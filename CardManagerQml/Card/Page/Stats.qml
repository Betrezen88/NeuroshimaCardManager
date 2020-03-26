import QtQuick 2.0

import "./../Section"

Item {
    id: main

    height: personal.height + tricks.height + 2
    width: personal.width

    Row {
        id: row
        anchors.fill: main
        spacing: 2

        Column {
            id: column1
            spacing: 2

            Personal {
                id: personal
            }

            Tricks {
                id: tricks
                width: main.width
            }
        }

        Column {
            id: column2
        }

        Column {
            id: column3
        }

        Column {
            id: column4
        }
    }
}
