import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSSkillpack 1.0
import core.NSCreationPointsManager 1.0

Rectangle {
    property NSSkillpack skillpack
    property NSCreationPointsManager pointsManager: manager.cardCreator.creationPointsManager()

    id: main
    height: col.height
    radius: 5
    border {
        width: 2
        color: "#000"
    }
    
    Column {
        id: col
        width: main.width
        height: implicitHeight
        padding: 5

        Row {
            id: titleRow
            width: main.width
            height: implicitHeight

            Text {
                id: skillpackName
                width: titleRow.width - titleRow.spacing - checkBox.width - col.padding * 2
                height: checkBox.height
                text: qsTr("Skillpack Name (W,T)")
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 10
            }

            CheckBox {
                id: checkBox
                text: qsTr("Kup")

                onCheckedChanged: {
                    if ( checked ) {
                       pointsManager.spendFreeSkillpoints(5)
                    }
                    else {
                        pointsManager.refundFreeSkillpoints(5)
                    }
                }
            }
        }

        Column {
            property var objects: []

            id: skills
            width: main.width
            height: implicitHeight
            spacing: 5
        }
    }

    onSkillpackChanged: {
        skillpackName.text = skillpack.fullname()

        for ( var o in skills.objects ) {
            skills.objects[o].destroy()
        }
        skills.objects = []

        if ( NSSkillpack.CONSTANT === skillpack.type ) {
            for ( var i in skillpack.skills ) {
                var component = Qt.createComponent("Skill.qml")
                var object = component.createObject(skills, {
                                                        width: skillpackName.width,
                                                        skill: skillpack.skills[i]
                                                    })
                skills.objects.push(object)
            }
        }
        else {
            var array = [];
            for ( var s in skillpack.skills ) {
                array.push(skillpack.skills[s].name)
            }

            for ( var j of [0, 1, 2] ) {
                var com = Qt.createComponent("GeneralSkill.qml")
                var obj = com.createObject(skills, {
                                                width: skillpackName.width,
                                                skills: array,
                                                no: j
                                           })
                skills.objects.push(obj)
            }
        }
    }
}
