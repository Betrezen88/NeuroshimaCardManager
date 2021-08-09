import QtQuick 2.12
import QtQuick.Controls 2.12

import core.NSAttributeMod 1.0

Column {
    property NSAttributeMod attributeMod

    id: main
    spacing: 5

    Rectangle {
        width: main.width
        height: _value.height + 4
        color: "#000"
        radius: 5

        Row {
            padding: 2

            Text {
                id: _name
                width: main.width - _value.width - 4
                height: _value.height
                text: "Attribute Name"
                font.bold: true
                font.pointSize: 16
                color: "#fff"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: _value
                padding: 1
            }
        }
    }

    Flow {
        width: main.width
        spacing: 5

        Repeater {
            id: _skillpacks
            delegate: SkillpackEdit {
                width: 280 /*main.width*/
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
