import QtQuick 2.12
import QtQuick.Controls 2.12

Row {
    id: main
    spacing: 5

    Text {
        id: _name
        text: "Miejsce"
        height: _value.height
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 12
    }

    SpinBox {
        id: _value
    }
}
