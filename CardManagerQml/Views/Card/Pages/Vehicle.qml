import QtQuick 2.0
import QtQuick.Controls 2.12

Pane {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height

        Label {
            anchors.centerIn: parent
            text: "Pojazd"
        }
    }

    Component.onCompleted: console.log("Vehicle.size(h/w):", height, width)
}
