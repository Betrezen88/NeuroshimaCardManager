import QtQuick 2.0
import QtQuick.Controls 2.5

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
                anchors.margins: 5
            }
        }
    }
}
