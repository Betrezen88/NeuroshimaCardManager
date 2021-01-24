import QtQuick 2.9
import QtQuick.Controls 2.12

Column {
    property int gathered
    property int spended

    signal showExperienceForm()

    id: main
    spacing: 2

    Rectangle {
        id: _title
        width: main.width
        height: 30
        color: "#000"
        radius: 10

        Text {
            color: "#fbfbfb"
            text: qsTr("Dowiadczenie")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
            anchors {
                top: parent.top
                bottom: parent.bottom
                left: parent.left
                right: _addBtn.left
            }
        }

        RoundButton {
            id: _addBtn
            text: "+"
            height: parent.height
            width: parent.height
            anchors {
                top: parent.top
                bottom: parent.bottom
                right: parent.right
            }
            onClicked: main.showExperienceForm()
        }
    }

    Rectangle {
        width: main.width
        height: _row.implicitHeight
        border.width: 2
        border.color: "#000"
        radius: 10

        Row {
            id: _row
            width: implicitWidth
            height: implicitHeight
            spacing: 5
            padding: 5

            Column {
                height: implicitHeight
                spacing: 5

                Text {
                    text: qsTr("Zdobyte:")
                    font.pointSize: 12
                }

                Text {
                    text: qsTr("Wydane:")
                    font.pointSize: 12
                }

                Text {
                    text: qsTr("Do wydania:")
                    font.pointSize: 12
                    onImplicitWidthChanged: parent.width = implicitWidth
                }
            }

            Column {
                height: implicitHeight
                spacing: 5

                Text {
                    id: _gathered
                    text: qsTr("0")
                    font.pointSize: 12
                }

                Text {
                    id: _spended
                    text: qsTr("0")
                    font.pointSize: 12
                }

                Text {
                    id: _available
                    text: qsTr("0")
                    font.pointSize: 12
                }
            }
        }
    }

    onGatheredChanged: {
        _gathered.text = gathered
        _available.text = gathered - main.spended
    }

    onSpendedChanged: {
        _spended.text = spended
        _available.text = main.gathered - spended
    }
}
