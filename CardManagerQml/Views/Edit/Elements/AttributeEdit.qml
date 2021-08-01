import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSAttributeMod 1.0

Column {
    property NSAttributeMod attributeMod

    id: main

    Text {
        id: _name
    }

    SpinBox {
        id: _value
    }

    Column {
        spacing: 5

        Repeater {
            id: _skillpacks
            delegate: SkillpackEdit {
                width: main.width
                skillpackMod: modelData
            }
        }
    }

    onAttributeModChanged: {
        if ( null == attributeMod )
            return

        _name.text = attributeMod.attribute.name
        _value.from = attributeMod.min
        _value.to = attributeMod.max
        _value.value = attributeMod.attribute.value
        _skillpacks.model = attributeMod.skillpacks
    }
}
