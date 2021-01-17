import QtQuick 2.9
import QtQuick.Controls 2.12

Text {
    property int value
    property string name
    property string type

    id: main
    text: value + " " + name
    font.pixelSize: 12

    function penalty() {
        return {
            name: main.name,
            value: main.value,
            type: main.type
        }
    }
}
