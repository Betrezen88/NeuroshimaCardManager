import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

Page {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            id: column
            spacing: 5
            anchors.margins: 5
            anchors.fill: parent

            AttributeRow {
                id: attribute1
                name: "Budowa"
                width: column.width
            }

            AttributeRow {
                id: attribute2
                name: "Zręczność"
                width: column.width
            }

            AttributeRow {
                id: attribute3
                name: "Charakter"
                width: column.width
            }

            AttributeRow {
                id: attribute4
                name: "Percepcja"
                width: column.width
            }

            AttributeRow {
                id: attribute5
                name: "Spryt"
                width: column.width
            }
        }
    }
}
