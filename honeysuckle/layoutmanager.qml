import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


Window {
    id:root
    visible: true
    width: 640
    height: 480

    Text {
        id: mytextid
        text: qsTr("textefefrfrfr")
    }

    GridLayout{
           id: gridLayout1
           columns: 2;
           rows:2;
           anchors.top: mytextid.bottom
           anchors.left: mytextid.left
           anchors.fill: parent ;
           //anchors.margins: 5;
           columnSpacing: 0;
           rowSpacing: 0;

           Rectangle{
               id:rect00;
               color: "red";
               Layout.fillWidth: true;
               Layout.fillHeight: true;
           }

           Rectangle{
               id:rect01;
               color: "blue";
               Layout.fillWidth: true;
               Layout.fillHeight: true;
           }

           Rectangle{
               id:rect10;
               color: "green";
               Layout.fillWidth: true;
               Layout.fillHeight: true;
               Layout.row:1;
               Layout.column: 1;
           }

       }



}
