import QtQuick 2.12
import QtQuick.Controls 2.5

Rectangle {
    property string name
    property string value
    property string description

    id: main

    height: title.height

    border.color: "#000"
    border.width: 2
    radius: 10

    ToolTip {
        id: tooltip
        visible: false
    }

    Text {
        id: title
        width: main.width
        padding: 5
        font.pointSize: 10
        textFormat: Text.RichText
        wrapMode: Text.WordWrap

        onTextChanged: main.height = title.height;
    }

    MouseArea {
        anchors.fill: main
        onPressed: {
            if ( 0 < main.description.length )
                tooltip.visible = !tooltip.visible;
        }
    }

    onNameChanged: title.text = "<b>"+main.name+":</b> "+main.value;
    onValueChanged: title.text = "<b>"+main.name+":</b> "+main.value;
    onDescriptionChanged: tooltip.text = main.description;

    Component.onCompleted: main.height = title.height;
}
