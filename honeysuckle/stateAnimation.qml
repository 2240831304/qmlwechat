import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import org.com.calculatorclient 1.1
import QtLocation 5.6
import QtQml 2.2


//stateAnimation.qml

Rectangle {
    id: root
    visible: true
    width: 150
    height: 400
//自定义属性 property <type> <name>:<value>
    property color black: '#1f1f21'
    property color red: '#fc3d39'
    property color green: '#53d769'
    property color yellow: '#ffff37'

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
    }

    Rectangle {
        id: light2
        x: 25; y: 135
        width: 100; height: width
        radius: width/2
        color: root.black
        border.color: Qt.lighter(color, 1.1)
    }
    Rectangle {
        id: light3
        x: 25; y: 255
        width: 100; height: width
        radius: width/2
        color: root.black
        border.color: Qt.lighter(color, 1.1)
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
            PropertyChanges { target: light3; color: root.yellow }
        }
    ]
//注意：在一个状态中，只需要描述属性如何从它们的默认状态改变（而不是前一个状态的改变）

    // 设置鼠标区域为全局
    MouseArea {
        anchors.fill: parent
        onClicked: {
                if(parent.state == "stop")
                parent.state = "wait";
                else if(parent.state == "wait")
                parent.state = "go";
                else
                parent.state = "stop"
                }
    }


    // 添加过渡
    transitions: [
        Transition {
            from: "stop"; to: "go"
//            from: "*"; to: "*"
            ColorAnimation { target: light1; properties: "color"; duration: 2000 }
            ColorAnimation { target: light2; properties: "color"; duration: 2000 }
        },
        Transition {
            from: "wait"; to: "go"
            ColorAnimation { target: light2; properties: "color"; duration: 2000 }
            ColorAnimation { target: light3; properties: "color"; duration: 2000 }
        }
    ]

}
