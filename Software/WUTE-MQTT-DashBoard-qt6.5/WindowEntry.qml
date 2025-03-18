import QtQuick 2.12
import Qt5Compat.GraphicalEffects   //QtGraphicalEffects 1.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import Qt.Singleton 1.0
import "qrc:/common"
import "qrc:/common/qmlQianDialog"
import "qrc:/common/qmlQianHints"

Rectangle {
    id: windowEntry

    color: skin.mainColor
    gradient: skin.gradient

    //全屏可点，可转移焦点
    MouseArea {
        id: mouseAreaAll
        anchors.fill: parent
        onClicked: {
            mouseAreaAll.forceActiveFocus()
        }
    }

    Message{
        id:messageTip
        z: 1
        parent: Overlay.overlay
    }

    function message(type, message) {
        if(type!=='success'&&type!=='error'&&type!=='info'){
            return false
        }
        messageTip.open(type, message)
    }

    //开屏弹窗
    // BlogDialog {
    //     id: skinQianDialog
    //     backParent: windowEntry
    //     parent: Overlay.overlay
    //     onAccept: {
    //         message('success', "You clicked the confirm button!")
    //         skinQianDialog.close();
    //     }
    // }

    // Component.onCompleted: {
    //     skinQianDialog.dialogOpen()
    // }


    layer.enabled: skin.windowShadow && !appStartAnimation.running && !rootWindow.maximized? true : false
    layer.effect: DropShadow {
        color: "#000000"
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0
        WindowTilte {
            color: skin.titleColor
            Layout.fillWidth: true
            Layout.preferredHeight: contentList.fullscreen ? 0 :  42
            Layout.alignment: Qt.AlignTop
            Behavior on Layout.preferredHeight {
                NumberAnimation { duration: 300 }
            }
            clip: true

        }
        ContentList { // ContentList
            id: contentList
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    SequentialAnimation {
        id: appStartAnimation
        running: true
        NumberAnimation { target: windowEntry;
            properties: "scale"; from: 0.3; to: 1.0; easing.type: Easing.InOutQuad; duration: 200 }

    }



}
