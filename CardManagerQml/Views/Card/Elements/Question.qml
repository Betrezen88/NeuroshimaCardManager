import QtQuick 2.9
import QtQuick.Controls 2.12

Column {
    property alias question: _question.text
    property alias subquestion: _subquestion.text
    property alias answer: _answer.text

    id: main
    spacing: 2
    bottomPadding: 5

    Text {
        id: _question
        width: main.width
        text: qsTr("Pytanie")
        wrapMode: Text.WordWrap
        font.pointSize: 10
        font.bold: true
        rightPadding: 5
    }

    Text {
        id: _subquestion
        width: main.width
        text: qsTr("Pytanie dodatkowe")
        wrapMode: Text.WordWrap
        font.italic: true
        font.pointSize: 10
        rightPadding: 5
    }

//    ScrollView {
//        width: main.width
//        height: 50

        TextArea {
            id: _answer
            width: main.width
            height: implicitHeight
            placeholderText: qsTr("Odpowiedź")
            wrapMode: Text.WordWrap
            font.pointSize: 10
        }
//    }
}
