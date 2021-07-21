import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSItem 1.0

Popup {
    property NSItem itemData

    id: main
    modal: true
    padding: 5

    ScrollView {
        id: _scrollView
        width: main.width - (main.padding*2)
        height: main.height - (main.padding*2)
        clip: true

        Column {
            anchors.fill: parent
            spacing: 10

            Text {
                id: _name
                width: _scrollView.width
                text: qsTr("Text")
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 15
            }

            Item {
                width: _scrollView.width
                height: _descBtn.height

                Text {
                    id: _description
                    width: parent.width - 5 - _descBtn.width
                    height: implicitHeight
                    text: qsTr("Text")
                    font.pixelSize: 12
                    wrapMode: Text.WordWrap
                }

                Button {
                    id: _descBtn
                    width: 50
                    height: 50
                    text: qsTr("<0>")
                    anchors.right: parent.right
                }
            }

            Row {
                width: implicitWidth
                height: implicitHeight
                spacing: 10

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Cena")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _price
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    Text {
                        width: implicitWidth
                        text: qsTr("Ilość")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _quantity
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                    spacing: 5
                }

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5
                    visible: itemData != null
                             && itemData.reputation > 0

                    Text {
                        width: implicitWidth
                        text: qsTr("Reputacja")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _reputation
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }
            }

            Text {
                width: _scrollView.width
                height: implicitHeight
                text: qsTr("Statystyki")
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 15
                visible: itemData != null
                          && ( itemData.type === "HANDWEAPON"
                          || itemData.type === "RANGEDWEAPON"
                          || itemData.type === "ARMOR"
                          || itemData.type === "SHIELD" )
            }

            Row {
                height: implicitHeight
                spacing: 5
                visible: itemData != null
                         && ( itemData.requirement != null
                         || itemData.penetration > 0
                         || itemData.durability != null )

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5
                    visible: itemData != null
                             && itemData.requirement != null

                    Text {
                        width: 100
                        text: qsTr("Wymagana Budowa")
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WordWrap
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _requirement
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5
                    visible: itemData != null
                             && itemData.durability != null

                    Text {
                        width: implicitWidth
                        text: qsTr("Wytrzymałość")
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WordWrap
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _durability
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Item {
                    width: _scrollView.width - _requirement.width
                           - _penetration.width - _durability.width
                           - (parent.spacing*2)
                    height: 1
                }

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5
                    visible: itemData != null
                             && itemData.penetration > 0

                    Text {
                        width: implicitWidth
                        text: qsTr("Przebicie")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _penetration
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }
            }

            Text {
                width: _scrollView.width
                height: implicitHeight
                text: qsTr("Bonusy do zręczności")
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 15
                visible: itemData != null && itemData.dexterityBonuses.length > 0
            }

            Row {
                height: implicitHeight
                spacing: 10
                visible: itemData != null && itemData.dexterityBonuses.length > 0

                Repeater {
                    id: _dexterityBonuses

                    delegate: Column {
                        width: implicitWidth
                        height: implicitHeight
                        spacing: 5

                        Text {
                            width: implicitWidth
                            text: qsTr(modelData.name)
                            horizontalAlignment: Text.AlignHCenter
                            font.bold: true
                            font.pointSize: 12
                        }

                        Text {
                            width: parent.width
                            text: modelData.value
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 15
                        }
                    }
                }
            }

            Row {
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData != null && itemData.damage.length > 0

                Text {
                    text: qsTr("Obrażenia:")
                    font.bold: true
                    font.pointSize: 12
                }

                Text {
                    id: _damage
                    text: qsTr("Draśnięcie")
                    font.pointSize: 12
                }
            }

            Row {
                width: implicitWidth
                height: implicitHeight
                spacing: 15
                visible: itemData != null
                         && ( itemData.bullet.length > 0
                             || itemData.magazine.length > 0
                             || itemData.ammunition > 0
                             || itemData.rateOfFire > 0
                             || itemData.jam.length > 0 )

                Column {
                    width: implicitWidth
                    height: 50
                    visible: itemData != null && itemData.bullet.length > 0

                    Text {
                        width: implicitWidth
                        text: qsTr("Nabój")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _bullet
                        width: parent.width
                        text: qsTr("9mm")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                    spacing: 5
                }

                Column {
                    width: implicitWidth
                    height: 50
                    spacing: 5
                    visible: itemData != null && itemData.magazine.length > 0

                    Text {
                        width: implicitWidth
                        text: qsTr("Magazynek")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _magazine
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    width: implicitWidth
                    height: 50
                    spacing: 5
                    visible: itemData != null && itemData.ammunition > 0

                    Text {
                        width: implicitWidth
                        text: qsTr("Amunicja")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _ammunition
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    width: implicitWidth
                    height: 50
                    spacing: 5
                    visible: itemData != null && itemData.rateOfFire > 0

                    Text {
                        id: text1
                        width: implicitWidth
                        text: qsTr("Szybkostrzelność")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _rateOfFire
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    width: implicitWidth
                    height: 50
                    spacing: 5
                    visible: itemData != null && itemData.jam.length > 0

                    Text {
                        width: implicitWidth
                        text: qsTr("Zacięcie")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _jam
                        width: parent.width
                        text: qsTr("16 - 20")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }
            }

            Flow {
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData != null && itemData.specials.length > 0

                Text {
                    text: qsTr("Reguły specjalne:")
                    font.bold: true
                    font.pointSize: 12
                }

                Repeater {
                    id: _specials
                    delegate: ItemSpecial {
                        name: modelData.name
                        description: modelData.description
                        visibleBtn: false
                    }
                }
            }

            Text {
                width: _scrollView.width
                height: implicitHeight
                text: qsTr("Lokacje")
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 15
                visible: itemData != null && itemData.locations.length > 0
            }

            Flow {
                width: _scrollView.width
                height: implicitHeight
                spacing: 10
                visible: itemData != null && itemData.locations.length > 0

                Repeater {
                    id: _locations

                    delegate: Column {
                        width: implicitWidth
                        height: implicitHeight
                        spacing: 5

                        Text {
                            width: implicitWidth
                            text: qsTr(modelData.location)
                            horizontalAlignment: Text.AlignHCenter
                            font.bold: true
                            font.pointSize: 12
                        }

                        Text {
                            width: parent.width
                            text: qsTr(modelData.armor + (modelData.cutting > 0 ? "/" + modelData.cutting : ""))
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 15
                        }
                    }
                }
            }

            Flow {
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData != null && itemData.penalties.length > 0

                Text {
                    text: qsTr("Kary/Bonusy:")
                    font.bold: true
                    font.pointSize: 12
                }

                Repeater {
                    id: _penalties

                    delegate: Penalty {
                        name: modelData.name
                        value: modelData.value
                        type: modelData.type
                    }
                }
            }

            Flow {
                property var objects: []
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData != null && itemData.features.length > 0

                Text {
                    text: qsTr("Cechy:")
                    font.bold: true
                    font.pointSize: 12
                }

                Repeater {
                    id: _features

                    delegate:  ItemSpecial {
                        name: modelData.name
                        description: modelData.description
                        visibleBtn: false
                    }
                }
            }
        }

        function createElement(elementName, parent, params) {
            var component = Qt.createComponent(elementName)
            var object = component.createObject(parent, params)
            return object
        }
    }

    onItemDataChanged: {
        if ( null == itemData )
            return

        _name.text = itemData.name
        _description.text = itemData.description
        _price.text = itemData.price
        _quantity.text = itemData.quantity
        _reputation.visible = itemData.reputation > 0
        _reputation.text = itemData.reputation

        if ( itemData.requirement != null )
            _requirement.text = itemData.requirement.value
        if ( itemData.durability != null )
            _durability.text = itemData.durability.current + "/" + itemData.durability.max
        _penetration.text = itemData.penetration

        if ( itemData.dexterityBonuses.length > 0 )
            _dexterityBonuses.model = itemData.dexterityBonuses

        if ( itemData.damage.length > 0 ) {
            var damage = itemData.damage
            if ( damage.length === 1 )
                _damage.text = damage[0]
            else {
                var dmg = ""
                for ( var d in damage ) {
                    dmg += parseInt(d)+1 + "s " + damage[d]
                            + ((d<damage.length-1) ? " / ": "")
                }
                _damage.text = dmg
            }
        }

        _bullet.text = itemData.bullet
        _magazine.text = itemData.magazine
        _ammunition.text = itemData.ammunition
        _jam.text = itemData.jam

        if ( itemData.specials.length > 0 )
            _specials.model = itemData.specials

        if ( itemData.locations.length > 0 )
            _locations.model = itemData.locations

        if ( itemData.penalties.length > 0 )
            _penalties.model = itemData.penalties

        if ( itemData.features.length > 0 )
            _features.model = itemData.features
    }
}
