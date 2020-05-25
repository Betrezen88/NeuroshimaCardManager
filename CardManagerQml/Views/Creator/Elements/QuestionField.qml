import QtQuick 2.0
import QtQuick.Controls 2.12

Column {
    property alias description: descriptionTxt.text
    property alias question: questionTxt.text
    property alias answer: answerTxt.text

    id: main
    height: questionTxt.height
            + descriptionTxt.height
            + answerView.height
            + (main.spacing * 2)
    spacing: 5

    Text {
        id: questionTxt
        width: main.width
        text: qsTr("Pytanie 1")
        font.bold: true
        font.pointSize: 10
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignJustify
    }

    Text {
        id: descriptionTxt
        width: main.width
        text: qsTr("Description")
        font.italic: true
        font.pointSize: 10
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignJustify
    }

    Rectangle {
        id: answerView
        border.color: "#000"
        border.width: 2
        radius: 10
        width: main.width
        height: 60

        ScrollView {
            anchors.fill: parent

            TextArea {
                id: answerTxt
                text: qsTr("")
                font.pointSize: 10
                width: main.width
                placeholderText: "Odpowiedź"
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignJustify
            }
        }
    }
}
