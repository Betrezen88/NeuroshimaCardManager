import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSItem 1.0

Popup {
    property NSItem itemData

    id: main
    modal: true
    padding: 5

    ScrollView {
        height: main.height - 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: main.width - 10
        clip: true

        Column {
            spacing: 5

            Label {
                id: _name
                width: main.width - (main.padding*2)
                text: "Item Name"
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 12
            }

            Row {
                id: _box
                width: main.width - (main.padding*2)
                height: _button.height
                spacing: 5

                Button {
                    id: _button
                    height: 40
                    text: "<O>"
                    onClicked: _box.height = ( _box.height == _button.height )
                               ? _description.implicitHeight : _button.height
                }

                Text {
                    id: _description
                }
            }
        } // Column
    }

    onItemDataChanged: {
        _name.text = itemData.name
        _description.text = itemData.description
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
