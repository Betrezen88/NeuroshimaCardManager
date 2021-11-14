import QtQuick 2.15
import QtQuick.Controls 2.12

import core.edit.NSStatsEditor 1.0
import core.models.NSTricksModel 1.0
import core.models.NSTricksEditModel 1.0

import core.edit.NSTrickEdit 1.0

import "../Elements"

Page {
    property NSStatsEditor statsEditor

    id: main

    ScrollView {
        width: main.width
        height: main.height
        clip: true

        Row {
            spacing: 5

            ListView {
                id: _tricks
                clip: true
                spacing: 5
                width: (main.width - parent.spacing)/2
                height: main.height
                delegate: TrickDelegate {
                    buyBtnVisible: false
                    trickData: modelData
                    width: _tricks.width
                    onShowDetails: {
                        _trickDetails.trickData = trickData
                        _trickDetails.open()
                    }
                }
            }

            ListView {
                id: _availableTricks
                clip: true
                spacing: 5
                width: (main.width - parent.spacing)/2
                height: main.height
                delegate: TrickDelegate {
                    buyBtnVisible: true
                    trickData: modelData
                    width: _availableTricks.width
                    onShowDetails: {
                        _trickDetails.trickData = trickData
                        _trickDetails.open()
                    }
                }
            }
        }
    }

    TrickDetails {
        id: _trickDetails
        width: main.width - 50
        height: main.height - 50
        anchors.centerIn: Overlay.overlay
    }

    NSTricksEditModel {
        id: _tricksModel
        sourceFile: ":/json/resources/json/Tricks.json"
        Component.onCompleted: _availableTricks.model = model
    }

    onStatsEditorChanged: _tricks.model = statsEditor.tricks
}
