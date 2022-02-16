import QtQuick 2.14
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.15

import "./Views"

ApplicationWindow {
    property bool forceClose: false

    id: _main
    visible: true
    width: Screen.width / 2
    height: Screen.height / 2
    title: qsTr("Neuroshima Card Manager")

    MainView {
        anchors.fill: parent
    }

    onClosing: {
        close.accepted = forceClose ? true : manager.cardManager.cards.length === 0

        if ( !close.accepted ) {
            if ( manager.cardManager.hasUnsavedData() )
                _saveOnCloseDialog.open()
            else
                close.accepted = true
        }
    }

    MessageDialog {
        id: _saveOnCloseDialog
        text: "Czy chcesz zapisać ostatnie zmiany ?"
        standardButtons: StandardButton.SaveAll | StandardButton.Close | StandardButton.No
        onAccepted: {
            manager.cardManager.saveAndCloseAllCards()
            _main.close()
        }
        onRejected: {
            forceClose = true
            _main.close()
        }
    }
}
