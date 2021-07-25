import QtQuick 2.9
import QtQuick.Controls 2.12

Column {
    spacing: 2
    bottomPadding: 5

    Text {
        id: _question
        width: main.width
        text: qsTr("Pytanie")
        wrapMode: Text.WordWrap
        font.pointSize: 10
    }

    Text {
        id: _subquestion
        width: main.width
        text: qsTr("Pytanie dodatkowe")
        wrapMode: Text.WordWrap
        font.italic: true
        font.pointSize: 10
    }

    Text {
        id: _answer
        width: main.width
        text: qsTr("Odpowiedź")
        wrapMode: Text.WordWrap
        font.pointSize: 10
    }
}
