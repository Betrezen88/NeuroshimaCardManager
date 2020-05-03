import QtQuick 2.14

Rectangle {
    property var card

    signal show(var card)

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
            text: card.stats.personal.fullname
            height: main.height
            verticalAlignment: Text.AlignVCenter
            padding: 5

            MouseArea {
                anchors.fill: parent
                onClicked: show(main.card)
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
                    cardManager.closeCard(card.filePath);
                    main.destroy();
                }
            }
        }
    }
}
