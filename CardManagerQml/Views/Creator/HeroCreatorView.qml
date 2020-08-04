import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSPageCreator 1.0
import core.NSCardCreator 1.0
import core.NSDataSource 1.0

import "./Pages"

Page {
    id: main

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

        Tricks { id: tricks }

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
            ListElement { text: "Sztuczki" }
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
                                                 "attributes": ":/json/resources/json/Attributes.json",
                                                 "difficulty": ":/json/resources/json/Difficulties.json"
                                             })
        form.statsCreator = manager.cardCreator.pageCreator(NSPageCreator.STATS)
        origin.statsCreator = manager.cardCreator.pageCreator(NSPageCreator.STATS)
        origin.dataSource = manager.cardCreator.dataSource(NSDataSource.STATS)
        profession.statsCreator = manager.cardCreator.pageCreator(NSPageCreator.STATS)
        profession.dataSource = manager.cardCreator.dataSource(NSDataSource.STATS)
        specialization.statsCreator = manager.cardCreator.pageCreator(NSPageCreator.STATS)
        specialization.dataSource = manager.cardCreator.dataSource(NSDataSource.STATS)
        disease.dataSource = manager.cardCreator.dataSource(NSDataSource.STATS)
        attributes.statsCreator = manager.cardCreator.pageCreator(NSPageCreator.STATS)
        attributes.dataSource = manager.cardCreator.dataSource(NSDataSource.STATS)
        skills.statsCreator = manager.cardCreator.pageCreator(NSPageCreator.STATS)
        skills.dataSource = manager.cardCreator.dataSource(NSDataSource.STATS)
    }
}
