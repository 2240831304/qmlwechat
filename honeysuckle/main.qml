
import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import org.com.calculatorclient 1.1

Window {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Calculator{
        id:calObject
    }

    Rectangle{
        //x:120
        //y:120
        width: 320
        height: 240
        color: "transparent"  //设置背景透明，否则会出现默认的白色背景
        border.color: "black"
        border.width: 2
        //anchors.verticalCenter: parent.verticalCenter
        //anchors.horizontalCenter: parent.horizontalCenter
        anchors.centerIn: parent //ju zhong

        Button{
            id:calculatorbut
            text:"计算器"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter


            //property string pressPic: "qrc:/image/123.png"
            //property string nomerPic: "qrc:/Images/001.png"
            //property string hoverPic: "qrc:/Images/002.png"
            onClicked:
            {
                console.log("calculator app Button clicked....")
                //calObject.testFunction()
                calObject.createUI()
            }

            background:Rectangle{
                implicitWidth:80
                implicitHeight:60
                color:"lightgray"
                border.width:calculatorbut.press?4:2
                border.color:(calculatorbut.hovered || calculatorbut.pressed)?"blue":"red"
            }

            //display:AbstractButton.TextBesideIcon
            //icon.source: "images/Contacts_white_round.png" //icon路径
            //icon.width:48 //宽度
            //icon.height:48 //高度
            //icon.color:"transparent" //颜色

            }

    }

}
