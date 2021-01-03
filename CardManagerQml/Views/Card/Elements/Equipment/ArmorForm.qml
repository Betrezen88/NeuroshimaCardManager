import QtQuick 2.0
import QtQuick.Controls 2.12

import "../"

Column {
    id: main
    spacing: 10
    height: implicitHeight

    Label {
        width: main.width
        text: "Statystyki"
        font.pointSize: 14
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
    }

    Row {
        spacing: 5
        Text {
            text: "Głowa:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _head
            height: parent.height
            from: 0
            to: 4
        }
    }
    Row {
        spacing: 5
        Text {
            text: "Tułów:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _torso
            height: parent.height
            from: 0
            to: 4
        }
    }
    Row {
        spacing: 5
        Text {
            text: "Lewa ręka:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _leftHand
            height: parent.height
            from: 0
            to: 4
        }
    }
    Row {
        spacing: 5
        Text {
            text: "Prawa ręka:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _rightHand
            height: parent.height
            from: 0
            to: 4
        }
    }
    Row {
        spacing: 5
        Text {
            text: "Lewa noga:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _leftLeg
            height: parent.height
            from: 0
            to: 4
        }
    }
    Row {
        spacing: 5
        Text {
            text: "Prawa ręka:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _rightLeg
            height: parent.height
            from: 0
            to: 4
        }
    }

    Row {
        spacing: 5
        Text {
            text: "Wytrzymałość:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _durability
            height: parent.height
            from: 0
            to: 4
        }
    }

    Flow {
        Text {
            text: "Kary"
            font.pointSize: 14
            font.bold: true
        }
        Button {
            text: "+"
        }
    }

    function statsData() {
        var stats = { durability: _durability.value, locations:[] }

        if ( _head.value > 0 )
            stats["locations"].push({ type: "head", value: _head.value })
        if ( _torso.value > 0 )
            stats["locations"].push({ type: "torso", value: _torso.value })
        if ( _leftHand.value > 0 )
            stats["locations"].push({ type: "leftHand", value: _leftHand.value })
        if ( _rightHand.value > 0 )
            stats["locations"].push({ type: "rightHand", value: _rightHand.value })
        if ( _leftLeg.value > 0 )
            stats["locations"].push({ type: "leftLeg", value: _leftLeg.value })
        if ( _rightLeg.value > 0 )
            stats["locations"].push({ type: "rightLeg", value: _rightLeg.value })

        return stats
    }
}
