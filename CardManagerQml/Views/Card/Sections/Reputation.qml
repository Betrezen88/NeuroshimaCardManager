import QtQuick 2.12
import QtQuick.Controls 2.12

Popup {
    property var model

    id: main
    width: 150
    height: 400
    padding: 5
    closePolicy: Popup.CloseOnPressOutsideParent

    Column {
        width: implicitWidth
        height: implicitHeight
        spacing: 5

        Text {
            id: _title
            width: main.width - (main.padding*2)
            text: qsTr("Twoja Reputacja")
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.pointSize: 16
        }

        ScrollView {
            id: _scrollView
            width: main.width - (main.padding*2)
            height: main.height - (main.padding*2) - 5 - _title.height
            clip: true
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn

            Column {
                width: parent.width
                height: implicitHeight
                spacing: 5

                Repeater {
                    id: _places
                    delegate: Text {
                        width: parent.width
                        text: modelData.name + ": " + modelData.value
                        font.pointSize: 12
                    }
                }
            }
        }
    }

    onModelChanged: _places.model = model
}
