import QtQuick 2.9
import QtQuick.Controls 2.12

import core.edit.NSStatsEditor 1.0

Item {
    property NSStatsEditor statsEditor
    property bool isNewSkillAffortable

    signal newSkillPopup()

    id: main

    Column {
        spacing: 5

        Rectangle {
            width: main.width
            height: _row.implicitHeight
            color: "#000"
            radius: 5

            Row {
                id: _row
                padding: 5

                Text {
                    text: "Inne umiejętności"
                    width: main.width - _addBtn.width - _row.padding*2
                    height: _addBtn.height
                    color: "#fff"
                    font.bold: true
                    font.pointSize: 16
                    verticalAlignment: Text.AlignVCenter
                }

                Button {
                    id: _addBtn
                    width: height
                    text: "+"
                    font.bold: true
                    font.pointSize: 16
                    onClicked: {
                        if ( main.isNewSkillAffortable )
                            main.newSkillPopup()
                        else
                            ToolTip.show("Za mało punktów doświadczenia.")
                    }
                }
            }
        }

        Rectangle {
            width: main.width
            height: main.height - _row.height - 5
            radius: 5
            border.width: 2
            border.color: "#000"

            ListView {
                id: _otherSkills
                anchors.fill: parent
                anchors.margins: 5
                spacing: 5
                clip: true

                delegate: OtherSkillEdit {
                    width: parent.width
                    otherSkillEdit: modelData
                    onRemove: main.statsEditor.removeOtherSkill(otherSkillEdit)
                }
            }
        }

    } // Column

    onStatsEditorChanged: {
        _otherSkills.model = statsEditor.otherSkills

        statsEditor.otherSkillsChanged.connect(function(){
            _otherSkills.model = statsEditor.otherSkills
        })
    }

} // Item
