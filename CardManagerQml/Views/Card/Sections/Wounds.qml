import QtQuick 2.9
import QtQuick.Controls 2.5

import "./../Elements"

Column {
    id: main

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
                wounds: "D, D, L, L, C, C, K, K"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _leftHand
                label: "L. ręka:"
                wounds: "D, D, L, L, C, C, K, K"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _rightHand
                label: "P. ręka:"
                wounds: "D, D, L, L, C, C, K, K"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _torso
                label: "Tułów:"
                wounds: "D, D, L, L, C, C, K, K"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _leftLeg
                label: "L. noga:"
                wounds: "D, D, L, L, C, C, K, K"
                width: _column.width - (_column.padding*2)
            }

            WoundRow {
                id: _rightLeg
                label: "P. noga:"
                wounds: "D, D, L, L, C, C, K, K"
                width: _column.width - (_column.padding*2)
            }
        }
    }
}
