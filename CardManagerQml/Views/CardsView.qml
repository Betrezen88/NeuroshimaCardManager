import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    id: main

    Drawer {
        id: fullSidePanel
        width: 200
        height: main.height
        spacing: 5
        y: 40

        Column {
            anchors.fill: parent
            anchors.leftMargin: 5
            spacing: 5

            ToolButton {
                text: "St"
            }

            ToolButton {
                text: "Ek"
            }

            ToolButton {
                text: "No"
            }

            ToolButton {
                text: "Zn"
            }

            ToolButton {
                text: "Po"
            }

            ToolButton {
                text: "Be"
            }

            ToolButton {
                text: "<-"
                onClicked: fullSidePanel.close()
            }
        }
    }

    Row {
        anchors.fill: parent
        spacing: 2

        Item {
            id: quickSidePanel
            width: 50
            height: main.height

            Column {
                anchors.fill: parent
                anchors.leftMargin: 5
                spacing: 5

                ToolButton {
                    text: "St"
                }

                ToolButton {
                    text: "Ek"
                }

                ToolButton {
                    text: "No"
                }

                ToolButton {
                    text: "Zn"
                }

                ToolButton {
                    text: "Po"
                }

                ToolButton {
                    text: "Be"
                }

                ToolButton {
                    text: "->"
                    onClicked: fullSidePanel.open()
                }
            }
        }

        StackView {
            id: cardView
            width: main.width - quickSidePanel.width
            height: main.height
        }
    }

    Component.onCompleted: console.log("CardsView.size(h/w):", height, width);
}
