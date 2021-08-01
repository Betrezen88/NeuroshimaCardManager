import QtQuick 2.15
import QtQuick.Controls 2.12

Page {
    id: main

    Flow {
        width: main.width
        height: main.height
        spacing: 5

        Repeater {
            model: 10
            delegate: Row {
                spacing: 5
                Text { text: "Miejsce" }
                SpinBox {  }
            }
        }
    }
}
