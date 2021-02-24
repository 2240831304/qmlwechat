import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import org.com.calculatorclient 1.1
import QtLocation 5.6
import QtQml 2.2

Window {
    width: 200
    height: 200
    visible: true

    Rectangle {
        id: rect
        width: 100
        height: 100
        color: "red"

        //设置移动动画，时间为0.5秒
        Behavior on x {PropertyAnimation {duration: 500} }
        Behavior on y {PropertyAnimation {duration: 500} }
    }
    //到达鼠标点击的位置
    MouseArea {
        anchors.fill: parent
        onClicked: {rect.x = mouse.x; rect.y = mouse.y}
    }
}
