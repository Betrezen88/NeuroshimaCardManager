import QtQuick 2.9

Row {
    property alias label: _label.text
    property alias wounds: _wounds.text

    id: main
    height: implicitHeight
    spacing: 5

    Text {
        id: _label
        width: 83
        height: _wounds.height
        text: qsTr("Głowa:")
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 12
    }

    Rectangle {
        width: main.width - _label.width - main.spacing
        height: _wounds.implicitHeight
        color: "#ffffff"
        radius: 5
        border.width: 2
        Text {
            id: _wounds
            text: qsTr("")
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            padding: 5
            font.pointSize: 12
        }
    }
}
