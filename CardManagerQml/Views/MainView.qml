import QtQuick 2.0
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
            text: "|"
            height: parent.height
            width: parent.height
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
            ScrollBar.vertical: ScrollBar{}

            anchors {
                top: toolButtons.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            delegate: ItemDelegate {
                width: parent.width
                text: model.title
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
            title.text = "HeroCreatorView"
            stackView.push("qrc:/Views/HeroCreatorView.qml")
            sidePanel.close()
        }
    }

    Action {
        id: backAct
        onTriggered: {
            stackView.pop()
            viewBtn.action = panelAct
        }
    }

    Action {
        id: panelAct
        onTriggered: {
            sidePanel.open()
            viewBtn.action = backAct
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
