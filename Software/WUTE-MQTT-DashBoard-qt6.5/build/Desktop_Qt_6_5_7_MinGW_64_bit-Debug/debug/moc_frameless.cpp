/****************************************************************************
** Meta object code from reading C++ file 'frameless.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../common/Frameless/frameless.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frameless.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFramelessWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFramelessWindowENDCLASS = QtMocHelpers::stringData(
    "FramelessWindow",
    "resizeUpdate",
    "",
    "size",
    "maximizedChanged",
    "monitorKeyPress",
    "Qt::Key",
    "key",
    "setCursorDrag",
    "dragging",
    "monitorEnable",
    "resizable",
    "moveArea",
    "QList<QRect>",
    "maximized"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFramelessWindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[16];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[17];
    char stringdata5[16];
    char stringdata6[8];
    char stringdata7[4];
    char stringdata8[14];
    char stringdata9[9];
    char stringdata10[14];
    char stringdata11[10];
    char stringdata12[9];
    char stringdata13[13];
    char stringdata14[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFramelessWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFramelessWindowENDCLASS_t qt_meta_stringdata_CLASSFramelessWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "FramelessWindow"
        QT_MOC_LITERAL(16, 12),  // "resizeUpdate"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 4),  // "size"
        QT_MOC_LITERAL(35, 16),  // "maximizedChanged"
        QT_MOC_LITERAL(52, 15),  // "monitorKeyPress"
        QT_MOC_LITERAL(68, 7),  // "Qt::Key"
        QT_MOC_LITERAL(76, 3),  // "key"
        QT_MOC_LITERAL(80, 13),  // "setCursorDrag"
        QT_MOC_LITERAL(94, 8),  // "dragging"
        QT_MOC_LITERAL(103, 13),  // "monitorEnable"
        QT_MOC_LITERAL(117, 9),  // "resizable"
        QT_MOC_LITERAL(127, 8),  // "moveArea"
        QT_MOC_LITERAL(136, 12),  // "QList<QRect>"
        QT_MOC_LITERAL(149, 9)   // "maximized"
    },
    "FramelessWindow",
    "resizeUpdate",
    "",
    "size",
    "maximizedChanged",
    "monitorKeyPress",
    "Qt::Key",
    "key",
    "setCursorDrag",
    "dragging",
    "monitorEnable",
    "resizable",
    "moveArea",
    "QList<QRect>",
    "maximized"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFramelessWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    5 /* Public */,
       4,    0,   41,    2, 0x06,    7 /* Public */,
       5,    1,   42,    2, 0x06,    8 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   45,    2, 0x02,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QSize,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

 // methods: parameters
    QMetaType::Void, QMetaType::Bool,    9,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00015003, uint(-1), 0,
      11, QMetaType::Bool, 0x00015003, uint(-1), 0,
      12, 0x80000000 | 13, 0x0001500b, uint(-1), 0,
      14, QMetaType::Bool, 0x00015103, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject FramelessWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSFramelessWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFramelessWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFramelessWindowENDCLASS_t,
        // property 'monitorEnable'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'resizable'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'moveArea'
        QtPrivate::TypeAndForceComplete<QList<QRect>, std::true_type>,
        // property 'maximized'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FramelessWindow, std::true_type>,
        // method 'resizeUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSize, std::false_type>,
        // method 'maximizedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'monitorKeyPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>,
        // method 'setCursorDrag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void FramelessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FramelessWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resizeUpdate((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 1: _t->maximizedChanged(); break;
        case 2: _t->monitorKeyPress((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1]))); break;
        case 3: _t->setCursorDrag((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FramelessWindow::*)(QSize );
            if (_t _q_method = &FramelessWindow::resizeUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FramelessWindow::*)();
            if (_t _q_method = &FramelessWindow::maximizedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FramelessWindow::*)(Qt::Key );
            if (_t _q_method = &FramelessWindow::monitorKeyPress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QRect> >(); break;
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FramelessWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->m_monitorEnable; break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->m_resizable; break;
        case 2: *reinterpret_cast< QList<QRect>*>(_v) = _t->m_moveArea; break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->maximized(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FramelessWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_monitorEnable != *reinterpret_cast< bool*>(_v)) {
                _t->m_monitorEnable = *reinterpret_cast< bool*>(_v);
            }
            break;
        case 1:
            if (_t->m_resizable != *reinterpret_cast< bool*>(_v)) {
                _t->m_resizable = *reinterpret_cast< bool*>(_v);
            }
            break;
        case 2:
            if (_t->m_moveArea != *reinterpret_cast< QList<QRect>*>(_v)) {
                _t->m_moveArea = *reinterpret_cast< QList<QRect>*>(_v);
            }
            break;
        case 3: _t->setMaximized(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *FramelessWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramelessWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFramelessWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickWindow::qt_metacast(_clname);
}

int FramelessWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FramelessWindow::resizeUpdate(QSize _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FramelessWindow::maximizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FramelessWindow::monitorKeyPress(Qt::Key _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
