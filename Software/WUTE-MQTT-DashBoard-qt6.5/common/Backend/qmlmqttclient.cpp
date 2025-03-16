#include <QDebug>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QMqttTopicName>
#include "qmlmqttclient.h"
#include "jsondataprovider.h"

QmlMqttClient::QmlMqttClient(QObject *parent)
    : QObject(parent)
{
    connect(&m_client, &QMqttClient::hostnameChanged, this, &QmlMqttClient::hostnameChanged);
    connect(&m_client, &QMqttClient::portChanged, this, &QmlMqttClient::portChanged);
    connect(&m_client, &QMqttClient::usernameChanged, this, &QmlMqttClient::usernameChanged);
    connect(&m_client, &QMqttClient::clientIdChanged, this, &QmlMqttClient::clientidChanged);
    connect(&m_client, &QMqttClient::passwordChanged, this, &QmlMqttClient::passwordChanged);
    connect(&m_client, &QMqttClient::stateChanged, this, &QmlMqttClient::stateChanged);
}

//类QmlMqttSubscription里的成员函数QmlMqttSubscription(QMqttSubscription *s, QmlMqttClient *c)
QmlMqttSubscription::QmlMqttSubscription(QMqttSubscription *s, QmlMqttClient *c)
    : sub(s)
    , client(c) //在构造函数体之前初始化这些成员变量，使得代码更加高效和清晰。 例如： MyClass(int num1, int num2) : m_num1(num1), m_num2(num2)
{
    //messageReceived函数触发，handleMessage函数执行处理（函数调用）
    connect(sub, &QMqttSubscription::messageReceived, this, &QmlMqttSubscription::handleMessage);
    m_topic = sub->topic();
}

QmlMqttSubscription::~QmlMqttSubscription()
{
}

void QmlMqttClient::connectToHost()
{
    m_client.connectToHost();
}

void QmlMqttClient::disconnectFromHost()
{
    m_client.disconnectFromHost();
}


const QString QmlMqttClient::hostname() const
{
    return m_client.hostname();
}

void QmlMqttClient::setHostname(const QString &newHostname)
{
    m_client.setHostname(newHostname);
}

int QmlMqttClient::port() const
{
    return m_client.port();
}

void QmlMqttClient::setPort(int newPort)
{
    if (newPort < 0 || newPort > std::numeric_limits<quint16>::max()) {
        qWarning() << "Trying to set invalid port number";
        return;
    }
    m_client.setPort(static_cast<quint16>(newPort));
}

const QString QmlMqttClient::username() const
{
    return m_client.username();
}

void QmlMqttClient::setUsername(const QString &newUsername)
{
    m_client.setUsername(newUsername);
}

const QString QmlMqttClient::clientid() const
{
    return m_client.clientId();
}

void QmlMqttClient::setClientid(const QString &newClientid)
{
    m_client.setClientId(newClientid);
}

const QString QmlMqttClient::password() const
{
    return m_client.password();
}

void QmlMqttClient::setPassword(const QString &newPassword)
{
    m_client.setPassword(newPassword);
}


const QMqttClient::ClientState QmlMqttClient::state() const
{
    return m_client.state();
}

void QmlMqttClient::setState(const QMqttClient::ClientState &newState)
{
    m_client.setState(newState);
}

int QmlMqttClient::publish(const QString &topic, const QString &message, int qos, bool retain)
{
    auto result = m_client.publish(QMqttTopicName(topic), message.toUtf8(), qos, retain);
    return result;
}

QmlMqttSubscription* QmlMqttClient::subscribe(const QString &topic)
{
    auto sub = m_client.subscribe(topic, 0);
    auto result = new QmlMqttSubscription(sub, this);
    return result;
}


void QmlMqttSubscription::handleMessage(const QMqttMessage &qmsg)
{
    //发射原始报文
    emit messageReceived(qmsg.payload());   //发射函数
    JsonDataProvider::JsonDataParse(qmsg.payload());
}





