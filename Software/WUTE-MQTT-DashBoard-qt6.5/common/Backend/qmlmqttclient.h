#ifndef QMLMQTTCLIENT_H
#define QMLMQTTCLIENT_H

#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QTimer>
#include <QJsonObject>
#include <QQmlEngine>
#include <QtCore/QMap>
#include <QtMqtt/QMqttClient>
#include <QtQml/qqml.h>
#include <QtMqtt/QMqttSubscription>

class QmlMqttClient;

//创建一个派生类QmlMqttSubscription，负责接收报文，处理，传递数据至前端
class QmlMqttSubscription : public QObject
{
    Q_OBJECT
    //注册topic
    Q_PROPERTY(QMqttTopicFilter topic MEMBER m_topic NOTIFY topicChanged)
    QML_UNCREATABLE("Not intended to be creatable")

public:
    QmlMqttSubscription(QMqttSubscription *s, QmlMqttClient *c);
    ~QmlMqttSubscription();

Q_SIGNALS:
    void topicChanged(QString);
    void messageReceived(const QString &msg);

public slots:
    void handleMessage(const QMqttMessage &qmsg);

private:
    Q_DISABLE_COPY(QmlMqttSubscription)
    QMqttSubscription *sub; //声明一个属于QMqttSubscription类（含订阅相关的变量和函数，订阅状态、qos等等）的实例sub指针
    QmlMqttClient *client;
    QMqttTopicFilter m_topic;
};


//创建一个派生类QmlMqttSubscription，负责接收前端的客户端属性设置参数，send给MQTT API执行处理
class QmlMqttClient : public QObject
{
    Q_OBJECT
    //注册MQTT服务器连接相关属性
    Q_PROPERTY(QString hostname READ hostname WRITE setHostname NOTIFY hostnameChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString clientid READ clientid WRITE setClientid NOTIFY clientidChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QMqttClient::ClientState state READ state WRITE setState NOTIFY stateChanged)

    //将 QObject 派生类注册为可实例化的 QML 对象类型MqttClient
    QML_NAMED_ELEMENT(MqttClient)
    QML_EXTENDED_NAMESPACE(QMqttClient)

public:
    explicit QmlMqttClient(QObject *parent = nullptr);

    Q_INVOKABLE void connectToHost();
    Q_INVOKABLE void disconnectFromHost();
    Q_INVOKABLE int publish(const QString &topic, const QString &message, int qos = 0, bool retain = false);
    Q_INVOKABLE QmlMqttSubscription *subscribe(const QString &topic);

    const QString hostname() const;
    void setHostname(const QString &newHostname);

    int port() const;
    void setPort(int newPort);

    const QString username() const;
    void setUsername(const QString &newUsername);

    const QString clientid() const;
    void setClientid(const QString &newClientid);

    const QString password() const;
    void setPassword(const QString &newPassword);

    const QMqttClient::ClientState state() const;
    void setState(const QMqttClient::ClientState &newState);

signals:
    void hostnameChanged();
    void portChanged();
    void usernameChanged();
    void clientidChanged();
    void passwordChanged();

    void stateChanged();

private:
    Q_DISABLE_COPY(QmlMqttClient)
    QMqttClient m_client;

};

#endif // QMLMQTTCLIENT_H
