import QtQuick 2.0
import QtQuick.Controls 2.12

Pane {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height

        Label {
            anchors.centerIn: parent
            text: "Notatki"
        }
    }

    Component.onCompleted: console.log("Notes.size(h/w):", height, width)
}
