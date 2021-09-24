import QtQuick 2.9
import QtQuick.Controls 2.5

import core.view.NSStats 1.0

import "./../Elements"

Column {
    property NSStats stats

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

            Repeater {
                id: _woundRows
                delegate: WoundRow {
                    width: _column.width - (_column.padding*2)
                    label: modelData
                    wounds: stats.wound( modelData )
                    Component.onCompleted: {
                        stats.woundsChanged.connect(function(){
                            wounds = statsData.wound( modelData )
                        })
                    }
                }
            }
        } // Column
    } // Rectangle

    onStatsChanged: {
        _woundRows.model = stats.locations
    }
} // Column
