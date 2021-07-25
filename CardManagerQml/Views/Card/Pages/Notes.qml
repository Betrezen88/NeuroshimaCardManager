﻿import QtQuick 2.9
import QtQuick.Controls 2.12

import "../Elements"

Pane {
    id: main
//    width: 640
//    height: 480

    ScrollView {
        width: parent.width
        height: parent.height
        clip: true

        Column {
            width: implicitWidth
            height: implicitHeight
            spacing: 5

            Flow {
                width: main.width - 20
                height: implicitHeight
                spacing: 5

                Text {
                    id: _fullname
                    text: qsTr("Imie 'Ksywa' Nazwisko")
                    padding: 5
                    font.pointSize: 12
                }

                Text {
                    id: _profession
                    text: qsTr("Profesja")
                    padding: 5
                    font.pointSize: 12
                }

                Text {
                    id: _origin
                    text: qsTr("Miasto")
                    padding: 5
                    font.pointSize: 12
                }

                Text {
                    id: _age
                    text: qsTr("18 lat")
                    padding: 5
                    font.pointSize: 12
                }
            }

            Flow {
                width: main.width - 20
                height: implicitHeight
                padding: 2
                spacing: 5

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Label {
                        width: (main.width/2 - 20) < 200 ? 200 : main.width/2 - 20
                        height: 30
                        text: "Biografia"
                        color: "#fff"
                        font.pointSize: 12
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        background: Rectangle {
                            color: "#000"
                            radius: 10
                        }
                    }

                    ScrollView {
                        width: (main.width/2 - 20) < 200 ? 200 : main.width/2 - 20
                        height: 250
                        clip: true
                        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                        TextArea {
                            id: _biography
                            width: parent.width
                            height: parent.height
                            wrapMode: Text.WordWrap
                            font.pointSize: 10
                            placeholderText: qsTr("Biografia postaci")
                        }
                    }
                }

                Column {
                    width: implicitWidth
                    height: implicitHeight
                    spacing: 5

                    Label {
                        width: (main.width/2 - 20) < 200 ? 200 : main.width/2 - 20
                        height: 30
                        color: "#ffffff"
                        text: "Notatki"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        background: Rectangle {
                            color: "#000000"
                            radius: 10
                        }
                        font.pointSize: 12
                    }

                    ScrollView {
                        width: (main.width/2 - 20) < 200 ? 200 : main.width/2 - 20
                        height: 250
                        clip: true
                        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                        TextArea {
                            id: _notes
                            width: parent.width
                            height: parent.height
                            wrapMode: Text.WordWrap
                            font.pointSize: 10
                            placeholderText: qsTr("Notatki")
                        }
                    }
                }
            }

            Column {
                width: implicitWidth
                height: implicitHeight
                spacing: 5

                Label {
                    width: main.width - 20
                    height: 30
                    color: "#ffffff"
                    text: "Pytania"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    background: Rectangle {
                        color: "#000000"
                        radius: 10
                    }
                    font.pointSize: 12
                }

                Repeater {
                    id: _questions
                    model: 3
                    delegate: Question {
                        width: main.width - 20
                    }
                }
            }
        }
    }
}
