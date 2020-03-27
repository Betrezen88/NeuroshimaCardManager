import QtQuick 2.0

import "./../Section"

Item {
    id: main

    height: personal.height + tricks.height + 2
    width: (3*row.spacing)
           + personal.width
           + budowa.width
           + character.width
           + cleaverness.width

    Row {
        id: row
        anchors.fill: main
        spacing: 4

        Column {
            id: column1
            spacing: 4

            Personal {
                id: personal
            }

            Tricks {
                id: tricks
                width: personal.width
            }
        }

        Column {
            id: column2
            spacing: 4

            Attribute {
                id: budowa
                width: 250
                attribute: ({
                    name: "Budowa",
                    value: 14,
                    skillpacks: [
                        { name: "Sprawność",
                            specializations: ["Ranger"],
                            skills: [
                                { name: "Kondycja", value: 1 },
                                { name: "Pływanie", value: 1 },
                                { name: "Wspinaczka", value: 1 }
                            ]
                        },
                        { name: "Jeździectwo",
                            specializations: ["Ranger"],
                            skills: [
                                { name: "Jazda Konna", value: 1 },
                                { name: "Powożenie", value: 1 },
                                { name: "Ujeżdżanie", value: 1 }
                            ]
                        }
                    ]
                })
            }

            Attribute {
                id: dexterity
                width: 250
                attribute: ({
                    name: "Zręczność",
                    value: 15,
                    skillpacks: [
                        { name: "Walka wręcz",
                            specializations: ["Wojownik"],
                            skills: [
                                { name: "Bijatyka", value: 1 },
                                { name: "Rzucanie", value: 1 },
                                { name: "Broń biała", value: 1 }
                            ]
                        },
                        { name: "Prowadzenie pojazdów",
                            specializations: ["Technik"],
                            skills: [
                                { name: "Samochód", value: 1 },
                                { name: "Motocykl", value: 1 },
                                { name: "Ciężarówka", value: 1 }
                            ]
                        },
                        { name: "Zdolności manualne",
                            specializations: ["Cwaniak"],
                            skills: [
                                { name: "Kradzież kieszonkowa", value: 1 },
                                { name: "Otwieranie zamków", value: 1 },
                                { name: "Zwinne dłonie", value: 1 }
                            ]
                        },
                        { name: "Broń strzelecka",
                            specializations: ["Wojownik"],
                            skills: [
                                { name: "Pistolety", value: 1 },
                                { name: "Karabiny", value: 1 },
                                { name: "Broń maszynowa", value: 1 }
                            ]
                        },
                        { name: "Broń dystansowa",
                            specializations: ["Ranger","Wojownik"],
                            skills: [
                                { name: "Łuk", value: 1 },
                                { name: "Kusza", value: 1 },
                                { name: "Proca", value: 1 }
                            ]
                        }
                    ]
                })
            }
        }

        Column {
            id: column3
            spacing: 4

            Attribute {
                id: character
                width: 250
                attribute: ({
                    name: "Charakter",
                    value: 14,
                    skillpacks: [
                        { name: "Negocjacje",
                            specializations: ["Cwaniak"],
                            skills: [
                                { name: "Zastraszanie", value: 1 },
                                { name: "Perswazja", value: 1 },
                                { name: "Zdolności przywódcze", value: 1 }
                            ]
                        },
                        { name: "Empatia",
                            specializations: ["Cwaniak"],
                            skills: [
                                { name: "Postrzeganie emocji", value: 1 },
                                { name: "Blef", value: 1 },
                                { name: "Opieka nad zwierzętami", value: 1 }
                            ]
                        },
                        { name: "Siła woli",
                            specializations: ["Wojownik"],
                            skills: [
                                { name: "Odporność na ból", value: 1 },
                                { name: "Niezłomność", value: 1 },
                                { name: "Morale", value: 1 }
                            ]
                        }
                    ]
                })
            }

            Attribute {
                id: perception
                width: 250
                attribute: ({
                    name: "Percepcja",
                    value: 15,
                    skillpacks: [
                        { name: "Orientacja w terenie",
                            specializations: ["Ranger"],
                            skills: [
                                { name: "Wyczucie kierunku", value: 1 },
                                { name: "Przygotowanie pułapki", value: 1 },
                                { name: "Tropienie", value: 1 }
                            ]
                        },
                        { name: "Spostrzegawczość",
                            specializations: ["Ranger"],
                            skills: [
                                { name: "Nasłuchiwanie", value: 1 },
                                { name: "Wypatrywanie", value: 1 },
                                { name: "Czujność", value: 1 }
                            ]
                        },
                        { name: "Kamuflaż",
                            specializations: ["Ranger", "Cwaniak"],
                            skills: [
                                { name: "Skradanie się", value: 1 },
                                { name: "Ukrywanie się", value: 1 },
                                { name: "Maskowanie", value: 1 }
                            ]
                        },
                        { name: "Przetrwanie",
                            specializations: ["Ranger"],
                            skills: [
                                { name: "Łowiectwo", value: 1 },
                                { name: "Znajomość terenu", value: 1 },
                                { name: "Zdobywanie wody", value: 1 }
                            ]
                        }
                    ]
                })
            }
        }

        Column {
            id: column4
            spacing: 4

            Attribute {
                id: cleaverness
                width: 250
                attribute: ({
                    name: "Spryt",
                    value: 15,
                    skillpacks: [
                        { name: "Medycyna",
                            specializations: ["Ranger", "Technik"],
                            skills: [
                                { name: "Leczenie chorób", value: 1 },
                                { name: "Leczenie ran", value: 1 },
                                { name: "Pierwsza pomoc", value: 1 }
                            ]
                        },
                        { name: "Technika",
                            specializations: ["Technik"],
                            skills: [
                                { name: "Mechanika", value: 1 },
                                { name: "Elektronika", value: 1 },
                                { name: "Komputery", value: 1 }
                            ]
                        },
                        { name: "Wiedza ogólna",
                            specializations: ["Technik"],
                            skills: [
                                { name: "Historia", value: 1 },
                                { name: "Biologia", value: 1 },
                                { name: "Chemia", value: 1 }
                            ]
                        },
                        { name: "Sprzęt",
                            specializations: ["Technik"],
                            skills: [
                                { name: "Maszyny ciężkie", value: 1 },
                                { name: "Wozy bojowe", value: 1 },
                                { name: "Kutry", value: 1 }
                            ]
                        },
                        { name: "Pirotechnika",
                            specializations: ["Wojownik", "Technik"],
                            skills: [
                                { name: "Rusznikarstwo", value: 1 },
                                { name: "Wyrzutnie", value: 1 },
                                { name: "Mat. Wybuchowe", value: 1 }
                            ]
                        }
                    ]
                })
            }

            OtherSkills {
                id: otherSkills
                width: 250
            }
        }
    }
}
