#if 0

#ifndef QMLMQTTSUBSCRIPTION_H
#define QMLMQTTSUBSCRIPTION_H

#include <QObject>
#include <QtCore/QMap>
#include <QtMqtt/QMqttClient>
#include "qmlmqttclient.h"
#include <QtMqtt/QMqttSubscription>

class QmlMqttClient;

//创建一个派生类QmlMqttSubscription，继承基类QObject
class QmlMqttSubscription : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QMqttTopicFilter topic MEMBER m_topic NOTIFY topicChanged)
    QML_UNCREATABLE("Not intended to be creatable")
public:
    QmlMqttSubscription(QMqttSubscription *s, QmlMqttClient *c);
    ~QmlMqttSubscription();

    Q_INVOKABLE QmlMqttSubscription *subscribe(const QString &topic);

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

#endif // QMLMQTTSUBSCRIPTION_H

#endif
