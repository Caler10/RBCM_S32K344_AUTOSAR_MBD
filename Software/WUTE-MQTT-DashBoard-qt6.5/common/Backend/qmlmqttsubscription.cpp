#if 0

#include "qmlmqttsubscription.h"

//类QmlMqttSubscription里的成员函数QmlMqttSubscription(QMqttSubscription *s, QmlMqttClient *c)
QmlMqttSubscription::QmlMqttSubscription(QMqttSubscription *s, QmlMqttClient *c)
    : sub(s)
    , client(c) //在构造函数体之前初始化这些成员变量，使得代码更加高效和清晰。 例如： MyClass(int num1, int num2) : m_num1(num1), m_num2(num2)
{
    //messageReceived函数被发射（触发），QmlMqttSubscription类的handleMessage函数立即执行处理（只有定义过这个信号的类及其派生类能够发射这个信号）（函数调用）
    connect(sub, &QMqttSubscription::messageReceived, this, &QmlMqttSubscription::handleMessage);
    m_topic = sub->topic();
}

QmlMqttSubscription::~QmlMqttSubscription()
{
}

QmlMqttSubscription* QmlMqttSubscription::subscribe(const QString &topic)
{
    auto sub = QmlMqttClient::m_client.subscribe(topic, 0);
    auto result = new QmlMqttSubscription(sub, this);
    return result;
}

void QmlMqttSubscription::handleMessage(const QMqttMessage &qmsg)
{
    emit messageReceived(qmsg.payload());   //发射函数
}

#endif
