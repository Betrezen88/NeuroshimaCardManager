import QtQuick 2.14

Rectangle {
    property string cardPath
    property string fullname
    property bool selected: false

    signal show(string cardPath)
    signal select(string cardPath)

    id: main
    width: name.width + closeIcon.width
    border.color: "#000"
    border.width: 2
    color: "#fff"

    onSelectedChanged: main.color = (selected) ? "#9f9f9f" : "#fff";

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
                    selected = true;
                    show(main.cardPath);
                    select(main.cardPath);
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
}
