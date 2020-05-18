import QtQuick 2.9

import "./../Elements"

Item {
    property variant attribute

    id: main

    height: mainHeight()

    Rectangle {
        id: background
        color: "#cac6c6"
        anchors.fill: main

        border.color: "#000"
        border.width: 1

        Column {
            anchors.fill: background
            spacing: 2

            Text {
                id: title
                padding: 5
                font.pointSize: 14
                width: main.width
            }

            ValueBoxRow {
                id: valueRow
                width: main.width
            }

            Column {
                property var objects: []
                id: column
                spacing: 2
                rightPadding: 5
                leftPadding: 5

                function clearSkillpacks() {
                    for ( var i in objects )
                        objects[i].destroy();
                    objects = [];
                }
            }
        }
    }

    onAttributeChanged: {
        valueRow.value = attribute.value;
        title.text = attribute.name;
        column.clearSkillpacks();
        for ( var i in attribute.skillpacks ) {
            var component = Qt.createComponent("./../Element/Skillpack.qml");
            var object = component.createObject(
                            column,{
                            width: main.width - column.rightPadding - column.leftPadding,
                            skillpack: attribute.skillpacks[i]
                        });

            column.objects.push(object);
        }
        main.height = mainHeight();
    }

    function mainHeight() {
        var h = 0;
        var objCount = column.objects.length;

        if ( "undefined" !== typeof(title) )
            h += title.height
        if ( "undefined" !== typeof(valueRow) )
            h += valueRow.height
        if ( 0 < objCount ) {
            h += (objCount * column.objects[0].height)
            + ((objCount + 1) * 2) + 2;
        }
        return h;
    }
}
