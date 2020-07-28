import QtQuick 2.0
import QtQuick.Controls 2.12

SwipeDelegate {
    property string name
    property string attribute

    id: main
    padding: 0

    contentItem: Row {
        width: main.width
        spacing: 3

        Text {
            id: skillName
            width: main.width - attributeName.width - skillValue.width
            height: skillValue.height
            text: qsTr("Skill Name")
            font.pointSize: 10
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: attributeName
            width: implicitWidth
            height: skillValue.height
            font.pointSize: 10
            verticalAlignment: Text.AlignVCenter
        }

        SpinBox {
            id: skillValue
            width: implicitWidth
            height: 40
        }
    }

    ListView.onRemove: SequentialAnimation {
        PropertyAction {
            target: main
            property: "ListView.delayRemove"
            value: true
        }
        NumberAnimation {
            target: main
            property: "height"
            to: 0
            easing.type: Easing.InOutQuad
        }
        PropertyAction {
            target: main
            property: "ListView.delayRemove"
            value: false
        }
    }

    onClicked: {
        if (swipe.position === 0)
            swipe.open(SwipeDelegate.Left)
        else
            swipe.close()
    }

    swipe.left: Label {
        id: deleteLabel
        text: qsTr("Usuń")
        color: "white"
        verticalAlignment: Label.AlignVCenter
        padding: 12
        height: parent.height
        anchors.left: parent.left

        SwipeDelegate.onClicked: listView.model.remove(index)

        background: Rectangle {
            color: deleteLabel.SwipeDelegate.pressed ? Qt.darker("tomato", 1.1) : "tomato"
        }
    }

    onNameChanged: skillName.text = name
    onAttributeChanged: attributeName.text = attribute
}
