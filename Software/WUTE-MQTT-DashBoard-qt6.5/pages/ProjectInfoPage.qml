import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtLocation 5.14
import QtQuick.Controls.Material 2.12
import Qt.labs.platform 1.0
import "qrc:/common"

Item {
    ColumnLayout {
        anchors.fill: parent
        anchors.rightMargin: 60
        anchors.topMargin: 30
        anchors.bottomMargin: 30
        anchors.leftMargin: 60
        spacing: 10

        ColumnLayout {
            spacing: 40
            Layout.bottomMargin: 50
            ColumnLayout {
                spacing: 10
                YaheiText {
                    text: "关于WUTE-MQTT-DashBoard"
                    font.pixelSize: 24
                    Layout.preferredWidth: leftWidth
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                }
                ColumnLayout {
                    YaheiText {
                        text: '作者：李家乐'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    }
                    YaheiText {
                        text: '项目前端使用了大佬诺谦的开源界面框架 原开源项目地址：<font color="${accentColorStr}"><a href="https://github.com/nuoqian-lgtm/QianWindow">github地址</a></font>'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        onLinkActivated:  Qt.openUrlExternally(link);
                    }
                    YaheiText {
                        text: '后端使用QT自带的MQTT通信API实现与后车身域控制器的数据收发'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    }
                    YaheiText {
                        text: '后端MQTT连接与订阅参考例程 项目地址：<font color="${accentColorStr}"><a href="https://doc.qt.io/qt-6/qtmqtt-quicksubscription-example.html">例程文档</a></font>'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        onLinkActivated:  Qt.openUrlExternally(link);
                    }
                    YaheiText {
                        text: '合成大西瓜非本人制作，为他人开源项目 项目地址：<font color="${accentColorStr}"><a href="https://github.com/nuoqian-lgtm/QianWindow">github地址</a></font>'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                        onLinkActivated:  Qt.openUrlExternally(link);
                    }
                }
            }
            ColumnLayout {
                spacing: 10
                YaheiText {
                    text: "WUTE-MQTT-DashBoard使用说明"
                    font.pixelSize: 24
                    Layout.preferredWidth: leftWidth
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                }
                ColumnLayout {
                    YaheiText {
                        text: '请先在连接配置界面连接至MQTT服务器'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    }
                    YaheiText {
                        text: '订阅车身域控制器的赛车数据Topic'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    }
                    YaheiText {
                        text: '回到前面的界面可以看到数据实时刷新'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    }
                    YaheiText {
                        text: '功能还在开发中...'
                        elide: text.wrap    //自动换行
                        font.pixelSize: 16
                        Layout.preferredWidth: leftWidth
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    }
                }
            }
        }
    }
}
