import QtQuick 2.12
import QtQuick.Controls 2.12

import core.NSTrick 1.0

import "./../Elements"

Popup {
    property NSTrick trickData

    id: main
    anchors.centerIn: parent
    modal: true
    
    contentItem: Item {
        width: main.width
        height: main.height

        ScrollView {
            id: scrollView
            anchors {
                top: parent.top
                bottom: closeBtn.top
                left: parent.left
                right: parent.right
            }

            clip: true
            
            Column {
                spacing: 5
                anchors.fill: parent
                
                Text {
                    id: trickName
                    text: "Nazwa Sztuczki"
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                    font.bold: true
                    font.pointSize: 14
                    width: scrollView.width
                }

                Row {
                    spacing: 3
                    width: scrollView.width

                    Text {
                        id: reqLabel
                        text: "Wymagania:"
                        font.bold: true
                        font.pointSize: 11
                    }
                    Text {
                        id: trickRequirements
                        width: parent.width - reqLabel.width
                        text: qsTr("Atrybut +14, Umiejętność +1, Profesja")
                        font.pointSize: 11
                        wrapMode: Text.WordWrap
                    }
                }

                Row {
                    spacing: 3
                    width: scrollView.width

                    Text {
                        id: descLabel
                        text: "Opis:"
                        font.bold: true
                        font.pointSize: 11
                    }
                    Text {
                        id: trickDecription
                        width: parent.width - reqLabel.width
                        text: qsTr("Historia opowiadająca o działaniu sztuczki, opowiastka na luzie, z humorem.")
                        font.pointSize: 11
                        font.italic: true
                        wrapMode: Text.WordWrap
                    }
                }

                Row {
                    spacing: 3
                    width: scrollView.width

                    Text {
                        id: actLabel
                        text: "Działanie:"
                        font.bold: true
                        font.pointSize: 11
                    }
                    Text {
                        id: trickAction
                        width: parent.width - actLabel.width
                        text: qsTr("Opis działania sztuczki w mechanice, podaje przykłady zastosowania, bonusy wynikające z użycia oraz warunki jakie muszą zostać spełnione aby móc wykorzystać sztuczkę.")
                        font.pointSize: 11
                        wrapMode: Text.WordWrap
                    }
                }
            }
        } // ScrollView

        Button {
            id: closeBtn
            text: "Zamknij"
            height: 40
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            onClicked: main.close()
        }

    } // Item

    onTrickDataChanged: {
        trickName.text = trickData.name
        trickDecription.text = trickData.description
        trickAction.text = trickData.action
        trickRequirements.text = ""

        console.log(trickData.hasRequirements())

        if ( trickData.hasRequirements() ) {
            for ( var i in trickData.requirements ) {
                var req = trickData.requirements[i]
                trickRequirements.text += req.name + " +" + req.value
                if ( i < trickData.requirements.length )
                    trickRequirements.text += ", "
            }
        }
    }
}
