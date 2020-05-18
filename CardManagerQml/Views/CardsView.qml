import QtQuick 2.0
import QtQuick.Controls 2.12

import "./Pages/HeroCard"

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
                    action: statsAct
                }

                ToolButton {
                    text: "Ek"
                    action: equipmentAct
                }

                ToolButton {
                    text: "No"
                    action: notesAct
                }

                ToolButton {
                    text: "Zn"
                    action: friendsAct
                }

                ToolButton {
                    text: "Po"
                    action: vehicleAct
                }

                ToolButton {
                    text: "Be"
                    action: beastsAct
                }

                ToolButton {
                    text: "->"
                    onClicked: fullSidePanel.open()
                }
            }
        }

        StackView {
            property string currentPage: ""

            id: pageView
            width: main.width - quickSidePanel.width
            height: main.height

            initialItem: Stats {  }
        }
    }

    Action {
        id: statsAct
        onTriggered: {
            if ( pageView.depth > 1 )
                pageView.pop()
        }
    }

    Action {
        id: equipmentAct
        onTriggered: {
            main.showPage("qrc:/Views/Pages/HeroCard/Equipment.qml");
        }
    }

    Action {
        id: notesAct
        onTriggered: {
            main.showPage("qrc:/Views/Pages/HeroCard/Notes.qml");
        }
    }

    Action {
        id: friendsAct
        onTriggered: {
            main.showPage("qrc:/Views/Pages/HeroCard/Friends.qml");
        }
    }

    Action {
        id: vehicleAct
        onTriggered: {
            main.showPage("qrc:/Views/Pages/HeroCard/Vehicle.qml");
        }
    }

    Action {
        id: beastsAct
        onTriggered: {
            main.showPage("qrc:/Views/Pages/HeroCard/Beasts.qml");
        }
    }

    function showPage(page) {
        if ( pageView.currentPage !== page ) {
            console.log("Adding page:", page)
            if ( pageView.depth >1 ) {
                console.log("Pop")
                pageView.pop()
            }
            pageView.currentPage = page
            pageView.push(page)
        }
    }

    Component.onCompleted: console.log("CardsView.size(h/w):", height, width);
}
