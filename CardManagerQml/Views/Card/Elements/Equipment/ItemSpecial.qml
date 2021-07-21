import QtQuick 2.9
import QtQuick.Controls 2.12

Row {
    property alias name: _name.text
    property alias description: _description.text
    property alias visibleBtn: _removeBtn.visible

    id: main
    spacing: 5

    Text {
        id: _name
        font.pointSize: 12
        verticalAlignment: Text.AlignVCenter

        MouseArea {
            anchors.fill: parent
            onClicked: { _tooltip.open() }
        }

        Popup {
            id: _tooltip
            padding: 5
            width: (_description.implicitWidth > 300)
                   ? 300 : _description.implicitWidth
            height: _description.implicitHeight + 10

            y: parent.y - height

            Text {
                id: _description
                width: _tooltip.width - (_tooltip.padding*5)
                wrapMode: Text.WordWrap
            }
        }
    }

    Button {
        id: _removeBtn
        height: _name.height
        width: _name.height
        text: "X"
        visible: !main.removable
        onClicked: main.destroy()
    }

    function special() {
        return {
            NAME: _name.text,
            DESCRIPTION: _description.text
        }
    }
}
