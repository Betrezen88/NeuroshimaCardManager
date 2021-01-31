import QtQuick 2.0
import QtQuick.Controls 2.15

import "./Pages"

Page {
    property var cardData

    id: main

    ListModel {
        id: pagesModel
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
        ListElement {
            icon: "qrc:/icon/resources/icons/rules.svg"
            page: "qrc:/Views/Card/Pages/Rules.qml"
            text: "Zasady"
        }
    }

    Row {
        anchors.fill: parent
        spacing: 2

        Item {
            id: quickSidePanel
            width: 50
            height: main.height

            ListView {
                id: listSidePanel
                clip: true
                anchors {
                    top: parent.top
                    bottom: colBtn.top
                    left: parent.left
                    right: parent.right
                    bottomMargin: 5
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
                                visible: (quickSidePanel.width === 50) ? false : true
                            }
                        }
                    }
                }

                model: pagesModel
            }

            Column {
                id: colBtn
                anchors {
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }
                spacing: 5

                ToolButton {
                    id: sidePageBtn
                    width: quickSidePanel.width
                    height: 50
                    background: Rectangle { color: "lightGray" }
                    contentItem: Item {
                        Row {
                            anchors.fill: parent
                            spacing: 10
                            Image {
                                source: "qrc:/icon/resources/icons/side_page.svg"
                                width: sidePageBtn.height - 10
                                height: sidePageBtn.height - 10
                            }
                            Text {
                                text: "Strona obok"
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
                                visible: (quickSidePanel.width === 50) ? false : true
                            }
                        }
                    }

                    onClicked: sidePageMenu.open()

                    Menu {
                        id: sidePageMenu

                        Repeater {
                            model: pagesModel
                            delegate: MenuItem {
                                icon.source: model.icon
                                text: model.text
                                onClicked: setSidePage(model.page)
                            }
                        }
                        MenuItem {
                            text: "Ukryj stronę"
                            onClicked: closeSidePage()
                        }
                    }
                }

                ToolButton {
                    id: panelBtn
                    width: parent.width
                    height: 50
                    icon.source: (quickSidePanel.width === 50)
                                 ? "qrc:/icon/resources/icons/arrow_forward.svg"
                                 : "qrc:/icon/resources/icons/arrow_back.svg"
                    background: Rectangle { color: "lightGray" }
                    onClicked: {
                        quickSidePanel.width = (quickSidePanel.width === 50) ? 150 : 50
                    }
                }
            }
        }

        SplitView {
            id: splitView
            orientation: Qt.Horizontal
            width: main.width - quickSidePanel.width
            height: main.height

            StackView {
                property string currentPage: ""
                property string sidePage: ""
                property QtObject sidePageObj

                id: pageView
                width: splitView.width
                height: splitView.height
                SplitView.minimumWidth: 300

                onCurrentPageChanged: {
                    if ( pageView.depth > 1 )
                        pageView.pop()

                    if ( "" !== currentPage ) {
                        pageView.push(currentPage)

                        switch (currentPage) {
                            case "qrc:/Views/Card/Pages/Stats.qml":
                                currentItem.statsData = cardData.stats
                                break
                            case "qrc:/Views/Card/Pages/Equipment.qml":
                                currentItem.equipmentData = cardData.equipment
                                break
                            case "qrc:/Views/Card/Pages/Rules.qml":
                                currentItem.rulesData = cardData.rules
                                break;
                            default:
                                console.log("Unknown page to load data")
                        }
                    }
                }
            } // StackView
        } // SplitView
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

    function setSidePage(page) {
        if ( page !== pageView.sidePage ) {
            splitView.removeItem(pageView.sidePageObj)
            delete pageView.sidePageObj
        }

        var component = Qt.createComponent(page)
        var object = component.createObject(splitView, {
                                                width: splitView.preferredWidth/2,
                                                height: splitView.height
                                            })
        if ( page === "qrc:/Views/Card/Pages/Stats.qml" )
            object.statsData = cardData.stats
        else if ( page === "qrc:/Views/Card/Pages/Equipment.qml" )
            object.equipmentData = cardData.equipment
        else if ( page === "qrc:/Views/Card/Pages/Rules.qml" )
            object.rulesData = cardData.rules

        pageView.sidePageObj = object
        pageView.sidePage = page
        splitView.addItem(pageView.sidePageObj)
    }

    function closeSidePage() {
        if ( "" === pageView.sidePage )
            return;

        splitView.removeItem(pageView.sidePageObj)
        pageView.width = splitView.preferredWidth
        pageView.sidePage = ""
        delete pageView.sidePageObj
    }
}
