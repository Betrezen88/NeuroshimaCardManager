import QtQuick 2.9
import QtQuick.Controls 2.12

import core.view.NSOtherSkill 1.0

Row {
    property NSOtherSkill skill

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
            textFormat: Text.PlainText
            font.pointSize: 9
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
    }

    onSkillChanged: {
        _title.text = (skill != null) ? skill.name : ""
        _attribute.text = (skill != null) ? skill.attributeShort : ""
        _value.text = (skill != null) ? skill.value : 0
        _used.checked = (skill != null) ? skill.used : false
    }
}
