import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import core.NSItem 1.0

Popup {
    property string name

    id: main

    signal accept()

    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Text {
            text: "Czy na pewno chcesz wyrzucić " + main.name + "?"
            font.pointSize: 12
            width: main.width
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 5

            Item {
                Layout.fillWidth: true
                height: 1
            }

            Button {
                id: _yesBtn
                text: "Tak"
                onClicked: {
                    main.accept()
                    main.close()
                }
            }
            Button {
                id: _noBtn
                text: "Nie"
                onClicked: main.close()
            }
        }
    }
}
