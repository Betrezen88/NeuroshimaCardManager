import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Element"

Item {
    id: main

    height: background.height
            + title.height

    Column {
        anchors.fill: parent
        spacing: 2

        Label {
            id: title
            height: 30
            width: main.width
            text: "Rany"
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
            id: background
            width: main.width
            height: scratch.height
                    + light.height
                    + heavy.height
                    + critical.height
                    + (woundsList.anchors.margins * 2)
                    + (woundsList.spacing * 5)
            border.color: "#000"
            border.width: 2
            radius: 10

            Column {
                id: woundsList
                anchors.fill: parent
                anchors.margins: 2
                spacing: 2

                WoundRow {
                    id: scratch
                    name: "Draśnięcia"
                    value: ""
                    width: main.width
                }

                WoundRow {
                    id: light
                    name: "Lekkie"
                    value: ""
                    width: main.width
                }

                WoundRow {
                    id: heavy
                    name: "Ciężkie"
                    value: ""
                    width: main.width
                }

                WoundRow {
                    id: critical
                    name: "Krytyczne"
                    value: ""
                    width: main.width
                }
            }
        }
    }
}
