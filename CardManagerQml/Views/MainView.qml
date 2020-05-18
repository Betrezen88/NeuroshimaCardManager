import QtQuick 2.9
import QtQuick.Controls 2.12

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

                    MenuItem {
                        text: "Nowa karta"
                        action: addAct
                    }

                    MenuItem {
                        text: "Wczytaj kartę"
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

                    MenuItem {
                        text: "Zapisz.."
                    }
                    MenuItem {
                        text: "Zapisz wszystko"
                    }
                }
            }
        }

        ListView {
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
                id: listItem
                width: parent.width
                height: 40

                Row {
                    anchors.fill: parent
                    spacing: 5

                    ToolButton {
                        icon.source: "qrc:/icon/resources/icons/close.svg"
                        height: parent.height
                        width: parent.height
                    }

                    Rectangle {
                        height: parent.height
                        width: parent.width - parent.height - 5
                        color: listItem.ListView.isCurrentItem ? "red" : "#fff"

                        Text {
                            text: model.title
                            height: 40
                            width: parent.width - 45
                            verticalAlignment: Text.AlignVCenter
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                sidePanel.close()
                                console.log("Show this card.")
                                cardsList.currentIndex = index
                            }
                        }
                    }
                }
            }

            model: ListModel {
                ListElement { title: "John Doe" }
                ListElement { title: "Jane Doe" }
                ListElement { title: "Mike Doe" }
                ListElement { title: "Sven Doe" }
                ListElement { title: "Bill Doe" }
                ListElement { title: "John Doe" }
                ListElement { title: "Jane Doe" }
                ListElement { title: "Mike Doe" }
                ListElement { title: "Sven Doe" }
                ListElement { title: "Bill Doe" }
                ListElement { title: "John Doe" }
                ListElement { title: "Jane Doe" }
                ListElement { title: "Mike Doe" }
                ListElement { title: "Sven Doe" }
                ListElement { title: "Bill Doe" }
            }
        }
    }

    Action {
        id: addAct
        onTriggered: {
            title.text = "Views.HeroCreatorView"
            stackView.push("qrc:/Views/HeroCreatorView.qml")
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

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: CardsView {
            id: cardsView
        }
    }
}
