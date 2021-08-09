import QtQuick 2.9
import QtQuick.Controls 2.12

Popup {
    property var attributesModel

    signal buyNewSkill(string name, string attribute)

    id: main
    modal: true

    Column {
        spacing: 5

        Text {
            text: "Kup nową umiejętność"
            font.bold: true
            font.pointSize: 14
            width: _skillName.width + 5 + _skillAttribute.width
            horizontalAlignment: Text.AlignHCenter
        }

        Row {
            spacing: 5

            TextField {
                id: _skillName
                placeholderText: "Nazwa umiejętności"
            }

            ComboBox { id: _skillAttribute }
        }

        Row {
            spacing: 5

            Item {
                height: 1
                width: _skillName.width + _skillAttribute.width + 5
                       - _cancelBtn.width - _buyBtn.width - (2*5)
            }

            Button {
                id: _cancelBtn
                text: "Anuluj"
                onClicked: main.close()
            }

            Button {
                id: _buyBtn
                text: "Kup"
                onClicked:  {
                    main.buyNewSkill(_skillName.text, _skillAttribute.currentText)
                    main.close()
                }
            }
        }
    } // Column

    onClosed: {
        _skillName.clear()
        _skillAttribute.currentIndex = 0
    }

    onAttributesModelChanged: _skillAttribute.model = attributesModel
}
