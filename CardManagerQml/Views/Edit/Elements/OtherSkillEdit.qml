import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSOtherSkillMod 1.0

Row {
    property bool newSkill: false
    property NSOtherSkillMod otherSkillMod

    id: main

    Button {
        id: _removeBtn
        icon.source: "qrc:/icon/resources/icons/close.svg"
        width: _removeBtn.height
        visible: newSkill
    }

    Text {
        id: _name
        width: main.width - _value.width - _attribute.implicitWidth
               - (main.newSkill ? _removeBtn.width : 0)
        height: _value.height
        leftPadding: (main.newSkill ? 2 : 0)
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: _attribute
        rightPadding: 5
        height: _value.height
        verticalAlignment: Text.AlignVCenter
    }

    SpinBox { id: _value }

    onOtherSkillModChanged: {
        if ( null == otherSkillMod )
            return

        _name.text = otherSkillMod.otherSkill.name
        _attribute.text = shortAttribute(otherSkillMod.otherSkill.attribute)
        _value.value = otherSkillMod.otherSkill.value
        _value.from = otherSkillMod.min
        _value.to = otherSkillMod.max
        _value.enabled = otherSkillMod.otherSkill.used
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
