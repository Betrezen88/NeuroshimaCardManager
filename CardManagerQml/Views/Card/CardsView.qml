import QtQuick 2.0
import QtQuick.Controls 2.12

import "./Pages"

Page {
    property var cardData

    id: main

    Row {
        anchors.fill: parent
        spacing: 2

        Item {
            id: quickSidePanel
            width: 50
            height: main.height

            ListView {
                id: listSidePanel
                anchors {
                    top: parent.top
                    bottom: panelBtn.top
                    left: parent.left
                    right: parent.right
                }
                spacing: 5

                delegate: ToolButton {
                    id: sideBtn
                    height: 50
                    width: parent.width
                    icon.source: model.icon
                    text: model.text
                    onClicked: {
                        pageView.currentPage = model.page
                        listSidePanel.currentIndex = index
                    }
                    background: Rectangle {
                        color: parent.ListView.isCurrentItem ? "gray" : "lightGray"
                    }
                    contentItem: Item {
                        Row {
                            anchors.fill: parent
                            spacing: 10
                            Image {
                                source: sideBtn.icon.source
                                width: sideBtn.height - 10
                                height: sideBtn.height - 10
                            }
                            Text {
                                text: sideBtn.text
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                }

                model: ListModel {
                    ListElement {
                        icon: "qrc:/icon/resources/icons/stats.svg"
                        page: "qrc:/Views/Card/Pages/Stats.qml"
                        text: "Statystyki"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/equipment.svg"
                        page: "qrc:/Views/Card/Pages/Equipment.qml"
                        text: "Ekwipunek"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/notes.svg"
                        page: "qrc:/Views/Card/Pages/Notes.qml"
                        text: "Notatki"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/friends.svg"
                        page: "qrc:/Views/Card/Pages/Friends.qml"
                        text: "Znajomości"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/vehicle.svg"
                        page: "qrc:/Views/Card/Pages/Vehicle.qml"
                        text: "Pojazd"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/beasts.svg"
                        page: "qrc:/Views/Card/Pages/Beasts.qml"
                        text: "Bestie"
                    }
                }
            }

            ToolButton {
                id: panelBtn
                width: parent.width
                height: 50
                anchors.bottom: quickSidePanel.bottom
                icon.source: (quickSidePanel.width === 50)
                             ? "qrc:/icon/resources/icons/arrow_forward.svg"
                             : "qrc:/icon/resources/icons/arrow_back.svg"
                background: Rectangle { color: "lightGray" }
                onClicked: {
                    quickSidePanel.width = (quickSidePanel.width === 50) ? 150 : 50
                }
            }
        }

        StackView {
            property string currentPage: ""

            id: pageView
            width: main.width - quickSidePanel.width
            height: main.height

            onCurrentPageChanged: {
                if ( pageView.depth > 1 )
                    pageView.pop()

                if ( "" !== currentPage ) {
                    pageView.push(currentPage)

                    switch (currentPage) {
                        case "qrc:/Views/Card/Pages/Stats.qml":
                            currentItem.statsData = cardData.stats
                            break
                        default:
                            console.log("Unknown page to load data")
                    }
                }
            }
        }
    }

    onCardDataChanged: {
        if (pageView.depth > 0) {
            pageView.clear()
            pageView.currentPage = ""
        }

        if ( cardData !== "undefined" ) {
            if ( cardData.stats !== null ) {
                pageView.currentPage = "qrc:/Views/Card/Pages/Stats.qml"
            }
        }
    }
}
