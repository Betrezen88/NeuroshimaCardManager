import QtQuick 2.14
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

import "./Card"
import "./Card/UI"
import "./Creator"

ApplicationWindow {
    signal load(string filePath)

    id: main
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
                    onClicked: mainView.currentView = "./Creator/CreatorView.qml";
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
                onClicked: loadDialog.visible = true
            }

            MenuItem {
                text: "Zapisz"
            }

            MenuItem {
                text: "Zapisz jako.."
            }
        }
    }

    FileDialog {
        id: loadDialog
        title: "Wczytaj postać..."
        folder: shortcuts.home
        visible: false
        onAccepted: {
            mainView.currentView = "./Card/UI/CardsView.qml";
            main.load(fileUrl);
            visible = false;
        }
        onRejected: {
            visible = false;
        }
    }

    MessageDialog {
        id: messageDialog
        title: "Błąd"
        visible: false
        onAccepted: visible = false;
    }

    MainView {
        id: mainView
        width: main.width
        height: main.height
    }

    Connections {
        target: cardManager
        onErrorMessage: {
            messageDialog.text = message;
            messageDialog.visible = true;
        }
    }
}
