import QtQuick 2.9
import QtQuick.Controls 2.12

import core.edit.NSStatsEditor 1.0

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

        _body.attributeEdit = statsEditor.attribute("Budowa")
        _dexterity.attributeEdit = statsEditor.attribute("Zręczność")
        _charisma.attributeEdit = statsEditor.attribute("Charakter")
        _perception.attributeEdit = statsEditor.attribute("Percepcja")
        _cleaverness.attributeEdit = statsEditor.attribute("Spryt")
        _otherSkills.statsEditor = statsEditor
        _otherSkills.isNewSkillAffortable = statsEditor.experience.isNewSkillAffortable
        _otherSkillForm.attributesModel = statsEditor.attributesNames()

        statsEditor.experience.isNewSkillAffortableChanged.connect(function(){
            _otherSkills.isNewSkillAffortable = main.statsEditor.experience.isNewSkillAffortable
        })
    }
}
