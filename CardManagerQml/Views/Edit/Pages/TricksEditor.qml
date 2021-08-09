import QtQuick 2.15
import QtQuick.Controls 2.12

Page {
    id: main

    ScrollView {
        width: main.width
        height: main.height
        clip: true

        Row {
            spacing: 5

            Column {
                spacing: 5

                Button {
                    text: "Usuń"
                }

                ListView {
                    id: _tricks
                }
            }

            Column {
                spacing: 5

                Button {
                    text: "Kup"
                }

                ListView {
                    id: _availableTricks
                }
            }
        }
    }
}
