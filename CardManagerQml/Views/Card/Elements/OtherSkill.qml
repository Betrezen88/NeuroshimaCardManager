import QtQuick 2.9
import QtQuick.Controls 2.12

Row {
    property var skill

    id: main
    spacing: 5
    leftPadding: 5
    rightPadding: 5
    height: _used.height

    CheckBox {
        id: _used
        width: 30
        height: 30
        onCheckedChanged: main.skill.used = checked
    }

    Text {
        id: _title
        text: main.skill.name
        width: main.width - _used.width - _attribute.width
               - _rect.width - (main.spacing * 4) - 10
        height: _used.height
        textFormat: Text.PlainText
        wrapMode: Text.WordWrap
        font.pointSize: 10
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: _attribute
        width: implicitWidth
        height: _used.height
        textFormat: Text.PlainText
        wrapMode: Text.WordWrap
        font.pointSize: 10
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Rectangle {
        id: _rect
        width: 60
        height: _used.height
        color: "#fff"
        border.color: "#000"
        border.width: 1
        radius: 5

        Text {
            id: _value
            text: main.skill.value
            textFormat: Text.PlainText
            font.pointSize: 9
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
    }

    onSkillChanged: {
        _title.text = skill.name
        _attribute.text = shortAttribute(skill.attribute)
        _value.text = skill.value
        _used.checked = skill.used
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
