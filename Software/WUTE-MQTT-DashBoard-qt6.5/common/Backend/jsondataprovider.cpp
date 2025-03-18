#include "jsondataprovider.h"

JsonDataProvider* JsonDataProvider::m_instance = NULL;

JsonDataProvider::JsonDataProvider(QObject *parent)
    : QObject(parent)
{
}


void JsonDataProvider::JsonDataParse(QByteArray package)
{
    qDebug()<<package;
    QJsonParseError parseError;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(package, &parseError);//字符串格式化为JSON
    if(parseError.error != QJsonParseError::NoError)
    {
        qWarning() << "JSON 解析错误:" << parseError.errorString();

        // 检查是否为 JSON 对象
        if (!root_Doc.isObject()) {
            qWarning() << "JSON 数据不是对象格式";
        }
    }
    //{"cSpeed":10,"Pos":"20"}
    else
    {
        QJsonObject root_Obj = root_Doc.object();

        // 数值解析测试用例
        // if (root_Obj.contains("data1") && root_Obj["data1"].isDouble()) {
        //     m_instance->setdata1(root_Obj["data1"].toInt());
        //     qDebug()<<"data1 is "<<m_instance->data1();
        // } else { qWarning() << "data1 字段缺失或类型错误"; }
        // 字符串解析测试用例
        // if (root_Obj.contains("data2") && root_Obj["data2"].isString()) {
        //     m_instance->setdata2(root_Obj["data2"].toString());
        //     qDebug()<<"data2 is "<<m_instance->data2();
        // } else { qWarning() << "BmsValue 字段缺失或类型错误"; }

        //关键信号数据
        m_instance->setActButtonState(root_Obj["ActButtonState"].toInt());              //激活按钮状态
        m_instance->setILValue(root_Obj["ILValue"].toInt());                            //安全回路电流诊断数据
        m_instance->setReadyButtonState(root_Obj["ReadyButtonState"].toInt());          //待驶按钮状态
        m_instance->setMcuReadyState(root_Obj["McuReadyState"].toInt());                //MCU ready状态
        m_instance->setDriveReadyState(root_Obj["DriveReadyState"].toInt());            //待驶状态
        //低压电池监测数据
        m_instance->setLvBatsV(root_Obj["LvBatsV"].toInt());              //低压电池电压
        m_instance->setLvBatsI(root_Obj["LvBatsI"].toInt());              //低压电池输出电流
        m_instance->setLvBatsT(root_Obj["LvBatsT"].toInt());              //低压电池温度
        //低压设备诊断分析数据
        m_instance->setVcuState(root_Obj["VcuState"].toInt());              //VcuState
        m_instance->setBmsState(root_Obj["BmsState"].toInt());              //BmsState
        m_instance->setMcuState(root_Obj["McuState"].toInt());              //McuState
        m_instance->setBduState(root_Obj["BduState"].toInt());              //BduState
        m_instance->setBspdState(root_Obj["BspdState"].toInt());            //BspdState
        m_instance->setTsalrState(root_Obj["TsalrState"].toInt());          //TsalrState
        m_instance->setPumpState(root_Obj["PumpState"].toInt());            //PumpState
        m_instance->setFan1State(root_Obj["Fan1State"].toInt());            //Fan1State
        m_instance->setFan2State(root_Obj["Fan2State"].toInt());            //Fan2State
        m_instance->setTaillightState(root_Obj["TaillightState"].toInt());  //TaillightState
        m_instance->setBuzzerState(root_Obj["BuzzerState"].toInt());        //BuzzerState
        m_instance->setDrsState(root_Obj["DrsState"].toInt());              //DrsState
        //低压设备诊断数据
        m_instance->setVcuValue(root_Obj["VcuValue"].toInt());              //VcuValue
        m_instance->setBmsValue(root_Obj["BmsValue"].toInt());              //BmsValue
        m_instance->setMcuValue(root_Obj["McuValue"].toInt());              //McuValue
        m_instance->setBduValue(root_Obj["BduValue"].toInt());              //BduValue
        m_instance->setBspdValue(root_Obj["BspdValue"].toInt());            //BspdValue
        m_instance->setTsalrValue(root_Obj["TsalrValue"].toInt());          //TsalrValue
        m_instance->setPumpValue(root_Obj["PumpValue"].toInt());            //PumpValue
        m_instance->setFan1Value(root_Obj["Fan1Value"].toInt());            //Fan1Value
        m_instance->setFan2Value(root_Obj["Fan2Value"].toInt());            //Fan2Value
        m_instance->setTaillightValue(root_Obj["TaillightValue"].toInt());  //TaillightValue
        m_instance->setBuzzerValue(root_Obj["BuzzerValue"].toInt());        //BuzzerValue
        m_instance->setDrsValue(root_Obj["DrsValue"].toInt());              //DrsValue
        //高压系统数据
        m_instance->setAccuV(root_Obj["AccuV"].toInt());              //VcuValue
        m_instance->setAccuI(root_Obj["AccuI"].toInt());              //BmsValue
        m_instance->setAccuTcmax(root_Obj["AccuTcmax"].toInt());              //McuValue
        m_instance->setAccudVmax(root_Obj["AccudVmax"].toInt());              //BduValue
        m_instance->setMcuT(root_Obj["McuT"].toInt());            //BspdValue
        m_instance->setMotorRpm(root_Obj["MotorRpm"].toInt());          //TsalrValue
        m_instance->setMotorTorque(root_Obj["MotorTorque"].toInt());            //PumpValue
        m_instance->setMotorTemp(root_Obj["MotorTemp"].toInt());            //Fan1Value


        qDebug()<<"VcuValue is "<<m_instance->VcuValue();
        qDebug()<<"BmsValue is "<<m_instance->BmsValue();
    }
}
