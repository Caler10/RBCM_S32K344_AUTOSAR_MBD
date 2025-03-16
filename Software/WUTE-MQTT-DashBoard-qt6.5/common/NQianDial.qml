import QtQuick 2.12
import QtQuick.Controls 2.14
import "qrc:/common"

Dial {
    id:dial;

    property real fromData: 0                        // 起始值
    property real toData: 50                         // 结束值
    property real valueScope: toData - fromData
    property int decimalCnt: 0                       // 小数点数量
    property string unit: "°C"                       // 值单位
    property color color: "#FBB72E"
    property alias pixelSize : _text.font.pixelSize  // 数字大小,根据位数个人自定义
    property real lineWidth : dial.background.width * 0.075     // 动态设定,无需更改

    readonly  property real currentData: (dial.value * valueScope + fromData).toFixed(decimalCnt)  // 实时值(只读)

    property var gradientList: null                 // 渐变颜色,内容为{offset,  color}

    // 设置当前实时值
    function setData(data) {
        if(data < fromData) data = fromData
        else if(data > toData) data = toData

        value = (data-fromData) / valueScope
    }


    value: 0


    onAngleChanged: {
        canvas.requestPaint()
    }

    handle: Rectangle {
      id: handleItem
      x: dial.background.x + dial.background.width / 2 - width / 2
      y: dial.background.y + dial.background.height / 2 - height / 2

      width:  dial.lineWidth * 1.5
      height: width
      color: gradientList == null ? dial.color : "#646464"
      radius: width/2
      antialiasing: true
      opacity: dial.enabled ? 1 : 0.3
      Rectangle {
        width: parent.width*0.6
        height: width
        anchors.centerIn: parent
        radius: width/2
        color: gradientList == null ? "#121923" :  "#323232"
      }
      transform: [
          Translate {
              y: -Math.min(dial.background.width, dial.background.height) * 0.5 +(handleItem.width)/3
          },
          Rotation {
              angle: dial.angle
              origin.x: handleItem.width / 2
              origin.y: handleItem.height / 2
          }
      ]
    }
    background: Item {
        x: dial.width / 2 - width / 2
        y: dial.height / 2 - height / 2
        width: Math.max(64, Math.min(dial.width, dial.height))
        height: width
        opacity: dial.enabled ? 1 : 0.3

        Canvas {
            id: canvas
            anchors.fill: parent
            antialiasing: true
            smooth: true

            function fillDialPlate(ctx) {
                ctx.strokeStyle  = "#323232"
                ctx.lineWidth  = dial.lineWidth
                ctx.lineCap = "round"
                ctx.beginPath()


                ctx.arc(0,0, width/2 - ctx.lineWidth/2, Math.PI - Math.PI * 0.277777777777, 0.277777777777*Math.PI, false)

                ctx.stroke()
            }

            function fillPassDialPlate(ctx) {

                ctx.lineWidth  = dial.lineWidth
                ctx.lineCap = "round"
                ctx.beginPath()

                let an = (dial.angle - (-140)) / 180 * Math.PI

                if(gradientList != null) {
                    var grd=ctx.createConicalGradient(0,0, -0.27777777778*Math.PI);  // 渐变逆时针

                    for(let i = 0; i < gradientList.length; i++) {
                        grd.addColorStop((1.0 - gradientList[i].offset) * 0.777778,
                                         gradientList[i].color)
                    }
                    ctx.strokeStyle  = grd
                } else {
                    ctx.strokeStyle  = dial.color
                }


                ctx.arc(0,0, width/2 - ctx.lineWidth/2,
                        Math.PI - Math.PI * 0.277777777777,
                        Math.PI - Math.PI * 0.277777777777 + an, false)

                ctx.stroke()
            }

            onPaint: {
                var ctx = getContext("2d");
                ctx.clearRect(0,0, canvas.width, canvas.height);
                ctx.save()
                ctx.translate(width/2, height/2)
                fillDialPlate(ctx)
                fillPassDialPlate(ctx)
                ctx.restore()
            }
        }

    }
    YaheiText {
        id: _text
        anchors.centerIn: parent;
        anchors.verticalCenterOffset: dial.background.height * 0.05
        anchors.horizontalCenterOffset: -  dial.background.height * 0.035
        //color:"#FFF";
        font.family: "Microsoft Yahei";
        font.bold: true;
        font.pixelSize: 75
        text: currentData
        YaheiText {
            anchors.left: parent.right
            anchors.top: parent.top
            anchors.topMargin:  dial.background.height * 0.05
            //color:"#FFF";
            font.family: "Microsoft Yahei";
            font.pixelSize: parent.font.pixelSize / 3;
            text: unit;
        }
    }

    width: 200;
    height: 200;


}
