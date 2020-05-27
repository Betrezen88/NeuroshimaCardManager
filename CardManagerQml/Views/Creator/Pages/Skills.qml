import QtQuick 2.0
import QtQuick.Controls 2.12

import "./../Elements"

Page {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Row {
            spacing: 10
            anchors.fill: parent
            anchors.margins: 5

            Column {
                id: column
                width: column.implicitWidth
                height: column.implicitHeight
                spacing: 5

                Rectangle {
                    id: skillPointsBox
                    width: 300
                    height: 70
                    color: "#ffffff"
                    radius: 10
                    visible: true
                    border.width: 2

                    Column {
                        id: column1
                        height: column1.implicitHeight
                        spacing: 5
                        anchors.fill: parent
                        anchors.margins: 5

                        Text {
                            id: label
                            width: column1.width
                            text: qsTr("Wolne Punkty Umiejętności")
                            font.bold: true
                            font.pointSize: 12
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Text {
                            id: generalPoints
                            text: qsTr("Ogólne: 0")
                            font.pointSize: 10
                        }

                        Text {
                            id: specializationPoints
                            text: qsTr("Specjalizacja: 0")
                            font.pointSize: 10
                        }
                    }
                }

                Attribute {
                    id: attribute1
                }

                Attribute {
                    id: attribute2
                }
            }

            Column {
                id: column2
                width: column2.implicitWidth
                height: column2.implicitHeight
                spacing: 5

                Attribute {
                    id: attribute3
                }

                Attribute {
                    id: attribute4
                }
            }

            Column {
                id: col
                width: col.implicitWidth
                height: col.implicitHeight
                spacing: 5

                Attribute {
                    id: attribute5
                }
            }
        }
    }
}
