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
                        toData: 500
                        color: "#FBB72E"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        value: JsonDataProvider.AccuV / (toData - fromData)
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
                        fromData: 0
                        toData: 200
                        color: "#0081FF"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        value: JsonDataProvider.AccuI / (toData - fromData)
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
                        fromData: 0
                        toData: 80
                        decimalCnt: 1
                        color: "#121923"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

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

                        value: JsonDataProvider.AccuTcmax / (toData - fromData)
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "单体最高温度"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    }
                }
                ColumnLayout {
                    Layout.rightMargin: 60
                    NQianDial {
                        unit: "mV"
                        fromData: 0
                        toData: 100
                        color: "#FBB72E"

                        Layout.preferredWidth: 125
                        Layout.preferredHeight: 125
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        value: JsonDataProvider.AccudVmax / (toData - fromData)
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
                        fromData: 0
                        toData: 100
                        decimalCnt: 1
                        color: "#121923"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

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

                        value: JsonDataProvider.McuT / (toData - fromData)
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
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: "23.456W"
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
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: "23.456W"
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
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: "23.456W"
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
                        toData: 8000
                        color: "#FBB72E"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                        pixelSize: 40

                        value: JsonDataProvider.MotorRpm / (toData - fromData)
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "电机转速"
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    }
                }

                ColumnLayout {
                    Layout.rightMargin: 40
                    NQianDial {
                        unit: "N*m"
                        fromData: 0
                        toData: 2000
                        color: "#0081FF"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                        pixelSize: 40

                        value: JsonDataProvider.MotorTorque / (toData - fromData)
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "电机转矩"
                        Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    }
                }
                ColumnLayout {
                    Layout.rightMargin: 40
                    NQianDial {
                        unit: "°C"
                        fromData: 0
                        toData: 100
                        decimalCnt: 1
                        color: "#121923"

                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 150
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

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

                        value: JsonDataProvider.MotorTemp / (toData - fromData)
                    }
                    YaheiText {
                        font.pixelSize: 15
                        font.family: "Microsoft Yahei"
                        text: "电机温度"
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
