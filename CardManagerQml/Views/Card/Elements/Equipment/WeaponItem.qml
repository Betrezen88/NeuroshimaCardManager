import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSItem 1.0

Rectangle {
    property int index
    property NSItem item

    signal unequipWeapon(int index)
    signal throwWeapon(int index)

    id: main
    height: _titleBar.height + _stats.height
    color: "#fff"
    border.color: "#000"
    border.width: 2
    radius: 10

    Rectangle {
        id: _titleBar
        height: _title.height
        color: "#000000"
        radius: 10
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: 0

        Row {
            width: _title.width + _actionBtn.width
            height: _title.height
            spacing: 5

            Text {
                id: _title
                width: main.width - _actionBtn.width - parent.spacing
                color: "#fff"
                text: qsTr("Nazwa broni")
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                font.pointSize: 15
            }

            RoundButton {
                id: _actionBtn
                width: _title.implicitHeight
                height: _title.implicitHeight
                text: "..."
                font.bold: true
                font.pointSize: 15
                onClicked: _menu.open()

                Menu {
                    id: _menu

                    MenuItem {
                        text: "Zwiń"
                        onClicked: {
                            _stats.visible = !_stats.visible
                            text = _stats.visible ? "Zwiń" : "Rozwiń"
                            main.height = _stats.visible
                                    ? _titleBar.height + _stats.height
                                    : _titleBar.height
                        }
                    }

                    MenuItem {
                        text: "Do plecaka"
                        onClicked: main.unequipWeapon(main.index)
                    }

                    MenuItem {
                        text: "Wyrzuć"
                        onClicked: _throwPopup.open()
                    }
                }
            }
        }
    }

    Column {
        id: _stats
        width: main.width
        height: implicitHeight
        anchors.top: _titleBar.bottom
        spacing: 5
        padding: 5

        // Wymagana budowa, Przebicie
        Row {
            width: implicitWidth
            height: implicitHeight
            spacing: 5

            Text {
                id: _requirementL
                text: qsTr("Wymagana Budowa:")
                font.bold: true
                font.pointSize: 15
            }

            Text {
                id: _requirement
                text: qsTr("15")
                font.pointSize: 15
            }

            Item {
                width: main.width - _requirementL.width - _requirement.width
                       - _penetrationL.width - _penetration.width
                       - (parent.spacing*5) - 10
                height: 1
            }

            Text {
                id: _penetrationL
                text: qsTr("Przebicie:")
                font.pointSize: 15
                font.bold: true
            }

            Text {
                id: _penetration
                text: qsTr("1")
                font.pointSize: 15
            }
        }
        // Bonus do zręczności
        Row {
            id: _dexBonusC
            width: main.width - (_stats.padding*2)
            height: implicitHeight
            spacing: 5

            Text {
                id: _dexBonusL
                text: qsTr("Bonus do Zręczności:")
                font.pointSize: 15
                font.bold: true
            }

            Flow {
                property var bonuses: []
                id: _dexBonus
                width: parent.width - _dexBonusL.width - parent.spacing
                height: implicitHeight
                spacing: 5
            }
        }
        // Obrażenia
        Row {
            width: main.width - (_stats.padding*2)
            height: implicitHeight
            spacing: 5

            Text {
                id: _damageL
                text: qsTr("Obrażenia:")
                font.bold: true
                font.pointSize: 15
            }

            Flow {
                property var damage: []
                id: _damage
                width: parent.width - _damageL.width - parent.spacing
                height: implicitHeight
                spacing: 5
            }
        }
        // Nabój, Magazynek
        Row {
            width: main.width - (_stats.padding*2)
            height: implicitHeight
            spacing: 5

            Text {
                id: _bulletL
                text: qsTr("Nabój:")
                font.bold: true
                font.pointSize: 15
            }

            Text {
                id: _bullet
                text: qsTr("9mm")
                font.pointSize: 15
            }

            Item {
                width: 160
                height: 1
            }

            Text {
                id: _magazineL
                text: qsTr("Magazynek:")
                font.pointSize: 15
                font.bold: true
            }

            Text {
                id: _magazine
                text: qsTr("30")
                font.pointSize: 15
            }


        }
        // Amunicja, Szybkostrzelność
        Row {
            width: main.width - (_stats.padding*2)
            height: implicitHeight
            spacing: 5

            Text {
                id: _ammunitionL
                height: _ammunition.height
                text: qsTr("Amunicja:")
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                font.bold: true
            }

            SpinBox { id: _ammunition }

            Item {
                width: 30
                height: 1
            }

            Text {
                id: _rateOfFireL
                height: parent.height
                text: qsTr("Szybkostrzelność:")
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                font.bold: true
            }

            Text {
                id: _rateOfFire
                height: parent.height
                text: qsTr("1")
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
            }
        }
        // Zacięcia
        Row {
            id: _jamC
            spacing: 5

            Text {
                text: "Zacięcie:"
                font.pointSize: 15
                font.bold: true
            }

            Text {
                id: _jam
                font.pointSize: 15
            }
        }

        // Wytrzymałość, Pancerz
        Row {
            width: main.width - (_stats.padding*2)
            height: implicitHeight
            spacing: 5

            Text {
                id: _durabilityL
                height: parent.height
                text: qsTr("Wytrzymałość:")
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                font.bold: true
            }

            SpinBox { id: _durability }

            Item {
                width: 30
                height: parent.height
            }

            Text {
                id: _armorL
                height: parent.height
                text: qsTr("Pancerz:")
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                font.bold: true
            }

            Text {
                id: _armor
                height: parent.height
                text: qsTr("1")
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
            }
        }
        // Reguły specjalne
        Flow {
            property var specials: []
            id: _specials
            width: _stats.width - (_stats.padding*2)
            height: implicitHeight
            spacing: 5

            Text {
                id: _specialsL
                text: qsTr("Reguły specjalne:")
                font.bold: true
                font.pointSize: 15
            }
        }
    }

    ThrowForm {
        id: _throwPopup
        name: (main.item !== null) ? main.item.name : "przedmiot"
        anchors.centerIn: main
        width: _titleBar.width
        onAccept: main.throwWeapon(main.index)
    }

    onItemChanged: {
        if ( item === null )
            return

        _title.text = item.name

        _requirementL.visible = item.hasStat("REQUIREMENT")
        _requirement.visible = item.hasStat("REQUIREMENT")
        if ( item.hasStat("REQUIREMENT") )
            _requirement.text = item.requiredBody

        _penetrationL.visible = item.hasStat("PENETRATION")
        _penetration.visible = item.hasStat("PENETRATION")
        if ( item.hasStat("PENETRATION") )
            _penetration.text = item.penetration

        _dexBonusC.visible = item.hasStat("BONUS")
        if ( item.hasStat("BONUS") ) {
            var bonus = item.dexBonus
            var keys = Object.keys(bonus)

            for ( var k in keys ) {
                var obj = Qt.createQmlObject('import QtQuick 2.0; Text { font.pointSize: 15 }',
                                             _dexBonus)
                if ( "ATTACK" === keys[k] )
                    obj.text = "+" + bonus[keys[k]] + " Atak"
                else if ( "DEFENCE" === keys[k] )
                    obj.text = "+" + bonus[keys[k]] + " Obrona"
                else if ( "INICIATIVE" === keys[k] )
                    obj.text = "+" + bonus[keys[k]] + " Inicjatywa"
                else
                    obj.text = "+" + bonus[keys[k]] + " Grupa"
                if ( k < keys.length-1 )
                    obj.text += ","
                _dexBonus.bonuses.push(obj)
            }
        }

        for ( var d in item.damage ) {
            var dObj = Qt.createQmlObject('import QtQuick 2.0; Text { font.pointSize: 15 }',
                                          _damage)
            dObj.text = (item.damage.length > 1)
                    ? parseInt(d)+1 + "s " + item.damage[d]
                        + ((d<item.damage.length-1) ? " / " : "")
                    : item.damage[d]
            _damage.damage.push(dObj)
        }

        _bulletL.visible = item.hasStat("BULLET")
        _bullet.visible = item.hasStat("BULLET")
        if ( item.hasStat("BULLET") )
            _bullet.text = item.bullet

        _magazineL.visible = item.hasStat("MAGAZINE")
        _magazine.visible = item.hasStat("MAGAZINE")
        if ( item.hasStat("MAGAZINE") )
            _magazine.text = item.magazine

        _ammunitionL.visible = item.hasStat("AMMUNITION")
        _ammunition.visible = item.hasStat("AMMUNITION")
        if ( item.hasStat("AMMUNITION") )
            _ammunition.value = item.magazine

        _rateOfFireL.visible = item.hasStat("RATEOFFIRE")
        _rateOfFire.visible = item.hasStat("RATEOFFIRE")
        if ( item.hasStat("RATEOFFIRE") )
            _rateOfFire.text = item.magazine

        _jamC.visible = item.hasStat("JAM")
        if ( item.hasStat("JAM") )
            _jam.text = item.jam

        _durabilityL.visible = item.hasStat("DURABILITY")
        _durability.visible = item.hasStat("DURABILITY")
        if ( item.hasStat("DURABILITY") )
            _durability.value = item.durability

        _armorL.visible = item.hasStat("ARMOR")
        _armor.visible = item.hasStat("ARMOR")
        if ( item.hasStat("ARMOR") )
            _armor.value = item.armor

        _specials.visible = item.hasStat("SPECIAL")
        for ( var s in item.special ) {
            var component = Qt.createComponent("ItemSpecial.qml")
            _specials.specials.push( component.createObject(_specials,
                                              {
                                                  name: item.special[s].name,
                                                  description: item.special[s].description,
                                                  visibleBtn: false
                                              })
                                    )
        }
    }
}
