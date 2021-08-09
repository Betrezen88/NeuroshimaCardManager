import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSStatsEditor 1.0

import "../Elements"
import "../Forms"

Page {
    property NSStatsEditor statsEditor

    id: main

    ScrollView {
        width: main.width
        height: main.height
        clip: true

        Row {
            spacing: 5

            Column {
                height: implicitHeight
                spacing: 5

                AttributeEdit { id: _body }
                AttributeEdit { id: _dexterity }
            }

            Column {
                height: implicitHeight
                spacing: 5

                AttributeEdit { id: _charisma }
                AttributeEdit { id: _perception }
            }

            Column {
                height: implicitHeight
                spacing: 5

                AttributeEdit { id: _cleaverness }
                OtherSkillsEdit {
                    id: _otherSkills
                    statsEditor: main.statsEditor
                    onNewSkillPopup: _otherSkillForm.open()
                }
            }
        }
    }

    OtherSkillForm {
        id: _otherSkillForm
        attributesModel: statsEditor.attributesNames
        anchors.centerIn: parent
        onBuyNewSkill: statsEditor.addOtherSkill(name, attribute)
    }

    onWidthChanged: {
        var columns = (Math.floor(width/280))
        _body.width = (columns > 3) ? 280*2+5 : 280
        _dexterity.width = (columns > 3) ? 280*2+5 : 280
        _charisma.width = (columns > 4) ? 280*2+5 : 280
        _perception.width = (columns > 4) ? 280*2+5 : 280
        _cleaverness.width = (columns > 5) ? 280*2+5 : 280
        _otherSkills.width = (columns > 5) ? 280*2+5 : 280
    }

    onHeightChanged: {
        _otherSkills.height = _charisma.height + _perception.height - _cleaverness.height
    }

    onStatsEditorChanged: {
        if ( null == statsEditor )
            return

        _body.attributeMod = statsEditor.attributeMod("Budowa")
        _dexterity.attributeMod = statsEditor.attributeMod("Zręczność")
        _charisma.attributeMod = statsEditor.attributeMod("Charakter")
        _perception.attributeMod = statsEditor.attributeMod("Percepcja")
        _cleaverness.attributeMod = statsEditor.attributeMod("Spryt")
        _otherSkills.statsEditor = statsEditor
    }
}
