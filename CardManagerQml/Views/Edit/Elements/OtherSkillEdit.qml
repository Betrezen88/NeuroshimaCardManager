import QtQuick 2.9
import QtQuick.Controls 2.12

import core.edit.NSOtherSkillEdit 1.0

Row {
    property NSOtherSkillEdit otherSkillEdit

    id: main

    signal remove(NSOtherSkillEdit otherSkillEdit)

    Button {
        id: _removeBtn
        icon.source: "qrc:/icon/resources/icons/close.svg"
        width: _removeBtn.height
        onClicked: main.remove( main.otherSkillEdit )
    }

    Text {
        id: _name
        width: main.width - _value.width - _attribute.implicitWidth
               - (main.otherSkillEdit.isNew ? _removeBtn.width : 0)
        height: _value.height
        leftPadding: (main.otherSkillEdit.isNew ? 2 : 0)
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
    }

    Text {
        id: _attribute
        rightPadding: 5
        height: _value.height
        verticalAlignment: Text.AlignVCenter
    }

    SpinBox {
        id: _value
        width: 100
    }

    onOtherSkillEditChanged: {
        if ( null == otherSkillEdit )
            return

        _removeBtn.visible = otherSkillEdit.isNew
        _name.text = otherSkillEdit.name
        _attribute.text = otherSkillEdit.attributeShort
        _value.value = otherSkillEdit.value
        _value.from = otherSkillEdit.min
        _value.to = otherSkillEdit.max
        _value.enabled = otherSkillEdit.used
    }
}
