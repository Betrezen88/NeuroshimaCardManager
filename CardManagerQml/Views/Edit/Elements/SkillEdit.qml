﻿import QtQuick 2.12
import QtQuick.Controls 2.12

import core.NSSkillMod 1.0

Row {
    property NSSkillMod skillMod

    id: main
    spacing: 5

    Text {
        id: _name
        text: "Skill name"
        height: _value.height
        verticalAlignment: Text.AlignVCenter
    }

    SpinBox {
        id: _value
    }

    onSkillModChanged: {
        if ( null == skillMod )
            return

        _name.text = skillMod.skill.name
        _value.from = skillMod.min
        _value.to = skillMod.max
        _value.enabled = skillMod.skill.used
    }
}
