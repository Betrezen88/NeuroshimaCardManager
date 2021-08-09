import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

import core.NSPage 1.0

import "./Card"
import "./Common"
import "./Edit"

Page {
    id: main

    header: ToolBar {
        width: main.width
        height: 40

        ToolButton {
            id: viewBtn
            height: parent.height; width: parent.height
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "qrc:/icon/resources/icons/list.svg"
            }
            anchors.left: parent.left
            action: panelAct
        }

        Label {
            id: title
            text: "Views.MainView"
            height: parent.height
            anchors {
                left: viewBtn.right
                right: menuBtn.left
            }
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }

        ToolButton {
            id: menuBtn
            height: parent.height; width: parent.height
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "qrc:/icon/resources/icons/gear.svg"
            }
            anchors.right: parent.right

            onPressed: {
                if ( settingsView.visible )
                    settingsView.close()
                else
                    settingsView.open()
            }
        }
    }

    Drawer {
        id: sidePanel
        width: 200
        height: main.height
        spacing: 5

        Flow {
            id: toolButtons
            spacing: 5
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }

            ToolButton {
                id: _addToolBtn
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/icon/resources/icons/add.svg"
                }
                onClicked: addMenu.open()

                Menu {
                    id: addMenu
                    x: parent.width - width
                    y: parent.height
                    width: sidePanel.width

                    NSMenuItem {
                        action: addAct
                        text: "Nowa karta"
                        shortcut: addAct.shortcut
                    }

                    NSMenuItem {
                        text: "Wczytaj kartę"
                        action: loadAct
                        shortcut: loadAct.shortcut
                    }
                }
            }

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/icon/resources/icons/save.svg"
                }
                onClicked: saveMenu.open()

                Menu {
                    id: saveMenu
                    x: parent.width - width
                    y: parent.height
                    width: sidePanel.width

                    NSMenuItem {
                        text: "Zapisz.."
                        action: saveAct
                        shortcut: saveAct.shortcut
                    }
                    MenuItem {
                        text: "Zapisz wszystko"
                    }
                }
            }

            ToolButton {
                width: _addToolBtn.width
                height: _addToolBtn.height
                contentItem: Image {
                    fillMode: Image.PreserveAspectFit
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/icon/resources/icons/page_edit.svg"
                }
                onClicked: _pageOptions.open()

                Menu {
                    id: _pageOptions
                    x: parent.width - width
                    y: parent.height
                    width: sidePanel.width

                    NSMenuItem {
                        text: "Dodaj stronę"
                        shortcut: "Ctrl+P"
                    }
                    NSMenuItem {
                        text: "Rozwiń postać"
                        action: _spendExperienceAct
                        shortcut: _spendExperienceAct.shortcut
                    }
                }
            }
        }

        ListView {
            property int secCurrentIndex: -1
            id: cardsList
            focus: true
            clip: true
            spacing: 5
            ScrollBar.vertical: ScrollBar{}

            header: Text {
                width: parent.width; height: 35
                text: "Otwarte karty"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                padding: 5
                font {
                    bold: true
                    pixelSize: 12
                }
            }

            anchors {
                top: toolButtons.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            delegate: ItemDelegate {
                property string filePath: model.filePath
                id: cardItem
                width: parent.width
                height: 40

                Row {
                    anchors.fill: parent
                    spacing: 5

                    ToolButton {
                        icon.source: "qrc:/icon/resources/icons/close.svg"
                        height: parent.height
                        width: parent.height
                        onClicked: {
                            manager.cardManager.closeCard(cardItem.filePath)
                        }
                    }

                    Rectangle {
                        height: parent.height
                        width: parent.width - parent.height - 5
                        color: cardItem.ListView.isCurrentItem ? "red" : "#fff"

                        Text {
                            text: model.stats.fullname
                            height: 40
                            width: parent.width - 45
                            verticalAlignment: Text.AlignVCenter
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                sidePanel.close()
                                if ( cardsList.currentIndex !== index ) {
                                    cardsList.currentIndex = index
                                    cardsView.cardData = manager.cardManager.card(cardItem.filePath)
                                    manager.cardManager.selectedCard = cardItem.filePath
                                }
                            }
                        }
                    }
                }
            }

            model: manager.cardManager.cards

            onCurrentIndexChanged: {
                if ((currentIndex !== -1) && (currentIndex !== secCurrentIndex)) {
                    console.log("MainView.qml onCurrentIndexChanged")
                    cardsView.cardData = manager.cardManager.card(cardsList.currentItem.filePath)
                    manager.cardManager.selectedCard = cardsList.currentItem.filePath
                    secCurrentIndex = currentIndex
                }
            }
        }
    }

    Action {
        id: addAct
        shortcut: StandardKey.New
        onTriggered: {
            title.text = "Views.HeroCreatorView"
            stackView.push("qrc:/Views/Creator/HeroCreatorView.qml")
            sidePanel.close()
            viewBtn.action = backAct
            viewBtn.contentItem.source = "qrc:/icon/resources/icons/close.svg"
        }
    }

    Action {
        id: backAct
        onTriggered: {
            stackView.pop()
            viewBtn.action = panelAct
            viewBtn.contentItem.source = "qrc:/icon/resources/icons/list.svg"
            title.text = "Views.MainView"
        }
    }

    Action {
        id: panelAct
        onTriggered: {
            sidePanel.open()
        }
    }

    Action {
        id: loadAct
        shortcut: StandardKey.Open
        onTriggered: {
            sidePanel.close()
            loadDialog.open()
        }
    }

    Action {
        id: saveAct
        shortcut: StandardKey.Save
        onTriggered: {
            sidePanel.close()
            if ( cardsView.cardData !== undefined ) {
                manager.cardManager.saveSelectedCard()
            }
            else {
                manager.cardManager.errorMessage(
                            "Błąd zapisu",
                            "Brak karty do zapisania"
                        )
            }
        }
    }

    Action {
        id: _spendExperienceAct
        shortcut: "Ctrl+E"
        onTriggered: {
            sidePanel.close()
            if ( cardsView.cardData !== undefined && cardsView.cardData.hasPage(NSPage.STATS) ) {
                stackView.push( "qrc:/Views/Edit/StatsEditor.qml",
                               {
                                   "stats": cardsView.cardData.stats,
                                   "width": stackView.width,
                                   "height": stackView.height
                               }
                        )
                stackView.currentItem.onClose.connect(function(){
                    stackView.pop()
                })
            }
            else {
                manager.cardManager.errorMessage(
                            "Nie można rozwinąć postaci.",
                            "Brak karty lub strony statystyk."
                        )
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        padding: 5
        visible: cardsList.count > 0 || depth > 1

        initialItem: CardsView {
            id: cardsView
        }
    }

    FileDialog {
        id: loadDialog
        title: "Wczytaj kartę"
        folder: "file:///" + appSettings.defaultCardFolder
        onAccepted: {
            manager.cardManager.loadCard(loadDialog.fileUrl)
            close()
        }
    }

    SettingsView {
        id: settingsView
        width: main.width
        height: main.height
    }

    MessageDialog {
        id: messageDialog
        onAccepted: messageDialog.close()
    }

    Connections {
        target: manager.cardManager
        function onErrorMessage(title, message) {
            messageDialog.title = title
            messageDialog.text = message
            messageDialog.open()
        }
        function onInfoMessage(title, message) {
            messageDialog.title = title
            messageDialog.text = message
            messageDialog.open()
        }
    }
}
