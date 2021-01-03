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
            id: _damageL
            text: "Obrażenia:"
            font.pointSize: 14
            font.bold: true
        }

        ComboBox {
            id: _damage
            height: _damageL.height
            model: [ "Draśnięcie", "Lekka", "Ciężka", "Krytyczna" ]
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

    Row {
        spacing: 5
        Text {
            text: "Szybkostrzelność"
            font.pointSize: 14
            onImplicitHeightChanged: parent.height = implicitHeight
        }
        SpinBox {
            id: _rateOfFire
            height: parent.height
            from: 0
            to: 4
        }
    }

    Row {
        spacing: 5
        Text {
            text: "Nabój:"
            font.pointSize: 14
            font.bold: true
        }
        TextField {
            id: _bullet
            placeholderText: "Wpisz kaliber"
            font.pointSize: 14
        }
    }

    Row {
        spacing: 5
        Text {
            text: "Magazynek:"
            font.pointSize: 14
            font.bold: true
        }
        TextField {
            id: _magazine
            placeholderText: "Ilość naboi"
            font.pointSize: 14
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
        for ( var i in _specials.objects )
            _specials.objects[i].destroy()
        _specials.objects = []
    }

    function statsData() {
        var stats = {
            damage: [ _damage.currentText ],
            bullet: _bullet.text,
            magazine: _magazine.text
        }

        if ( _body.value > 0 )
            stats["body"] = _body.value

        if ( _penetration.value > 0 )
            stats["penetration"] = _penetration.value
        if ( _rateOfFire.value > 0 )
            stats["rateOfFire"] = _rateOfFire.value

        if ( _specials.objects.length > 0 ) {
            var specials = []
            for ( var j in _specials.objects )
                 specials.push(_specials.objects[j].special())
            stats["special"] = specials
        }

        return stats
    }

    Component.onCompleted: console.log("RangedWeaponForm.size(w/h):", width, height)

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
