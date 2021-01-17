import QtQuick 2.0
import QtQuick.Controls 2.12

Popup {
    id: main
    padding: 5
    modal: true

    signal sendPenalty(int value, string name, string type)

    Column {
        width: 200
        height: 400
        spacing: 5

        Text {
            width: main.width - (main.padding*2)
            text: qsTr("Bonus / Kara")
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 13
        }

        Row {
            width: implicitWidth
            height: implicitHeight
            spacing: 5

            SpinBox {
                id: _value
                from: -100
                to: 100
                editable: true
            }

            TextField {
                id: _name
                placeholderText: qsTr("Nazwa")
            }

            ComboBox {
                id: _type
                model: [ "Test", "Atrybut" ]
            }
        }

        Row {
            width: main.width - (main.padding*2)
            height: implicitHeight
            layoutDirection: Qt.RightToLeft
            spacing: 5

            Button {
                text: qsTr("Dodaj")
                onClicked: {
                    main.sendPenalty(_value.value, _name.text, _type.currentText)
                    main.close()
                }
            }

            Button {
                text: qsTr("Anuluj")
                onClicked: main.close()
            }
        }
    }

    onClosed: {
        _value.value = 0
        _name.clear()
        _type.currentIndex = 0
    }
}
