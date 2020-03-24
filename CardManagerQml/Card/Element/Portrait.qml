import QtQuick 2.0

Rectangle {
    property string file

    id: main

    border.color: "#000"
    border.width: 2
    radius: 20

    Image {
        id: image
        anchors.fill: main
        anchors.margins: 2
        fillMode: Image.PreserveAspectFit
    }

    onFileChanged: image.source = "file:///"+main.file;
}
