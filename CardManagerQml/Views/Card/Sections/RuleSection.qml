import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    property alias title: _title.text
    property var rows: []
    property int firstColWidth: 0

    id: main
    spacing: 5

    Rectangle {
        width: main.width
        height: 50
        color: "#000"

        Row {
            spacing: 5
            anchors.fill: parent

            Text {
                id: _title
                width: main.width - _visibility.width - 5
                anchors.verticalCenter: parent.verticalCenter
                text: "Section Title"
                color: "#fff"
                font.pointSize: 12
                font.bold: true
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
            }

            CheckBox {
                id: _visibility
                checked: false
                anchors.verticalCenter: parent.verticalCenter
                onCheckedChanged: updateItems(setChildVisibility, checked)
            }
        }
    } // Rectangle

    onRowsChanged: {
        for ( var i in rows ) {
            var component = Qt.createComponent("../Elements/RulesRow.qml")
            var object = component.createObject(main, {
                                                    dark: i % 2 === 0,
                                                    items: rows[i],
                                                    width: main.width,
                                                    visible: _visibility.checked
                                                })
            if ( main.firstColWidth < object.firstColWidth )
                main.firstColWidth = object.firstColWidth
            else
                object.firstColWidth = main.firstColWidth
        }
    }

    onWidthChanged: updateItems(setChildWidth, width)
    onFirstColWidthChanged: updateItems(setChildFirstColWidth, firstColWidth)

    function updateItems(method, param) {
        for ( var index in children )
            if ( index > 0 )
                method(children[index], param)
    }
    function setChildWidth(child, width) {
        child.width = width
    }
    function setChildFirstColWidth(child, firstColWidth) {
        child.firstColWidth = firstColWidth
    }
    function setChildVisibility(child, visibility) {
        child.visible = visibility
    }
}
