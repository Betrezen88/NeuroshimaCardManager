import QtQuick 2.0

import "./../Section"

Item {
    id: main

    height: personal.height
    width: personal.width

    Row {
        id: row
        anchors.fill: main
        spacing: 2

        Column {
            id: column1

            Personal {
                id: personal
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
