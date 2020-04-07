import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import org.com.calculatorclient 1.1
import QtLocation 5.6
import QtQml 2.2

Item {
    id:root
    visible: true
    width: 640
    height: 480
    objectName:"technology"

    TextInput{
        id:firstInput
        color: "black"
        text:"123"
    }

    TextInput{
        id:secondInput
        text:"456"
        anchors.top:  firstInput.bottom
        anchors.margins: 3
        anchors.left: firstInput.left
    }

    Text {
        id: resultText
        anchors.top:  secondInput.bottom
        anchors.topMargin:  3
        anchors.left: secondInput.left
        text: qsTr("")
    }

    Button{
        id:calculatorBtn
        x:2
        y:100
        width:100
        height:50
        text:"计算执行"

        onClicked:
        {
            console.log(firstInput.text)
            //CalculatorServerObject.testFunction()
            resultText.text = CalculatorServerObject.calAdd(firstInput.text,secondInput.text)
        }
    }

    Button{
        id:listmapdatatestBut
        width:100
        height:50
        anchors.left: calculatorBtn.right
        anchors.leftMargin: 3
        anchors.top: calculatorBtn.top
        text:"传递列表"

        onClicked:
        {
            var i = {
                "from" :  "xiaoguo.liu@company.com",
                "to" :  "y@mail.com",
                "message" : "This is teriffic!"
            };

            var j = ["Saab", "Volvo", "BMW"];

            CalculatorServerObject.callingFromQml(j,i)
            //changeText()
        }
    }

    Button{
        id:signalbinded
        objectName:"testtestdst"
        width:100
        height:50
        anchors.left: listmapdatatestBut.right
        anchors.leftMargin: 3
        anchors.top: listmapdatatestBut.top
        text:"信号绑定"

        onClicked:
        {
            CalculatorServerObject.connectSignal()
        }
    }

    Button{
        id:layoutManagerBut
        width:100
        height:50
        anchors.left: signalbinded.right
        anchors.leftMargin: 3
        anchors.top: signalbinded.top
        text:"布局管理器"

        onClicked:
        {
            CalculatorServerObject.createLayoutManager()
        }
    }

    Button{
        id:newWindowBut
        width:100
        height:50
        anchors.left: layoutManagerBut.right
        anchors.leftMargin: 3
        anchors.top: layoutManagerBut.top
        text:"打开新窗口"

        onClicked:
        {
            var component = Qt.createComponent("repeater.qml")
            if (component.status === Component.Ready) {
                var bQml = component.createObject(root);
                //root.visible = false
                component.visible = true
            }
        }
    }

    Connections{
        target: CalculatorServerObject
        onChangeSig:{
            console.log("surface.qml 注册的是C++对象，则需要Connections连接")
            resultText.text = "signal test"
        }
    }

    function changeText()
    {
        console.log("surface.qml function changeText()!!!!!!!!!!!!!!!")
        //CalculatorServerObject.testFunction()
    }

}
