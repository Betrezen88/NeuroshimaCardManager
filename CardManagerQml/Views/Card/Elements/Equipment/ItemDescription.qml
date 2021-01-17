import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSItem 1.0

Popup {
    property NSItem itemData

    id: main
    modal: true
    padding: 5

    ScrollView {
        id: scrollView
        height: main.height - 10
        width: main.width - 10
        clip: true

        Column {
            spacing: 5
            width: main.width - 10

            Label {
                id: _name
                width: main.width - (main.padding*2)
                text: "Item Name"
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 12
            }

            Row {
                id: _box
                width: main.width - (main.padding*2)
                height: _button.height
                spacing: 5

                Button {
                    id: _button
                    height: 40
                    text: "<O>"
                    onClicked: _box.height = ( _box.height == _button.height )
                               ? _description.implicitHeight : _button.height
                }

                Text { id: _description }
            }

            Flow {
                spacing: 10
                width: main.width - (main.padding*2)
                Text { id: _price }
                Text { id: _quantity }
                Text { id: _reputation }
            }

            Text { id: _requiredBody }

            Text { id: _damage }

            Text { id: _penetration }

            Text { id: _durability }

            Flow {
                id: _specials
                width: main.width - 10
            }
        } // Column
    }

    onItemDataChanged: {
        _name.text = itemData.name
        _description.text = itemData.description

        _price.text = "Cena: " + itemData.price
        _quantity.text = "Ilość: " + itemData.quantity

        console.log( "REPUTATION:", itemData.hasStat("REPUTATION") )
        _reputation.visible = itemData.hasStat("REPUTATION")
        _reputation.text = "Reputacja: " + itemData.reputation

        _requiredBody.visible = itemData.hasStat("REQUIREMENT")
        _requiredBody.text = "Wymagana Budowa: " + itemData.requiredBody

        _damage.visible = itemData.hasStat("DAMAGE")
        _damage.text = "Obrażenia: " + itemData.damage

        console.log( "PENETRATION:", itemData.hasStat("PENETRATION") )
        _penetration.visible = itemData.hasStat("PENETRATION")
        _penetration.text = "Przebicie: " + itemData.penetration

        console.log( "DURABILITY:", itemData.hasStat("DURABILITY") )
        _durability.visible = itemData.hasStat("DURABILITY")
        _durability.text = "Wytrzymałość: " + itemData.durability
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
