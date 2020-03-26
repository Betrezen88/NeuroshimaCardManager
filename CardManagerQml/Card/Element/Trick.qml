import QtQuick 2.9
import QtQuick.Controls 2.5

Rectangle {
    property variant trick

    id: main

    height: name.height

    border.color: "#000"
    border.width: 2
    radius: 10

    ToolTip {
        id: toolip
        visible: false
    }

    Text {
        id: name
        padding: 5
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }

    MouseArea {
        anchors.fill: main
        onClicked: {
            if ( 0 < toolip.text.length )
                toolip.visible = !toolip.visible;
        }
    }

    onTrickChanged: {
        name.text = trick.name;
        toolip.text = trick.description;
    }
}
