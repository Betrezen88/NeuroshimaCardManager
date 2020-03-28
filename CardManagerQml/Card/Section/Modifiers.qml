import QtQuick 2.9
import QtQuick.Controls 2.5

import "./../Element"

Item {
    id: main

    height: title.height + background.height + 2

    Column {
        spacing: 2
        anchors.fill: parent

        Label {
            id: title
            height: 30
            width: main.width
            text: "Modyfikatory"
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
            height: label.height + 2 + modsList.height

            border.color: "#000"
            border.width: 2
            radius: 10

            Column {
                anchors.fill: parent
                spacing: 2

                Row {
                    width: main.width
                    padding: 5
                    spacing: 2

                    Text {
                        id: label
                        text: "Utrudnienia wspólne:"
                        textFormat: Text.PlainText
                        font.pointSize: 10
                    }
                    Text {
                        id: allMods
                        text: "0%"
                        textFormat: Text.PlainText
                        font.pointSize: 10
                    }
                }
                ListView {
                    id: modsList
                    clip: true
                    width: main.width
                    height: 100

                    delegate: Modifier {
                        modifier: ({ source: source, value: value })
                        width: main.width
                    }

                    model: ListModel {
                        ListElement { source: "Lekka"; value: 15 }
                        ListElement { source: "Lekka"; value: 30 }
                        ListElement { source: "Draśnięcie"; value: 10 }
                        ListElement { source: "Lekka"; value: 15 }
                    }
                }
            }
        }
    }
}
