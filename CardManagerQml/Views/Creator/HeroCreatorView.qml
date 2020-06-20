import QtQuick 2.9
import QtQuick.Controls 2.12

import core 1.0

import "./Pages"

Page {
    property var heroCreator
    property var dataSource

    id: main

    SwipeView {
        id: view
        anchors.fill: parent

        currentIndex: buttons.currentIndex

        Form {
            id: form
            heroCreator: main.heroCreator
        }

        Origin {
            id: origin
        }

        Profession { id: profession }

        Attributes { id: attributes }

        Specialization { id: specialization }

        Disease { id: disease }

        Skills { id: skills }

        Equipment { id: equipment }

        Friends { id: friends }

        onCurrentIndexChanged: {
            if ( currentIndex !== buttons.currentIndex )
                buttons.currentIndex = currentIndex
        }
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

    Component.onCompleted: {
        console.log("Creating StatsSource object")
        manager.cardCreator.createDataSource(NSDataSource.STATS, {
                                                 "origins": ":/json/resources/json/Origins.json",
                                                 "professions": ":/json/resources/json/Professions.json",
                                                 "specializations": ":/json/resources/json/Specializations.json",
                                                 "diseases": ":/json/resources/json/Diseases.json",
                                                 "attributes": ":/json/resources/json/Attributes.json"
                                             })
        origin.dataSource = manager.cardCreator.dataSource(NSDataSource.STATS)
    }
}
