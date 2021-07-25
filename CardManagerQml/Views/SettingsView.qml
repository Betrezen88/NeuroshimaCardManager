import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

Popup {
    id: main
    closePolicy: Popup.NoAutoClose

    ScrollView {
        id: _scrollView
        width: main.width
        height: main.height

        Column {
            width: parent.width
            height: parent.height
            spacing: 5

            Label {
                width: main.width
                height: implicitHeight
                text: qsTr("Ustawienia ogólne")
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                padding: 2
                font.pointSize: 14
                font.bold: true
            }

            Row {
                height: implicitHeight < _folderBtn.height ? _folderBtn.height : implicitHeight
                leftPadding: 5
                spacing: 2

                Text {
                    width: main.width - _folderBtn.width - 25
                    height: implicitHeight < _folderBtn.height ? _folderBtn.height : implicitHeight
                    text: qsTr("Katalog kart postaci")
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap
                    font.pointSize: 11
                    font.bold: true
                }

                Button {
                    id: _folderBtn
                    width: 40
                    height: 40
                    icon.source: "qrc:/icon/resources/icons/folder.svg"
                    display: AbstractButton.IconOnly
                    onClicked: _defaultCardFolderDialog.open()
                }
            }

            TextInput {
                id: _defaultCardFolder
                width: main.width
                height: 30
                text: appSettings.defaultCardFolder
                enabled: false
                font.pixelSize: 11
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WordWrap
            }
        } // Column
    } // ScrollView

    FileDialog {
        id: _defaultCardFolderDialog
        title: "Domyślny folder kart postaci"
        folder: "file:///" + appSettings.defaultCardFolder
        selectFolder: true
        onAccepted: {
            appSettings.defaultCardFolder = _defaultCardFolderDialog.fileUrl
            close()
        }
    }
} // Page
