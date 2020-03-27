import QtQuick 2.0

Item {
    property var skillpack

    id: main

    Rectangle {
        anchors.fill: parent
        color: "#fff"
        border.color: "#000"
        border.width: 2
        radius: 10

        Column {
            id: skills
            anchors.fill: parent
            anchors.margins: 3
            spacing: 2

            Text {
                id: title
                textFormat: Text.PlainText
                font.pointSize: 10
                font.bold: true
                anchors.left: parent.left
                anchors.leftMargin: 10
            }
        }
    }

    Component.onCompleted: main.height += title.height + skills.spacing + 1;

    onSkillpackChanged: {
        title.text = main.skillpack.name + specs();
        var h = 0;
        for ( var i in skillpack.skills ) {
            var component = Qt.createComponent("Skill.qml");
            var object = component.createObject(skills,
                                                {
                                                    skill: skillpack.skills[i],
                                                    width: main.width
                                                });
            h += object.height + skills.spacing + 1;
        }
        main.height = h;;
    }

    function specs() {
        var text = " (";
        for (var i in skillpack.specializations) {
            text += skillpack.specializations[i].charAt(0);
            if ( parseInt(i) < skillpack.specializations.length-1 )
                text += ",";
        }
        text += ")";
        return text;
    }
}
