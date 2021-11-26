import QtQuick 2.12
import QtQuick.Controls 2.12

import core.edit.NSTrickEdit 1.0

Popup {
    property NSTrickEdit trickData
    property bool buyBtnVisible: true

    signal buyTrick(NSTrickEdit trickData)
    signal sellTrick(NSTrickEdit trickData)

    id: main
    padding: 5
    modal: true

    Text {
        id: _title
        width: main.width
        text: qsTr("Trick Name")
        anchors.top: parent.top
        horizontalAlignment: Text.AlignHCenter
        anchors.topMargin: 0
        font.bold: true
        font.pointSize: 16
    }

    ScrollView {
        clip: true
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: _title.bottom
        anchors.bottom: _buttonRow.top
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        Column {
            width: parent.width
            height: implicitHeight
            spacing: 5

            Row {
                width: main.width - (main.padding*4)
                height: implicitHeight
                spacing: 5

                Text {
                    id: _reqL
                    text: qsTr("Wymagania:")
                    font.bold: true
                    font.pointSize: 12
                }

                Flow {
                    width: parent.width - _reqL.width - parent.spacing
                    height: implicitHeight
                    spacing: 5

                    Repeater {
                        id: _requirements
                        delegate: Text {
                            text: modelData.name + " " + modelData.value
                                  + ( (index < _requirements.count-1)
                                    ? ((modelData.optional) ? " lub " : ",")
                                    : "" )
                            font.pointSize: 12
                        }
                    }
                }
            }

            Row {
                width: main.width - (main.padding*4)
                height: implicitHeight
                spacing: 5
                Text {
                    id: _descL
                    text: qsTr("Opis:")
                    font.pointSize: 12
                    font.bold: true
                }

                Text {
                    id: _description
                    width: parent.width - _descL.width - parent.spacing
                    text: qsTr("Opis")
                    wrapMode: Text.WordWrap
                    font.italic: true
                    font.bold: false
                    font.pointSize: 12
                }
            }

            Row {
                width: main.width - (main.padding*4)
                height: implicitHeight
                Text {
                    id: _actL
                    text: qsTr("Działanie:")
                    font.bold: true
                    font.pointSize: 12
                }

                Text {
                    id: _action
                    width: parent.width - _actL.width - parent.spacing
                    text: qsTr("Działanie")
                    wrapMode: Text.WordWrap
                    font.bold: false
                    font.pointSize: 12
                }
                spacing: 5
            }
        }
    }

    Row {
        id: _buttonRow
        width: main.width - (main.padding*2)
        height: implicitHeight
        anchors.bottom: parent.bottom
        spacing: 5

        Item {
            width: parent.width - (parent.spacing*2)
                   - _closeBtn.width - _buyBtn.width
            height: 1
        }

        Button {
            id: _closeBtn
            text: qsTr("Zamknij")
            onClicked: main.close()
        }

        Button {
            id: _buyBtn
            text: qsTr("Kup")
            ToolTip.visible: hovered
            ToolTip.text: "-" + ((main.trickData != null) ? main.trickData.cost : 0)
            onClicked: {
                main.buyTrick(main.trickData)
                main.close()
            }
        }

        Button {
            id: _sellBtn
            text: qsTr("Sprzedaj")
            ToolTip.visible: hovered
            ToolTip.text: "+" + ((main.trickData != null) ? main.trickData.cost : 0)
            onClicked: {
                main.sellTrick(main.trickData)
                main.close()
            }
        }
    }

    onTrickDataChanged: {
        if ( trickData == null )
            return

        _title.text = trickData.name
        _requirements.model = trickData.requirements
        _description.text = trickData.description
        _action.text = trickData.action
        _sellBtn.visible = trickData.isNew
    }

    onBuyBtnVisibleChanged: _buyBtn.visible = buyBtnVisible
}
