import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.12
import "qrc:/common"
//import Qt.MqttClient 1.0
//import "ConnectConfigPage.qml" as Other

Item {
    property int leftWidth: 150
    property int fontsize: 19
    ColumnLayout {
        anchors.fill: parent
        anchors.rightMargin: 60
        anchors.topMargin: 30
        anchors.bottomMargin: 30
        anchors.leftMargin: 60
        spacing: 15

        RowLayout {
            //spacing: 10
            YaheiText {
                text: "电池箱"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
            }
            RowLayout {
                spacing: -30
                ColumnLayout {
                    Layout.rightMargin: 60
                    NQianDial {
                        unit: "V"
                        fromData: 0
                        toData: 50
                        color: "#FBB72E"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        Component.onCompleted:  setData(23)
                        onCurrentDataChanged: {
                            console.log("温度改变: ", currentData);
                        }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "电压"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    }
                }

                ColumnLayout {
                    Layout.rightMargin: 60
                    NQianDial {
                        unit: "A"
                        fromData: 100
                        toData: 200
                        color: "#0081FF"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        value: 0.6
                        //Component.onCompleted: setData(carSpeed)

                        // onCurrentDataChanged: {
                        //     console.log("电阻改变: ", currentData);
                        // }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "电流"
                        Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    }
                }

                ColumnLayout {
                    Layout.rightMargin: 60
                    NQianDial {
                        unit: "°C"
                        fromData: 10
                        toData: 100
                        decimalCnt: 1
                        color: "#121923"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        Component.onCompleted:  setData(60)

                        gradientList: [
                            {
                                offset: 0,
                                color: "#3572FF"
                            },
                            {
                                offset: 0.5,
                                color: "#82FD45"
                            },
                            {
                                offset: 0.75,
                                color: "#FBF41E"
                            },
                            {
                                offset: 1.0,
                                color: "#FF2C1E"
                            }
                        ]
                        onCurrentDataChanged: {
                            console.log("电压改变: ", currentData);
                        }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "最高温度"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    }
                }
                ColumnLayout {
                    Layout.rightMargin: 60
                    NQianDial {
                        unit: "mV"
                        fromData: 0
                        toData: 50
                        color: "#FBB72E"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        Component.onCompleted:  setData(23)
                        onCurrentDataChanged: {
                            console.log("温度改变: ", currentData);
                        }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "单体最大压差"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
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
            spacing: 80
            YaheiText {
                text: "MCU"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.topMargin: 12
            }
            RowLayout {
                spacing: 60
                ColumnLayout {
                    Layout.rightMargin: 60
                    NQianDial {
                        unit: "°C"
                        fromData: 10
                        toData: 100
                        decimalCnt: 1
                        color: "#121923"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        Component.onCompleted:  setData(60)

                        gradientList: [
                            {
                                offset: 0,
                                color: "#3572FF"
                            },
                            {
                                offset: 0.5,
                                color: "#82FD45"
                            },
                            {
                                offset: 0.75,
                                color: "#FBF41E"
                            },
                            {
                                offset: 1.0,
                                color: "#FF2C1E"
                            }
                        ]
                        onCurrentDataChanged: {
                            console.log("电压改变: ", currentData);
                        }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "MCU温度"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    }
                }
                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "预留1："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata1
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            text: "23.456W"
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
                            text: "预留2："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata2
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            text: "23.456W"
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
                            text: "预留3："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata3
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            text: "23.456W"
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
        }

        Rectangle {
            height: 1
            color: tingeOpacityColor
            Layout.fillWidth: true
        }

        RowLayout {
            spacing: 30
            YaheiText {
                text: "Motor"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                Layout.topMargin: 12

            }
            RowLayout {
                spacing: 10
                ColumnLayout {
                    Layout.rightMargin: 40
                    NQianDial {
                        unit: "rpm"
                        fromData: 0
                        toData: 50
                        color: "#FBB72E"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                        pixelSize: 40

                        Component.onCompleted:  setData(23)
                        onCurrentDataChanged: {
                            console.log("温度改变: ", currentData);
                        }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "转速"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    }
                }

                ColumnLayout {
                    Layout.rightMargin: 40
                    NQianDial {
                        unit: "N*m"
                        fromData: 100
                        toData: 200
                        color: "#0081FF"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                        pixelSize: 40

                        value: 0.6
                        //Component.onCompleted: setData(carSpeed)

                        // onCurrentDataChanged: {
                        //     console.log("电阻改变: ", currentData);
                        // }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "转矩"
                        Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    }
                }
                ColumnLayout {
                    Layout.rightMargin: 40
                    NQianDial {
                        unit: "°C"
                        fromData: 10
                        toData: 100
                        decimalCnt: 1
                        color: "#121923"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        Component.onCompleted:  setData(60)

                        gradientList: [
                            {
                                offset: 0,
                                color: "#3572FF"
                            },
                            {
                                offset: 0.5,
                                color: "#82FD45"
                            },
                            {
                                offset: 0.75,
                                color: "#FBF41E"
                            },
                            {
                                offset: 1.0,
                                color: "#FF2C1E"
                            }
                        ]
                        onCurrentDataChanged: {
                            console.log("电压改变: ", currentData);
                        }
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "温度"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
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
