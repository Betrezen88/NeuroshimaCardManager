import QtQuick 2.12
import QtQuick.Controls 2.12

import core.edit.NSSkillEdit 1.0

Row {
    property NSSkillEdit skillEdit

    id: main
    spacing: 5
    padding: 3

    Text {
        id: _name
        text: "Skill name"
        height: _value.height
        verticalAlignment: Text.AlignVCenter
    }

    SpinBox {
        id: _value
        width: 140

        ToolTip.text: (up.hovered ? "-" : "+") + main.skillEdit.cost
        ToolTip.visible: up.hovered || down.hovered

        up.onPressedChanged: {
            if ( up.pressed ) {
                up.pressed = false
                main.skillEdit.increase();
            }
        }

        down.onPressedChanged: {
            if ( down.pressed ) {
                down.pressed = false
                main.skillEdit.decrease();
            }
        }
    }

    onSkillEditChanged: {
        if ( null == skillEdit )
            return

        _name.text = skillEdit.name
        _name.width = main.width - _value.width - main.spacing - main.padding*2
        _value.from = skillEdit.min
        _value.to = skillEdit.max
        _value.value = skillEdit.value
        _value.enabled = skillEdit.used && skillEdit.affordable

        skillEdit.affordableChanged.connect(function(){
            _value.enabled = main.skillEdit.used && main.skillEdit.affordable
        })
        skillEdit.valueChanged.connect(function(){
            _value.value = main.skillEdit.value
        })
    }
}
