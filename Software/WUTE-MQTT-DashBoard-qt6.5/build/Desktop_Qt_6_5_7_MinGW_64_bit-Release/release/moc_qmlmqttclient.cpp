/****************************************************************************
** Meta object code from reading C++ file 'qmlmqttclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../common/Backend/qmlmqttclient.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmlmqttclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS = QtMocHelpers::stringData(
    "QmlMqttSubscription",
    "QML.Creatable",
    "false",
    "QML.UncreatableReason",
    "Not intended to be creatable",
    "topicChanged",
    "",
    "messageReceived",
    "msg",
    "handleMessage",
    "QMqttMessage",
    "qmsg",
    "topic",
    "QMqttTopicFilter"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[20];
    char stringdata1[14];
    char stringdata2[6];
    char stringdata3[22];
    char stringdata4[29];
    char stringdata5[13];
    char stringdata6[1];
    char stringdata7[16];
    char stringdata8[4];
    char stringdata9[14];
    char stringdata10[13];
    char stringdata11[5];
    char stringdata12[6];
    char stringdata13[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS_t qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "QmlMqttSubscription"
        QT_MOC_LITERAL(20, 13),  // "QML.Creatable"
        QT_MOC_LITERAL(34, 5),  // "false"
        QT_MOC_LITERAL(40, 21),  // "QML.UncreatableReason"
        QT_MOC_LITERAL(62, 28),  // "Not intended to be creatable"
        QT_MOC_LITERAL(91, 12),  // "topicChanged"
        QT_MOC_LITERAL(104, 0),  // ""
        QT_MOC_LITERAL(105, 15),  // "messageReceived"
        QT_MOC_LITERAL(121, 3),  // "msg"
        QT_MOC_LITERAL(125, 13),  // "handleMessage"
        QT_MOC_LITERAL(139, 12),  // "QMqttMessage"
        QT_MOC_LITERAL(152, 4),  // "qmsg"
        QT_MOC_LITERAL(157, 5),  // "topic"
        QT_MOC_LITERAL(163, 16)   // "QMqttTopicFilter"
    },
    "QmlMqttSubscription",
    "QML.Creatable",
    "false",
    "QML.UncreatableReason",
    "Not intended to be creatable",
    "topicChanged",
    "",
    "messageReceived",
    "msg",
    "handleMessage",
    "QMqttMessage",
    "qmsg",
    "topic",
    "QMqttTopicFilter"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQmlMqttSubscriptionENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       2,   14, // classinfo
       3,   18, // methods
       1,   45, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   36,    6, 0x06,    2 /* Public */,
       7,    1,   39,    6, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   42,    6, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,

 // properties: name, type, flags
      12, 0x80000000 | 13, 0x0001500b, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QmlMqttSubscription::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQmlMqttSubscriptionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'topic'
        QMqttTopicFilter,
        // Q_OBJECT / Q_GADGET
        QmlMqttSubscription,
        // method 'topicChanged'
        void,
        QString,
        // method 'messageReceived'
        void,
        const QString &,
        // method 'handleMessage'
        void,
        const QMqttMessage &
    >,
    nullptr
} };

void QmlMqttSubscription::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QmlMqttSubscription *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->topicChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->messageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->handleMessage((*reinterpret_cast< std::add_pointer_t<QMqttMessage>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QMqttMessage >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QmlMqttSubscription::*)(QString );
            if (_t _q_method = &QmlMqttSubscription::topicChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QmlMqttSubscription::*)(const QString & );
            if (_t _q_method = &QmlMqttSubscription::messageReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicFilter >(); break;
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QmlMqttSubscription *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QMqttTopicFilter*>(_v) = _t->m_topic; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QmlMqttSubscription *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_topic != *reinterpret_cast< QMqttTopicFilter*>(_v)) {
                _t->m_topic = *reinterpret_cast< QMqttTopicFilter*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *QmlMqttSubscription::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmlMqttSubscription::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQmlMqttSubscriptionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QmlMqttSubscription::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QmlMqttSubscription::topicChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QmlMqttSubscription::messageReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQmlMqttClientENDCLASS = QtMocHelpers::stringData(
    "QmlMqttClient",
    "QML.Element",
    "MqttClient",
    "QML.Extended",
    "QMqttClient",
    "QML.ExtensionIsNamespace",
    "true",
    "hostnameChanged",
    "",
    "portChanged",
    "usernameChanged",
    "clientidChanged",
    "passwordChanged",
    "stateChanged",
    "connectToHost",
    "disconnectFromHost",
    "publish",
    "topic",
    "message",
    "qos",
    "retain",
    "subscribe",
    "QmlMqttSubscription*",
    "hostname",
    "port",
    "username",
    "clientid",
    "password",
    "state",
    "QMqttClient::ClientState"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[14];
    char stringdata1[12];
    char stringdata2[11];
    char stringdata3[13];
    char stringdata4[12];
    char stringdata5[25];
    char stringdata6[5];
    char stringdata7[16];
    char stringdata8[1];
    char stringdata9[12];
    char stringdata10[16];
    char stringdata11[16];
    char stringdata12[16];
    char stringdata13[13];
    char stringdata14[14];
    char stringdata15[19];
    char stringdata16[8];
    char stringdata17[6];
    char stringdata18[8];
    char stringdata19[4];
    char stringdata20[7];
    char stringdata21[10];
    char stringdata22[21];
    char stringdata23[9];
    char stringdata24[5];
    char stringdata25[9];
    char stringdata26[9];
    char stringdata27[9];
    char stringdata28[6];
    char stringdata29[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmlMqttClientENDCLASS_t qt_meta_stringdata_CLASSQmlMqttClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "QmlMqttClient"
        QT_MOC_LITERAL(14, 11),  // "QML.Element"
        QT_MOC_LITERAL(26, 10),  // "MqttClient"
        QT_MOC_LITERAL(37, 12),  // "QML.Extended"
        QT_MOC_LITERAL(50, 11),  // "QMqttClient"
        QT_MOC_LITERAL(62, 24),  // "QML.ExtensionIsNamespace"
        QT_MOC_LITERAL(87, 4),  // "true"
        QT_MOC_LITERAL(92, 15),  // "hostnameChanged"
        QT_MOC_LITERAL(108, 0),  // ""
        QT_MOC_LITERAL(109, 11),  // "portChanged"
        QT_MOC_LITERAL(121, 15),  // "usernameChanged"
        QT_MOC_LITERAL(137, 15),  // "clientidChanged"
        QT_MOC_LITERAL(153, 15),  // "passwordChanged"
        QT_MOC_LITERAL(169, 12),  // "stateChanged"
        QT_MOC_LITERAL(182, 13),  // "connectToHost"
        QT_MOC_LITERAL(196, 18),  // "disconnectFromHost"
        QT_MOC_LITERAL(215, 7),  // "publish"
        QT_MOC_LITERAL(223, 5),  // "topic"
        QT_MOC_LITERAL(229, 7),  // "message"
        QT_MOC_LITERAL(237, 3),  // "qos"
        QT_MOC_LITERAL(241, 6),  // "retain"
        QT_MOC_LITERAL(248, 9),  // "subscribe"
        QT_MOC_LITERAL(258, 20),  // "QmlMqttSubscription*"
        QT_MOC_LITERAL(279, 8),  // "hostname"
        QT_MOC_LITERAL(288, 4),  // "port"
        QT_MOC_LITERAL(293, 8),  // "username"
        QT_MOC_LITERAL(302, 8),  // "clientid"
        QT_MOC_LITERAL(311, 8),  // "password"
        QT_MOC_LITERAL(320, 5),  // "state"
        QT_MOC_LITERAL(326, 24)   // "QMqttClient::ClientState"
    },
    "QmlMqttClient",
    "QML.Element",
    "MqttClient",
    "QML.Extended",
    "QMqttClient",
    "QML.ExtensionIsNamespace",
    "true",
    "hostnameChanged",
    "",
    "portChanged",
    "usernameChanged",
    "clientidChanged",
    "passwordChanged",
    "stateChanged",
    "connectToHost",
    "disconnectFromHost",
    "publish",
    "topic",
    "message",
    "qos",
    "retain",
    "subscribe",
    "QmlMqttSubscription*",
    "hostname",
    "port",
    "username",
    "clientid",
    "password",
    "state",
    "QMqttClient::ClientState"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQmlMqttClientENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       3,   14, // classinfo
      12,   20, // methods
       6,  124, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,
       5,    6,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   92,    8, 0x06,    7 /* Public */,
       9,    0,   93,    8, 0x06,    8 /* Public */,
      10,    0,   94,    8, 0x06,    9 /* Public */,
      11,    0,   95,    8, 0x06,   10 /* Public */,
      12,    0,   96,    8, 0x06,   11 /* Public */,
      13,    0,   97,    8, 0x06,   12 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,   98,    8, 0x02,   13 /* Public */,
      15,    0,   99,    8, 0x02,   14 /* Public */,
      16,    4,  100,    8, 0x02,   15 /* Public */,
      16,    3,  109,    8, 0x22,   20 /* Public | MethodCloned */,
      16,    2,  116,    8, 0x22,   24 /* Public | MethodCloned */,
      21,    1,  121,    8, 0x02,   27 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   17,   18,   19,   20,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,   17,   18,   19,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   17,   18,
    0x80000000 | 22, QMetaType::QString,   17,

 // properties: name, type, flags
      23, QMetaType::QString, 0x00015103, uint(0), 0,
      24, QMetaType::Int, 0x00015103, uint(1), 0,
      25, QMetaType::QString, 0x00015103, uint(2), 0,
      26, QMetaType::QString, 0x00015103, uint(3), 0,
      27, QMetaType::QString, 0x00015103, uint(4), 0,
      28, 0x80000000 | 29, 0x0001510b, uint(5), 0,

       0        // eod
};

Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_CLASSQmlMqttClientENDCLASS[] = {
    QMetaObject::SuperData::link<QMqttClient::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject QmlMqttClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQmlMqttClientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQmlMqttClientENDCLASS,
    qt_static_metacall,
    qt_meta_extradata_CLASSQmlMqttClientENDCLASS,
    qt_metaTypeArray<
        // property 'hostname'
        QString,
        // property 'port'
        int,
        // property 'username'
        QString,
        // property 'clientid'
        QString,
        // property 'password'
        QString,
        // property 'state'
        QMqttClient::ClientState,
        // Q_OBJECT / Q_GADGET
        QmlMqttClient,
        // method 'hostnameChanged'
        void,
        // method 'portChanged'
        void,
        // method 'usernameChanged'
        void,
        // method 'clientidChanged'
        void,
        // method 'passwordChanged'
        void,
        // method 'stateChanged'
        void,
        // method 'connectToHost'
        void,
        // method 'disconnectFromHost'
        void,
        // method 'publish'
        int,
        const QString &,
        const QString &,
        int,
        bool,
        // method 'publish'
        int,
        const QString &,
        const QString &,
        int,
        // method 'publish'
        int,
        const QString &,
        const QString &,
        // method 'subscribe'
        QmlMqttSubscription *,
        const QString &
    >,
    nullptr
} };

void QmlMqttClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->hostnameChanged(); break;
        case 1: _t->portChanged(); break;
        case 2: _t->usernameChanged(); break;
        case 3: _t->clientidChanged(); break;
        case 4: _t->passwordChanged(); break;
        case 5: _t->stateChanged(); break;
        case 6: _t->connectToHost(); break;
        case 7: _t->disconnectFromHost(); break;
        case 8: { int _r = _t->publish((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->publish((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->publish((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { QmlMqttSubscription* _r = _t->subscribe((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QmlMqttSubscription**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::hostnameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::portChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::usernameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::clientidChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::passwordChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QmlMqttClient::*)();
            if (_t _q_method = &QmlMqttClient::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttClient::ClientState >(); break;
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->hostname(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->port(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->username(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->clientid(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->password(); break;
        case 5: *reinterpret_cast< QMqttClient::ClientState*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QmlMqttClient *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHostname(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setPort(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setUsername(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setClientid(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setPassword(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setState(*reinterpret_cast< QMqttClient::ClientState*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *QmlMqttClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmlMqttClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQmlMqttClientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QmlMqttClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QmlMqttClient::hostnameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QmlMqttClient::portChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QmlMqttClient::usernameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QmlMqttClient::clientidChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QmlMqttClient::passwordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QmlMqttClient::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
