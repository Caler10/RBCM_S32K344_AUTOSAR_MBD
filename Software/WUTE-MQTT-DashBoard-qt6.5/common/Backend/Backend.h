#ifndef Backed_H
#define Backed_H

#include <QtNetwork/QNetworkReply>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QQmlEngine>

namespace HttpApi
{

};
// 后端通用类,负责与后端和前端交互
// 诺谦 2022-08-20
class Backend : public QObject
{
    Q_OBJECT

public:

    Q_INVOKABLE  bool saveFile(QString path, const QString& data);
    Q_INVOKABLE  bool copyFile(QString path, QString newPath);
    Q_INVOKABLE  QString importFile(QString path);
    Q_INVOKABLE  bool fileExists(QString path);



    Backend(QObject *parent = 0);
    static Backend* instance()
    {
        if(m_instance==NULL) {
            m_instance = new Backend();
        }
        return m_instance;
    }

signals:
    // 消息提示窗口提示
    void errorMessage(QString msg);
    void successMessage(QString msg);
    void infoMessage(QString msg);
    void modalMessage(QString msg, int msec = 2000);
    void message(QString msg, int msec = 2000);


private slots:

protected:


private:
    static Backend *m_instance;       // 阻塞实例
};


//定义一个回调类指针,用于接收回调.
static QObject *Backend_qobject_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    //Q_UNUSED: 向编译器指示参数未在函数的主体中使用。这可用于抑制编译器警告
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return Backend::instance();
}

#endif
