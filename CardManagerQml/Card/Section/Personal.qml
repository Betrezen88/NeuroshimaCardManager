import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Element"

Item {
    id: main

    width: portrait.width
    height: mainHeight()

    Column {
        anchors.fill: main
        spacing: 2

        Portrait {
            id: portrait
            width: 200
            height: 200
        }

        Label {
            id: personalLabel
            height: 30
            width: main.width
            text: "Postać"
            color: "#fff"
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            background: Rectangle {
                color: "#000"
                radius: 10
            }
        }

        PersonalField {
            id: name
            width: main.width
            name: "Imię"
            value: "Nick 'Happy' Sax with bick dick and very hairy balls who smokes and drinks"
            description: "Imię, ksywa i nazwisko bohatera"
        }

        PersonalField {
            id: origin
            width: main.width
            name: "Pochodzenie"
            value: "Południowa Hegemonia"
            description: "Meksykańskie zabijaki"
        }

        PersonalField {
            id: profession
            width: main.width
            name: "Profesja"
            value: "Ochroniarz"
            description: "Ochrania ludzi przed innymi"
        }

        PersonalField {
            id: specialization
            width: main.width
            name: "Specjalizacja"
            value: "Wojownik"
            description: "Duży, zły i groźny, wyćwiczony w walce"
        }

        PersonalField {
            id: disease
            width: main.width
            name: "Choroba"
            value: "Gorączka sobotniej nocy"
            description: "Tańczysz jak John Travolta"
        }

        PersonalField {
            id: originFeature
            width: main.width
            name: "Cecha z pochodzenia"
            value: "Zabijaka"
            description: "Skutecznie zabijasz"
        }

        PersonalField {
            id: professionFeature
            width: main.width
            name: "Cecha z profesji"
            value: "Zanim on!"
            description: "Jesteś szybszy niż typek co to chce Ci ubić klienta"
        }

        Button {
            id: reputation
            width: main.width
            height: 30
            text: "Reputacja"
            font.pointSize: 10
            font.bold: true
            background: Rectangle {
                color: "#fff"
                border.color: "#000"
                border.width: 2
                radius: 10
            }
        }

        PersonalField {
            id: fame
            width: main.width
            name: "Sława"
            value: "0"
            description: "Określa jaki z Ciebie badass"
        }
    }

    function mainHeight() {
        return portrait.height + personalLabel.height
                + name.height + origin.height + profession.height
                + specialization.height + disease.height
                + originFeature.height + professionFeature.height
                + reputation.height + fame.height + (11*2);
    }
}
