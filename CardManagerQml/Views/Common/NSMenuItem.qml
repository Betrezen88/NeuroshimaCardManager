import QtQuick 2.9
import QtQuick.Controls 2.12

MenuItem {
    property var shortcut

    id: main

    contentItem: Item {
        Text {
            text: qsTr(main.text)
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
            }
        }
        Text {
            text: qsTr(_shortcut.nativeText)
            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
            }
        }
    }

    Shortcut {
        id: _shortcut
        sequence: main.shortcut
        context: Qt.ApplicationShortcut
        onActivated: main.action.triggered()
    }
}
