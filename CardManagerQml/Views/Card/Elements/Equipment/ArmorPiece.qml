import QtQuick 2.12
import QtQuick.Controls 2.12

Row {
    property alias title: _title.text

    id: main
    
    Column {
        Rectangle {
            color: "#000"
            height: _title.implicitHeight
            width: main.width  - main.height

            Text {
                id: _title
                color: "#fff"
                anchors.centerIn: parent
                padding: 5
                font.pointSize: 12
            }
        }
        Rectangle {
            color: "#fff"
            border.color: "#000"
            border.width: 2
            height: _name.implicitHeight
            width: main.width - main.height

            Text {
                id: _name
                text: qsTr("Hełm Kewlarowy")
                font.pointSize: 10
                padding: 5
            }
        }
    }
    
    Rectangle {
        color: "#fff"
        border.color: "#000"
        border.width: 2
        width: main.height
        height: main.height

        Text {
            id: _value
            text: qsTr("0")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }
}
