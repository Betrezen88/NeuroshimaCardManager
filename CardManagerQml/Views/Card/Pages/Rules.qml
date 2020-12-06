import QtQuick 2.0
import QtQuick.Controls 2.15

import core.NSRules 1.0
import core.NSRulesSection 1.0

import "../Sections"
import "../Elements"

Pane {
    property NSRules rulesData

    id: main

    SplitView.preferredHeight: splitView.height
    SplitView.preferredWidth: splitView.width/2

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            id: sections
            spacing: 10
            anchors.fill: parent
        }

        onWidthChanged: {
            for ( var c in sections.children)
                sections.children[c].width = width < 400 ? 400 : width
        }
    }

    onRulesDataChanged: {
        for ( var i in rulesData.sections ) {
            var component = Qt.createComponent("../Sections/RuleSection.qml")
            var object = component.createObject(sections, {
                                                    title: rulesData.sections[i].title,
                                                    rows: rulesData.sections[i].rows,
                                                    width: sections.width < 400 ? 400 : sections.width
                                          })
        }
    }
}
