import QtQuick 2.12
import QtQuick.Controls 2.12

import core.edit.NSReputationEdit 1.0

Row {
    property NSReputationEdit reputationData
    property alias titleWidth : _name.width

    id: main
    spacing: 5

    Text {
        id: _name
        text: "Miejsce"
        height: _value.height
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 12
        leftPadding: 5
    }

    SpinBox {
        id: _value

        ToolTip.text: (up.hovered ? "-" : "+") + main.reputationData.cost
        ToolTip.visible: up.hovered || down.hovered

        up.onPressedChanged: {
            if ( up.pressed ) {
                up.pressed = false
                main.reputationData.increase()
            }
        }

        down.onPressedChanged: {
            if ( down.pressed ) {
                down.pressed = false
                main.reputationData.decrease()
            }
        }
    }

    onReputationDataChanged: {
        _name.text = reputationData.name
        _value.from = reputationData.min
        _value.to = reputationData.max
        _value.value = reputationData.value

        reputationData.isAffordableChanged.connect(function(){
            _value.enabled = main.reputationData.isAffordable
        })
        reputationData.valueChanged.connect(function(){
            _value.value = main.reputationData.value
        })
        reputationData.maxChanged.connect(function(){
            _value.to = main.reputationData.max
        })
    }
}
