#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include <QDir>
#include "frameless.h"
#include "qmlmqttclient.h"
#include "jsondataprovider.h"

int main(int argc, char *argv[])
{
    //用于设置Qt应用程序支持高DPI显示，在QT6中无效，默认启用
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("Some organization");
    QApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    qmlRegisterType<FramelessWindow>("Qt.Window", 1, 0, "Frameless");
    qmlRegisterSingletonType(QUrl("qrc:/common/SkinModel.qml"), "Qt.Singleton", 1, 0, "SkinSingleton");
    qmlRegisterType<QmlMqttClient>("Qt.MqttClient", 1, 0, "MqttClient");
    //注册为单例类，方便不同界面同步状态
    qmlRegisterSingletonType<JsonDataProvider>("Qt.JsonDataProvider", 1, 0, "JsonDataProvider", JsonData_provider);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
