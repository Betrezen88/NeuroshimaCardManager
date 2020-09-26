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
                    id: name
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
                        id: requirementsL
                        text: "Wymagania:"
                        font.bold: true
                        font.pointSize: 11
                    }
                    Text {
                        id: requirements
                        width: scrollView.width - requirementsL.width - 5
                        text: qsTr("Atrybut +14, Umiejętność +1, Profesja")
                        font.pointSize: 11
                        wrapMode: Text.WordWrap
                    }
                }

                Row {
                    spacing: 3
                    width: scrollView.width

                    Text {
                        text: "Opis:"
                        font.bold: true
                        font.pointSize: 11
                        width: requirementsL.width
                    }
                    Text {
                        id: description
                        width: scrollView.width - requirementsL.width - 5
                        text: qsTr("Historia opowiadająca o działaniu sztuczki, opowiastka na luzie, z humorem.")
                        font.pointSize: 11
                        font.italic: true
                        wrapMode: Text.WordWrap
                    }
                }

                Row {
                    spacing: 3

                    Text {
                        text: "Działanie:"
                        font.bold: true
                        font.pointSize: 11
                        width: requirementsL.width
                    }
                    Text {
                        id: action
                        width: scrollView.width - requirementsL.width - 5
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
        name.text = trickData.name
        description.text = trickData.description
        action.text = trickData.action
        requirements.text = ""

        if ( trickData.hasRequirements() ) {
            for ( var i in trickData.requirements ) {
                var req = trickData.requirements[i]
                requirements.text += req.name + " +" + req.value
                if ( i < trickData.requirements.length )
                    requirements.text += ", "
            }
        }
    }
}
