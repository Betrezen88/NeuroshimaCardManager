import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    id: main
    height: implicitHeight
    spacing: 5
    padding: 5

    property int fontSize: 14

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
            id: _rangedType
            text: qsTr("(Pistolet)")
            font.pointSize: fontSize
            font.bold: true
            onImplicitWidthChanged: spacer.width = parent.spacerWidth()
        }

        onWidthChanged: spacer.width = spacerWidth()

        function spacerWidth() {
            return main.width - (_bodyL.implicitWidth + _body.implicitWidth
                    + _rangedType.implicitWidth
                    + (parent.spacing * children.length) + 5)
        }
    }

    Row {
        width: main.width
        height: implicitHeight
        spacing: 5

        Text {
            id: _damageL
            text: qsTr("Obrażenia:")
            font.pointSize: fontSize
            font.bold: true
            onImplicitWidthChanged: spacer1.width = parent.spacerWidth()
        }

        Text {
            id: _damage
            text: qsTr("Lekkie")
            font.pointSize: fontSize
            onImplicitWidthChanged: spacer1.width = parent.spacerWidth()
        }

        Item {
            id: spacer1
            height: 1
        }

        Text {
            id: _penetrationL
            text: qsTr("Przebicie:")
            font.pointSize: fontSize
            font.bold: true
            onImplicitWidthChanged: spacer1.width = parent.spacerWidth()
        }

        Text {
            id: _penetration
            text: qsTr("2")
            font.pointSize: fontSize
            onImplicitWidthChanged: spacer1.width = parent.spacerWidth()
        }

        onWidthChanged: spacer1.width = spacerWidth()

        function spacerWidth() {
            return main.width - (_damageL.implicitWidth + _damage.implicitWidth
                    + _penetrationL.implicitWidth + _penetration.implicitWidth
                    + (parent.spacing * children.length) + 5)
        }
    }

    Row {
        width: main.width
        height: implicitHeight
        spacing: 5

        Text {
            text: qsTr("Szybkostrzelność:")
            font.pointSize: fontSize
            font.bold: true
        }

        Text {
            id: _rateOfFire
            text: "1"
            font.pointSize: fontSize
        }
    }

    Row {
        width: main.width
        height: implicitHeight
        spacing: 5

        Text {
            id: _bulletL
            text: qsTr("Nabój:")
            font.pointSize: fontSize
            font.bold: true
            onImplicitWidthChanged: spacer2.width = parent.spacerWidth()
        }

        Text {
            id: _bullet
            text: qsTr("9mm")
            font.pointSize: fontSize
            onImplicitWidthChanged: spacer2.width = parent.spacerWidth()
        }

        Item {
            id: spacer2
            height: 1
        }

        Text {
            id: _magazineL
            text: qsTr("Magazynek:")
            font.pointSize: fontSize
            font.bold: true
            onImplicitWidthChanged: spacer2.width = parent.spacerWidth()
        }

        Text {
            id: _magazine
            text: qsTr("11")
            font.pointSize: fontSize
            onImplicitWidthChanged: spacer2.width = parent.spacerWidth()
        }

        onWidthChanged: spacer2.width = spacerWidth()

        function spacerWidth() {
            return main.width - (_bulletL.implicitWidth + _bullet.implicitWidth
                    + _magazineL.implicitWidth + _magazine.implicitWidth
                    + (parent.spacing * children.length) + 5)
        }
    }

    ValueRow {
        name: "Amunicja:"
        value: "11"
        width: main.width
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
