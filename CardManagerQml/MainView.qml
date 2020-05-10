import QtQuick 2.0

import "./Card/UI"
import "./Creator"

Item {
    property string currentView
    property var creator

    id: main

    CardsView {
        id: cardsView
        width: main.width
        height: main.height
    }

    onCurrentViewChanged: {
        var component = Qt.createComponent(currentView);

        if (component.status !== Component.Ready) {
            console.log("Error loading component:", component.errorString());
        }

        main.creator = component.createObject(main, {
                                                width: main.width,
                                                height: main.height,
                                                z: 2
                                            });
    }
}
