import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.12
import "qrc:/common"
import Qt.JsonDataProvider 1.0

//颜色统一：黄色：#FBB72E  橙色：#FF5900   蓝色：#0081FF  红色：#FF2C1E  绿色：#82FD45  灰色:#909090

Item {
    property int leftWidth: 150
    property int fontsize: 19
    ColumnLayout {
        anchors.fill: parent
        anchors.rightMargin: 60
        anchors.topMargin: 30
        anchors.bottomMargin: 30
        anchors.leftMargin: 60
        spacing: 10

        RowLayout {
            spacing: 180
            YaheiText {
                text: "激活信号"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
            }
            RowLayout{
                id: layout3
                anchors.centerIn: parent
                Layout.topMargin: 10
                spacing: 20 //间距
                RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "激活按钮状态："
                        font.pixelSize: 16
                        //font.bold: true
                        //Layout.preferredWidth: leftWidth
                        //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        //Layout.topMargin: 12
                    }
                    TextField {
                        id: data1
                        implicitHeight: 32
                        implicitWidth: 80
                        Layout.topMargin: 8
                        font.pixelSize: 14
                        color: "#ffffff"
                        font.family: "Microsoft Yahei"
                        text: JsonDataProvider.ActButtonState == 1 ? "   ON" :  "   OFF"
                        enabled: false
                        cursorVisible: false    //光标不可见
                        selectByMouse: false    //不可选中文本
                        readOnly: true
                        background: Rectangle {
                            border.width: 1
                            border.color: accentColor
                            color: JsonDataProvider.ActButtonState == 1 ? "#0081FF" :  "#909090"  // 设置背景颜色
                            radius: 5  // 设置圆角半径
                        }
                    }
                }                    RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "安回电流："
                        font.pixelSize: 16
                        //font.bold: true
                        //Layout.preferredWidth: leftWidth
                        //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        //Layout.topMargin: 12
                    }
                    TextField {
                        id: data2
                        implicitHeight: 32
                        implicitWidth: 80
                        Layout.topMargin: 8
                        font.pixelSize: 14
                        color: accentColor
                        font.family: "Microsoft Yahei"
                        text: JsonDataProvider.ILValue/100.0 + "A"
                        enabled: false
                        cursorVisible: false    //光标不可见
                        selectByMouse: false    //不可选中文本
                        readOnly: true
                        background: Rectangle {
                            border.width: 1
                            border.color: accentColor
                            color: !skin.gradSupport && !skin.imageSupport ? skin.contentBackColor :
                                                                             !skin.light  ? Qt.rgba(0,0,0, 0.7 - setting.skinOpacity * 0.38) : Qt.rgba(1,1,1, 0.10 + setting.skinOpacity * 0.88)  // 设置背景颜色
                            radius: 5  // 设置圆角半径
                        }
                    }
                }
                RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "远程激活："
                        font.pixelSize: 16
                        //font.bold: true
                        //Layout.preferredWidth: leftWidth
                        //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        //Layout.topMargin: 12
                    }
                    //远程激活按钮
                    BaseButton {
                        id: activeButton
                        width: 60; height: 30
                        Layout.topMargin: 8
                        implicitHeight: 32

                        text: "禁用中"
                        Layout.preferredHeight: 28
                        Layout.preferredWidth: 78
                        font.pixelSize:  14
                        backRadius: 4
                        bckcolor: "#4785FF"
                        // bckcolor: {
                        //     switch(2) {
                        //     case 1: "#00FF00"
                        //     case 2: "#FFFF00"
                        //     default: "#FF0000"
                        //     }
                        // }
                        //点击事件未启用
                    }
                }
            }
        }

        Rectangle {
            height: 1
            color: tingeOpacityColor
            Layout.fillWidth: true
            Layout.topMargin: 12
        }

        RowLayout {
            spacing: 180
            YaheiText {
                text: "待驶信号"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.topMargin: 12
            }
            RowLayout{
                id: layout2
                anchors.centerIn: parent
                //Layout.alignment: Qt.AlignCenter
                Layout.topMargin: 10
                spacing: 20 //间距
                RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "待驶按钮状态："
                        font.pixelSize: 16
                        //font.bold: true
                        //Layout.preferredWidth: leftWidth
                        //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        //Layout.topMargin: 12
                    }
                    TextField {
                        id: data11
                        implicitHeight: 32
                        implicitWidth: 80
                        Layout.topMargin: 8
                        font.pixelSize: 14
                        color: "#ffffff"
                        font.family: "Microsoft Yahei"
                        text: JsonDataProvider.ReadyButtonState == 1 ? "   ON" :  "   OFF"
                        enabled: false
                        cursorVisible: false    //光标不可见
                        selectByMouse: false    //不可选中文本
                        readOnly: true
                        background: Rectangle {
                            border.width: 1
                            border.color: accentColor
                            color: JsonDataProvider.ReadyButtonState == 1 ? "#FBB72E" :  "#909090"  // 设置背景颜色
                            radius: 5  // 设置圆角半径
                        }
                    }
                }                    RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "MCU 准备："
                        font.pixelSize: 16
                        //font.bold: true
                        //Layout.preferredWidth: leftWidth
                        //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        //Layout.topMargin: 12
                    }
                    TextField {
                        id: data12
                        implicitHeight: 32
                        implicitWidth: 80
                        Layout.topMargin: 8
                        font.pixelSize: 14
                        color: "#ffffff"
                        font.family: "Microsoft Yahei"
                        text: JsonDataProvider.McuReadyState == 1 ? "   ON" :  "   OFF"
                        enabled: false
                        cursorVisible: false    //光标不可见
                        selectByMouse: false    //不可选中文本
                        readOnly: true
                        background: Rectangle {
                            border.width: 1
                            border.color: accentColor
                            color: JsonDataProvider.McuReadyState == 1 ? "#FBB72E" :  "#909090"  // 设置背景颜色
                            radius: 5  // 设置圆角半径
                        }
                    }
                }
                RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "待驶状态："
                        font.pixelSize: 16
                        //font.bold: true
                        //Layout.preferredWidth: leftWidth
                        //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        //Layout.topMargin: 12
                    }
                    TextField {
                        id: data13
                        implicitHeight: 32
                        implicitWidth: 80
                        Layout.topMargin: 8
                        font.pixelSize: 14
                        color: "#ffffff"
                        font.family: "Microsoft Yahei"
                        text: JsonDataProvider.DriveReadyState == 1 ? "   ON" :  "   OFF"
                        enabled: false
                        cursorVisible: false    //光标不可见
                        selectByMouse: false    //不可选中文本
                        readOnly: true
                        background: Rectangle {
                            border.width: 1
                            border.color: accentColor
                            color: JsonDataProvider.DriveReadyState == 1 ? "#FBB72E" :  "#909090"  // 设置背景颜色
                            radius: 5  // 设置圆角半径
                        }
                    }
                }
            }
        }

        Rectangle {
            height: 1
            color: tingeOpacityColor
            Layout.fillWidth: true
            Layout.topMargin: 12
        }

        RowLayout {
            YaheiText {
                text: "其他关键信号"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.topMargin: 12
            }
            Rectangle {
                id: listButton_1
                width: 640
                height: 380
                //Layout.fillWidth: true
                Layout.topMargin: 20
                radius: 10
                color: tingeOpacityColor
            }

        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

}
