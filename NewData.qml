import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Rectangle
{
    x: 0
    y: 0
    height: 20
    id:mainrect
    property string t_id: ""
    property string task: ""
    property string date_end: ""
    property string prog: ""

    Rectangle {
        id: t_id_rect
        x: 0
        y: 0
        width: 65
        height: 20
        border.color: "#040404"

        TextEdit {
            id: textEdit
            x: 0
            y: 0
            width: 65
            height: 20
            text: t_id
            textMargin: 3
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: t_task_rect
        width: 119
        height: 20
        border.color: "#040404"
        anchors.left: t_id_rect.right

        TextEdit {
            id: textEdit1
            x: 0
            y: 0
            width: 119
            height: 20
            text: task
            textMargin: 3
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: t_datee_rect
        width: 93
        height: 20
        border.color: "#040404"
        anchors.left: t_task_rect.right

        TextEdit {
            id: textEdit4
            x: 0
            y: 0
            width: 93
            height: 20
            text: date_end
            textMargin: 3
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: t_prog_rect
        width: 79
        height: 20
        border.color: "#040404"
        anchors.left: t_datee_rect.right

        TextEdit {
            id: textEdit5
            x: 0
            y: 0
            width: 79
            height: 20
            text: prog
            textMargin: 3
            font.pixelSize: 12
        }
    }    
}



