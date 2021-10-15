import QtQuick 2.15
import QtQuick.Controls 2.12

import core.view.NSStats 1.0
import core.edit.NSStatsEditor 1.0

import "./Pages"

Page {
    property NSStats stats

    signal close()

    id: main

    Column {
        width: implicitWidth
        height: implicitHeight
        spacing: 5

        Row {
            id: _tabsRow
            spacing: 5
            leftPadding: 5
            width: main.width

            Button {
                id: _skillsBtn
                text: "Umiejętności"
                onClicked: _swipeView.setCurrentIndex(0)
                highlighted: true
            }

            Button {
                id: _tricksBtn
                text: "Sztuczki"
                onClicked: _swipeView.setCurrentIndex(1)
            }

            Button {
                id: _reputationBtn
                text: "Reputacja"
                onClicked: _swipeView.setCurrentIndex(2)
            }

            Item {
                height: 1
                width: 40
            }

            Button {
                display: AbstractButton.IconOnly
                icon.source: "qrc:/icon/resources/icons/close.svg"
                width: height
                onClicked: main.close()
            }

            Button {
                display: AbstractButton.IconOnly
                icon.source: "qrc:/icon/resources/icons/accept.svg"
                width: height
                onClicked: main.close()
            }
        }

        Row {
            id: _experienceInfoRow
            spacing: 5
            padding: 5

            Text {
                text: "Doświadczenie:"
                font.pointSize: 16
                font.bold: true
            }

            Text {
                id: _experienceToSpend
                text: "0"
                font.pointSize: 16
            }
        }

        SwipeView {
            id: _swipeView
            width: main.width
            height:  main.height - (parent.spacing * 2) - _tabsRow.height - _experienceInfoRow.height

            SkillsEditor {
                id: _skillsEditor
                width: _swipeView.width
                height: _swipeView.height
            }

            TricksEditor {
                id: _tricksEditor
                width: _swipeView.width
            }

            ReputationEditor {
                id: _reputationEditor
                width: _swipeView.width
                height: _swipeView.height
            }

            onCurrentIndexChanged: {
                _skillsBtn.highlighted = 0 == currentIndex
                _tricksBtn.highlighted = 1 == currentIndex
                _reputationBtn.highlighted = 2 == currentIndex
            }
        }
    } // Column

    NSStatsEditor {
        id: _nsStatsEditor
    }

    onStatsChanged: {
        if ( null == stats )
            return

        _nsStatsEditor.init(stats.stats, ":/json/resources/json/Experience.json")
        _skillsEditor.statsEditor = _nsStatsEditor
        _experienceToSpend.text = _nsStatsEditor.experience.available

        _nsStatsEditor.experience.availableChanged.connect(function(){
            _experienceToSpend.text = _nsStatsEditor.experience.available
        })
    }
}
