import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import core.NSItem 1.0

Popup {
    id: main
    width: 640
    padding: 5
    modal: true

    signal sendItem(var itemData)

    ScrollView {
        id: _scrollView
        width: main.width - (main.padding*2)
        height: main.height - (main.padding*2)
        clip: true

        ListModel {
            id: _damageModel
            ListElement { name: "Draścięnie" }
            ListElement { name: "Lekka" }
            ListElement { name: "Ciężka" }
            ListElement { name: "Krytyczna" }
        }

        Column {
            spacing: 5
            clip: true

            Row {
                spacing: 5

                TextField {
                    id: _name
                    width: _scrollView.width - parent.spacing - _type.width
                    font.pointSize: 10
                    placeholderText: qsTr("Nazwa przedmiotu")
                }

                ComboBox {
                    id: _type
                    width: 150
                    model: [ "Zwykły", "Użytkowy", "Pancerz", "Tarcza", "Broń ręczna", "Broń zasięgowa" ]
                    onCurrentIndexChanged: {
                        main.clearStats()
                    }
                }
            }

            Row {
                width: implicitWidth
                height: implicitHeight

                Rectangle {
                    width: _scrollView.width
                    height: 80
                    color: "#ffffff"
                    border.width: 1

                    ScrollView {
                        anchors.fill: parent
                        clip: true

                        TextArea {
                            id: _description
                            font.pointSize: 10
                            placeholderText: qsTr("Opis przedmiotu")
                        }
                    }
                }
            }

            Row {
                spacing: 5
                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Text {
                        width: _price.width
                        text: qsTr("Cena")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 12
                    }

                    SpinBox {
                        id: _price
                        editable: true
                        to: 9999
                        font.pointSize: 10
                    }
                }

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    Text {
                        width: _quantity.width
                        text: qsTr("Ilość")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 12
                    }

                    SpinBox {
                        id: _quantity
                        editable: true
                        from: 1
                        font.pointSize: 10
                    }
                    spacing: 5
                }

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    Text {
                        width: _reputation.width
                        text: qsTr("Reputacja")
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 12
                    }

                    SpinBox {
                        id: _reputation
                        to: 5
                        font.pointSize: 10
                    }
                    spacing: 5
                }
            }

            Column {
                height: implicitHeight
                spacing: 5
                visible: _type.currentIndex > 0

                Text {
                    width: _scrollView.width
                    text: qsTr("Statystyki")
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pointSize: 16
                }

                Row {
                    spacing: 5
                    visible: _type.currentIndex > 2

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        spacing: 5

                        Text {
                            width: _requirement.width
                            text: qsTr("Wymagana Budowa")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _requirement
                            to: 25
                            font.pointSize: 10
                        }
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        spacing: 5

                        Text {
                            width: _penetration.width
                            text: qsTr("Przebicie")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _penetration
                            to: 4
                            font.pointSize: 10
                        }
                    }
                }

                // Bonusy do dręczności
                Text {
                    width: _scrollView.width
                    text: qsTr("Bonus do Zręczczności")
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pointSize: 14
                    visible: _type.currentIndex === 3 || _type.currentIndex === 4
                }

                Flow {
                    width: _scrollView.width
                    height: implicitHeight
                    visible: _type.currentIndex === 3 || _type.currentIndex === 4

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _attack.width
                            text: qsTr("Atak")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _attack
                            to: 5
                            font.pointSize: 10
                        }
                        spacing: 5
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _defence.width
                            text: qsTr("Obrona")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _defence
                            to: 5
                            font.pointSize: 10
                        }
                        spacing: 5
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _iniciative.width
                            text: qsTr("Inicjatywa")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _iniciative
                            to: 5
                            font.pointSize: 10
                        }
                        spacing: 5
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _group.width
                            text: qsTr("Grupa")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _group
                            to: 5
                            font.pointSize: 10
                        }
                        spacing: 5
                    }

                    spacing: 5
                }

                // Obrażenia
                Row {
                    width: _scrollView.width
                    height: implicitHeight
                    visible: _type.currentIndex > 2

                    Text {
                        id: _damageL
                        height: _1s.height
                        text: qsTr("Obrażenia:")
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                        font.pointSize: 14
                    }

                    Flow {
                        width: _scrollView.width - _damageL.width - parent.spacing
                        height: implicitHeight
                        spacing: 5

                        Row {
                            width: implicitWidth
                            height: implicitHeight
                            spacing: 2

                            Text {
                                height: _1s.height
                                text: qsTr("1s")
                                font.pixelSize: 18
                                verticalAlignment: Text.AlignVCenter
                                visible: _type.currentIndex > 2 && _type.currentIndex < 5
                            }

                            ComboBox {
                                id: _1s
                                wheelEnabled: false
                                font.pointSize: 10
                                textRole: "name"
                                model: _damageModel
                            }
                        }

                        Row {
                            width: implicitWidth
                            height: implicitHeight
                            visible: _type.currentIndex > 2 && _type.currentIndex < 5

                            Text {
                                height: _2s.height
                                text: qsTr("2s")
                                font.pixelSize: 18
                                verticalAlignment: Text.AlignVCenter
                            }

                            ComboBox {
                                id: _2s
                                font.pointSize: 10
                                textRole: "name"
                                model: _damageModel
                            }
                            spacing: 2
                        }

                        Row {
                            width: implicitWidth
                            height: implicitHeight
                            visible: _type.currentIndex > 2 && _type.currentIndex < 5

                            Text {
                                height: _3s.height
                                text: qsTr("3s")
                                font.pixelSize: 18
                                verticalAlignment: Text.AlignVCenter
                            }

                            ComboBox {
                                id: _3s
                                font.pointSize: 10
                                textRole: "name"
                                model: _damageModel
                            }
                            spacing: 2
                        }
                    } // Flow
                } // Row

                // Dane broni zasięgowej
                Row {
                    width: implicitWidth
                    height: implicitHeight
                    visible: _type.currentIndex === 5

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _bullet.width
                            text: qsTr("Nabój")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        TextField {
                            id: _bullet
                            width: 130
                            placeholderText: "np.: 9mm"
                            font.pointSize: 10
                        }
                        spacing: 5
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _magazine.width
                            text: qsTr("Magazynek")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        TextField {
                            id: _magazine
                            width: 130
                            font.pointSize: 10
                            placeholderText: "Kompatybilne wielkości"
                        }
                        spacing: 5
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _rateOfFire.width
                            text: qsTr("Szybkostrzelność")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _rateOfFire
                            font.pointSize: 10
                            to: 3
                        }
                        spacing: 5
                    }

                    spacing: 5
                } // Row

                // Reguły specjalne
                Row {
                    width: _scrollView.width
                    height: implicitHeight
                    visible: _type.currentIndex > 2

                    Text {
                        id: _specialL
                        text: qsTr("Reguły specjalne:")
                        font.bold: true
                        font.pointSize: 15
                    }

                    Flow {
                        property var objects: []
                        id: _specials
                        width: 400
                        height: implicitHeight
                        spacing: 5

                        Button {
                            id: _addSpecialBtn
                            width: _specialL.height + 10
                            height: _specialL.height + 10
                            text: qsTr("+")
                            font.pointSize: 12
                            onClicked: specialForm.open()
                        }

                        function clear() {
                            for ( var s in objects ) {
                                objects[s].destroy()
                            }
                            objects = []
                        }
                    }
                }

                // Lokacje pancerza
                Text {
                    width: _scrollView.width
                    text: qsTr("Lokacje")
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pointSize: 14
                    visible: _type.currentIndex === 2 || _type.currentIndex === 3
                }

                Flow {
                    width: _scrollView.width
                    height: implicitHeight
                    spacing: 5
                    visible: _type.currentIndex === 2 || _type.currentIndex === 3

                    Column {
                        width: implicitWidth
                        height: implicitHeight

                        Text {
                            width: _head.width
                            height: implicitHeight
                            text: qsTr("Głowa")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _head
                            to: 4
                            enabled: true
                        }
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _leftHand.width
                            height: implicitHeight
                            text: qsTr("Lewa ręka")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _leftHand
                            to: 4
                            enabled: true
                        }
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _rightHand.width
                            height: implicitHeight
                            text: qsTr("Prawa ręka")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _rightHand
                            to: 4
                            enabled: true
                        }
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _torso.width
                            height: implicitHeight
                            text: qsTr("Tułów")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _torso
                            to: 4
                            enabled: true
                        }
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _leftLeg.width
                            height: implicitHeight
                            text: qsTr("Lewa noga")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _leftLeg
                            to: 4
                            enabled: true
                        }
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        Text {
                            width: _rightLeg.width
                            height: implicitHeight
                            text: qsTr("Prawa noga")
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 12
                        }

                        SpinBox {
                            id: _rightLeg
                            to: 4
                            enabled: true
                        }
                    }
                }

                // Kary / Bonusy, Cechy
                Row {
                    height: implicitHeight
                    spacing: 5
                    visible: _type.currentIndex === 2

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        spacing: 5

                        Row {
                            width: ((main.width - (main.padding*2)) / 2) - parent.spacing
                            height: implicitHeight
                            spacing: 5

                            Text {
                                width: parent.width - parent.height - parent.spacing
                                height: implicitHeight
                                text: qsTr("Kary / Bonusy")
                                horizontalAlignment: Text.AlignHCenter
                                font.bold: true
                                font.pointSize: 14
                            }

                            Button {
                                width: parent.height
                                height: parent.height
                                text: "+"
                                onClicked: _penaltyForm.open()
                            }
                        }

                        ListView {
                            id: _penalties
                            width: ((main.width - (main.padding*2)) / 2) - 5
                            height: 100
                            spacing: 5
                            clip: true
                            delegate: Row {
                                property int value: model.value
                                property string name: model.name
                                property string type: model.type

                                spacing: 5

                                Button {
                                    text: "X"
                                    width: 40
                                    height: 40
                                    onClicked: _penalties.model.remove(model.index)
                                }
                                Text {
                                    height: 40
                                    text: ((model.value>0) ? "+": "")
                                          + model.value + " "
                                          + (model.type==="Test" ? "% " : "")
                                          + model.name
                                          + " ("+model.type+")"
                                    font.pointSize: 12
                                    verticalAlignment: Text.AlignVCenter
                                }
                            }
                            model: ListModel{}
                        }
                    }

                    Column {
                        width: implicitWidth
                        height: implicitHeight
                        spacing: 5

                        Row {
                            width: ((main.width - (main.padding*2)) / 2) - parent.spacing
                            height: implicitHeight
                            spacing: 5

                            Text {
                                width: parent.width - parent.height - parent.spacing
                                height: implicitHeight
                                text: qsTr("Cechy")
                                horizontalAlignment: Text.AlignHCenter
                                font.bold: true
                                font.pointSize: 14
                            }

                            Button {
                                width: parent.height
                                height: parent.height
                                text: "+"
                                onClicked: _featureForm.open()
                            }
                        }

                        ListView {
                            id: _features
                            width: ((main.width - (main.padding*2)) / 2) - 5
                            height: 100
                            spacing: 5
                            clip: true
                            delegate: Row {
                                property string name: model.name
                                property string description: model.description
                                spacing: 5

                                Button {
                                    text: "X"
                                    width: 40
                                    height: 40
                                    onClicked: _features.model.remove(model.index)
                                }

                                Text {
                                    height: 40
                                    text: model.name
                                    font.pointSize: 12
                                    verticalAlignment: Text.AlignVCenter

                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: _tooltip.open()
                                    }
                                }

                                Popup {
                                    id: _tooltip
                                    padding: 5
                                    width: parent.width
                                    height: _tooltipText.implicitHeight + 10

                                    Text {
                                        id: _tooltipText
                                        text: model.description
                                        width: parent.width - 10
                                        wrapMode: Text.WordWrap
                                    }
                                }
                            }
                            model: ListModel{}
                        }
                    }
                } // Flow
            } // Column Stats

            // Przyciski
            Row {
                width: _scrollView.width
                height: implicitHeight
                layoutDirection: Qt.RightToLeft
                spacing: 5

                Button {
                    text: qsTr("Dodaj")
                    onClicked: {
                        if ( _name.text.length === 0
                                || _description.text.length === 0 )
                            return

                        var itemData = {
                            "NAME": _name.text,
                            "DESCRIPTION": _description.text,
                            "PRICE": _price.value,
                            "QUANTITY": _quantity.value,
                            "TYPE": _type.currentText
                        }
                        var stats = {}

                        if ( _reputation.value > 0 )
                            stats["REPUTATION"] = _reputation.value
                        if ( _type.currentIndex > 2 && _requirement.value > 0 )
                            stats["REQUIREMENT"] = _requirement.value
                        if ( _type.currentIndex > 2 && _penetration.value > 0 )
                            stats["PENETRATION"] = _penetration.value

                        if ( _type.currentIndex === 3
                                || _type.currentIndex === 4 ) {
                            var bonus = {}
                            if ( _attack.value > 0 )
                                bonus["ATTACK"] = _attack.value
                            if ( _defence.value > 0 )
                                bonus["DEFENCE"] = _defence.value
                            if ( _iniciative.value > 0 )
                                bonus["INICIATIVE"] = _iniciative.value
                            if ( _group.value > 0 )
                                bonus["GROUP"] = _group.value
                            if ( Object.keys(bonus).length > 0 )
                                stats["BONUS"] = bonus
                        }

                        if ( _type.currentIndex > 2 ) {
                            var damage = []
                            damage.push(_1s.currentText)

                            if ( _type.currentIndex === 3
                                    || _type.currentIndex === 4 ) {
                                damage.push(_2s.currentText)
                                damage.push(_3s.currentText)
                            }
                            stats["DAMAGE"] = damage
                        }

                        if ( _type.currentIndex === 5 ) {
                            stats["BULLET"] = _bullet.text
                            stats["MAGAZINE"] = _magazine.text
                            if ( _rateOfFire.value > 0 )
                                stats["RATEOFFIRE"] = _rateOfFire.value
                        }

                        if ( _type.currentIndex === 2 ) {
                            var locations = {}

                            if ( _head.value > 0 )
                                locations["HEAD"] = _head.value
                            if ( _torso.value > 0 )
                                locations["TORSO"] = _torso.value
                            if ( _leftHand.value > 0 )
                                locations["LEFTHAND"] = _leftHand.value
                            if ( _rightHand.value > 0 )
                                locations["RIGHTHAND"] = _rightHand.value
                            if ( _leftLeg.value > 0 )
                                locations["LEFTLEG"] = _leftLeg.value
                            if ( _rightLeg.value > 0 )
                                locations["RIGHTLEG"] = _rightLeg.value
                            stats["LOCATIONS"] = locations

                            if ( _penalties.model.count > 0 ) {
                                stats["PENALTIES"] = []
                                for ( var p=0; p<_penalties.model.count; ++p ) {
                                    stats["PENALTIES"].push({
                                        "VALUE": _penalties.model.get(p).value,
                                        "NAME": _penalties.model.get(p).name,
                                        "TYPE": _penalties.model.get(p).type
                                    })
                                }
                            }

                            if ( _features.model.count > 0 ) {
                                stats["FEATURES"] = []
                                for ( var f=0; f<_features.model.count; ++f ) {
                                    stats["FEATURES"].push({
                                        "NAME": _features.model.get(f).name,
                                        "DESCRIPTION": _features.model.get(f).description
                                    })
                                }
                            }
                        }
                        itemData["STATS"] = stats

                        main.sendItem(itemData)
                        main.close()
                    }
                }

                Button {
                    text: qsTr("Anuluj")
                    onClicked: main.close()
                }
            }
        } // Column
    } // ScrollView

    DataForm {
        id: specialForm
        title: "Reguła specjalna"
        anchors.centerIn: parent
        modal: true
        onSendData: {
            var component = Qt.createComponent("ItemSpecial.qml")
            var object = component.createObject(_specials, {
                                                    name: name,
                                                    description: description,
                                                    visibleBtn: true
                                                })
            _specials.objects.push(object)
        }
    }

    PenaltyForm {
        id: _penaltyForm
        anchors.centerIn: parent
        modal: true
        onSendPenalty: {
            _penalties.model.append({value: value, name: name, type: type})
        }
    }

    DataForm {
        id: _featureForm
        title: "Cecha"
        anchors.centerIn: parent
        modal: true
        onSendData: {
            _features.model.append({name: name, description: description});
        }
    }

    onClosed: {
        _name.clear()
        _description.clear()
        _price.value = 0
        _quantity.value = 1
        _type.currentIndex = 0
        _reputation.value = 0
        main.clearStats()
    }

    function clearStats() {
        _requirement.value = 0
        _penetration.value = 0
        _attack.value = 0
        _defence.value = 0
        _iniciative.value = 0
        _group.value = 0
        _1s.currentIndex = 0
        _2s.currentIndex = 0
        _3s.currentIndex = 0
        _bullet.clear()
        _magazine.clear()
        _rateOfFire.value = 0
        _specials.clear()
        _penalties.model.clear()
        _features.model.clear()
    }
}
