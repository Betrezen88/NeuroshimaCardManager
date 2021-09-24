﻿import QtQuick 2.0
import QtQuick.Controls 2.5

import core.view.NSStats 1.0

import "./../Elements"

Column {
    property NSStats personalData

    id: main

    height: implicitHeight
    spacing: 2

    Portrait {
        id: portrait
        width: main.width
        height: main.width
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
    }

    PersonalField {
        id: origin
        width: main.width
        name: "Pochodzenie"
    }

    PersonalField {
        id: profession
        width: main.width
        name: "Profesja"
    }

    PersonalField {
        id: specialization
        width: main.width
        name: "Specjalizacja"
    }

    PersonalField {
        id: disease
        width: main.width
        name: "Choroba"
    }

    PersonalField {
        id: originFeature
        width: main.width
        name: "Cecha z pochodzenia"
    }

    PersonalField {
        id: professionFeature
        width: main.width
        name: "Cecha z profesji"
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

    onPersonalDataChanged: {
        name.value = personalData.fullname
        origin.value = personalData.origin.name
        origin.description = personalData.origin.description
        profession.value = personalData.profession.name
        profession.description = personalData.profession.description
        specialization.value = personalData.specialization.name
        specialization.description = personalData.specialization.description
        disease.value = personalData.disease.name
        disease.description = personalData.disease.description
        originFeature.value = personalData.origin.feature.name
        originFeature.description = personalData.origin.feature.description
        professionFeature.value = personalData.profession.feature.name
        professionFeature.description = personalData.profession.feature.description
    }
}
