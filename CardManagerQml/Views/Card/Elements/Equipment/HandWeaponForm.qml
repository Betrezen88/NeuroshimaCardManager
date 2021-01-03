import QtQuick 2.0
import QtQuick.Controls 2.12

import "../"

Column {
    id: main
    spacing: 10
    height: implicitHeight

    Label {
        width: main.width
        text: "Statystyki"
        font.pointSize: 14
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
    }

    Row {
        spacing: 5
        Text {
            text: "Wymagana Budowa:"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _body
            height: parent.height
            from: 0
            to: 30
        }
    }

    Row {
        spacing: 5

        Text {
            id: _bonusLabel
            text: "Bonusy do Zręczności:"
            font.pointSize: 14
            font.bold: true
        }

        Column {
            spacing: 5

            Row {
                spacing: 5
                Text {
                    text: "Atak"
                    font.pointSize: 14
                    onImplicitHeightChanged: parent.height = implicitHeight
                }
                SpinBox {
                    id: _attack
                    height: parent.height
                    from: 0
                    to: 5
                }
            }

            Row {
                spacing: 5
                Text {
                    text: "Obrona"
                    font.pointSize: 14
                    onImplicitHeightChanged: parent.height = implicitHeight
                }
                SpinBox {
                    id: _defence
                    height: parent.height
                    from: 0
                    to: 5
                }
            }
            Row {
                spacing: 5
                Text {
                    text: "Inicjatywa"
                    font.pointSize: 14
                    onImplicitHeightChanged: parent.height = implicitHeight
                }
                SpinBox {
                    id: _iniciative
                    height: parent.height
                    from: 0
                    to: 5
                }
            }
            Row {
                spacing: 5
                Text {
                    text: "Grupa"
                    font.pointSize: 14
                    onImplicitHeightChanged: parent.height = implicitHeight
                }
                SpinBox {
                    id: _group
                    height: parent.height
                    from: 0
                    to: 5
                }
            }
        }
    }

    Column {
        spacing: 5

        Row {
            spacing: 5
            Text {
                id: _label
                text: "Obrażenia:"
                font.pointSize: 14
                font.bold: true
            }
            Text {
                text: "1s:"
                font.pointSize: 14
            }
            ComboBox {
                id: _1s
                height: _label.height
                model: [ "Draśnięcie", "Lekka", "Ciężka", "Krytyczna" ]
            }
        }
        Row {
            spacing: 5
            Item { width: _label.implicitWidth; height: 1 }
            Text {
                text: "2s:"
                font.pointSize: 14
            }
            ComboBox {
                id: _2s
                height: _label.height
                model: [ "Draśnięcie", "Lekka", "Ciężka", "Krytyczna" ]
            }
        }
        Row {
            spacing: 5
            Item { width: _label.implicitWidth; height: 1 }
            Text {
                text: "3s:"
                font.pointSize: 14
            }
            ComboBox {
                id: _3s
                height: _label.height
                model: [ "Draśnięcie", "Lekka", "Ciężka", "Krytyczna" ]
            }
        }
    }

    Row {
        spacing: 5
        Text {
            text: "Przebicie"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _penetration
            height: parent.height
            from: 0
            to: 4
        }
    }

    Flow {
        property var objects: []

        id: _specials
        width: main.width
        spacing: 5

        Text {
            id: _specialLabel
            text: "Reguły specjalne:"
            font.pointSize: 14
            font.bold: true
        }

        Button {
            text: "+"
            width: _specialLabel.implicitHeight
            height: _specialLabel.implicitHeight
            onClicked: specialPopup.open()
        }
    }

    function clear() {
        _body.value = 0
        _attack.value = 0
        _defence.value = 0
        _iniciative.value = 0
        _group.value = 0
        _1s.currentIndex = 0
        _2s.currentIndex = 0
        _3s.currentIndex = 0
        for ( var i in _specials.objects )
            _specials.objects[i].destroy()
        _specials.objects = []
    }

    function statsData() {
        var stats = { damage: [ _1s.currentText, _2s.currentText, _3s.currentText ] }
        var bonus = {};

        if ( _body.value > 0 )
            stats["body"] = _body.value

        if ( _attack.value > 0 )
            bonus["attack"] = _attack.value
        if ( _defence.value > 0 )
            bonus["defence"] = _defence.value
        if ( _iniciative.value > 0 )
            bonus["iniciative"] = _iniciative.value
        if ( _group.value > 0 )
            bonus["group"] = _group.value

        if ( Object.keys(bonus).length > 0 )
            stats["bonus"] = bonus;

        if ( _specials.objects.length > 0 ) {
            var specials = []
            for ( var j in _specials.objects )
                 specials.push(_specials.objects[j].special())
            stats["special"] = specials
        }

        return stats
    }

    Component.onCompleted: console.log("HandWeaponForm.size(w/h):", width, height)

    SpecialForm {
        id: specialPopup
        anchors.centerIn: main
        onSendSpecial: {
            var component = Qt.createComponent("ItemSpecial.qml")
            var object = component.createObject(_specials, {
                                                    name: name,
                                                    description: description
                                                })
            _specials.objects.push(object)
        }
    }
}
