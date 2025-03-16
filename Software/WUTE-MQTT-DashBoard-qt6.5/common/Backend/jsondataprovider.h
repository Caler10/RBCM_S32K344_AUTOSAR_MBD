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
    Q_PROPERTY(int data1 READ data1 WRITE setdata1 NOTIFY data1Changed)
    //Q_PROPERTY(int data2 READ data2 WRITE setdata2 NOTIFY data2Changed)

    //将 QObject 派生类注册为可实例化的 QML 对象类型JsonDataProvider
    QML_NAMED_ELEMENT(JsonDataProvider)
    QML_EXTENDED_NAMESPACE(JsonDataProvider)

public:
    explicit JsonDataProvider(QObject *parent = nullptr);
    static void JsonDataParse(const QByteArray package);

    //定义单例
    static JsonDataProvider* instance()
    {
        if(m_instance==NULL) {
            m_instance = new JsonDataProvider();
        }
        return m_instance;
    }

    int data1() const { return m_data1; }
    // QString data2() const {
    //     return m_data2;
    // }
    void setdata1(const int &data1) {
        if(data1 != m_data1) {
            m_data1 = data1;
            emit data1Changed();
        }
    }
    // void setData2(const QString &data2) {
    //     if(data2 != m_data2) {
    //         m_data2 = data2;
    //         qDebug()<<"m_data2 is "<<m_data2;
    //         emit data2Changed();
    //     }
    // }

signals:
    void data1Changed();
    //void data2Changed();

private:
    Q_DISABLE_COPY(JsonDataProvider)
    static JsonDataProvider *m_instance;
    int m_data1;
    //QString m_data2;
};

static QObject *JsonData_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    //Q_UNUSED: 向编译器指示参数未在函数的主体中使用。这可用于抑制编译器警告
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return JsonDataProvider::instance();
}

#endif // JSONDATAPROVIDER_H
