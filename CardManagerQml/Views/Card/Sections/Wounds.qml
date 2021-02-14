import QtQuick 2.9
import QtQuick.Controls 2.5

import core.NSWound 1.0

import "./../Elements"

Column {
    property var wounds: []

    id: main

    signal showWoundForm()

    Rectangle {
        width: main.width
        height: 30
        color: "#000000"
        radius: 10

        Row {
            width: parent.width
            height: parent.height

            Text {
                width: parent.width - _addWoundBtn.width
                height: parent.height
                color: "#ffffff"
                text: qsTr("Rany")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 15
            }

            RoundButton {
                id: _addWoundBtn
                width: parent.height
                height: parent.height
                text: "+"
                onClicked: main.showWoundForm()
            }
        }
    }

    Rectangle {
        width: main.width
        height: _column.height
        color: "#ffffff"
        radius: 10
        border.width: 2

        Column {
            id: _column
            width: parent.width
            height: implicitHeight
            spacing: 5
            padding: 5

            WoundRow {
                id: _head
                label: "Głowa:"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _leftHand
                label: "L. ręka:"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _rightHand
                label: "P. ręka:"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _torso
                label: "Tułów:"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _leftLeg
                label: "L. noga:"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _rightLeg
                label: "P. noga:"
                width: _column.width - (_column.padding*2)
            }
        }
    }

    onWoundsChanged: {
        var tWounds = {}

        for (var w in wounds) {
            if ( !tWounds.hasOwnProperty(wounds[w].location) )
                tWounds[wounds[w].location] = []

            tWounds[wounds[w].location].push(wounds[w].type.charAt(0))
        }

        _head.wounds = tWounds["Głowa"]
        _torso.wounds = tWounds["Tułów"]
        _leftHand.wounds = tWounds["Lewa ręka"]
        _rightHand.wounds = tWounds["Prawa ręka"]
        _leftLeg.wounds = tWounds["Lewa noga"]
        _rightLeg.wounds = tWounds["Prawa noga"]
    }
}
