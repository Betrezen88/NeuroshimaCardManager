import QtQuick 2.0
import QtQuick.Controls 2.5

import "./../Element"

Item {
    property var personalData

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
            value: personalData.fullname
        }

        PersonalField {
            id: origin
            width: main.width
            name: "Pochodzenie"
            value: personalData.origin.name
            description: personalData.origin.description
        }

        PersonalField {
            id: profession
            width: main.width
            name: "Profesja"
            value: personalData.profession.name
            description: personalData.profession.description
        }

        PersonalField {
            id: specialization
            width: main.width
            name: "Specjalizacja"
            value: personalData.specialization.name
            description: personalData.specialization.description
        }

        PersonalField {
            id: disease
            width: main.width
            name: "Choroba"
            value: personalData.disease.name
            description: personalData.disease.description
        }

        PersonalField {
            id: originFeature
            width: main.width
            name: "Cecha z pochodzenia"
            value: personalData.originFeature.name
            description: personalData.originFeature.description
        }

        PersonalField {
            id: professionFeature
            width: main.width
            name: "Cecha z profesji"
            value: personalData.professionFeature.name
            description: personalData.professionFeature.description
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
