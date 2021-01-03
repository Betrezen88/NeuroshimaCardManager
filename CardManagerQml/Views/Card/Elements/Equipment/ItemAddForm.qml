import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import core.NSItem 1.0

import "../"

Popup {
    id: main
    width: 640
    padding: 5
    modal: true

    signal sendItem(var itemData)

    ScrollView {
        height: main.height - 10
        width: main.width - 10
        clip: true

        Column {
            id: mainColumn
            width: main.width - (main.padding*2)
            spacing: 5

            Row {
                width: main.width - (spacing*3)
                spacing: 5

                TextField {
                    id: _name
                    width: parent.width * 0.6
                    placeholderText: "Nazwa przedmiotu"
                }
                ComboBox {
                    id: _type
                    width: parent.width * 0.4
                    model: [ "Zwykły", "Broń ręczna", "Broń zasięgowa", "Pancerz" ]
                    onCurrentTextChanged: {
                        if ( content.children.length === 1 ) {
                            content.height -= content.children[0].height
                            content.children[0].destroy()
                        }

                        if ( currentText === "Zwykły" )
                            return

                        var formFile;
                        if ( currentText === "Broń ręczna" )
                            formFile = "HandWeaponForm.qml"
                        else if ( currentText === "Broń zasięgowa" )
                            formFile = "RangedWeaponForm.qml"
                        else if ( currentText === "Pancerz" )
                            formFile = "ArmorForm.qml"

                        var component = Qt.createComponent(formFile)
                        var object = component.createObject(content, {
                                                            width: content.width
                                                        })
                        content.height += object.height
                    }
                }
            }

            Rectangle {
                width: parent.width - (main.padding*2)
                height: 80
                color: "#ffffff"
                border.color: "#000"
                border.width: 2
                radius: 10

                ScrollView {
                    width: parent.width
                    height: parent.height

                    TextArea {
                        id: _description
                        placeholderText: "Opis"
                        padding: 5
                    }
                }
            }

            Flow {
                width: parent.width
                spacing: 5

                Row {
                    spacing: 5
                    Text {
                        text: "Cena:"
                        font.pointSize: 14
                        onImplicitHeightChanged: parent.height = implicitHeight
                    }
                    SpinBox {
                        id: _price
                        height: parent.height
                        from: 0
                    }
                }

                Row {
                    spacing: 5
                    Text {
                        text: "Ilość:"
                        font.pointSize: 14
                        onImplicitHeightChanged: parent.height = implicitHeight
                    }
                    SpinBox {
                        id: _quantity
                        height: parent.height
                        from: 1
                    }
                }

                Row {
                    spacing: 5
                    Text {
                        text: "Reputacja:"
                        font.pointSize: 14
                        onImplicitHeightChanged: parent.height = implicitHeight
                    }
                    SpinBox {
                        id: _reputation
                        height: parent.height
                        from: 0
                        to: 5
                    }
                }
            }

            Item { width: 1; height: 10 }

            Item {
                id: content
                width: mainColumn.width
                onWidthChanged: {
                    if ( children.length === 1 )
                        children[0].width = width
                }
            }

            Item { width: 1; height: 10 }

            Row {
                spacing: 5

                Item {
                    height: 1
                    width: mainColumn.width - _closeBtn.width
                           - _addBtn.width - (parent.spacing*2)
                }

                Button {
                    id: _closeBtn
                    text: "Zamknij"
                    onClicked: main.close()
                }

                Button {
                    id: _addBtn
                    text: "Dodaj"
                    onClicked: {
                        if ( _name.text.length === 0
                            || _description.text.length === 0 )
                            return

                        var itemType = typeToString(_type.currentText)
                        var itemData = {
                            type: itemType,
                            name: _name.text,
                            description: _description.text,
                            quantity: _quantity.value,
                            price: _price.value,
                            reputation: _reputation.value
                        }

                        if ( content.children.length > 0 ) {
                            itemData["stats"] = content.children[0].statsData()
                        }

                        main.sendItem(itemData)
                        main.close()
                    }

                    function typeToString(type) {
                        if ( type === _type.model[1]
                            || type === _type.model[2] )
                            return "weapon"
                        else if ( type === _type.model[3] )
                            return "armor"
                        else
                            return "other"
                    }
                }
            }

            function clear() {
                _name.text = ""
                _description.text = ""
                _price.value = 0
                _quantity.value = 1
                _reputation.value = 0
                _type.currentIndex = "0"
            }
        }
    } //ScrollView
}
