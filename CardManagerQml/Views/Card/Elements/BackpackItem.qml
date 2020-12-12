import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.15

Rectangle {
    property alias name: _name.text
    property alias quantity: _quantity.text

    id: main
    height: 40
    width: parent.width
    color: "#fff"
    radius: 10
    border.width: 2
    border.color: "#000"
    
    Text {
        id: _name
        padding: 5
        font.pointSize: 12
        visible: text.length > 0
        anchors {
            left: parent.left
            right: _quantity.left
            verticalCenter: parent.verticalCenter
        }
    }

    Text {
        id: _quantity
        width: implicitWidth
        padding: 5
        font.pointSize: 12
        visible: _name.text.length > 0
        anchors {
            right: _button.left
            verticalCenter: parent.verticalCenter
        }
    }

    Button {
        id: _button
        text: "..."
        width: parent.height - 10
        height: parent.height - 10
        visible: _name.text.length > 0
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        
        onClicked: itemMenu.open()
        
        Menu {
            id: itemMenu
            
            MenuItem { text: "Opis" }
            MenuItem { text: "Użyj" }
            MenuItem { text: "Usuń" }
        }
    }
}
