import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtLocation 5.6
import QtQml 2.2


//stateAnimation.qml

Rectangle {
    id: root
    visible: true
    width: 200
    height: 400
//自定义属性 property <type> <name>:<value>
    property color black: '#1f1f21'
    property color red: '#fc3d39'
    property color green: '#53d769'
    property color yellow: '#ffff37'

    property int redtime: 6
    property int greentime: 4
    property int yellowtime: 3

//颜色渐变
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#2ed5fa" }
        GradientStop { position: 1.0; color: "#2467ec" }
    }


    Rectangle {
        id: light1
        x: 25; y: 15
        width: 100; height: width
        radius: width/2
        color: root.black
        border.color: Qt.lighter(color, 1.1)
        Text {
            id: redtext
            anchors.centerIn: parent
            //text: root.redtime
        }

    }

    Rectangle {
        id: light2
        x: 25; y: 135
        width: 100; height: width
        radius: width/2
        color: root.black
        border.color: Qt.lighter(color, 1.1)

        Text {
            id: greentext
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: light3
        x: 25; y: 255
        width: 100; height: width
        radius: width/2
        color: root.black
        border.color: Qt.lighter(color, 1.1)

        Text {
            id: yellowtext
            anchors.centerIn: parent
        }
    }

    // 默认状态为“stop”
    state: "stop"

    states: [
        State {
            name: "stop"
            PropertyChanges { target: light1; color: root.red }
            PropertyChanges { target: light2; color: root.black }
        },
        State {
            name: "go"
            PropertyChanges { target: light1; color: root.black }
            PropertyChanges { target: light2; color: root.green }
        },
        State {
            name: "wait"
            PropertyChanges { target: light1; color: root.black }
            PropertyChanges { target: light2; color: root.black }
            PropertyChanges { target: light3; color: root.yellow; }
            PropertyChanges { target: yellowtext;text:root.yellowtime; }
        }
    ]
//注意：在一个状态中，只需要描述属性如何从它们的默认状态改变（而不是前一个状态的改变）

    // 设置鼠标区域为全局
    MouseArea {
        anchors.fill: parent
        onClicked: {
            redtimer.start()
            redtext.text = root.redtime
//            if(parent.state == "stop")
//                parent.state = "wait";
//            else if(parent.state == "wait")
//                parent.state = "go";
//            else
//                parent.state = "stop"
        }
    }

    // 添加过渡
    transitions: [
//        Transition {
//            from: "stop"; to: "go"
//            ColorAnimation { target: light1; properties: "color"; duration: 2000 }
//            ColorAnimation { target: light2; properties: "color"; duration: 2000 }
//        },
//        Transition {
//            from: "wait"; to: "go"
//            ColorAnimation { target: light2; properties: "color"; duration: 2000 }
//            ColorAnimation { target: light3; properties: "color"; duration: 2000 }
//        }

//        Transition {
//            from: "stop"; to: "wait"
//            //ColorAnimation { target: light2; properties: "color"; duration: 2000 }
//            ColorAnimation { target: light3; properties: "color"; duration: 1000 }
//        }
    ]


    Timer{
        id:redtimer;
        interval: 1000; //定时周期
        repeat:true
        triggeredOnStart:false
        onTriggered: {
             //console.log("tttttttttttttttttt")
            root.redtime--
            if(root.redtime == 0){
                redtimer.stop()
                parent.state = "wait";
                redtext.text = ""
                //yellowtext.text = root.yellowtime

                yellowtimer.start()
            }else{
                redtext.text = root.redtime
            }

        }

    }

    Timer{
        id:yellowtimer;
        interval: 1000; //定时周期
        repeat:true
        triggeredOnStart: false
        onTriggered: {
            root.yellowtime--
            if(root.yellowtime == 0){
                yellowtimer.stop()
                parent.state = "go";
                yellowtext.text = ""

                greentext.text = root.greentime
                greentimer.start()
            }else{
                yellowtext.text = root.yellowtime
            }

        }

    }

    Timer{
        id:greentimer;
        interval: 1000; //定时周期
        repeat:true
        triggeredOnStart: false
        onTriggered: {
            root.greentime--
            if(root.greentime == 0){
                greentimer.stop()
                parent.state = "stop";
                greentext.text = ""
            }else{
                greentext.text = root.greentime
            }

        }

    }


}
