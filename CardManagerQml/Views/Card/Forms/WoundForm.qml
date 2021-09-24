import QtQuick 2.0
import QtQuick.Controls 2.12

import core.view.NSStats 1.0

import "./../Sections"

Popup {
    property NSStats stats

    id: main

    signal sendWound(string location, string type, bool passed)

    Column {
        spacing: 5

        Row {
            spacing: 5

            Column {
                spacing: 5
                Text {
                    text: "Lokalizacja"
                    font.pointSize: 15
                    width: _localization.width
                    horizontalAlignment: Text.AlignHCenter
                }
                ComboBox { id: _localization }
            }

            Column {
                spacing: 5
                Text {
                    text: "Rana"
                    font.pointSize: 15
                    width: _wound.width
                    horizontalAlignment: Text.AlignHCenter
                }
                ComboBox { id: _wound }
            }

            Column {
                spacing: 5
                Text {
                    text: "Zdany test na ból"
                    font.pointSize: 15
                    horizontalAlignment: Text.AlignHCenter
                }
                CheckBox { id: _passed }
            }
        }

        Row {
            spacing: 5
            Button {
                text: "Anuluj"
                onClicked: main.close()
            }
            Button {
                text: "Dodaj"
                onClicked: {
                    main.sendWound(_localization.currentText, _wound.currentText, _passed.checked)
                    main.close()
                }
            }
        }
    }

    onStatsChanged: {
        _localization.model = stats.locations
        _wound.model = stats.woundTypes
    }

    onClosed: {
        _localization.currentIndex = 0
        _wound.currentIndex = 0
        _passed.checked = false
    }
}
