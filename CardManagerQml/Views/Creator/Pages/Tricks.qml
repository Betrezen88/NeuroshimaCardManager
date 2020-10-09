import QtQuick 2.12
import QtQuick.Controls 2.12

import core.NSStatsCreator 1.0
import core.NSStatsSource 1.0
import core.NSPageCreator 1.0
import core.NSTrick 1.0
import core.NSTrickValidator 1.0

import "./../Elements"

Page {
    property NSStatsSource dataSource
    property NSStatsCreator statsCreator

    id: main

    ScrollView {
        property NSTrickValidator validator: manager.cardCreator.trickValidator()

        id: scrollView
        width: parent.width
        height: parent.height
        clip: true

        Row {
            spacing: 5
            padding: 5

            Column {
                spacing: 5

                Label {
                    id: label1
                    text: "Dostępne"
                    width: (main.width / 2) - 12 < 250 ? 250 : (main.width / 2) - 12
                    horizontalAlignment: Text.AlignHCenter
                    font.weight: Font.Bold
                    font.pointSize: 14
                }

                Rectangle {
                    width: (main.width / 2) - 12 < 250 ? 250 : (main.width / 2) - 12
                    height: main.height - label1.height - 15
                    border.width: 1

                    ListView {
                        id: availableTricks
                        anchors.fill: parent
                        anchors.margins: 5
                        spacing: 3
                        clip: true

                        delegate: Trick {
                            width: parent.width
                            valid: scrollView.isValid(trickData)
                            added: false
                            trickData: dataSource.tricks[model.index]
                            onDetails: {
                                popup.trickData = trickData
                                popup.open()
                            }
                            onAction: statsCreator.addTrick(trickData)

                            Connections {
                                target: manager.cardCreator.pageCreator(NSPageCreator.STATS)
                                onStatsChanged: valid = scrollView.isValid(trickData)
                            }
                        }
                    }
                }
            } // Column

            Column {
                spacing: 5

                Label {
                    id: label2
                    width: (main.width / 2) - 12 < 250 ? 250 : (main.width / 2) - 12
                    text: "Posiadane"
                    horizontalAlignment: Text.AlignHCenter
                    font.weight: Font.Bold
                    font.pointSize: 14
                }

                Rectangle {
                    width: (main.width / 2) - 12 < 250 ? 250 : (main.width / 2) - 12
                    height: main.height - label2.height - 15
                    border.width: 1

                    ListView {
                        id: ownedTricks
                        anchors.fill: parent
                        anchors.margins: 5
                        spacing: 3
                        clip: true

                        delegate: Trick {
                            width: parent.width
                            valid: scrollView.isValid(trickData)
                            added: true
                            trickData: statsCreator.tricks[model.index]
                            onDetails: {
                                popup.trickData = trickData
                                popup.open()
                            }
                            onAction: statsCreator.removeTrick(trickData)

                            Connections {
                                target: manager.cardCreator.pageCreator(NSPageCreator.STATS)
                                onStatsChanged: valid = scrollView.isValid(trickData)
                            }
                        }

                        model: statsCreator.tricks
                    }
                }

            } // Column
        } //Row

        function isValid(trickData) {
            return scrollView.validator.fulfillsRequirements(
                        manager.cardCreator.pageCreator(NSPageCreator.STATS),
                        trickData )
        }

    } //ScrollView

    TrickDetails {
        id: popup
        width: (main.width - (main.width * 0.3))
        height: (main.height - (main.height * 0.3))
    }

    onDataSourceChanged: availableTricks.model = dataSource.tricks
}
