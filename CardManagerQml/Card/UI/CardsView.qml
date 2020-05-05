import QtQuick 2.0
import QtQuick.Controls 2.5

import "../"

Item {
    id: main

    ScrollView {
        id: upperPanel
        height: 40
        width: main.width

        Row {
            property var objects: []
            id: row
            spacing: 2
            anchors.fill: upperPanel

            function deselect(cardPath) {
                for ( var i in objects ) {
                    var object = objects[i];
                    if ( object.selected && object.cardPath !== cardPath )
                        object.selected = false;
                }
            }
        }
    }

    Card {
        id: card
        anchors {
            top: upperPanel.bottom
            left: main.left
            right: main.right
            bottom: main.bottom
        }
        visible: false
    }

    Connections {
        target: cardManager
        onCardsChanged: {
            var length = cardManager.cards.length;
            if ( add ) {
                var component = Qt.createComponent("CardButton.qml");
                var cardData = cardManager.cards[length-1];
                var object = component.createObject(row, {
                                                        cardPath: cardData.filePath,
                                                        fullname: cardData.stats.personal.fullname,
                                                        height: upperPanel.height
                                                    });
                object.onShow.connect(main.displayCard);
                object.onSelect.connect(row.deselect);
                row.objects.push(object);
                if ( 1 === length ) {
                    main.displayCard(cardData.filePath);
                    card.visible = true;
                    object.selected = true;
                }
            }
            else {
                if ( 0 === length ) card.visible = false;
                else {
                    displayCard(row.objects[0].cardPath);
                    row.objects[0].selected = true;
                }
            }
        }
    }

    function displayCard(cardPath) {
        card.cardData = cardManager.card(cardPath);
    }
}
