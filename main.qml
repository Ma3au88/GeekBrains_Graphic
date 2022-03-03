import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import com.vv.reader 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Reader v. 1.0")

    property string ns: 'NewData{width:640; height:20;}'
    property string ts: 'NewData{width:640; height:20;'
    property int num: 0

    ScrollView {
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        anchors.fill: parent
        Component.onCompleted:
        {
            loader.loadBase()
        }

        ColumnLayout {
            id:list
            y:35
        }
    }

    Reader{
        id : loader
        onInitEnd:
        {
            if (succeed)
            {
              loader.getNextRecord()
              Qt.createQmlObject(ns, list, "objdata")
            }
            else
            {
                Qt.quit()
            }
        }
        onLoad:
        {
            var total = ts + 't_id:"' + id + '";task:"' + task + '";date_end:"' + date_end + '";prog:"' + prog +'";}'
            Qt.createQmlObject(total, list, "obj" + (++num))
            loader.getNextRecord()
        }
    }

    Rectangle {
        id: id_rect
        x: 0
        y: 0
        width: 65
        height: 40
        border.color: "#040404"

        Text {
            id: id_label
            x: 18
            y: 8
            text: qsTr("ID")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: task_rect
        width: 119
        height: 40
        border.color: "#040404"
        anchors.left: id_rect.right

        Text {
            id: task_label
            x: 41
            y: 8
            text: qsTr("Задача")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: dateend_rect
        width: 93
        height: 40
        border.color: "#040404"
        anchors.left: task_rect.right

        Text {
            id: dateend_label
            x: 13
            y: 2
            text: qsTr("Срок\nвыполнения")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: progress_rect
        width: 93
        height: 40
        border.color: "#040404"
        anchors.left: dateend_rect.right

        Text {
            id: progress_label
            x: 14
            y: 8
            text: qsTr("Прогресс")
            font.pixelSize: 12
        }
    }

    Button {
        id: addData
        text: qsTr("Добавить")
        anchors.left: progress_rect.right
        Component.onCompleted: {
            width=100
            height=40
        }
        onClicked:
        {
            var data_id = list.data[num].data[0].data[0].text
            var data_task = list.data[num].data[1].data[0].text
            var data_dateend = list.data[num].data[2].data[0].text
            var data_prog = list.data[num].data[3].data[0].text
            loader.writeNewInformation(data_id, data_task, data_dateend, data_prog)
            Qt.createQmlObject(ns, list, "objdata")
            num++
        }
    }

    Label {
        id: label
        text: "Количество задач: " + num
        anchors.left: addData.right
    }
}
