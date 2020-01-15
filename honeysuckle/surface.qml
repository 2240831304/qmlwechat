import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    visible: true
    width: 640
    height: 480

    Button{
        id:myBtn
        x:300
        y:100
        width:100
        height:50
        text:"OK"

        onClicked:
        {
            CalculatorServerObject.testFunction()
        }
    }
}
