import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSSkillpack 1.0
import core.NSPageCreator 1.0
import core.NSStatsCreator 1.0
import core.NSCreationPointsManager 1.0

Rectangle {
    property NSSkillpack skillpack
    property NSCreationPointsManager pointsManager: manager.cardCreator.creationPointsManager()
    property NSStatsCreator statsCreator: manager.cardCreator.pageCreator(NSPageCreator.STATS)

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
                        if ( skillpack.specializations.indexOf(statsCreator.specialization) > -1 )
                            pointsManager.spendSpecializationSkillpoints(5);
                        else
                            pointsManager.spendFreeSkillpoints(5)
                    }
                    else {
                        if ( skillpack.specializations.indexOf(statsCreator.specialization) > -1 )
                            pointsManager.refundSpecializationSkillpoints(5);
                        else
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
                object.spend.connect(function(value){
                    if ( skillpack.specializations.indexOf(statsCreator.specialization) > -1 )
                        pointsManager.spendSpecializationSkillpoints(value)
                    else
                        pointsManager.spendFreeSkillpoints(value)
                })
                object.refund.connect(function(value){
                    if ( skillpack.specializations.indexOf(statsCreator.specialization) > -1 )
                        pointsManager.refundSpecializationSkillpoints(value)
                    else
                        pointsManager.refundFreeSkillpoints(value)
                })
            }
        }
        else {
            for ( var j of [0, 1, 2] ) {
                var com = Qt.createComponent("GeneralSkill.qml")
                var obj = com.createObject(skills, {
                                                width: skillpackName.width,
                                                skills: skillpack.skills,
                                                current: j
                                           })
                skills.objects.push(obj)
                obj.spend.connect(function(value){
                    if ( skillpack.specializations.indexOf(statsCreator.specialization) > -1 )
                        pointsManager.spendSpecializationSkillpoints(value)
                    else
                        pointsManager.spendFreeSkillpoints(value)
                })
                obj.refund.connect(function(value){
                    if ( skillpack.specializations.indexOf(statsCreator.specialization) > -1 )
                        pointsManager.refundSpecializationSkillpoints(value)
                    else
                        pointsManager.refundFreeSkillpoints(value)
                })
                obj.currentSkillChanged.connect(function(skill, index){
                    for ( var s in skills.objects )
                        if ( skill !== skills.objects[s]
                            && skill.current === skills.objects[s].current )
                            skills.objects[s].current = index
                })
            }
        }
    }
}
