/****************************************************************************
** Meta object code from reading C++ file 'book.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../book.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'book.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Book_t {
    QByteArrayData data[18];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Book_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Book_t qt_meta_stringdata_Book = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Book"
QT_MOC_LITERAL(1, 5, 9), // "createDir"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 9), // "flushFile"
QT_MOC_LITERAL(4, 26, 6), // "delDir"
QT_MOC_LITERAL(5, 33, 10), // "renameFile"
QT_MOC_LITERAL(6, 44, 8), // "enterDir"
QT_MOC_LITERAL(7, 53, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 65, 5), // "index"
QT_MOC_LITERAL(9, 71, 13), // "clearEnterDir"
QT_MOC_LITERAL(10, 85, 9), // "returnPre"
QT_MOC_LITERAL(11, 95, 10), // "uploadFile"
QT_MOC_LITERAL(12, 106, 14), // "uploadFileData"
QT_MOC_LITERAL(13, 121, 10), // "delRegFile"
QT_MOC_LITERAL(14, 132, 12), // "downloadFile"
QT_MOC_LITERAL(15, 145, 9), // "shareFile"
QT_MOC_LITERAL(16, 155, 8), // "moveFile"
QT_MOC_LITERAL(17, 164, 13) // "selectDestDir"

    },
    "Book\0createDir\0\0flushFile\0delDir\0"
    "renameFile\0enterDir\0QModelIndex\0index\0"
    "clearEnterDir\0returnPre\0uploadFile\0"
    "uploadFileData\0delRegFile\0downloadFile\0"
    "shareFile\0moveFile\0selectDestDir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Book[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    1,   93,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
       6,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Book::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Book *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createDir(); break;
        case 1: _t->flushFile(); break;
        case 2: _t->delDir(); break;
        case 3: _t->renameFile(); break;
        case 4: _t->enterDir((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->clearEnterDir(); break;
        case 6: { QString _r = _t->enterDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->returnPre(); break;
        case 8: _t->uploadFile(); break;
        case 9: _t->uploadFileData(); break;
        case 10: _t->delRegFile(); break;
        case 11: _t->downloadFile(); break;
        case 12: _t->shareFile(); break;
        case 13: _t->moveFile(); break;
        case 14: _t->selectDestDir(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Book::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Book.data,
    qt_meta_data_Book,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Book::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Book::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Book.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Book::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
