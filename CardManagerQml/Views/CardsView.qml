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
                anchors.fill: parent
                spacing: 5

                delegate: ToolButton {
                    height: parent.width
                    width: parent.width
                    icon.source: model.icon
                    onClicked: {
                        pageView.currentPage = model.page
                        listSidePanel.currentIndex = index
                    }
                    background: Rectangle {
                        color: parent.ListView.isCurrentItem ? "gray" : "lightGray"
                    }
                }

                model: ListModel {
                    ListElement {
                        icon: "qrc:/icon/resources/icons/stats.svg"
                        page: "qrc:/Views/Pages/Stats.qml"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/equipment.svg"
                        page: "qrc:/Views/Pages/Equipment.qml"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/notes.svg"
                        page: "qrc:/Views/Pages/Notes.qml"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/friends.svg"
                        page: "qrc:/Views/Pages/Friends.qml"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/vehicle.svg"
                        page: "qrc:/Views/Pages/Vehicle.qml"
                    }
                    ListElement {
                        icon: "qrc:/icon/resources/icons/beasts.svg"
                        page: "qrc:/Views/Pages/Beasts.qml"
                    }
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
                        case "qrc:/Views/Pages/Stats.qml":
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
                pageView.currentPage = "qrc:/Views/Pages/Stats.qml"
            }
        }
    }
}
