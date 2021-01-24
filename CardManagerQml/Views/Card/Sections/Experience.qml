import QtQuick 2.9
import QtQuick.Controls 2.12

Column {
    id: main
    spacing: 5

    Label {
        height: 30
        width: main.width
        text: "Doświadczenie"
        color: "#fff"
        font.pointSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        background: Rectangle {
            color: "#000"
            radius: 10
        }
    }

    Rectangle {
        width: main.width
        height: _row.implicitHeight
        border.width: 2
        border.color: "#000"
        radius: 10

        Row {
            id: _row
            width: implicitWidth
            height: implicitHeight
            spacing: 5
            padding: 5

            Column {
                height: implicitHeight
                spacing: 5

                Text {
                    text: qsTr("Zdobyte:")
                    font.pointSize: 12
                }

                Text {
                    text: qsTr("Wydane:")
                    font.pointSize: 12
                }

                Text {
                    text: qsTr("Dostępne:")
                    font.pointSize: 12
                    onImplicitWidthChanged: parent.width = implicitWidth
                }
            }

            Column {
                height: implicitHeight
                spacing: 5

                Text {
                    id: _gathered
                    text: qsTr("0")
                    font.pointSize: 12
                }

                Text {
                    id: _spended
                    text: qsTr("0")
                    font.pointSize: 12
                }

                Text {
                    id: _available
                    text: qsTr("0")
                    font.pointSize: 12
                }
            }
        }
    }
}
