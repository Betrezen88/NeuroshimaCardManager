import QtQuick 2.0
import QtQuick.Controls 2.12

Pane {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height

        Label {
            anchors.centerIn: parent
            text: "Statysytyki"
        }
    }

    Component.onCompleted: console.log("Stats.size(h/w):", height, width)
}
