﻿import QtQuick 2.14

Rectangle {
    property string cardPath
    property string fullname

    id: main
    width: name.width + closeIcon.width
    border.color: "#000"
    border.width: 2
    color: "#fff"

    Row {
        anchors.fill: parent
        spacing: 2

        Text {
            id: name
            text: main.fullname
            height: main.height
            verticalAlignment: Text.AlignVCenter
            padding: 5

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    cardManager.selectedCard = cardPath;
                }
            }
        }

        Image {
            id: closeIcon
            height: main.height
            width: main.height
            fillMode: Image.PreserveAspectFit
            source: "file:///f:/Workspace/Qt/NeuroshimaCardManager/CardManagerQml/resources/icons/close_icon.svg"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    cardManager.closeCard(main.cardPath);
                    main.destroy();
                }
            }
        }
    }

    Connections {
        target: cardManager
        onSelectedCardChanged: {
            main.color = ( main.cardPath === cardManager.selectedCard )
                            ? "#9f9f9f" : "#fff";
        }
    }
}
