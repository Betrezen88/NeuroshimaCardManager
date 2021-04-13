import QtQuick 2.12
import QtQuick.Controls 2.12

import core.NSItem 1.0

Row {
    property alias title: _title.text
    property NSItem item: null
    property string location

    id: main
    height: implicitHeight

    signal unequip(NSItem item)

    Rectangle {
        width: main.width
        height: _column.height
        color: "#000000"

        Column {
            id: _column
            width: main.width
            height: implicitHeight
            spacing: 5
            padding: 5

            Row {
                width: _column.width - (_column.padding*2)
                height: implicitHeight
                spacing: 5

                RoundButton {
                    id: _menuBtn
                    width: 30
                    height: 30
                    text: "..."
                    font.bold: true
                    font.pointSize: 12
                    onClicked: {
                        if ( null === main.item )
                            return
                        _menu.open()
                    }

                    Menu {
                        id: _menu

                        MenuItem {
                            text: "Opis"
                        }
                        MenuItem {
                            text: "Do plecaka"
                            onClicked: {
                                main.unequip(main.item)
                                main.item = null
                            }
                        }
                        MenuItem {
                            text: "Zmień wytrzymałość"
                            onClicked: {
                                if ( null !== item )
                                    _durabilityPopup.open()
                            }
                        }
                        MenuItem {
                            text: "Wyrzuć"
                        }
                    }
                }

                Text {
                    id: _title
                    width: parent.width - (parent.spacing * 2) - _value.width - _menuBtn.width
                    height: _menuBtn.height
                    color: "#ffffff"
                    text: qsTr("Lewa ręka")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 14
                }

                Rectangle {
                    width: 60
                    height: _menuBtn.height
                    color: "#ffffff"
                    border.width: 2

                    Text {
                        id: _value
                        text: qsTr("0")
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                        font.pointSize: 14
                    }
                }
            }

            Rectangle {
                width: _column.width - _column.leftPadding - _column.rightPadding
                height: _name.height
                color: "#ffffff"

                Text {
                    id: _name
                    text: qsTr("")
                    padding: 5
                    font.pointSize: 12
                }
            }

            Row {
                width: _column.width - _column.leftPadding - _column.rightPadding
                height: implicitHeight
                spacing: 5

                Rectangle {
                    width: parent.width - parent.spacing - _durabilityRow.width
                    height: _durability.height
                    color: "#ffffff"
                    Text {
                        text: qsTr("Wytrzymałość")
                        padding: 5
                        font.pointSize: 12
                    }
                }

                Rectangle {
                    width: _durabilityRow.width
                    height: _durability.height
                    color: "#ffffff"

                    Row {
                        id: _durabilityRow
                        width: implicitWidth
                        height: implicitHeight
                        rightPadding: 5
                        leftPadding: 5
                        spacing: 0

                        Text {
                            id: _durability
                            text: qsTr("-")
                            padding: 5
                            font.pointSize: 12
                        }

                        Text {
                            text: qsTr("/")
                            padding: 5
                            font.pointSize: 12
                        }

                        Text {
                            id: _maxDurability
                            text: qsTr("-")
                            padding: 5
                            font.pointSize: 12
                        }
                    }
                }
            }
        }
    }

    Popup {
        id: _durabilityPopup
        anchors.centerIn: parent
        modal: true
        width: 300

        Column {
            spacing: 5
            anchors.fill: parent

            Text {
                text: "Zmień wytrzymałość"
                width: _durabilityPopup.width
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                text: (null !== item) ? item.name : ""
                width: _durabilityPopup.width
            }
            SpinBox {
                id: _newDurability
                from: 0
                to: (null !== item) ? item.maxDurability : 0
                value: (null !== item) ? item.currentDurability : 0
            }
            Row {
                spacing: 5
                width: _durabilityPopup.width
                Button {
                    text: "Zmień"
                    onClicked: {
                        item.setCurrentDurability(_newDurability.value)
                        _durabilityPopup.close()
                    }
                }
                Button {
                    text: "Anuluj"
                    onClicked: _durabilityPopup.close()
                }
            }
        }
    }

    onItemChanged: {
        _name.text = ( null !== item ) ? item.name : ""
        _maxDurability.text = ( null !== item ) ? item.maxDurability : "-"
        _durability.text = ( null !== item ) ? item.currentDurability : "-"

        if ( null !== item ) {
            item.currentDurabilityChanged.connect(function(){
                _durability.text = item.currentDurability
            })
        }

        var locations = ( null !== item ) ? item.locations : []
        _value.text = locations.hasOwnProperty(main.getLocation(_title.text))
                            ? locations[main.getLocation(_title.text)]
                            : 0
    }

    function getLocation(title) {
        if ( "Głowa" === title )
            return "HEAD"
        else if ( "Tułów" === title )
            return "TORSO"
        else if ( "Prawa Ręka" === title )
            return "RIGHTHAND"
        else if ( "Lewa Ręka" === title )
            return "LEFTHAND"
        else if ( "Prawa Noga" === title )
            return "RIGHTLEG"
        else if ( "Lewa Noga" === title )
            return "LEFTLEG"
        else
            return ""
    }
}
