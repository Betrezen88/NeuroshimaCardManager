import QtQuick 2.12
import QtQuick.Controls 2.12

import core.edit.NSAttributeEdit 1.0

Column {
    property NSAttributeEdit attributeEdit

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

                ToolTip.text: (up.hovered ? "-" : "+") + main.attributeEdit.cost
                ToolTip.visible: up.hovered || down.hovered

                up.onPressedChanged: {
                    if ( up.pressed ) {
                        up.pressed = false
                        main.attributeEdit.increase()
                    }
                }
                down.onPressedChanged: {
                    if ( down.pressed ) {
                        down.pressed = false
                        main.attributeEdit.decrease()
                    }
                }
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
                skillpackEdit: modelData
            }
        }
    }

    onAttributeEditChanged: {
        if ( null == attributeEdit )
            return

        _name.text = attributeEdit.name
        _value.from = attributeEdit.min
        _value.to = attributeEdit.max
        _value.value = attributeEdit.value
        _skillpacks.model = attributeEdit.skillpacks
        _value.enabled = attributeEdit.affordable

        attributeEdit.affordableChanged.connect(function(){
            _value.enabled = main.attributeEdit.affordable
        })
        attributeEdit.valueChanged.connect(function(){
            _value.value = main.attributeEdit.value
        })
    }
}
