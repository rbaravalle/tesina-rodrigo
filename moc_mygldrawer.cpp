/****************************************************************************
** Meta object code from reading C++ file 'mygldrawer.h'
**
** Created: Mon Feb 8 20:05:30 2010
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mygldrawer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygldrawer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyGLDrawer[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      34,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      78,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     114,   11,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     152,   11,   11,   11, 0x0a,
     172,   11,   11,   11, 0x0a,
     192,   11,   11,   11, 0x0a,
     216,   11,   11,   11, 0x0a,
     240,   11,   11,   11, 0x0a,
     264,   11,   11,   11, 0x0a,
     278,   11,   11,   11, 0x0a,
     292,   11,   11,   11, 0x0a,
     306,   11,   11,   11, 0x0a,
     330,   11,   11,   11, 0x0a,
     354,   11,   11,   11, 0x0a,
     378,   11,   11,   11, 0x0a,
     408,   11,   11,   11, 0x0a,
     438,   11,   11,   11, 0x0a,
     468,   11,   11,   11, 0x0a,
     498,   11,   11,   11, 0x0a,
     528,   11,   11,   11, 0x0a,
     558,   11,   11,   11, 0x0a,
     579,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyGLDrawer[] = {
    "MyGLDrawer\0\0cambiarAmplitud1(int)\0"
    "cambiarAmplitud2(int)\0cambiarAmplitud3(int)\0"
    "cambiarTurb1(int)\0cambiarTurb2(int)\0"
    "cambiarTurb3(int)\0cambiarAngulo1(int)\0"
    "cambiarAngulo2(int)\0cambiarAngulo3(int)\0"
    "cambiarFrecuencia1(int)\0cambiarFrecuencia2(int)\0"
    "cambiarFrecuencia3(int)\0cambiarUsa1()\0"
    "cambiarUsa2()\0cambiarUsa3()\0"
    "cambiarIntensidad1(int)\0cambiarIntensidad2(int)\0"
    "cambiarIntensidad3(int)\0"
    "cambiarDesplazamiento_u1(int)\0"
    "cambiarDesplazamiento_u2(int)\0"
    "cambiarDesplazamiento_u3(int)\0"
    "cambiarDesplazamiento_v1(int)\0"
    "cambiarDesplazamiento_v2(int)\0"
    "cambiarDesplazamiento_v3(int)\0"
    "cambiarCombina1(int)\0cambiarCombina2(int)\0"
};

const QMetaObject MyGLDrawer::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLDrawer,
      qt_meta_data_MyGLDrawer, 0 }
};

const QMetaObject *MyGLDrawer::metaObject() const
{
    return &staticMetaObject;
}

void *MyGLDrawer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLDrawer))
        return static_cast<void*>(const_cast< MyGLDrawer*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLDrawer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cambiarAmplitud1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: cambiarAmplitud2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: cambiarAmplitud3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: cambiarTurb1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: cambiarTurb2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: cambiarTurb3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: cambiarAngulo1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: cambiarAngulo2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: cambiarAngulo3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: cambiarFrecuencia1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: cambiarFrecuencia2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: cambiarFrecuencia3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: cambiarUsa1(); break;
        case 13: cambiarUsa2(); break;
        case 14: cambiarUsa3(); break;
        case 15: cambiarIntensidad1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: cambiarIntensidad2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: cambiarIntensidad3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: cambiarDesplazamiento_u1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: cambiarDesplazamiento_u2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: cambiarDesplazamiento_u3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: cambiarDesplazamiento_v1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: cambiarDesplazamiento_v2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: cambiarDesplazamiento_v3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: cambiarCombina1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: cambiarCombina2((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
