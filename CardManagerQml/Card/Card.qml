import QtQuick 2.0
import QtQuick.Controls 2.5

import "./Page"

Item {
    property var cardData

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
            contentHeight: stats.height
            contentWidth: stats.width
            clip: true

            Stats {
                id: stats
            }
        }
    }
}
