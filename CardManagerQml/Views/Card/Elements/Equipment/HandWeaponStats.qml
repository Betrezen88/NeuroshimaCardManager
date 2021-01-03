import QtQuick 2.12

Column {
    property int fontSize: 14

    id: main
    spacing: 5
    height: implicitHeight
    padding: 5

    Row {
        width: main.width
        height: implicitHeight
        spacing: 5

        Text {
            id: _bodyL
            text: qsTr("Wymagana Budowa:")
            font.pointSize: fontSize
            font.bold: true
            onImplicitWidthChanged: spacer.width = parent.spacerWidth()
        }

        Text {
            id: _body
            text: qsTr("15")
            font.pointSize: fontSize
            onImplicitWidthChanged: spacer.width = parent.spacerWidth()
        }

        Item {
            id: spacer
            height: 1
        }

        Text {
            id: _penetrationL
            text: qsTr("Przebicie:")
            font.pointSize: fontSize
            font.bold: true
            onImplicitWidthChanged: spacer.width = parent.spacerWidth()
        }

        Text {
            id: _penetration
            text: qsTr("1")
            font.pointSize: fontSize
            onImplicitWidthChanged: spacer.width = parent.spacerWidth()
        }

        onWidthChanged: spacer.width = spacerWidth()

        function spacerWidth() {
            return main.width - (_bodyL.implicitWidth + _body.implicitWidth
                    + _penetrationL.implicitWidth + _penetration.implicitWidth
                    + (parent.spacing * children.length) + 5)
        }
    }

    Flow {
        width: main.width
        height: implicitHeight
        spacing: 5

        Text {
            text: qsTr("Bonus do Zr:")
            font.pointSize: fontSize
            font.bold: true
        }

        Text { text: "+1 Atak,"; font.pointSize: fontSize }
        Text { text: "+1 Obrona,"; font.pointSize: fontSize }
        Text { text: "+1 Inicjatywa,"; font.pointSize: fontSize }
        Text { text: "+1 Grupa"; font.pointSize: fontSize }
    }

    Row {
        width: main.width
        height: implicitHeight
        spacing: 5

        Text {
            text: qsTr("Obrażenia:")
            font.pointSize: fontSize
            font.bold: true
        }

        Text {
            id: _damage
            text: qsTr("1s: Lekka / 2s: Ciężka / 3s: Krytyczna")
            font.pointSize: fontSize
        }
    }

    Flow {
        width: main.width
        height: implicitHeight
        spacing: 5

        Text {
            text: qsTr("Reguły specjalne:")
            font.pointSize: fontSize
            font.bold: true
        }

        Text {
            text: qsTr("Miażdżenie,")
            font.pointSize: fontSize
        }

        Text {
            text: qsTr("Zamach,")
            font.pointSize: fontSize
        }

        Text {
            text: qsTr("Specjalny manewr,")
            font.pointSize: fontSize
        }

        Text {
            text: qsTr("Zasada specjalna,")
            font.pointSize: fontSize
        }
    }
}
