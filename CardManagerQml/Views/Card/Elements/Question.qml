import QtQuick 2.9
import QtQuick.Controls 2.12

import core.view.NSQuestion 1.0

Column {
    property NSQuestion question

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

    TextArea {
        id: _answer
        width: main.width
        height: implicitHeight
        placeholderText: qsTr("Odpowiedź")
        wrapMode: Text.WordWrap
        font.pointSize: 10
        onTextChanged: {
            if ( null == question )
                return

            question.answer = text
        }
    }

    onQuestionChanged: {
        _question.text = question.question
        _subquestion.text = question.subquestion
        _answer.text = question.answer
    }
}
