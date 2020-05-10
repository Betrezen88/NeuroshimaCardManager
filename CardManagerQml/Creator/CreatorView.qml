import QtQuick 2.0
import QtQuick.Controls 2.14

Rectangle {
    id: main
    color: "#fff"

    Column {
        anchors.fill: parent

        ScrollView {
            id: upperPanel
            height: 40
            width: main.width

            Row {
                anchors.fill: parent
                spacing: 2

                Button {
                    text: "Zakończ"
                    height: upperPanel.height
                    onClicked: main.destroy();
                }

                Button {
                    text: "Formularz"
                    height: upperPanel.height
                }
            }
        }

        StackView {
            id: stackView
        }
    }
}
