import QtQuick 2.14
import QtQuick.Controls 2.5

import "./Card"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Neuroshima Card Manager")

    header: MenuBar {
        id: menuBar

        Menu {
            id: fileMenu
            title: "Postać"

            Menu {
                id: createMenu
                title: "Stwórz..."

                MenuItem {
                    text: "Bohatera"
                }

                Menu {
                    id: createOthersMenu
                    title: "Inne..."

                    MenuItem {
                        text: "Bestia"
                    }

                    MenuItem {
                        text: "Maszyna"
                    }
                }
            }

            MenuSeparator {}

            MenuItem {
                text: "Wczytaj"
            }

            MenuItem {
                text: "Zapisz"
            }

            MenuItem {
                text: "Zapisz jako.."
            }
        }
    }

    Card {
        id: card
        cardData: cardManager.cards[0]
        width: parent.width
        height: parent.height
    }
}
