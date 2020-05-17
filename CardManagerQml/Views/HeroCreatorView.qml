import QtQuick 2.0
import QtQuick.Controls 2.12

SwipeView {
    id: main

    Page {
        id: page1
        width: main.width
        height: main.height

        Rectangle {
            color: "yellow"
            anchors.fill: parent
        }

        Component.onCompleted: console.log("Page.size(w/h):",
                                           width, height)
    }

    Component.onCompleted: console.log("HeroCreateView.size(w/h):",
                                       width, height)
}
