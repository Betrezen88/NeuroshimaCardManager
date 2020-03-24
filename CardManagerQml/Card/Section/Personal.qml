import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Element"

Item {
    id: main

    width: portrait.width
    height: portrait.height

    Column {
        anchors.fill: main
        spacing: 2

        Portrait {
            id: portrait
            width: 200
            height: 200
        }

        Label {
            id: personalLabel
            height: 30
            width: main.width
            text: "Postać"
            color: "#fff"
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            background: Rectangle {
                color: "#000"
                radius: 10
            }
        }
    }
}
