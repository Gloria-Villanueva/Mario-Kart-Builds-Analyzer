/****************************************************************************
** Meta object code from reading C++ file 'AppController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/viewmodels/AppController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppController.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13AppControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto AppController::qt_create_metaobjectdata<qt_meta_tag_ZN13AppControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AppController",
        "loadedChanged",
        "",
        "errorChanged",
        "selectionChanged",
        "percentileChanged",
        "selectDriver",
        "index",
        "selectBody",
        "selectTire",
        "selectGlider",
        "calculatePercentile",
        "computeRanking",
        "topN",
        "computeSimilar",
        "k",
        "computeAggregation",
        "filterType",
        "filterValue",
        "operation",
        "loaded",
        "errorMessage",
        "driversModel",
        "ComponentListModel*",
        "bodiesModel",
        "tiresModel",
        "glidersModel",
        "rankingModel",
        "BuildListModel*",
        "similarModel",
        "currentBuild",
        "BuildViewModel*",
        "selectedDriverIndex",
        "selectedBodyIndex",
        "selectedTireIndex",
        "selectedGliderIndex",
        "lastPercentile",
        "percentileReady",
        "driverSizes",
        "bodyTypes"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'loadedChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'percentileChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectDriver'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'selectBody'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'selectTire'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'selectGlider'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'calculatePercentile'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'computeRanking'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Slot 'computeSimilar'
        QtMocHelpers::SlotData<void(int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 },
        }}),
        // Slot 'computeAggregation'
        QtMocHelpers::SlotData<double(const QString &, const QString &, const QString &)>(16, 2, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 17 }, { QMetaType::QString, 18 }, { QMetaType::QString, 19 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'loaded'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'errorMessage'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'driversModel'
        QtMocHelpers::PropertyData<ComponentListModel*>(22, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'bodiesModel'
        QtMocHelpers::PropertyData<ComponentListModel*>(24, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'tiresModel'
        QtMocHelpers::PropertyData<ComponentListModel*>(25, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'glidersModel'
        QtMocHelpers::PropertyData<ComponentListModel*>(26, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'rankingModel'
        QtMocHelpers::PropertyData<BuildListModel*>(27, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'similarModel'
        QtMocHelpers::PropertyData<BuildListModel*>(29, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'currentBuild'
        QtMocHelpers::PropertyData<BuildViewModel*>(30, 0x80000000 | 31, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'selectedDriverIndex'
        QtMocHelpers::PropertyData<int>(32, QMetaType::Int, QMC::DefaultPropertyFlags, 2),
        // property 'selectedBodyIndex'
        QtMocHelpers::PropertyData<int>(33, QMetaType::Int, QMC::DefaultPropertyFlags, 2),
        // property 'selectedTireIndex'
        QtMocHelpers::PropertyData<int>(34, QMetaType::Int, QMC::DefaultPropertyFlags, 2),
        // property 'selectedGliderIndex'
        QtMocHelpers::PropertyData<int>(35, QMetaType::Int, QMC::DefaultPropertyFlags, 2),
        // property 'lastPercentile'
        QtMocHelpers::PropertyData<double>(36, QMetaType::Double, QMC::DefaultPropertyFlags, 3),
        // property 'percentileReady'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
        // property 'driverSizes'
        QtMocHelpers::PropertyData<QStringList>(38, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'bodyTypes'
        QtMocHelpers::PropertyData<QStringList>(39, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AppController, qt_meta_tag_ZN13AppControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AppController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AppControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AppControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13AppControllerE_t>.metaTypes,
    nullptr
} };

void AppController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AppController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->loadedChanged(); break;
        case 1: _t->errorChanged(); break;
        case 2: _t->selectionChanged(); break;
        case 3: _t->percentileChanged(); break;
        case 4: _t->selectDriver((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->selectBody((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->selectTire((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->selectGlider((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->calculatePercentile(); break;
        case 9: _t->computeRanking((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->computeSimilar((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: { double _r = _t->computeAggregation((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast<double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AppController::*)()>(_a, &AppController::loadedChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AppController::*)()>(_a, &AppController::errorChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AppController::*)()>(_a, &AppController::selectionChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (AppController::*)()>(_a, &AppController::percentileChanged, 3))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BuildListModel* >(); break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BuildViewModel* >(); break;
        case 5:
        case 4:
        case 3:
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ComponentListModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->loaded(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->errorMessage(); break;
        case 2: *reinterpret_cast<ComponentListModel**>(_v) = _t->driversModel(); break;
        case 3: *reinterpret_cast<ComponentListModel**>(_v) = _t->bodiesModel(); break;
        case 4: *reinterpret_cast<ComponentListModel**>(_v) = _t->tiresModel(); break;
        case 5: *reinterpret_cast<ComponentListModel**>(_v) = _t->glidersModel(); break;
        case 6: *reinterpret_cast<BuildListModel**>(_v) = _t->rankingModel(); break;
        case 7: *reinterpret_cast<BuildListModel**>(_v) = _t->similarModel(); break;
        case 8: *reinterpret_cast<BuildViewModel**>(_v) = _t->currentBuild(); break;
        case 9: *reinterpret_cast<int*>(_v) = _t->selectedDriverIndex(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->selectedBodyIndex(); break;
        case 11: *reinterpret_cast<int*>(_v) = _t->selectedTireIndex(); break;
        case 12: *reinterpret_cast<int*>(_v) = _t->selectedGliderIndex(); break;
        case 13: *reinterpret_cast<double*>(_v) = _t->lastPercentile(); break;
        case 14: *reinterpret_cast<bool*>(_v) = _t->percentileReady(); break;
        case 15: *reinterpret_cast<QStringList*>(_v) = _t->driverSizes(); break;
        case 16: *reinterpret_cast<QStringList*>(_v) = _t->bodyTypes(); break;
        default: break;
        }
    }
}

const QMetaObject *AppController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AppControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void AppController::loadedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AppController::errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppController::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AppController::percentileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
