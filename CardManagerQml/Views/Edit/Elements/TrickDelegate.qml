import QtQuick 2.12
import QtQuick.Controls 2.15

import core.edit.NSTrickEdit 1.0

Rectangle {
    property NSTrickEdit trickData
    property bool buyBtnVisible: true

    signal showDetails(NSTrickEdit trickData)

    id: main
    height: _buyBtn.height
    color: "lightgray"

    Row {

        Button {
            id: _buyBtn
            text: "+"
            width: height
            onClicked: {
                console.log("Trick bought.")
            }
        }

        Text {
            id: _title
            text: main.text
            height: _buyBtn.height
            width: main.width - ((buyBtnVisible) ? _buyBtn.width : _removeBtn.width)
            leftPadding: 5
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap

            MouseArea {
                anchors.fill: parent
                onClicked: main.showDetails(main.trickData)
            }
        }

        Button {
            id: _removeBtn
            text: "-"
            width: height
            onClicked: {
                console.log("Trick removed.")
            }
        }
    }

    onTrickDataChanged: {
        _title.text = trickData.name
        _buyBtn.enabled = trickData.meetsRequirements

        trickData.meetsRequirementsChanged.connect(function(){
            _buyBtn.enabled = main.trickData.meetsRequirements
        })
    }

    onBuyBtnVisibleChanged: {
        _buyBtn.visible = buyBtnVisible
        _removeBtn.visible = !buyBtnVisible
    }
}
