import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

import "./../Elements"

Page {
    id: main

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            id: column
            spacing: 5
            anchors.fill: parent
            anchors.margins: 5

            Row {
                id: personalRow
                width: column.width
                height: 150
                spacing: 5

                Rectangle {
                    id: pictureBorder
                    width: personalRow.height
                    height: personalRow.height
                    color: "#ffffff"
                    border.width: 2

                    Image {
                        id: picture
                        anchors.fill: parent
                        anchors.margins: 2
                        fillMode: Image.PreserveAspectFit

                        Text {
                            anchors.centerIn: parent
                            text: qsTr("Kliknij aby zmienić portret")
                            visible: picture.source.toString() === ""
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: portretDialog.open()
                        }
                    }

                }

                Column {
                    id: personalData
                    width: personalRow.width - pictureBorder.width - personalRow.spacing
                    height: personalRow.height
                    spacing: 5

                    TextField {
                        id: name
                        text: qsTr("Text Field")
                    }

                    TextField {
                        id: surname
                        text: qsTr("Text Field")
                    }

                    TextField {
                        id: nickname
                        text: qsTr("Text Field")
                    }
                }

            }

            QuestionField {
                id: q1
                width: main.width - (column.anchors.margins * 2)
                question: "Jest późny wieczór, od zachodu zbliża się wichura, pierwsze podmuchy poruszają konarami skarłowaciałych drzew. Wyłaniasz się zza załomu muru, przekraczasz ulicę i wchodzisz do knajpy. Panujący w niej zgiełk ustaje, a zgromadzeni wewnątrz dostrzegają..."
                description: "Jak wyglądasz? Jak się poruszasz, jak spoglądasz? Jesteś wysoki czy niski, ubierasz się niechlujnie czy szpanersko? Broń jest widoczna czy ukryta pod płaszczem? jesteś pewny siebie czy raczej czujnym wzrokiem spoglądasz w stronę nieznajomych?"
            }

            QuestionField {
                id: q2
                width: main.width - (column.anchors.margins * 2)
                question: "Siedzisz przy barze, rozglądając się po zniszczonych, poprzecinanych seriami pocisków ścianach. W pewnym momencie dosiada się facet o krzywym spojrzeniu i stawia Ci piwo. Co robisz?"
                description: "Jesteś kontaktowy czy mrukliwy? Łatwo nawiązujesz przyjaźnie czy raczej jesteś nieufny? A może Twój styl bycia sprawia, że takie patałachy nigdy się do Ciebie nie dostają? Gaasz jak najęty czy cedzisz słowa jak Clint Eastwood?"
            }

            QuestionField {
                id: q3
                width: main.width - (column.anchors.margins * 2)
                question: "W końcu jeden z tych palantów podchodzi do jakiejś laski i bez słowa uderza ją w twarz. Panienka przewraca się na ziemię, on kopie ją, a nastepnie łapie za włosy i wyciąga na zewnątrz knajpy. I co Ty na to?"
                description: "Jak z uczuciami? Wiesz co to litość? Jesteś brutalny czy delikatny? Co sądzisz o przemocy? Zabiłeś już kogoś czy nie? Masz jakieś zasady morlane? No jak, co z Tobą?"
            }

            QuestionField {
                id: q4
                width: main.width - (column.anchors.margins * 2)
                question: "Zamieszanie się kończy, sączysz piwo, cicha muzyka uspokaja Cię. Wracasz wspomnieniami do dawnych dni, do czasów młodości. Wspominasz rodzinę..."
                description: "Jakie masz nastawienie do tradycji i rodziny? Co sądzisz o swoim ojcu i matce? Masz rodzeństwo? Jesteś samotny czy może gdzieś daleko stąd ktoś na Ciebie czeka?"
            }

            QuestionField {
                id: q5
                width: main.width - (column.anchors.margins * 2)
                question: "Przypominają Ci się słowa Twojego ojca. Możesz je powtórzyć?"
                description: "Czy Twój ojciec, lub ktoś inny, bardzo dla Ciebie ważny, czegoś Cię nauczył? Zdradził Ci jakąś mądrość, prawdę życiową? Jest coś, za co go wyjątkowo szanujesz? Chciałbyś być taki jak on?"
            }

            QuestionField {
                id: q6
                width: main.width - (column.anchors.margins * 2)
                question: "Nagle spokój zostaje brutalnie przerwany hukiem wystrzału. Ktoś kogoś postrzelił, teraz wychodzą na zewnątrz, słychać krzyki, jeszcze jeden huk wystrzału. Ktoś własnie kopnął w kalendarz. Dobrze, że to nie Ty, co?"
                description: "Boisz się śmierci? Jak reagujesz w sytuacjach niebezpiecznych? Mięknie Ci rura czy dalej jesteś hardy? Myślisz czasami o końcu? Masz jakiś cel, który chciałbyś osiągnąć zanim wyciągniesz kopyta?"
            }
        }
    }

    FileDialog {
        id: portretDialog
        title: "Wybierz portret postaci"
        folder: shortcuts.home
        onAccepted: picture.source = fileUrl
    }
}
