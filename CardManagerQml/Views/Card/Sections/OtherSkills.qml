import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Elements"

Column {
    property alias otherSkills: _skillsList.model

    id: main
    spacing: 2

    Label {
        id: _title
        height: 30
        width: main.width
        text: "Inne umiejętności"
        color: "#fff"
        font.pointSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        background: Rectangle {
            color: "#000"
            radius: 10
        }
    }

    Rectangle {
        id: _rect
        width: main.width
        height: main.height - _title.height - main.spacing
        border.color: "#000"
        border.width: 2
        radius: 10

        ListView {
            id: _skillsList
            anchors.fill: parent
            anchors.topMargin: 5
            clip: true
            spacing: 2

            delegate: OtherSkill {
                width: main.width
                skill: modelData
            }
        } // ListView
    } // Rectangle
}
