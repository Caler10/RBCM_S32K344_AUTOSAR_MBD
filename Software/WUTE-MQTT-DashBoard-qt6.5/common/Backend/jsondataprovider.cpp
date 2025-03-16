#include "jsondataprovider.h"

JsonDataProvider* JsonDataProvider::m_instance = NULL;

JsonDataProvider::JsonDataProvider(QObject *parent)
    : QObject(parent)
{

}


void JsonDataProvider::JsonDataParse(QByteArray package)
{
    qDebug()<<package;
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(package, &err_rpt);//字符串格式化为JSON
    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON格式错误";
    }
    //{"cSpeed":10,"Pos":"20"}
    else
    {
        QJsonObject root_Obj = root_Doc.object();

        m_instance->setdata1(root_Obj.value("data1").toInt());  //地速
        // setRmotorTemp(root_Obj.value("rmoTemp").toInt()); //氧传感器
        // setLmotorSpeed(root_Obj.value("lmSpeed").toInt());//发动机转速
        // setRmotorSpeed(root_Obj.value("rmSpeed").toInt());
        // setMcu1Temp(root_Obj.value("mcu1Temp").toInt()); //机油温度
        // setMcu2Temp(root_Obj.value("mcu2Temp").toInt()); //发动机温度
        // setBatTemp(root_Obj.value("bTemp").toInt());   //ECU温度
        // setBatLevel(root_Obj.value("bLevel").toInt());
        // setGearMode(root_Obj.value("gMode").toInt()); //挡位 Gear
        // setCarMode(root_Obj.value("cMode").toInt());
        // setBatAlarm(root_Obj.value("bAlarm").toInt());  //低压电池电量报警
        // setMotorSpeed(root_Obj.value("lmSpeed").toInt());
        // setTimeCount(root_Obj.value("timeCount").toInt());
        // setBatVol(root_Obj.value("batVol").toInt());   //低压电池电量
        // setCarDistance(root_Obj.value("carDistce").toInt());
        // setBrakeTravel(root_Obj.value("brakeTravel").toInt());

        //m_instance->setdata1(root_Obj.value("data1").toInt());  //数值解析测试
        //m_instance->setData2(root_Obj.("data2").toString());  //字符串解析测试
        //qDebug()<<"message is "<<m_instance->data1();
    }
}
