﻿import QtQuick 2.0

Item {
    property var skill

    id: main

    height: title.height

    Row {
        anchors.fill: main
        anchors.leftMargin: 10
        spacing: 5

        Text {
            id: title
            text: main.skill.name
            textFormat: Text.PlainText
            wrapMode: Text.WordWrap
            font.pointSize: 10
            horizontalAlignment: Text.AlignLeft
            width: (main.width / 3)*1.4
        }

        Text {
            id: attribute
            text: shortAttribute(main.skill.attribute)
            textFormat: Text.PlainText
            wrapMode: Text.WordWrap
            font.pointSize: 10
            horizontalAlignment: Text.AlignLeft
            width: (main.width / 3)*0.3
        }

        Rectangle {
            width: main.width / 3
            height: title.height
            color: "#fff"
            border.color: "#000"
            border.width: 1
            radius: 5

            Text {
                id: number
                text: main.skill.value
                textFormat: Text.PlainText
                font.pointSize: 9
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
    }

    function shortAttribute(attributeName) {
        if ( "Budowa" === attributeName )
            return "(Bd)";
        if ( "Zręczność" === attributeName )
            return "(Zr)";
        if ( "Charakter" === attributeName )
            return "(Ch)";
        if ( "Percepcja" === attributeName )
            return "(Pe)";
        if ( "Spryt" === attributeName )
            return "(Sp)";
        return "(--)";
    }
}
