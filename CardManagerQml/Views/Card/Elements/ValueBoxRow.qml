import QtQuick 2.0

Item {
    property int value
    property var mods: [
        { name: "Łat.", value: 2 },
        { name: "Prz.", value: 0 },
        { name: "Pro.", value: -2 },
        { name: "Tru.", value: -5 },
        { name: "B.T.", value: -8 },
        { name: "Ch.T.", value: -11 },
        { name: "Fuks", value: -15 }
    ]

    id: main

    Row {
        property variant objects: []
        id: row
        spacing: 3
        anchors.fill: main
    }

    onValueChanged: {
        for ( var i in main.mods ) {
            var component = Qt.createComponent("ValueBox.qml");
            var object = component.createObject(row, {
                                                    name: main.mods[i].name,
                                                    mod: main.mods[i].value,
                                                    value: main.value,
                                                    width: valueBoxWidth()
                                                });
            row.objects.push(object);
        }
        main.height = row.objects[0].height;
    }

    function valueBoxWidth() {
        return Math.floor((main.width-row.spacing*(mods.length-1))/mods.length);
    }
}
