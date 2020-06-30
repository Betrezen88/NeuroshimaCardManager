import QtQuick 2.0
import QtQuick.Controls 2.12

import core.NSSymptom 1.0
import core.NSPenalty 1.0

Column {
    property NSSymptom symptom

    id: main
    width: 300
    height: implicitHeight + 20
    spacing: 5
    
    Text {
        id: name
        width: main.width
        text: qsTr("Nazwa")
        font.bold: true
        font.pointSize: 11
        horizontalAlignment: Text.AlignHCenter
    }
    
    Text {
        id: description
        width: main.width
        text: qsTr("Opis symptomu")
        wrapMode: Text.WordWrap
        font.pointSize: 9
        font.bold: false
        horizontalAlignment: Text.AlignLeft
    }
    
    Text {
        id: penalties
        width: main.width
        text: qsTr("Kary:")
        wrapMode: Text.WordWrap
        font.pointSize: 9
        font.bold: false
        horizontalAlignment: Text.AlignLeft
    }

    onSymptomChanged: {
        name.text = symptom.name
        description.text = symptom.description

        var text = "Kary: "

        for ( var i in symptom.penalties ) {
            var penalty = symptom.penalties[i]
            text += "\n"
            text += (penalty.value > 0) ? "+" : ""
            text += penalty.value
            text += (penalty.type === NSPenalty.TEST) ? "%" : ""
            text += " " + penalty.name
        }
        penalties.text = text
    }
}
