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
                    visible: itemData !== null
                             && itemData.hasStat("REPUTATION")

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
                visible: itemData !== null
                          && ( itemData.type === NSItem.HANDWEAPON
                          || itemData.type === NSItem.RANGEDWEAPON
                          || itemData.type === NSItem.ARMOR
                          || itemData.type === NSItem.SHIELD )
            }

            Row {
                height: implicitHeight
                spacing: 5
                visible: itemData !== null
                         && ( itemData.hasStat("REQUIEREMENT")
                         || itemData.hasStat("PENETRATION")
                         || itemData.hasStat("DURABILITY"))

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5
                    visible: itemData !== null
                             && itemData.hasStat("REQUIREMENT")

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
                    visible: itemData !== null
                             && itemData.hasStat("DURABILITY")

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
                    visible: itemData !== null
                             && itemData.hasStat("PENETRATION")

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
                visible: itemData !== null && itemData.hasStat("BONUS")
            }

            Row {
                height: implicitHeight
                spacing: 10
                visible: itemData !== null
                         && itemData.hasStat("BONUS")

                Column {
                    id: _attackC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Atak")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _attack
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _defenceC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Obrona")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _defence
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _iniciativeC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Inicjatywa")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _iniciative
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _groupC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Grupa")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _group
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }
            }

            Row {
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData !== null &&
                         itemData.hasStat("DAMAGE")

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
                visible: itemData !== null
                         && ( itemData.hasStat("BULLET")
                             || itemData.hasStat("MAGAZINE")
                             || itemData.hasStat("AMMUNITION")
                             || itemData.hasStat("RATEOFFIRE")
                             || itemData.hasStat("JAM") )

                Column {
                    width: implicitWidth
                    height: 50
                    visible: itemData !== null
                             && itemData.hasStat("BULLET")

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
                    visible: itemData !== null
                             && itemData.hasStat("MAGAZINE")

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
                    visible: itemData !== null
                             && itemData.hasStat("AMMUNITION")

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
                    visible: itemData !== null
                             && itemData.hasStat("RATEOFFIRE")

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
                    visible: itemData !== null
                             && itemData.hasStat("JAM")

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
                id: _specials
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData !== null
                         && itemData.hasStat("SPECIAL")

                Text {
                    text: qsTr("Reguły specjalne:")
                    font.bold: true
                    font.pointSize: 12
                }
            }

            Text {
                width: _scrollView.width
                height: implicitHeight
                text: qsTr("Lokacje")
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 15
                visible: itemData !== null
                         && itemData.hasStat("LOCATIONS")
            }

            Flow {
                width: _scrollView.width
                height: implicitHeight
                spacing: 10
                visible: itemData !== null
                         && itemData.hasStat("LOCATIONS")

                Column {
                    id: _headC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Głowa")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _head
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _leftHandC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Lewa ręka")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _leftHand
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _rightHandC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Prawa ręka")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _rightHand
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _torsoC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Tułów")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _torso
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _leftLegC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Lewa noga")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _leftLeg
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }

                Column {
                    id: _rightLegC
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: implicitWidth
                        text: qsTr("Prawa noga")
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.pointSize: 12
                    }

                    Text {
                        id: _rightLeg
                        width: parent.width
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                    }
                }
            }

            Flow {
                property var objects: []
                id: _penalties
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData !== null
                         && itemData.hasStat("PENALTIES")

                Text {
                    text: qsTr("Kary/Bonusy:")
                    font.bold: true
                    font.pointSize: 12
                }
            }

            Flow {
                property var objects: []
                id: _features
                width: _scrollView.width
                height: implicitHeight
                spacing: 5
                visible: itemData !== null
                         && itemData.hasStat("FEATURES")

                Text {
                    text: qsTr("Cechy:")
                    font.bold: true
                    font.pointSize: 12
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
        _name.text = itemData.name
        _description.text = itemData.description
        _price.text = itemData.price
        _quantity.text = itemData.quantity
        _reputation.visible = itemData.hasStat("REPUTATION")
        _reputation.text = itemData.reputation

        _requirement.text = itemData.requiredBody
        _durability.text = itemData.durability
        _penetration.text = itemData.penetration

        if ( itemData.hasStat("BONUS") ) {
            var bonus = itemData.dexBonus
            _attackC.visible = bonus.hasOwnProperty("ATTACK")
            _attack.text = bonus["ATTACK"]
            _defenceC.visible = bonus.hasOwnProperty("DEFENCE")
            _defence.text = bonus["DEFENCE"]
            _iniciativeC.visible = bonus.hasOwnProperty("INICIATIVE")
            _iniciative.text = bonus["INICIATIVE"]
            _groupC.visible = bonus.hasOwnProperty("GROUP")
            _group.text = bonus["GROUP"]
        }

        if ( itemData.hasStat("DAMAGE") ) {
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

        if ( itemData.hasStat("SPECIAL") ) {
            for ( var s in itemData.special ) {
                var spec = itemData.special[s]
                _scrollView.createElement( "ItemSpecial.qml",
                                          _specials,
                                          {
                                              name: spec.name,
                                              description: spec.description,
                                              visibleBtn: false
                                          }
                                        )
            }
        }

        if ( itemData.hasStat("LOCATIONS") ) {
            var locations = itemData.locations

            _headC.visible = locations.hasOwnProperty("HEAD")
            _head.text = locations.hasOwnProperty("HEAD")
                    ? locations["HEAD"] : "0"
            _leftHandC.visible = locations.hasOwnProperty("LEFTHAND")
            _leftHand.text = locations.hasOwnProperty("LEFTHAND")
                    ? locations["LEFTHAND"] : "0"
            _rightHandC.visible = locations.hasOwnProperty("RIGHTHAND")
            _rightHand.text = locations.hasOwnProperty("RIGHTHAND")
                    ? locations["RIGHTHAND"] : "0"
            _torsoC.visible = locations.hasOwnProperty("TORSO")
            _torso.text = locations.hasOwnProperty("TORSO")
                    ? locations["TORSO"] : "0"
            _leftLegC.visible = locations.hasOwnProperty("LEFTLEG")
            _leftLeg.text = locations.hasOwnProperty("LEFTLEG")
                    ? locations["LEFTLEG"] : "0"
            _rightLegC.visible = locations.hasOwnProperty("RIGHTLEG")
            _rightLeg.text = locations.hasOwnProperty("RIGHTLEG")
                    ? locations["RIGHTLEG"] : "0"
        }

        if ( itemData.hasStat("PENALTIES") ) {
            for ( var pen in _penalties.objects )
                _penalties.objects[pen].destroy()
            _penalties.objects = []
            for ( var p in itemData.penalties ) {
                var penalty = itemData.penalties[p]
                var penObject = _scrollView.createElement(
                            "Penalty.qml",
                            _penalties,
                            {
                                value: penalty.VALUE,
                                name: penalty.NAME,
                                type: penalty.TYPE
                            }
                        )
                _penalties.objects.push(penObject)
            }
        }

        if ( itemData.hasStat("FEATURES") ) {
            for ( var fea in _features.objects )
                _features.objects[fea].destroy()
            _features.objects = []
            for ( var f in itemData.features ) {
                var feature = itemData.features[f]
                var featObject = _scrollView.createElement(
                            "ItemSpecial.qml",
                            _features,
                            {
                                name: feature.NAME,
                                description: feature.DESCRIPTION,
                                visibleBtn: false
                            }
                        )
                _features.objects.push(featObject)
            }
        }
    }
}
