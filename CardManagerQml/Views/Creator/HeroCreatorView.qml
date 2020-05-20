import QtQuick 2.9
import QtQuick.Controls 2.12

import "./Pages"

Page {
    id: main
    width: parent.width
    height: parent.height

    SwipeView {
        id: view
        anchors.fill: parent

        currentIndex: buttons.currentIndex

        Form { id: form }

        Origin { id: origin }

        Profession { id: profession }

        Attributes { id: attributes }

        Specialization { id: specialization }

        Disease { id: disease }

        Skills { id: skills }

        Equipment { id: equipment }

        Friends { id: friends }
    }

    footer: ListView {
        id: buttons
        width: parent.width
        height: 50
        spacing: 5
        orientation: Qt.Horizontal

        delegate: Button {
            id: buttonItem
            text: model.text
            font {
                bold: true
                pixelSize: 12
            }
            padding: 15
            onClicked: buttons.currentIndex = view.currentIndex = index
            background: Rectangle {
                color: buttonItem.ListView.isCurrentItem ? "gray" : "lightGray"
            }
        }

        model: ListModel {
            ListElement { text: "Formularz" }
            ListElement { text: "Pochodzenie" }
            ListElement { text: "Profesja" }
            ListElement { text: "Atrybuty" }
            ListElement { text: "Specjalizacja" }
            ListElement { text: "Choroba" }
            ListElement { text: "Umiejętności" }
            ListElement { text: "Ekwipunek" }
            ListElement { text: "Znajomości" }
        }
    }
}
