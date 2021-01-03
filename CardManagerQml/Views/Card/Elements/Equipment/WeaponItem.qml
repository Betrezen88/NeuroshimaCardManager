import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    property var weaponData
    property alias name: _title.text
    property string type

    height: _titleBar.height + test.implicitHeight

    id: main
    color: "#fff"
    border.color: "#000"
    border.width: 2
    radius: 10

    Column {
        id: test
        anchors.fill: parent

        Rectangle {
            id: _titleBar
            width: main.width
            height: 30
            color: "#000"
            radius: 10

            Text {
                id: _title
                height: _titleBar.height
                color: "#fbffff"
                text: qsTr("Weapon Name")
                anchors.left: parent.left
                anchors.right: _button.left
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 12
                font.bold: true
            }

            RoundButton {
                id: _button
                width: _titleBar.height - 5
                height: _titleBar.height - 5
                text: qsTr("Button")
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                onClicked: itemMenu.open()

                Menu {
                    id: itemMenu

                    MenuItem { text: "Opis" }
                    MenuItem { text: "Zwiń" }
                    MenuItem { text: "Do ekwipunku" }
                    MenuItem { text: "Wyrzuć" }
                }
            }
        } // Rectangle _titleBar
    }

    onTypeChanged: {
        var file = (type === "handWeapon")
                ? "qrc:/Views/Card/Elements/Equipment/HandWeaponStats.qml"
                : "qrc:/Views/Card/Elements/Equipment/RangedWeaponStats.qml"
        var component = Qt.createComponent(file)
        var object = component.createObject(test, {
                                                width: main.width
                                            })
        main.widthChanged.connect(function(){ object.width = main.width })
    }
}
