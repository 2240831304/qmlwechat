
import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import org.com.calculatorclient 1.1
import QtLocation 5.6
import QtQml 2.2

Window {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello App")

    Calculator{
        id:calObject
        onTestSig:{
            console.log("main.qml 注册的是C++类，那么可以在QML中实例化对象的时候直接捕获")
            calculatorName.text = "计算器1"
        }
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
            state: "normal"
            //text:"计算器"
            //implicitWidth:80
            //implicitHeight:60
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            Image{
                anchors.fill: parent
                source: "qrc:/image/calculator.png"
            }

            onClicked:
            {
                console.log("calculator app Button clicked....")
                //calObject.testFunction()

                calObject.createUI()

//                var component = Qt.createComponent("qrc:/calculatorqml/surface.qml")
//                if (component.status === Component.Ready) {
//                    var bQml = component.createObject(root);
//                    root.visible = false
//                    component.visible = true
//                }
            }

            background:Rectangle {
                implicitWidth:80
                implicitHeight:60
                color:"lightgray"
                border.width:calculatorbut.press?4:2
                border.color:(calculatorbut.hovered || calculatorbut.pressed)?"blue":"red"
            }

            //background: Image{
            //    source: "qrc:/image/calculator.png"
            //}

            }

        Text {
            id:calculatorName
            anchors.top : calculatorbut.bottom
            anchors.margins: 2
            anchors.left: calculatorbut.left
            width:calculatorbut.width
            height:30
            text:"计算器"
        }

    }

}
