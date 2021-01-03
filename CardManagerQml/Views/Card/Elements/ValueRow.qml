import QtQuick 2.0
import QtQuick.Controls 2.12

Row {
    property alias name: _name.text
    property string value: _value.text
    property int fontSize: 14

    id: main
    height: implicitHeight
    spacing: 5

    Text {
        id: _name
        font.pointSize: fontSize
        font.bold: true
    }

    SpinBox {
        id: _value2
        height: _name.height
        from: 0
        to: 4
    }
}
