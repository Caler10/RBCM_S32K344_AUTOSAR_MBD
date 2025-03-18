#ifndef JSONDATAPROVIDER_H
#define JSONDATAPROVIDER_H

#include <QObject>
#include <QJsonObject>
#include <QQmlEngine>
#include <QtCore/QMap>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class JsonDataProvider : public QObject
{
    Q_OBJECT
    //注册车车属性
    //测试数据
    // Q_PROPERTY(int data1 READ data1 WRITE setdata1 NOTIFY data1Changed)
    // Q_PROPERTY(int data2 READ data2 WRITE setdata2 NOTIFY data2Changed)
    //激活数据
    Q_PROPERTY(int ActButtonState READ ActButtonState WRITE setActButtonState NOTIFY ActButtonStateChanged)
    Q_PROPERTY(int ILValue READ ILValue WRITE setILValue NOTIFY ILValueChanged)
    //待驶数据
    Q_PROPERTY(int ReadyButtonState READ ReadyButtonState WRITE setReadyButtonState NOTIFY ReadyButtonStateChanged)
    Q_PROPERTY(int McuReadyState READ McuReadyState WRITE setMcuReadyState NOTIFY McuReadyStateChanged)
    Q_PROPERTY(int DriveReadyState READ DriveReadyState WRITE setDriveReadyState NOTIFY DriveReadyStateChanged)
    //低压电池监测数据
    Q_PROPERTY(int LvBatsV READ LvBatsV WRITE setLvBatsV NOTIFY LvBatsVChanged)
    Q_PROPERTY(int LvBatsI READ LvBatsI WRITE setLvBatsI NOTIFY LvBatsIChanged)
    Q_PROPERTY(int LvBatsT READ LvBatsT WRITE setLvBatsT NOTIFY LvBatsTChanged)
    //低压设备诊断分析数据
    Q_PROPERTY(int VcuState READ VcuState WRITE setVcuState NOTIFY VcuStateChanged)
    Q_PROPERTY(int BmsState READ BmsState WRITE setBmsState NOTIFY BmsStateChanged)
    Q_PROPERTY(int McuState READ McuState WRITE setMcuState NOTIFY McuStateChanged)
    Q_PROPERTY(int BduState READ BduState WRITE setBduState NOTIFY BduStateChanged)
    Q_PROPERTY(int BspdState READ BspdState WRITE setBspdState NOTIFY BspdStateChanged)
    Q_PROPERTY(int TsalrState READ TsalrState WRITE setTsalrState NOTIFY TsalrStateChanged)
    Q_PROPERTY(int PumpState READ PumpState WRITE setPumpState NOTIFY PumpStateChanged)
    Q_PROPERTY(int Fan1State READ Fan1State WRITE setFan1State NOTIFY Fan1StateChanged)
    Q_PROPERTY(int Fan2State READ Fan2State WRITE setFan2State NOTIFY Fan2StateChanged)
    Q_PROPERTY(int TaillightState READ TaillightState WRITE setTaillightState NOTIFY TaillightStateChanged)
    Q_PROPERTY(int BuzzerState READ BuzzerState WRITE setBuzzerState NOTIFY BuzzerStateChanged)
    Q_PROPERTY(int DrsState READ DrsState WRITE setDrsState NOTIFY DrsStateChanged)
    //低压设备诊断数据
    Q_PROPERTY(int VcuValue READ VcuValue WRITE setVcuValue NOTIFY VcuValueChanged)
    Q_PROPERTY(int BmsValue READ BmsValue WRITE setBmsValue NOTIFY BmsValueChanged)
    Q_PROPERTY(int McuValue READ McuValue WRITE setMcuValue NOTIFY McuValueChanged)
    Q_PROPERTY(int BduValue READ BduValue WRITE setBduValue NOTIFY BduValueChanged)
    Q_PROPERTY(int BspdValue READ BspdValue WRITE setBspdValue NOTIFY BspdValueChanged)
    Q_PROPERTY(int TsalrValue READ TsalrValue WRITE setTsalrValue NOTIFY TsalrValueChanged)
    Q_PROPERTY(int PumpValue READ PumpValue WRITE setPumpValue NOTIFY PumpValueChanged)
    Q_PROPERTY(int Fan1Value READ Fan1Value WRITE setFan1Value NOTIFY Fan1ValueChanged)
    Q_PROPERTY(int Fan2Value READ Fan2Value WRITE setFan2Value NOTIFY Fan2ValueChanged)
    Q_PROPERTY(int TaillightValue READ TaillightValue WRITE setTaillightValue NOTIFY TaillightValueChanged)
    Q_PROPERTY(int BuzzerValue READ BuzzerValue WRITE setBuzzerValue NOTIFY BuzzerValueChanged)
    Q_PROPERTY(int DrsValue READ DrsValue WRITE setDrsValue NOTIFY DrsValueChanged)
    //电池箱BMS数据
    Q_PROPERTY(int AccuV READ AccuV WRITE setAccuV NOTIFY AccuVChanged)
    Q_PROPERTY(int AccuI READ AccuI WRITE setAccuI NOTIFY AccuIChanged)
    Q_PROPERTY(int AccuTcmax READ AccuTcmax WRITE setAccuTcmax NOTIFY AccuTcmaxChanged)
    Q_PROPERTY(int AccudVmax READ AccudVmax WRITE setAccudVmax NOTIFY AccudVmaxChanged)
    //MCU数据
    Q_PROPERTY(int McuT READ McuT WRITE setMcuT NOTIFY McuTChanged)
    //电机数据
    Q_PROPERTY(int MotorRpm READ MotorRpm WRITE setMotorRpm NOTIFY MotorRpmChanged)
    Q_PROPERTY(int MotorTorque READ MotorTorque WRITE setMotorTorque NOTIFY MotorTorqueChanged)
    Q_PROPERTY(int MotorTemp READ MotorTemp WRITE setMotorTemp NOTIFY MotorTempChanged)

    //将 QObject 派生类注册为可实例化的 QML 对象类型JsonDataProvider
    QML_NAMED_ELEMENT(JsonDataProvider)
    QML_EXTENDED_NAMESPACE(JsonDataProvider)

public:
    explicit JsonDataProvider(QObject *parent = nullptr);
    static void JsonDataParse(const QByteArray package);
    static void JsonDataAnalyse();

    //定义单例
    static JsonDataProvider* instance()
    {
        if(m_instance==NULL) {
            m_instance = new JsonDataProvider();
        }
        return m_instance;
    }

    // int data1() const { return m_data1; }
    // QString data2() const { return m_data2; }

    int ActButtonState() const { return m_ActButtonState; }
    int ILValue() const { return m_ILValue; }
    int ReadyButtonState() const { return m_ReadyButtonState; }
    int McuReadyState() const { return m_McuReadyState; }
    int DriveReadyState() const { return m_DriveReadyState; }

    int LvBatsV() const { return m_LvBatsV; }
    int LvBatsI() const { return m_LvBatsI; }
    int LvBatsT() const { return m_LvBatsT; }

    int VcuState() const { return m_VcuState; }
    int BmsState() const { return m_BmsState; }
    int McuState() const { return m_McuState; }
    int BduState() const { return m_BduState; }
    int BspdState() const { return m_BspdState; }
    int TsalrState() const { return m_TsalrState; }
    int PumpState() const { return m_PumpState; }
    int Fan1State() const { return m_Fan1State; }
    int Fan2State() const { return m_Fan2State; }
    int TaillightState() const { return m_TaillightState; }
    int BuzzerState() const { return m_BuzzerState; }
    int DrsState() const { return m_DrsState; }

    int VcuValue() const { return m_VcuValue; }
    int BmsValue() const { return m_BmsValue; }
    int McuValue() const { return m_McuValue; }
    int BduValue() const { return m_BduValue; }
    int BspdValue() const { return m_BspdValue; }
    int TsalrValue() const { return m_TsalrValue; }
    int PumpValue() const { return m_PumpValue; }
    int Fan1Value() const { return m_Fan1Value; }
    int Fan2Value() const { return m_Fan2Value; }
    int TaillightValue() const { return m_TaillightValue; }
    int BuzzerValue() const { return m_BuzzerValue; }
    int DrsValue() const { return m_DrsValue; }

    int AccuV() const { return m_AccuV; }
    int AccuI() const { return m_AccuI; }
    int AccuTcmax() const { return m_AccuTcmax; }
    int AccudVmax() const { return m_AccudVmax; }
    int McuT() const { return m_McuT; }
    int MotorRpm() const { return m_MotorRpm; }
    int MotorTorque() const { return m_MotorTorque; }
    int MotorTemp() const { return m_MotorTemp; }


    // void setdata1(const int &data1) {
    //     if(data1 != m_data1) {
    //         m_data1 = data1;
    //         emit data1Changed();
    //     }
    // }
    // void setData2(const QString &data2) {
    //     if(data2 != m_data2) {
    //         m_data2 = data2;
    //         qDebug()<<"m_data2 is "<<m_data2;
    //         emit data2Changed();
    //     }
    // }

    void setActButtonState(const int &ActButtonState) {
        if(ActButtonState != m_ActButtonState) {
            m_ActButtonState = ActButtonState;
            emit ActButtonStateChanged();
        }
    }
    void setILValue(const int &ILValue) {
        if(ILValue != m_ILValue) {
            m_ILValue = ILValue;
            emit ILValueChanged();
        }
    }
    void setReadyButtonState(const int &ReadyButtonState) {
        if(ReadyButtonState != m_ReadyButtonState) {
            m_ReadyButtonState = ReadyButtonState;
            emit ReadyButtonStateChanged();
        }
    }

    void setMcuReadyState(const int &McuReadyState) {
        if(McuReadyState != m_McuReadyState) {
            m_McuReadyState = McuReadyState;
            emit McuReadyStateChanged();
        }
    }
    void setDriveReadyState(const int &DriveReadyState) {
        if(DriveReadyState != m_DriveReadyState) {
            m_DriveReadyState = DriveReadyState;
            emit DriveReadyStateChanged();
        }
    }

    void setLvBatsV(const int &LvBatsV) {
        if(LvBatsV != m_LvBatsV) {
            m_LvBatsV = LvBatsV;
            emit LvBatsVChanged();
        }
    }
    void setLvBatsI(const int &LvBatsI) {
        if(LvBatsI != m_LvBatsI) {
            m_LvBatsI = LvBatsI;
            emit LvBatsIChanged();
        }
    }
    void setLvBatsT(const int &LvBatsT) {
        if(LvBatsT != m_LvBatsT) {
            m_LvBatsT = LvBatsT;
            emit LvBatsTChanged();
        }
    }

    void setVcuState(const int &VcuState) {
        if(VcuState != m_VcuState) {
            m_VcuState = VcuState;
            emit VcuStateChanged();
        }
    }
    void setBmsState(const int &BmsState) {
        if(BmsState != m_BmsState) {
            m_BmsState = BmsState;
            emit BmsStateChanged();
        }
    }
    void setMcuState(const int &McuState) {
        if(McuState != m_McuState) {
            m_McuState = McuState;
            emit McuStateChanged();
        }
    }
    void setBduState(const int &BduState) {
        if(BduState != m_BduState) {
            m_BduState = BduState;
            emit BduStateChanged();
        }
    }
    void setBspdState(const int &BspdState) {
        if(BspdState != m_BspdState) {
            m_BspdState = BspdState;
            emit BspdStateChanged();
        }
    }
    void setTsalrState(const int &TsalrState) {
        if(TsalrState != m_TsalrState) {
            m_TsalrState = TsalrState;
            emit TsalrStateChanged();
        }
    }
    void setPumpState(const int &PumpState) {
        if(PumpState != m_PumpState) {
            m_PumpState = PumpState;
            emit PumpStateChanged();
        }
    }
    void setFan1State(const int &Fan1State) {
        if(Fan1State != m_Fan1State) {
            m_Fan1State = Fan1State;
            emit Fan1StateChanged();
        }
    }
    void setFan2State(const int &Fan2State) {
        if(Fan2State != m_Fan2State) {
            m_Fan2State = Fan2State;
            emit Fan2StateChanged();
        }
    }
    void setTaillightState(const int &TaillightState) {
        if(TaillightState != m_TaillightState) {
            m_TaillightState = TaillightState;
            emit TaillightStateChanged();
        }
    }
    void setBuzzerState(const int &BuzzerState) {
        if(BuzzerState != m_BuzzerState) {
            m_BuzzerState = BuzzerState;
            emit BuzzerStateChanged();
        }
    }
    void setDrsState(const int &DrsState) {
        if(DrsState != m_DrsState) {
            m_DrsState = DrsState;
            emit DrsStateChanged();
        }
    }

    void setVcuValue(const int &VcuValue) {
        if(VcuValue != m_VcuValue) {
            m_VcuValue = VcuValue;
            emit VcuValueChanged();
        }
    }
    void setBmsValue(const int &BmsValue) {
        if(BmsValue != m_BmsValue) {
            m_BmsValue = BmsValue;
            emit BmsValueChanged();
        }
    }
    void setMcuValue(const int &McuValue) {
        if(McuValue != m_McuValue) {
            m_McuValue = McuValue;
            emit McuValueChanged();
        }
    }
    void setBduValue(const int &BduValue) {
        if(BduValue != m_BduValue) {
            m_BduValue = BduValue;
            emit BduValueChanged();
        }
    }
    void setBspdValue(const int &BspdValue) {
        if(BspdValue != m_BspdValue) {
            m_BspdValue = BspdValue;
            emit BspdValueChanged();
        }
    }
    void setTsalrValue(const int &TsalrValue) {
        if(TsalrValue != m_TsalrValue) {
            m_TsalrValue = TsalrValue;
            emit TsalrValueChanged();
        }
    }
    void setPumpValue(const int &PumpValue) {
        if(PumpValue != m_PumpValue) {
            m_PumpValue = PumpValue;
            emit PumpValueChanged();
        }
    }
    void setFan1Value(const int &Fan1Value) {
        if(Fan1Value != m_Fan1Value) {
            m_Fan1Value = Fan1Value;
            emit Fan1ValueChanged();
        }
    }
    void setFan2Value(const int &Fan2Value) {
        if(Fan2Value != m_Fan2Value) {
            m_Fan2Value = Fan2Value;
            emit Fan2ValueChanged();
        }
    }
    void setTaillightValue(const int &TaillightValue) {
        if(TaillightValue != m_TaillightValue) {
            m_TaillightValue = TaillightValue;
            emit TaillightValueChanged();
        }
    }
    void setBuzzerValue(const int &BuzzerValue) {
        if(BuzzerValue != m_BuzzerValue) {
            m_BuzzerValue = BuzzerValue;
            emit BuzzerValueChanged();
        }
    }
    void setDrsValue(const int &DrsValue) {
        if(DrsValue != m_DrsValue) {
            m_DrsValue = DrsValue;
            emit DrsValueChanged();
        }
    }
    void setAccuV(const int &AccuV) {
        if(AccuV != m_AccuV) {
            m_AccuV = AccuV;
            emit AccuVChanged();
        }
    }
    void setAccuI(const int &AccuI) {
        if(AccuI != m_AccuI) {
            m_AccuI = AccuI;
            emit AccuIChanged();
        }
    }
    void setAccuTcmax(const int &AccuTcmax) {
        if(AccuTcmax != m_AccuTcmax) {
            m_AccuTcmax = AccuTcmax;
            emit AccuTcmaxChanged();
        }
    }
    void setAccudVmax(const int &AccudVmax) {
        if(AccudVmax != m_AccudVmax) {
            m_AccudVmax = AccudVmax;
            emit AccudVmaxChanged();
        }
    }
    void setMcuT(const int &McuT) {
        if(McuT != m_McuT) {
            m_McuT = McuT;
            emit McuTChanged();
        }
    }
    void setMotorRpm(const int &MotorRpm) {
        if(MotorRpm != m_MotorRpm) {
            m_MotorRpm = MotorRpm;
            emit MotorRpmChanged();
        }
    }
    void setMotorTorque(const int &MotorTorque) {
        if(MotorTorque != m_MotorTorque) {
            m_MotorTorque = MotorTorque;
            emit MotorTorqueChanged();
        }
    }
    void setMotorTemp(const int &MotorTemp) {
        if(MotorTemp != m_MotorTemp) {
            m_MotorTemp = MotorTemp;
            emit MotorTempChanged();
        }
    }


signals:
    //void data1Changed();
    //void data2Changed();

    void ActButtonStateChanged();
    void ILValueChanged();
    void ReadyButtonStateChanged();
    void McuReadyStateChanged();
    void DriveReadyStateChanged();

    void LvBatsVChanged();
    void LvBatsIChanged();
    void LvBatsTChanged();

    void VcuStateChanged();
    void BmsStateChanged();
    void McuStateChanged();
    void BduStateChanged();
    void BspdStateChanged();
    void TsalrStateChanged();
    void PumpStateChanged();
    void Fan1StateChanged();
    void Fan2StateChanged();
    void TaillightStateChanged();
    void BuzzerStateChanged();
    void DrsStateChanged();

    void VcuValueChanged();
    void BmsValueChanged();
    void McuValueChanged();
    void BduValueChanged();
    void BspdValueChanged();
    void TsalrValueChanged();
    void PumpValueChanged();
    void Fan1ValueChanged();
    void Fan2ValueChanged();
    void TaillightValueChanged();
    void BuzzerValueChanged();
    void DrsValueChanged();

    void AccuVChanged();
    void AccuIChanged();
    void AccuTcmaxChanged();
    void AccudVmaxChanged();
    void McuTChanged();
    void MotorRpmChanged();
    void MotorTorqueChanged();
    void MotorTempChanged();

private:
    Q_DISABLE_COPY(JsonDataProvider)
    static JsonDataProvider *m_instance;
    //int m_data1;
    //QString m_data2;

    int m_ActButtonState;
    int m_ILValue;
    int m_ReadyButtonState;
    int m_McuReadyState;
    int m_DriveReadyState;

    int m_LvBatsV;
    int m_LvBatsI;
    int m_LvBatsT;

    int m_VcuState;
    int m_BmsState;
    int m_McuState;
    int m_BduState;
    int m_BspdState;
    int m_TsalrState;
    int m_PumpState;
    int m_Fan1State;
    int m_Fan2State;
    int m_TaillightState;
    int m_BuzzerState;
    int m_DrsState;

    int m_VcuValue;
    int m_BmsValue;
    int m_McuValue;
    int m_BduValue;
    int m_BspdValue;
    int m_TsalrValue;
    int m_PumpValue;
    int m_Fan1Value;
    int m_Fan2Value;
    int m_TaillightValue;
    int m_BuzzerValue;
    int m_DrsValue;

    int m_AccuV;
    int m_AccuI;
    int m_AccuTcmax;
    int m_AccudVmax;
    int m_McuT;
    int m_MotorRpm;
    int m_MotorTorque;
    int m_MotorTemp;
};

static QObject *JsonData_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    //Q_UNUSED: 向编译器指示参数未在函数的主体中使用。这可用于抑制编译器警告
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return JsonDataProvider::instance();
}

#endif // JSONDATAPROVIDER_H
