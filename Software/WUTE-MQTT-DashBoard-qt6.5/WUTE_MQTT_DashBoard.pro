QT += core qml gui
QT += quick
QT += widgets
QT += network mqtt
QT += quickcontrols2

CONFIG += c++17
# CONFIG += qmltypes #为将 QObject 派生类注册为可实例化的 QML 对象类型
CONFIG += resources_big #解决资源文件过大
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS   #消除警告

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \

HEADERS += \

RESOURCES += qml.qrc
include(./common/Frameless/frameless.pri)
include(./common/Backend/Backend.pri)


#INCLUDEPATH += $$PWD/pages/QianProjectPages/QianDragViewPage

win32 {
    RC_FILE += ./windowRes/Icon.rc
}


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


