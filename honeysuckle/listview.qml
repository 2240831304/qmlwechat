import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2


Window{
    visible:true
    width:200;
    height:200
    ListModel{  //数据模型
            id:listModel
            ListElement{
                name:"Bill"
                number:"5553264"
            }
            ListElement{
                name:"John"
                number:"5558426"
            }
            ListElement{
                name:"Sum";
                number:"5550473"
            }
    }

    Component{     //代理
        id:delegate
        Item{
            id:wrapper;
            width:200;
            height:40

        Column{
                x:5;
                y:5
                Text{text:"<b>Name:</b>"+name}
                Text{text:"<b>Number:</b>"+number}
            }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.ListView.view.currentIndex = index
            }
        }

        }
    }

    Component{   //高亮条
        id:highlight
        Rectangle{color:"lightsteelblue";radius:5}
    }

    ListView{  //视图
           id: view
            width:parent.width;
            height:parent.height
            model:listModel  //关联数据模型
            delegate:delegate  //关联代理
            highlight:highlight  //关联高亮条
            focus:true  //可以获得焦点，这样就可以响应键盘了

            onCurrentIndexChanged: {
                console.log(view.currentIndex)
                console.log("name:" + listModel.get(view.currentIndex).name)
                console.log("number:" + listModel.get(view.currentIndex).number)
            }
    }


}
