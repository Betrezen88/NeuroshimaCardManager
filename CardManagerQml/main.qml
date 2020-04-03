import QtQuick 2.14
import QtQuick.Controls 2.5

import "./Card"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Neuroshima Card Manager")

    Card {
        id: card
        width: parent.width
        height: parent.height
    }

    Component.onCompleted: console.log("pCard:", pCard.fullname);
}
