import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.12
import "qrc:/common"
import Qt.MqttClient 1.0
import Qt.JsonDataProvider 1.0

Item {
    id: root
    property int leftWidth: 130
    property int fontsize: 18
    property int subfontsize: 15

    property var tempSubscription: 0
    property var tempPublication: 0

    MqttClient {
        id: client
        hostname: hostnameField.text
        port: portField.text
        username: usernameField.text
        clientid: clientidField.text
        password: passwordField.text

        state: {
            if (client.state === MqttClient.Connected) {
                message('success', "connected to server!")
            }
        }
    }

    ListModel {
        id: messageModel
    }

    function addMessage(payload)
    {
        messageModel.insert(0, {"payload" : payload})

        if (messageModel.count >= 100)
            messageModel.remove(99)
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.rightMargin: 60
        anchors.topMargin: 30
        anchors.bottomMargin: 30
        anchors.leftMargin: 60
        spacing: 20

        RowLayout {
            ColumnLayout {
                spacing: 165
                YaheiText {
                    text: "连接服务器"
                    font.pixelSize: fontsize
                    Layout.preferredWidth: leftWidth
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                }
                //连接按钮
                SkinBaseButton {
                    id: connectButton
                    width: 60; height: 30
                    implicitHeight: 32
                    font.pixelSize:  14
                    backRadius: 4
                    text: client.state === MqttClient.Connected ? "Disconnect" : "Connect"
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
            ColumnLayout {
                spacing: 6
                //设置主机名
                RowLayout {
                    spacing: 5
                    //Hostname标签
                    YaheiText {
                        text: "Hostname:"
                        enabled: client.state === MqttClient.Disconnected   //与后端通信
                        font.pixelSize: subfontsize    //设置字体像素大小
                        Layout.preferredWidth: leftWidth    //设置布局首选宽度
                        Layout.alignment: Qt.AlignLeft    // 设置布局对齐方式为顶部和左对齐
                    }
                    //Hostname输入栏
                    TextField {
                        id: hostnameField
                        implicitHeight: 40
                        Layout.fillWidth: true
                        font.pixelSize: 14
                        font.family: "Microsoft Yahei"
                        text: "2ac4d9928b.st1.iotda-device.cn-east-3.myhuaweicloud.com"
                        placeholderText: "<Enter host running MQTT broker>"
                        enabled: client.state === MqttClient.Disconnected
                        selectByMouse: true //是否可以选择文本
                        selectionColor: "#999999"//选中背景颜色
                        // background: Rectangle {
                        //                 border.width: 1; border.color: "#FFFFFF"
                        //                 radius: 5; color: "#000000";
                        //                 opacity: 0.50
                        //                 implicitHeight: 8; implicitWidth: 280
                        //             }
                    }
                }
                //设置端口号
                RowLayout {
                    spacing: 5
                    //端口号标签
                    YaheiText {
                        text: "Port:"
                        enabled: client.state === MqttClient.Disconnected   //与后端通信
                        font.pixelSize: subfontsize    //设置字体像素大小
                        Layout.preferredWidth: leftWidth    //设置布局首选宽度
                        Layout.alignment: Qt.AlignLeft    // 设置布局对齐方式为顶部和左对齐
                    }
                    //端口号输入栏
                    TextField {
                        id: portField
                        implicitHeight: 40
                        Layout.fillWidth: true
                        font.pixelSize: 14
                        font.family: "Microsoft Yahei"
                        text: "1883"
                        placeholderText: "<Port>"
                        inputMethodHints: Qt.ImhDigitsOnly
                        enabled: client.state === MqttClient.Disconnected
                        selectByMouse: true //是否可以选择文本
                        selectionColor: "#999999"//选中背景颜色
                        // background: Rectangle {
                        //                 border.width: 0; border.color: "red"
                        //                 radius: 4; color: "#FFFFFF";
                        //                 opacity: 0.05
                        //                 implicitHeight: 25//; implicitWidth: 280
                        //             }
                    }
                }
                //设置Username
                RowLayout {
                    spacing: 5
                    //Username标签
                    YaheiText {
                        text: "Username:"
                        enabled: client.state === MqttClient.Disconnected   //与后端通信
                        font.pixelSize: subfontsize    //设置字体像素大小
                        Layout.preferredWidth: leftWidth    //设置布局首选宽度
                        Layout.alignment: Qt.AlignLeft    // 设置布局对齐方式为顶部和左对齐
                    }
                    //Username输入栏
                    TextField {
                        id: usernameField
                        implicitHeight: 40
                        Layout.fillWidth: true
                        font.pixelSize: 14
                        font.family: "Microsoft Yahei"
                        text: "Client_14141414"
                        placeholderText: "<Username>"
                        enabled: client.state === MqttClient.Disconnected
                        selectByMouse: true //是否可以选择文本
                        selectionColor: "#999999"//选中背景颜色
                        // background: Rectangle {
                        //                 border.width: 0; border.color: "red"
                        //                 radius: 4; color: "#FFFFFF";
                        //                 opacity: 0.05
                        //                 implicitHeight: 25//; implicitWidth: 280
                        //             }
                    }
                }
                //设置ClientID
                RowLayout {
                    spacing: 5
                    YaheiText {
                        text: "ClientID:"
                        enabled: client.state === MqttClient.Disconnected   //与后端通信
                        font.pixelSize: subfontsize    //设置字体像素大小
                        Layout.preferredWidth: leftWidth    //设置布局首选宽度
                        Layout.alignment: Qt.AlignLeft    // 设置布局对齐方式为顶部和左对齐
                    }
                    TextField {
                        id: clientidField
                        implicitHeight: 40
                        Layout.fillWidth: true
                        font.pixelSize: 14
                        font.family: "Microsoft Yahei"
                        text: "Client_14141414_0_0_2024120715"
                        placeholderText: "<ClientID>"
                        enabled: client.state === MqttClient.Disconnected
                        selectByMouse: true //是否可以选择文本
                        selectionColor: "#999999"//选中背景颜色
                        // background: Rectangle {
                        //                 border.width: 0; border.color: "red"
                        //                 radius: 4; color: "#FFFFFF";
                        //                 opacity: 0.05
                        //                 implicitHeight: 25//; implicitWidth: 280
                        //             }
                    }
                }
                //设置Password
                RowLayout {
                    spacing: 5
                    YaheiText {
                        text: "Password:"
                        enabled: client.state === MqttClient.Disconnected   //与后端通信
                        font.pixelSize: subfontsize    //设置字体像素大小
                        Layout.preferredWidth: leftWidth    //设置布局首选宽度
                        Layout.alignment: Qt.AlignLeft    // 设置布局对齐方式为顶部和左对齐
                    }
                    TextField {
                        id: passwordField
                        implicitHeight: 40
                        Layout.fillWidth: true
                        font.pixelSize: 14
                        font.family: "Microsoft Yahei"
                        text: "bab97a626de697b5bcd4c2cc74bc58899efa32d059ad46dbea9489c375f30fa0"
                        placeholderText: "<Password>"
                        enabled: client.state === MqttClient.Disconnected
                        selectByMouse: true //是否可以选择文本
                        selectionColor: "#999999"//选中背景颜色
                        // background: Rectangle {
                        //                 border.width: 0; border.color: "red"
                        //                 radius: 4; color: "#FFFFFF";
                        //                 opacity: 0.05
                        //                 implicitHeight: 25//; implicitWidth: 280
                        //             }
                        echoMode: TextInput.Password //密码模式
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
            //主标题
            YaheiText {
                text: "订阅Topic"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                Layout.topMargin: -10
            }

            RowLayout {
                spacing: 30
                TextField {
                    id: subField
                    implicitHeight: 40
                    text: "wute/car/test"
                    placeholderText: "<Subscription topic>"
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                    Layout.fillWidth: true
                    enabled: client.state === MqttClient.Connected && root.tempSubscription === 0
                }
                SkinBaseButton {
                    id: subButton
                    text: "Subscribe"
                    visible: client.state === MqttClient.Connected && root.tempSubscription === 0
                    width: 60; height: 30
                    implicitHeight: 32
                    font.pixelSize:  14
                    backRadius: 4
                    onClicked: {
                        if (subField.text.length === 0) {
                            console.log("No topic specified to subscribe to.")
                            message('info', "No topic specified to subscribe to.")
                            return
                        }
                        tempSubscription = client.subscribe(subField.text)
                        tempSubscription.messageReceived.connect(addMessage) //tempSubscription.messageReceived.connect(addMessage)
                    }
                }
            }
        }

        Rectangle {
            height: 1
            color: tingeOpacityColor
            Layout.fillWidth: true
        }

        RowLayout {
            YaheiText {
                text: "发布Topic"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                Layout.topMargin: -10

            }
            RowLayout {
                spacing: 30
                TextField {
                    id: pubField
                    implicitHeight: 40
                    text: "wute/client/test"
                    placeholderText: "<Publication topic>"
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                    Layout.fillWidth: true
                    enabled: client.state === MqttClient.Connected && root.tempPublication === 0
                }

                SkinBaseButton {
                    id: pubButton
                    text: "  Publish  "
                    visible: client.state === MqttClient.Connected && root.tempPublication === 0
                    width: 60; height: 30
                    implicitHeight: 32
                    font.pixelSize:  14
                    backRadius: 4
                    onClicked: {
                        if (subField.text.length === 0) {
                            console.log("No topic specified to publish to.")
                            message('info', "No topic specified to publish to.")
                            return
                        }
                        tempPublication = client.subscribe(subField.text)
                        tempPublication.messageReceived.connect(addMessage)
                    }
                }
            }
        }

        Rectangle {
            height: 1
            color: tingeOpacityColor
            Layout.fillWidth: true
        }

        RowLayout {
            YaheiText {
                text: "运行日志"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.topMargin: 6

            }
            ColumnLayout {  //ColumnLayout
                spacing: 20
                Rectangle {
                    id:background1
                    z: 100
                    radius: 5
                    //width: 650
                    height: 160
                    color: tingeOpacityColor
                    Layout.fillWidth: true
                    ListView {
                        id: messageView
                        model: messageModel
                        implicitHeight: background1.height
                        implicitWidth: background1.width
                        Layout.columnSpan: 2
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        clip: true

                        delegate: Rectangle {
                            id: delegatedRectangle
                            required property int index
                            required property string payload
                            width: ListView.view.width
                            height: 30
                            color: index % 2 ? "#DDDDDD" : "#888888"
                            radius: 5

                            function stateToString(value) {
                                if (value === 0)
                                    return "Disconnected"
                                else if (value === 1)
                                    return "Connecting"
                                else if (value === 2)
                                    return "Connected"
                                else
                                    return "Unknown"
                            }

                            Text {
                                text: "Status: " + stateToString(client.state) + "(" + client.state + ") " + delegatedRectangle.payload
                                // elide: text.wrap    //自动换行 有问题
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

    }

}
