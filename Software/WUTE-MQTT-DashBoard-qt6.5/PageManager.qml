import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import "qrc:/common"
import "qrc:/pages"
import "qrc:/pages/QianProjectPages/QianMergeWatermelonPage"

StackLayout {
    id: stack
    clip: true
    function switchPage(name) {
        for (var i = 0; i < stack.data.length; i++) {
            if (stack.data[i].name == name) {
                stack.currentIndex = i;
                break;
            }
        }
    }

    CoreInfoPage {
        property string name: "关键信息"
        width: stack.width
        height: stack.height

    }
    LowVoltageSysPage {
        property string name: "低压系统"
        width: stack.width
        height: stack.height
    }
    HighVoltageSysPage{
        property string name: "高压系统"
        width: stack.width
        height: stack.height
    }

    ConnectConfigPage {
        property string name: "连接配置"
        width: stack.width
        height: stack.height
    }

    QianMergeWatermelonPage {
        property string name: "合成大西瓜"
        width: stack.width
        height: stack.height
    }

    ProjectInfoPage {
        property string name: "关于本项目"
        width: stack.width
        height: stack.height
    }


 }
