import QtQuick 2.15
import QtQuick.Controls 2.12

import core.edit.NSStatsEditor 1.0
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
            leftPadding: 5

            ListView {
                id: _tricks
                clip: true
                spacing: 5
                width: (main.width/2) - parent.spacing - 5
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

            Column {
                spacing: 5

                ComboBox {
                    id: _filter
                    width: (main.width/2) - parent.spacing - 5
                    model: [ "Wszystkie", "Dostępne" ]
                    onCurrentIndexChanged: _tricksModel.onlyAvailable = currentIndex == 1
                }

                Row {
                    spacing: 5

                    TextField {
                        id: _search
                        placeholderText: "Szukaj po nazwie..."
                        width: (main.width/2) - parent.spacing - _sortBtn.width - 10
                        height: _sortBtn.height
                        onTextChanged: _tricksModel.pattern = text
                    }

                    Button {
                        id: _sortBtn
                        icon.source: "qrc:/icon/resources/icons/sort_desc.svg"
                        width: height
                        onClicked: {
                            _tricksModel.ascending = !_tricksModel.ascending
                            icon.source = ( _tricksModel.ascending )
                                    ? "qrc:/icon/resources/icons/sort_desc.svg"
                                    : "qrc:/icon/resources/icons/sort_asc.svg"
                        }
                    }
                }

                ListView {
                    id: _availableTricks
                    clip: true
                    spacing: 5
                    width: (main.width/2) - parent.spacing - 5
                    height: main.height - _filter.height - _search.height - (parent.spacing*2)
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
            } // Column
        } // Row
    } // ScrollView

    TrickDetails {
        id: _trickDetails
        width: main.width - 50
        height: main.height - 50
        anchors.centerIn: Overlay.overlay
    }

    NSTricksEditModel {
        id: _tricksModel
    }

    onStatsEditorChanged: {
        _tricksModel.modelChanged.connect(function(){
            _availableTricks.model = _tricksModel.model
        })

        _tricksModel.init( statsEditor, ":/json/resources/json/Tricks.json" )
        _tricks.model = statsEditor.tricks
    }
}
