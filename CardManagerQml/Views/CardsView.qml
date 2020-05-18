import QtQuick 2.0
import QtQuick.Controls 2.12

import "./Pages"

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
                action: statsAct
                text: "Statystyki"
            }

            ToolButton {
                action: equipmentAct
                text: "Ekwipunek"
            }

            ToolButton {
                action: notesAct
                text: "Notatki"
            }

            ToolButton {
                action: friendsAct
                text: "Znajomości"
            }

            ToolButton {
                action: vehicleAct
                text: "Pojazd"
            }

            ToolButton {
                action: beastsAct
                text: "Bestie"
            }

            ToolButton {
                icon.source: "qrc:/icon/resources/icons/arrow_back.svg"
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
                    action: statsAct
                    onClicked: fullSidePanel.close()
                }

                ToolButton {
                    action: equipmentAct
                    onClicked: fullSidePanel.close()
                }

                ToolButton {
                    action: notesAct
                    onClicked: fullSidePanel.close()
                }

                ToolButton {
                    action: friendsAct
                    onClicked: fullSidePanel.close()
                }

                ToolButton {
                    action: vehicleAct
                    onClicked: fullSidePanel.close()
                }

                ToolButton {
                    action: beastsAct
                    onClicked: fullSidePanel.close()
                }

                ToolButton {
                    icon.source: "qrc:/icon/resources/icons/arrow_forward.svg"
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
        icon.source: "qrc:/icon/resources/icons/stats.svg"
        onTriggered: {
            if ( pageView.depth > 1 ) {
                pageView.pop()
                pageView.currentPage = ""
            }
        }
    }

    Action {
        id: equipmentAct
        icon.source: "qrc:/icon/resources/icons/equipment.svg"
        onTriggered: {
            main.showPage("qrc:/Views/Pages/Equipment.qml");
        }
    }

    Action {
        id: notesAct
        icon.source: "qrc:/icon/resources/icons/notes.svg"
        onTriggered: {
            main.showPage("qrc:/Views/Pages/Notes.qml");
        }
    }

    Action {
        id: friendsAct
        icon.source: "qrc:/icon/resources/icons/friends.svg"
        onTriggered: {
            main.showPage("qrc:/Views/Pages/Friends.qml");
        }
    }

    Action {
        id: vehicleAct
        icon.source: "qrc:/icon/resources/icons/vehicle.svg"
        onTriggered: {
            main.showPage("qrc:/Views/Pages/Vehicle.qml");
        }
    }

    Action {
        id: beastsAct
        icon.source: "qrc:/icon/resources/icons/beasts.svg"
        onTriggered: {
            main.showPage("qrc:/Views/Pages/Beasts.qml");
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
