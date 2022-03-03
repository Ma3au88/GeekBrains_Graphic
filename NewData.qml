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

        TextField {
            id: textEdit4
            x: 0
            y: 0
            width: 93
            height: 20
            text: date_end
            placeholderText: qsTr("dd.mm.yyyy")
            font.pixelSize: 12
            validator: RegularExpressionValidator{regularExpression: /^(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[1,3-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$/}
        }
    }

    Rectangle {
        id: t_prog_rect
        width: 93
        height: 20
        border.color: "#040404"
        anchors.left: t_datee_rect.right

        TextField {
            id: textEdit5
            text: prog
            width: parent.width
            placeholderText: qsTr("Number 0 to 10")
            validator: RegularExpressionValidator{regularExpression: /[0-9]|10/}
        }
    }    
}
