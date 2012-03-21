/****************************************************************************
** Canvas meta object code from reading C++ file 'Dungeon.h'
**
** Created: Wed Apr 25 20:35:46 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.5   edited Sep 2 14:41 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Dungeon.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Canvas::className() const
{
    return "Canvas";
}

QMetaObject *Canvas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Canvas( "Canvas", &Canvas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Canvas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Canvas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Canvas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Canvas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Canvas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGLWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"Canvas", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Canvas.setMetaObject( metaObj );
    return metaObj;
}

void* Canvas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Canvas" ) )
	return this;
    return QGLWidget::qt_cast( clname );
}

bool Canvas::qt_invoke( int _id, QUObject* _o )
{
    return QGLWidget::qt_invoke(_id,_o);
}

bool Canvas::qt_emit( int _id, QUObject* _o )
{
    return QGLWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Canvas::qt_property( int id, int f, QVariant* v)
{
    return QGLWidget::qt_property( id, f, v);
}

bool Canvas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *GLPaint::className() const
{
    return "GLPaint";
}

QMetaObject *GLPaint::metaObj = 0;
static QMetaObjectCleanUp cleanUp_GLPaint( "GLPaint", &GLPaint::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString GLPaint::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GLPaint", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString GLPaint::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GLPaint", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* GLPaint::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "focal", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotChangeFocal", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "eye", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotChangeEye", 1, param_slot_1 };
    static const QUMethod slot_2 = {"slotAbout", 0, 0 };
    static const QUMethod slot_3 = {"slotExit", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotChangeFocal(int)", &slot_0, QMetaData::Protected },
	{ "slotChangeEye(int)", &slot_1, QMetaData::Protected },
	{ "slotAbout()", &slot_2, QMetaData::Protected },
	{ "slotExit()", &slot_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"GLPaint", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_GLPaint.setMetaObject( metaObj );
    return metaObj;
}

void* GLPaint::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "GLPaint" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool GLPaint::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotChangeFocal((int)static_QUType_int.get(_o+1)); break;
    case 1: slotChangeEye((int)static_QUType_int.get(_o+1)); break;
    case 2: slotAbout(); break;
    case 3: slotExit(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool GLPaint::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool GLPaint::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool GLPaint::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
