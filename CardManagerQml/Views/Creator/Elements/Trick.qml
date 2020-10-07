﻿import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSTrick 1.0

SwipeDelegate {
    property bool valid
    property bool added
    property NSTrick trickData

    id: main
    height: 40

    signal details(NSTrick trickData)
    signal action(NSTrick trickData)

    contentItem: Item {
        width: main.width

        Text {
            id: trickName
            text: "Trick name"
            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                margins: 5
            }
        }

        Image {
            width: 30
            source: "qrc:/icon/resources/icons/question.svg"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right

            MouseArea {
                anchors.fill: parent
                onClicked: main.details(trickData)
            }
        }
    }

    background: Rectangle {
        color: added ? "light gray" : valid ? "green" : "red"
    }

    onClicked: {
        if (swipe.position === 0)
            swipe.open(SwipeDelegate.Left)
        else
            swipe.close()
    }

    swipe.left: Image {
        smooth: true
        source: added ? "qrc:/icon/resources/icons/close.svg"
                      : "qrc:/icon/resources/icons/plus_circle.svg"
        height: main.height
        width: main.height

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if ( valid ) {
                    swipe.close()
                    main.action(trickData)
                }
                else {
                    swipe.close()
                    tooltip.show("Nie spełniasz wymagań tej sztuczki.")
                }
            }
        }

        ToolTip { id: tooltip }
    }

    onTrickDataChanged: trickName.text = trickData.name
}
