import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.12
import "qrc:/common"

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
                        font.family: "Microsoft Yahei"
                        text: "闭合"
                        enabled: disable
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
                }                    RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "安全回路电流："
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
                        font.family: "Microsoft Yahei"
                        text: "3.453A"
                        enabled: disable
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
                    SkinBaseButton {
                        id: activeButton
                        width: 60; height: 30
                        Layout.topMargin: 8
                        implicitHeight: 32
                        font.pixelSize:  14
                        backRadius: 4
                        text: "ActButton"
                        onClicked:{
                            if (client.state === MqttClient.Connected) {
                                client.disconnectFromHost()
                                messageModel.clear()
                                root.tempSubscription.destroy()
                                root.tempSubscription = 0
                                root.tempPublication.destroy()
                                root.tempPublication = 0
                            }
                            else if(client.state !== MqttClient.Connected){
                                client.connectToHost()
                            }
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
                        font.family: "Microsoft Yahei"
                        text: "断开"
                        enabled: disable
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
                }                    RowLayout {
                    Layout.alignment: Qt.AlignRight
                    YaheiText {
                        text: "MCU Ready："
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
                        font.family: "Microsoft Yahei"
                        text: "Ready"
                        enabled: disable
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
                        font.family: "Microsoft Yahei"
                        text: "已进"
                        enabled: disable
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
