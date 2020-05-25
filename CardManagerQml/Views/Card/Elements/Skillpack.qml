import QtQuick 2.9

Item {
    property var skillpack

    id: main
    height: mainHeight()

    Rectangle {
        anchors.fill: parent
        color: "#fff"
        border.color: "#000"
        border.width: 2
        radius: 10

        Column {
            property var objects: []

            id: skills
            anchors.fill: parent
            anchors.margins: 3
            spacing: 2

            Text {
                id: title
                textFormat: Text.PlainText
                font.pointSize: 10
                font.bold: true
                leftPadding: 10

                onHeightChanged: main.height = mainHeight();
            }
        }
    }

    onSkillpackChanged: {
        title.text = main.skillpack.name + specs();
        for ( var i in skillpack.skills ) {
            var component = Qt.createComponent("Skill.qml");
            var object = component.createObject(skills,
                                                {
                                                    skill: skillpack.skills[i],
                                                    width: main.width
                                                });
            skills.objects.push(object);
        }
        main.height = mainHeight();
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

    function mainHeight() {
        var h = 0;
        var objCount = skills.objects.length;

        if ( "undefined" !== typeof(title) )
            h += title.height;
        if ( 0 < objCount )
            h += (objCount * skills.objects[0].height)
                    + ((objCount+1) * skills.spacing)
                    + (skills.anchors.margins * 2);

        return h;
    }
}
