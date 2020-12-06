import QtQuick 2.12
import QtQuick.Controls 2.12

Row {
    property var items: []
    property bool dark
    property int firstColWidth: 0

    id: main
    spacing: 5

    onItemsChanged: {
        var heightObj;
        for ( var i in items ) {
            var component = Qt.createComponent("RulesCell.qml")
            var object = component.createObject(main, {
                                                    text: items[i],
                                                    dark: main.dark,
                                                    isFirst: parseInt(i) === 0
                                                })
            if (object.isFirst) {
                main.firstColWidth = object.width
                heightObj = object
            }
            heightObj = (heightObj.text.length < object.text.length)
                    ? object : heightObj
        }
        heightObj.changeHeight.connect(function(height){
            for (var c in children) {
                children[c].height = height
            }
        })
    }

    onFirstColWidthChanged: updateItems(setItemWidth)
    onWidthChanged: updateItems(setItemWidth)

    function updateItems(method) {
        for (var item in children)
            method(children[item])
    }
    function setItemWidth(item) {
        if ( item === null ) return

        if ( item.isFirst )
            item.width = (children.length > 1) ? main.firstColWidth : main.width
        else if ( children.length === 2 )
            item.width = main.width - main.firstColWidth
        else
            item.width = (main.width - main.firstColWidth) / (children.length - 1)
    }
}
