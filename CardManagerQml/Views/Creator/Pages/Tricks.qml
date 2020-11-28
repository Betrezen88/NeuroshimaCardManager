import QtQuick 2.12
import QtQuick.Controls 2.12

import core.NSStatsCreator 1.0
import core.NSStatsSource 1.0
import core.NSPageCreator 1.0
import core.NSTrick 1.0
import core.NSTrickValidator 1.0
import core.NSTricksSortFilterModel 1.0

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

        Column {
            spacing: 5
            padding: 5

            Row {
                spacing: 5

                TextField {
                    id: pattern
                    width: main.width - height - 15
                    height: 40
                    placeholderText: "Wpisz szukaną frazę..."
                    onTextChanged: dataSource.tricksSort.pattern = text
                }

                ToolButton {
                    width: pattern.height
                    height: pattern.height
                    icon.source: "qrc:/icon/resources/icons/filters.svg"
                    onClicked: filterMenu.open()

                    ToolTip {
                        id: filterTooltip;
                        x: -width-2
                    }

                    Menu {
                        id: filterMenu
                        width: parent.width
                        y: parent.height
                        onClosed: filterTooltip.close()

                        MenuItem {
                            icon.source: "qrc:/icon/resources/icons/sort_asc.svg"
                            onClicked: {
                                dataSource.tricksSort.order =
                                    (Qt.AscendingOrder === dataSource.tricksSort.order)
                                    ? Qt.DescendingOrder : Qt.AscendingOrder
                                icon.source = (Qt.AscendingOrder === dataSource.tricksSort.order)
                                        ? "qrc:/icon/resources/icons/sort_asc.svg"
                                        : "qrc:/icon/resources/icons/sort_desc.svg"
                            }
                            onHoveredChanged: {
                                filterTooltip.y = y + height
                                filterTooltip.show("Sortuj")
                            }
                        }

                        MenuItem {
                            text: "Abc"
                            onClicked: {
                                var caseSensitive = dataSource.tricksSort.caseSensitive
                                dataSource.tricksSort.caseSensitive = !caseSensitive
                                text = (caseSensitive) ? "Abc" : "ABC"
                            }
                            onHoveredChanged: {
                                filterTooltip.y = y + height
                                filterTooltip.show("Uwzględnij wielkość liter")
                            }
                        }
                    }
                }
            } // Row

            Row {
                spacing: 5

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
                        height: main.height - label1.height - 15 - 40
                        border.width: 1

                        ListView {
                            property NSTricksSortFilterModel tricksModel: dataSource.tricksSort

                            id: availableTricks
                            anchors.fill: parent
                            anchors.margins: 5
                            spacing: 3
                            clip: true
                            model: tricksModel.tricks

                            delegate: Trick {
                                width: parent.width
                                name: model.name
                                index: model.index
                                added: false
                                valid:  scrollView.isValid(availableTricks.tricksModel.tricks[index])
                                onDetails: {
                                    popup.trickData = availableTricks.tricksModel.tricks[index]
                                    popup.open()
                                }
                                onAction: {
                                    statsCreator.addTrick(availableTricks.tricksModel.tricks[index])
                                    manager.cardCreator.creationPointsManager().spendTrick(1)
                                }

                                Connections {
                                    target: manager.cardCreator.pageCreator(NSPageCreator.STATS)
                                    onStatsChanged: valid = scrollView.isValid(availableTricks.tricksModel.tricks[index])
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
                        height: main.height - label2.height - 15 - 40
                        border.width: 1

                        ListView {
                            id: ownedTricks
                            anchors.fill: parent
                            anchors.margins: 5
                            spacing: 3
                            clip: true
                            model: statsCreator.tricks

                            delegate: Trick {
                                width: parent.width
                                valid: scrollView.isValid(statsCreator.tricks[index])
                                added: true
                                name: model.name
                                onDetails: {
                                    popup.trickData = statsCreator.tricks[index]
                                    popup.open()
                                }
                                onAction: {
                                    manager.cardCreator.creationPointsManager().refundTrick(1)
                                    statsCreator.removeTrick(statsCreator.tricks[index])
                                }

                                Connections {
                                    target: manager.cardCreator.pageCreator(NSPageCreator.STATS)
                                    onStatsChanged: valid = scrollView.isValid(statsCreator.tricks[index])
                                }
                            }
                        }
                    }

                } // Column
            } // Row
        } // Column

        function isValid(trickData) {
            return scrollView.validator.fulfillsRequirements(
                        manager.cardCreator.pageCreator(NSPageCreator.STATS),
                        trickData )
        }

    } // ScrollView

    TrickDetails {
        id: popup
        width: (main.width - (main.width * 0.3))
        height: (main.height - (main.height * 0.3))
    }
}
