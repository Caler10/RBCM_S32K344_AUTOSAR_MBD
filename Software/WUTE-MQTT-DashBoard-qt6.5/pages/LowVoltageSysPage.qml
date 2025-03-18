import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.12
import "qrc:/common"
import Qt.JsonDataProvider 1.0

//颜色统一：黄色：#FBB72E  橙色：#FF5900   蓝色：#0081FF 红色：#FF2C1E  绿色：#82FD45 #55ee55 #1AAD19  灰色:#909090
Item {
    property int leftWidth: 150
    property int fontsize: 19
    ColumnLayout {
        anchors.fill: parent
        anchors.rightMargin: 60
        anchors.topMargin: 30
        anchors.bottomMargin: 30
        anchors.leftMargin: 60
        spacing: 20

        RowLayout {
            //spacing: 10
            YaheiText {
                text: "低压电池"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
            }
            RowLayout {
                spacing: 0
                ColumnLayout {
                    Layout.rightMargin: 60
                    NQianDial {
                        unit: "V"
                        fromData: 0
                        toData: 36
                        color: "#FBB72E"

                        Layout.preferredWidth: 160
                        Layout.preferredHeight: 160
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        value: JsonDataProvider.LvBatsV / (toData - fromData)
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
                        toData: 30
                        color: "#0081FF"

                        Layout.preferredWidth: 160
                        Layout.preferredHeight: 160
                        Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                        pixelSize: 40

                        value: JsonDataProvider.LvBatsI / (toData - fromData)
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
                        toData: 100
                        decimalCnt: 1
                        color: "#121923"

                        Layout.preferredWidth: 160
                        Layout.preferredHeight: 160
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

                        value: JsonDataProvider.LvBatsT / (toData - fromData)
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

        Rectangle {
            height: 1
            color: tingeOpacityColor
            Layout.fillWidth: true
            Layout.topMargin: 12
        }

        RowLayout {
            spacing: 160
            YaheiText {
                text: "低压设备"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.topMargin: 12
            }
            RowLayout{
                id: layout2
                anchors.centerIn: parent
                spacing: 30 //间距
                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "VCU："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata1
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: "#ffffff"
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.VcuState ? ( JsonDataProvider.VcuState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.VcuState ? ( JsonDataProvider.VcuState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "BMS："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata2
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.BmsState ? ( JsonDataProvider.BmsState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.BmsState ? ( JsonDataProvider.BmsState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "MCU："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata3
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.McuState ? ( JsonDataProvider.McuState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.McuState ? ( JsonDataProvider.McuState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                }
                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "BDU："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata4
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: "#ffffff"
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.BduState ? ( JsonDataProvider.BduState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.BduState ? ( JsonDataProvider.BduState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "BSPD："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata5
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.BspdState ? ( JsonDataProvider.BspdState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.BspdState ? ( JsonDataProvider.BspdState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "TSALR："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata6
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.TsalrState ? ( JsonDataProvider.TsalrState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.TsalrState ? ( JsonDataProvider.TsalrState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                }                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "水泵："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata7
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: "#ffffff"
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.PumpState ? ( JsonDataProvider.PumpState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.PumpState ? ( JsonDataProvider.PumpState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "风扇1："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata8
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.Fan1State ? ( JsonDataProvider.Fan1State-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.Fan1State ? ( JsonDataProvider.Fan1State-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "风扇2："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata9
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.Fan2State ? ( JsonDataProvider.Fan2State-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.Fan2State ? ( JsonDataProvider.Fan2State-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                }
                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "尾灯："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata10
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: "#ffffff"
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.TaillightState ? ( JsonDataProvider.TaillightState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.TaillightState ? ( JsonDataProvider.TaillightState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "蜂鸣器："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata11
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.BuzzerState ? ( JsonDataProvider.BuzzerState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.BuzzerState ? ( JsonDataProvider.BuzzerState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
                                radius: 5  // 设置圆角半径
                            }
                        }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "DRS："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: statedata12
                            implicitHeight: 32
                            implicitWidth: 60
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            font.family: "Microsoft Yahei"
                            color: "#ffffff"
                            text: JsonDataProvider.DrsState ? ( JsonDataProvider.DrsState-1 ? "过流" : "运行" ) : "停止"
                            enabled: false
                            cursorVisible: false    //光标不可见
                            selectByMouse: false    //不可选中文本
                            readOnly: true
                            background: Rectangle {
                                border.width: 1
                                border.color: accentColor
                                color: JsonDataProvider.DrsState ? ( JsonDataProvider.DrsState-1 ? "#FF5900" : "#0081FF" ) : "#909090"  // 设置背景颜色
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
            Layout.topMargin: 12
        }

        RowLayout {
            spacing: 160
            YaheiText {
                text: "设备功耗"
                font.pixelSize: fontsize
                Layout.preferredWidth: leftWidth
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.topMargin: 12
            }

            RowLayout{
                id: layout3
                anchors.centerIn: parent
                spacing: 20 //间距

                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "VCU："
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
                            text: JsonDataProvider.VcuValue*24/100.0 + "W"
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
                        // Connections {
                        //         target: JsonDataProvider
                        //         onDataUpdated: powerdata1.text = JsonDataProvider.carSpeed
                        //     }
                    }
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "BMS："
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
                            text: JsonDataProvider.BmsValue + "W"
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
                            text: "MCU："
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
                            text: JsonDataProvider.McuValue*24/100.0 + "W"
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
                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "BDU："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata4
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.BduValue*24/100.0 + "W"
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
                            text: "BSPD："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata5
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.BspdValue*24/100.0 + "W"
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
                            text: "TSALR："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata6
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.TsalrValue*24/100.0 + "W"
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
                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "水泵："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata7
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.PumpValue*24/100.0 + "W"
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
                            text: "风扇1："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata8
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.Fan1Value*24/100.0 + "W"
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
                            text: "风扇2："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata9
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.Fan2Value*24/100.0 + "W"
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
                ColumnLayout {
                    RowLayout {
                        Layout.alignment: Qt.AlignRight
                        YaheiText {
                            text: "尾灯："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata10
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.TaillightValue*24/100.0 + "W"
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
                            text: "蜂鸣器："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata11
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.BuzzerValue*24/100.0 + "W"
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
                            text: "DRS："
                            font.pixelSize: 16
                            //font.bold: true
                            //Layout.preferredWidth: leftWidth
                            //Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                            //Layout.topMargin: 12
                        }
                        TextField {
                            id: powerdata12
                            implicitHeight: 32
                            implicitWidth: 80
                            Layout.topMargin: 8
                            font.pixelSize: 14
                            color: accentColor
                            font.family: "Microsoft Yahei"
                            text: JsonDataProvider.DrsValue*24/100.0 + "W"
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

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
