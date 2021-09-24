﻿import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Elements"

Item {
    property var tricks
    id: main

    height: title.height + tricksList.height + 2

    Column {
        anchors.fill: main
        spacing: 2

        Label {
            id: title
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

        ListView {
            id: tricksList
            height: 300
            width: main.width
            spacing: 2
            clip: true

            model: []

            delegate: Trick {
                trick: modelData
                width: main.width
            }
        }
    }

    onTricksChanged: tricksList.model = tricks
}
