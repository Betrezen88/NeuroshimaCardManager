import QtQuick 2.15
import QtQuick.Controls 2.12

import core.edit.NSStatsEditor 1.0

import "../Elements"

Page {
    property NSStatsEditor statsEditor

    id: main

    ScrollView {
        width: main.width
        height: main.height
        clip: true

        Flow {
            width: main.width
            height: main.height
            spacing: 5

            Repeater {
                property int maxElementWidth: 0
                id: _reputation
                delegate: ReputationEdit {
                    reputationData: modelData
                    Component.onCompleted: {
                        if ( _reputation.maxElementWidth < titleWidth )
                            _reputation.maxElementWidth = titleWidth
                        else
                            titleWidth = _reputation.maxElementWidth
                    }
                }
                onMaxElementWidthChanged: {
                    for ( var element in _reputation.parent.children ) {
                        if ( _reputation.parent.children[element] instanceof ReputationEdit )
                            _reputation.parent.children[element].titleWidth = maxElementWidth
                    }
                }
            } // Repeater
        } // Flow
    } // ScrollView

    onStatsEditorChanged: _reputation.model = statsEditor.reputations
}
