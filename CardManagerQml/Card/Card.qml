import QtQuick 2.0
import QtQuick.Controls 2.5

import "./Page"

Item {
    id: main

    Row {
        id: row
        anchors.fill: main
        spacing: 2

        Rectangle {
            id: sidePanel
            height: main.height
            width: 50
            color: "green"
        }

        ScrollView {
            id: pageView
            width: main.width - row.spacing - sidePanel.width
            height: main.height

            Stats {
                id: stats
                anchors.fill: parent
            }
        }
    }
}
