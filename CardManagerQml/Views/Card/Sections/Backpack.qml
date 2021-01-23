import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQml.Models 2.15

import "../Elements"
import "../Elements/Equipment"

Column {
    property alias backpackItems: itemsList.model

    id: main
    spacing: 5

    signal openForm()
    signal showItemDetails(int index)

    property int fontSize: 14

    Rectangle {
        color: "#000"
        radius: 10
        width: main.width
        height: 30

        Text {
            text: "Plecak / Przy sobie"
            color: "#fff"
            font.pointSize: 14
            anchors.centerIn: parent
        }

        RoundButton {
            text: "+"
            width: parent.height
            height: parent.height
            anchors.right: parent.right
            onClicked: main.openForm()
        }
    }

    ListView {
        id: itemsList
        width: main.width
        height: (40 + spacing) * 18
        clip: true
        spacing: 2

        delegate: BackpackItem {
            name: model.name
            quantity: model.quantity
            index: model.index

            onItemDetails: main.showItemDetails(index)
        }
    }

    Row {
        width: main.width
        spacing: 5

        ValueRow {
            name: "Leki:"
            value: "11"
        }
        Text{ text:"/"; font.pointSize: fontSize }
        ValueRow {
            name: "Żywność:"
            value: "11"
        }
        Text{ text:"/"; font.pointSize: fontSize }
        ValueRow {
            name: "Woda:"
            value: "11"
        }
    }
}
