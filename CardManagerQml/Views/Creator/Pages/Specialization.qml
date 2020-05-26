import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            id: column
            anchors.fill: parent
            anchors.margins: 5

            Row {
                id: row
                width: column.width
                height: row.implicitHeight
                spacing: 5

                Text {
                    id: label
                    height: comboBox.height
                    text: "Specjalizacja:"
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 14
                }

                ComboBox {
                    id: comboBox
                    width: 200
                }
            }

            Text {
                id: description
                width: column.width
                text: qsTr("Opis")
                font.pointSize: 10
                wrapMode: Text.WordWrap
            }
        }

    }
}
