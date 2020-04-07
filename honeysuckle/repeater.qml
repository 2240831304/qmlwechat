import QtQuick 2.0
import QtQuick.Window 2.2

Window {
    visible: true
    width: 650
    height: 500
    title: qsTr("RepeaterDemo")
    Column{
        spacing:2
        Repeater{
            model:ListModel{
                ListElement{name:"Mercury";surfaceColor:"gray"}
                ListElement{name:"Venus";surfaceColor:"yellow"}
                ListElement{name:"Earth";surfaceColor:"blue"}
                ListElement{name:"Mars";surfaceColor:"orange"}
                ListElement{name:"Jupiter";surfaceColor:"orange"}
                ListElement{name:"Saturn";surfaceColor:"yellow"}
                ListElement{name:"Uranus";surfaceColor:"lightBlue"}
                ListElement{name:"Neptune";surfaceColor:"lightBlue"}
            }
            Rectangle{
                width: 150
                height: 50
                radius: 8
                color:"lightBlue"
                Text{
                    anchors.centerIn: parent
                    text:name
                }

                Rectangle{
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 2

                    width:32
                    height:32
                    radius: 16
                    border.color: "black"
                    border.width: 1
                    color: surfaceColor
                }
            }
        }
    }
}
