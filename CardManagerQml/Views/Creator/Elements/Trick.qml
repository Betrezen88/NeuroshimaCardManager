import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSTrick 1.0

SwipeDelegate {
    property bool valid
    property bool added
    property alias name: trickName.text
    property int index

    id: main
    height: 40

    signal details(int index)
    signal action(int index)

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
                onClicked: main.details(index)
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
                swipe.close()
                var points = manager.cardCreator.creationPointsManager().tricks
                if ( valid && points > 0 || added )
                    main.action(main.index)
                else {
                    var text = (!valid) ? "Nie spełniasz wymagań tej sztuczki."
                                        : "Nie masz już wolnych punktów sztuczek."
                    tooltip.show(text)
                }
            }
        }

        ToolTip { id: tooltip }
    }

    onNameChanged: trickName.text = name
}
