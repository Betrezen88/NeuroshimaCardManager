import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.15

import "../Elements"

Column {
    id: main
    spacing: 5

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

        Button {
            text: "+"
            width: parent.height
            height: parent.height
            anchors.right: parent.right
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
        }

        model: ListModel {
            ListElement { name: "Papieros"; quantity: 5 }
            ListElement { name: "Zapalniczka"; quantity: 1 }
            ListElement { name: "Krótkofalówka"; quantity: 1 }
        }

        Component.onCompleted: {
            while ( model.count < 18 )
                model.append( {name: "", quantity: 0} )
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
