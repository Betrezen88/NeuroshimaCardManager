import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSStatsSource 1.0

Page {
    property NSStatsSource dataSource

    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            id: column
            anchors.fill: parent
            anchors.margins: 5
            spacing: 5

            Row {
                id: row
                width: column.width
                height: row.implicitHeight
                spacing: 5

                Text {
                    id: label
                    height: specializationsList.height
                    text: "Specjalizacja:"
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 14
                }

                ComboBox {
                    id: specializationsList
                    width: 200
                    textRole: 'name'
                    onCurrentIndexChanged: {
                        var item = main.dataSource.specializations[currentIndex]
                        description.text = item.description
                    }
                }
            }

            Text {
                id: description
                width: main.width - column.anchors.margins * 2
                text: qsTr("Opis")
                font.pointSize: 12
                wrapMode: Text.WordWrap
            }

            Text {
                id: extra
                width: main.width - column.anchors.margins * 2
                text: qsTr("Dodatkowy opis")
                wrapMode: Text.WordWrap
                font.pointSize: 12
            }
        }
    }

    onDataSourceChanged: {
        specializationsList.model = main.dataSource.specializations
    }
}
