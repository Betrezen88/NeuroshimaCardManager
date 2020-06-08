﻿import QtQuick 2.14
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

import "./Views"

import core 1.0

ApplicationWindow {
    id: main
    visible: true
    width: 640
    height: 480
    title: qsTr("Neuroshima Card Manager")

    MainView {
        anchors.fill: parent
    }
}
