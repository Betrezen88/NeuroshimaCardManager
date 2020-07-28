import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSStatsCreator 1.0

Rectangle {
    property NSStatsCreator statsCreator

    id: main
    height: column.implicitHeight

    border {
        width: 2
        color: "#000"
    }
    radius: 5

    Column {
        id: column
        anchors.fill: parent
        anchors.margins: 5
        spacing: 5

        Label {
            id: label1
            width: main.width
            text: qsTr("Inne Umiejętnosci")
            font.bold: true
            font.pointSize: 14
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            id: button
            width: main.width - column.anchors.margins * 2
            text: qsTr("Kup Umiejętnosć")
            font.pointSize: 10

            onClicked: skillCreationDialog.open()
        }

        ListView {
            id: listView
            spacing: 5
            width: main.width - column.anchors.margins * 2
            height: 400
            clip: true
            delegate: OtherSkill {
                width: listView.width
                name: model.name
                attribute: model.attribute

                onRemove: statsCreator.removeOtherSkill(name)
            }

            model: statsCreator.otherSkills
        }

        Dialog {
            id: skillCreationDialog
            title: "Dodaj inną umiejętność"
            width: main.width - 10

            Column {
                anchors.fill: parent
                spacing: 5

                TextField {
                    id: skillName
                    width: skillCreationDialog.width - 20
                    placeholderText: "Nazwa umiejętności"
                }
                ComboBox {
                    id: attribute
                    width: skillCreationDialog.width - 20
                    model: [ "Bd", "Zr", "Ch", "Pe", "Sp" ]
                }

                Row {
                    spacing: 5
                    width: skillCreationDialog.width - 20

                    Button {
                        text: "Dodaj"
                        width: (parent.width / 2) - 2
                        enabled: skillName.length > 0
                        onClicked: {
                            statsCreator.addOtherSkill(skillName.text,
                                                       attribute.currentText,
                                                       0)
                            skillCreationDialog.close()
                        }
                    }
                    Button {
                        text: "Anuluj"
                        width: (parent.width / 2) - 2
                        onClicked: {
                            skillCreationDialog.close()
                        }
                    }
                }
            }

            onClosed: {
                skillName.clear()
                attribute.currentIndex = 0
            }
        }

    }
}
