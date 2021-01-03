import QtQuick 2.0
import QtQuick.Controls 2.12

import "../Elements/Equipment"

Column {
    id: main
    spacing: 5
    
    Label {
        id: title
        height: 30
        width: main.width
        text: "Pancerz"
        color: "#fff"
        font.pointSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        background: Rectangle {
            color: "#000"
            radius: 10
        }
    }
    
    Row {
        width: parent.width
        spacing: 5
        
        Column {
            width: parent.width/2 - parent.spacing
            spacing: 5

            ArmorPiece {
                id: head
                title: "Głowa"
                width: parent.width
            }

            ArmorPiece {
                id: rHand
                title: "Prawa Ręka"
                width: parent.width
            }

            ArmorPiece {
                id: rLeg
                title: "Prawa Noga"
                width: parent.width
            }
        }
        
        Column {
            width: parent.width/2 - parent.spacing
            spacing: 5

            ArmorPiece {
                id: torso
                title: "Tułów"
                width: parent.width
            }

            ArmorPiece {
                id: lHand
                title: "Lewa Ręka"
                width: parent.width
            }

            ArmorPiece {
                id: lLeg
                title: "Lewa Noga"
                width: parent.width
            }
        }
    }
}
