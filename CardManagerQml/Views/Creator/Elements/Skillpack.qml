import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSSkillpack 1.0
import core.NSSkillpackMod 1.0

Rectangle {
    property NSSkillpackMod skillpackMod

    signal buy(var skillpackMod)
    signal sell(var skillpackMod)
    signal skillUp(var skillpackMod, var skillMod)
    signal skillDown(var skillpackMod, var skillMod)

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
                width: titleRow.width - titleRow.spacing - bougth.width - col.padding * 2
                height: bougth.height
                text: qsTr("Skillpack Name (W,T)")
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 10
            }

            CheckBox {
                id: bougth
                text: qsTr("Kup")
                enabled: skillpackMod.enabled
                checked: skillpackMod.bougth

                onCheckedChanged: {
                    if ( skillpackMod.bougth )
                        main.sell(skillpackMod)
                    else
                        main.buy(skillpackMod)
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

    onSkillpackModChanged: {
        skillpackName.text = skillpackMod.skillpack.fullname()

        for ( var o in skills.objects ) {
            skills.objects[o].destroy()
        }
        skills.objects = []

        if ( NSSkillpack.CONSTANT === skillpackMod.skillpack.type ) {
            for ( var i in skillpackMod.skills ) {
                var component = Qt.createComponent("Skill.qml")
                var object = component.createObject(skills, {
                                                        width: skillpackName.width,
                                                        skillMod: skillpackMod.skills[i]
                                                    })
                skills.objects.push(object)
                object.skillUp.connect(function(skillMod){
                    main.skillUp(main.skillpackMod, skillMod)
                })
                object.skillDown.connect(function(skillMod){
                    main.skillDown(main.skillpackMod, skillMod)
                })
            }
        }
        else {
            for ( var j of [0, 1, 2] ) {
                var com = Qt.createComponent("GeneralSkill.qml")
                var obj = com.createObject(skills, {
                                                width: skillpackName.width,
                                                skills: skillpackMod.skills,
                                                current: j
                                           })
                skills.objects.push(obj)
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
