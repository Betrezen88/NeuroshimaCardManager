﻿import QtQuick 2.15
import QtQuick.Controls 2.12

import "../Elements"

Page {
    id: main

    ScrollView {
        width: main.width
        height: main.height
        clip: true

        Flow {
            width: main.width
            height: main.height
            spacing: 5

            Repeater {
                model: 10
                delegate: ReputationEdit {}
            }
        }
    }
}
