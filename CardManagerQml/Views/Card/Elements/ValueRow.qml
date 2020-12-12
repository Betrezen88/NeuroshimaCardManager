import QtQuick 2.0
import QtQuick.Controls 2.12

Row {
    property alias name: _name.text
    property alias value: _value.text
    property int fontSize: 14

    id: main
    height: implicitHeight
    spacing: 5

    Text {
        id: _name
        font.pointSize: fontSize
        font.bold: true
    }

    Button {
        id: _down
        text: "-"
        font.pointSize: fontSize
        height: _name.height
        width: _name.height
    }

    Text {
        id: _value
        font.pointSize: fontSize
    }

    Button {
        id: _up
        text: "+"
        font.pointSize: fontSize
        height: _name.height
        width: _name.height
    }
}
