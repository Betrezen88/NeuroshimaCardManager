import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "../"

Popup {
    property alias title: _title.text

    id: main
    height: implicitHeight
    width: 300
    padding: 5

    signal sendData(string name, string description)

    ColumnLayout {
        spacing: 5
        anchors.fill: parent

        Label {
            id: _title
            Layout.fillWidth: true
            font.pointSize: 12
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
        }

        TextField {
            id: _name
            Layout.fillWidth: true
            placeholderText: "Nazwa"
        }
        Rectangle {
            Layout.fillWidth: true
            height: 80
            color: "#ffffff"
            border.color: "#000"
            border.width: 1

            ScrollView {
                width: parent.width
                height: parent.height

                TextArea {
                    id: _description
                    width: parent.width
                    placeholderText: "Opis"
                    padding: 5
                    wrapMode: Text.WordWrap
                }
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignRight
            Layout.fillWidth: true
            spacing: 5
            Button {
                Layout.alignment: Qt.AlignRight
                text: "Anuluj"
                onClicked: main.close()
            }
            Button {
                Layout.alignment: Qt.AlignRight
                text: "Dodaj"
                onClicked: {
                    if ( _name.text.length === 0
                        || _description.text.length === 0 )
                        return

                    main.sendData(_name.text, _description.text)
                    main.close()
                }
            }
        }
    } // Column

    onClosed: {
        _name.clear()
        _description.clear()
    }
}
