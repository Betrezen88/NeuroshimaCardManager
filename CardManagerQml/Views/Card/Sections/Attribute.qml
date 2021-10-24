import QtQuick 2.9

import core.view.NSAttribute 1.0

import "./../Elements"
import "../../Common/Elements" as CommonElements

Rectangle {
    property NSAttribute attribute

    id: main
    height: _column.implicitHeight

    color: "#cac6c6"
    border.color: "#000"
    border.width: 1

    Column {
        id: _column
        spacing: 3
        padding: 5

        Text {
            id: _title
            padding: 5
            font.pointSize: 14
            width: main.width - _column.padding*2
        }

        CommonElements.ValueBoxRow {
            id: _valueRow
            width: main.width - _column.padding*2
        }

        Repeater {
            id: _skillpacks
            delegate: Skillpack {
                width: main.width - _column.padding*2
                skillpack: modelData
            }
        }
    }

    onAttributeChanged: {
        _valueRow.value = (attribute != null) ? attribute.value : 0
        _title.text = (attribute != null) ? attribute.name : ""
        _skillpacks.model = (attribute != null) ? attribute.skillpacks : []
    }
}
