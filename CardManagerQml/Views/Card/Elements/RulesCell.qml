import QtQuick 2.15

Rectangle {
    property alias text: _text.text
    property bool dark
    property bool isFirst

    signal changeHeight(int height)

    id: main
    width: _text.implicitWidth
    height: _text.implicitHeight
    color: (dark) ? "gray" : "lightGray"

    Text {
        id: _text
        padding: 5
        font.pointSize: 12
        font.bold: isFirst
        anchors.fill: main
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: isFirst ? Text.AlignHCenter : Text.AlignLeft

        onImplicitHeightChanged: {
            main.height = implicitHeight
            main.changeHeight(main.height)
        }
    }

    onDarkChanged: main.color = (dark) ? "gray" : "lightGray"
}
