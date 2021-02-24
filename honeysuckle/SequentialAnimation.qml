import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import org.com.calculatorclient 1.1
import QtLocation 5.6
import QtQml 2.2
//SequentialAnimation

Window {
    id: root
    visible: true
    width: 640
    height: 380
    property int duration: 3000

    // M1>>
    Rectangle {
        id: sky
        width: parent.width
        height: 200
        //设置颜色渐变
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#0080FF" }
            GradientStop { position: 1.0; color: "#66CCFF" }
        }
    }
    Rectangle {
        id: ground
        anchors.top: sky.bottom
        anchors.bottom: root.bottom
        width: parent.width
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#00FF00" }
            GradientStop { position: 1.0; color: "#00803F" }
        }
    }
    // <<M1

    // M2>>
    Image {
        id: ball
        x: 0; y: root.height-height
        source: "qrc:/image/close.png"

        MouseArea {
            anchors.fill: parent
            //点击后初始化
            onClicked: {
                ball.x = 0;
                ball.y = root.height-ball.height;
                ball.rotation = 0;
                anim.restart()
            }
        }
    }
    // <<M2

    // M3>>
    //平行动画
    ParallelAnimation {
        id: anim
        //插入连续动画
        SequentialAnimation {
            //Y方向上升
            NumberAnimation {
                target: ball
                properties: "y"
                to: 20
                duration: root.duration * 0.4
                //设置缓冲曲线风格
                easing.type: Easing.OutCirc
            }
            //Y方向下降
            NumberAnimation {
                target: ball
                properties: "y"
                to: root.height-ball.height
                duration: root.duration * 0.6
                easing.type: Easing.OutBounce
            }
        }
        //X方向移动
        NumberAnimation {
            target: ball
            properties: "x"
            to: root.width-ball.width
            duration: root.duration
        }
        //角度旋转
        RotationAnimation {
            target: ball
            properties: "rotation"
            to: 720
            duration: root.duration
        }
    }
    // <<M3


}
