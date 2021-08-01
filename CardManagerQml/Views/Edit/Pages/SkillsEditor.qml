import QtQuick 2.9
import QtQuick.Controls 2.12

import core.NSStats 1.0
import core.NSAttributeMod 1.0

import "../Elements"

Page {
    property NSStats stats

    id: main

    Row {
        spacing: 5

        Column {
            spacing: 5

            AttributeEdit {
                id: _body
            }

            AttributeEdit {
                id: _dexterity
            }
        }

        Column {
            spacing: 5

            AttributeEdit {
                id: _charisma
            }

            AttributeEdit {
                id: _perception
            }
        }

        Column {
            spacing: 5

            AttributeEdit {
                id: _cleaverness
            }
        }
    }

    onStatsChanged: {
        if ( null == stats )
            return
    }
}
