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

    SpinBox { id: _value }

    onReputationDataChanged: {
        _name.text = reputationData.name
        _value.from = reputationData.min
        _value.to = reputationData.max
        _value.value = reputationData.value
    }
}
