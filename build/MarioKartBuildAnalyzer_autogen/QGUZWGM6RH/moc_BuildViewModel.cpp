/****************************************************************************
** Meta object code from reading C++ file 'BuildViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/viewmodels/BuildViewModel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BuildViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN14BuildViewModelE_t {};
} // unnamed namespace

template <> constexpr inline auto BuildViewModel::qt_create_metaobjectdata<qt_meta_tag_ZN14BuildViewModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BuildViewModel",
        "changed",
        "",
        "ready",
        "driverName",
        "bodyName",
        "tireName",
        "gliderName",
        "speedGround",
        "speedWater",
        "speedAir",
        "speedAntiG",
        "acceleration",
        "weight",
        "handlingGround",
        "handlingWater",
        "handlingAir",
        "handlingAntiG",
        "traction",
        "normSpeedGround",
        "normSpeedWater",
        "normSpeedAir",
        "normSpeedAntiG",
        "normAcceleration",
        "normWeight",
        "normHandlingGround",
        "normHandlingWater",
        "normHandlingAir",
        "normHandlingAntiG",
        "normTraction",
        "performanceScore",
        "normPerformanceScore"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'changed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'ready'
        QtMocHelpers::PropertyData<bool>(3, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'driverName'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'bodyName'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'tireName'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'gliderName'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'speedGround'
        QtMocHelpers::PropertyData<double>(8, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'speedWater'
        QtMocHelpers::PropertyData<double>(9, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'speedAir'
        QtMocHelpers::PropertyData<double>(10, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'speedAntiG'
        QtMocHelpers::PropertyData<double>(11, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'acceleration'
        QtMocHelpers::PropertyData<double>(12, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'weight'
        QtMocHelpers::PropertyData<double>(13, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'handlingGround'
        QtMocHelpers::PropertyData<double>(14, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'handlingWater'
        QtMocHelpers::PropertyData<double>(15, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'handlingAir'
        QtMocHelpers::PropertyData<double>(16, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'handlingAntiG'
        QtMocHelpers::PropertyData<double>(17, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'traction'
        QtMocHelpers::PropertyData<double>(18, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normSpeedGround'
        QtMocHelpers::PropertyData<double>(19, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normSpeedWater'
        QtMocHelpers::PropertyData<double>(20, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normSpeedAir'
        QtMocHelpers::PropertyData<double>(21, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normSpeedAntiG'
        QtMocHelpers::PropertyData<double>(22, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normAcceleration'
        QtMocHelpers::PropertyData<double>(23, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normWeight'
        QtMocHelpers::PropertyData<double>(24, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normHandlingGround'
        QtMocHelpers::PropertyData<double>(25, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normHandlingWater'
        QtMocHelpers::PropertyData<double>(26, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normHandlingAir'
        QtMocHelpers::PropertyData<double>(27, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normHandlingAntiG'
        QtMocHelpers::PropertyData<double>(28, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normTraction'
        QtMocHelpers::PropertyData<double>(29, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'performanceScore'
        QtMocHelpers::PropertyData<double>(30, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'normPerformanceScore'
        QtMocHelpers::PropertyData<double>(31, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BuildViewModel, qt_meta_tag_ZN14BuildViewModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject BuildViewModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BuildViewModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BuildViewModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14BuildViewModelE_t>.metaTypes,
    nullptr
} };

void BuildViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BuildViewModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->changed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BuildViewModel::*)()>(_a, &BuildViewModel::changed, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->ready(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->driverName(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->bodyName(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->tireName(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->gliderName(); break;
        case 5: *reinterpret_cast<double*>(_v) = _t->speedGround(); break;
        case 6: *reinterpret_cast<double*>(_v) = _t->speedWater(); break;
        case 7: *reinterpret_cast<double*>(_v) = _t->speedAir(); break;
        case 8: *reinterpret_cast<double*>(_v) = _t->speedAntiG(); break;
        case 9: *reinterpret_cast<double*>(_v) = _t->acceleration(); break;
        case 10: *reinterpret_cast<double*>(_v) = _t->weight(); break;
        case 11: *reinterpret_cast<double*>(_v) = _t->handlingGround(); break;
        case 12: *reinterpret_cast<double*>(_v) = _t->handlingWater(); break;
        case 13: *reinterpret_cast<double*>(_v) = _t->handlingAir(); break;
        case 14: *reinterpret_cast<double*>(_v) = _t->handlingAntiG(); break;
        case 15: *reinterpret_cast<double*>(_v) = _t->traction(); break;
        case 16: *reinterpret_cast<double*>(_v) = _t->normSpeedGround(); break;
        case 17: *reinterpret_cast<double*>(_v) = _t->normSpeedWater(); break;
        case 18: *reinterpret_cast<double*>(_v) = _t->normSpeedAir(); break;
        case 19: *reinterpret_cast<double*>(_v) = _t->normSpeedAntiG(); break;
        case 20: *reinterpret_cast<double*>(_v) = _t->normAcceleration(); break;
        case 21: *reinterpret_cast<double*>(_v) = _t->normWeight(); break;
        case 22: *reinterpret_cast<double*>(_v) = _t->normHandlingGround(); break;
        case 23: *reinterpret_cast<double*>(_v) = _t->normHandlingWater(); break;
        case 24: *reinterpret_cast<double*>(_v) = _t->normHandlingAir(); break;
        case 25: *reinterpret_cast<double*>(_v) = _t->normHandlingAntiG(); break;
        case 26: *reinterpret_cast<double*>(_v) = _t->normTraction(); break;
        case 27: *reinterpret_cast<double*>(_v) = _t->performanceScore(); break;
        case 28: *reinterpret_cast<double*>(_v) = _t->normPerformanceScore(); break;
        default: break;
        }
    }
}

const QMetaObject *BuildViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BuildViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BuildViewModelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BuildViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void BuildViewModel::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
