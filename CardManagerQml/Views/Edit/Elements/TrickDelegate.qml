import QtQuick 2.12
import QtQuick.Controls 2.15

import core.edit.NSTrickEdit 1.0

Rectangle {
    property bool heroTrick
    property NSTrickEdit trickData

    signal showDetails(NSTrickEdit trickData)

    id: main
    height: _title.height
    color: "lightgray"

    Text {
        id: _title
        text: main.text
        width: main.width
        padding: 10
        font.pointSize: 12
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap

        MouseArea {
            anchors.fill: parent
            onClicked: main.showDetails(main.trickData)
        }
    }

    onTrickDataChanged: {
        _title.text = trickData.name

        main.color = (!heroTrick && !trickData.canBeBougth())
                ? "#a24c4c" // red
                : (heroTrick && !trickData.isNew)
                  ? "lightgray"
                  : "#52a068" // green
    }
}
