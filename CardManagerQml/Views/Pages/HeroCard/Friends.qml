import QtQuick 2.0
import QtQuick.Controls 2.12

Pane {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height

        Label {
            anchors.centerIn: parent
            text: "Znajomośći"
        }
    }

    Component.onCompleted: console.log("Friends.size(h/w):", height, width)
}
