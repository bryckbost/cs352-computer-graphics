#ifndef GLPAINT_H
#define GLPAINT_H

#include <qmainwindow.h>
#include <qgl.h>
#include <qpen.h>
#include <qpoint.h>
#include <qimage.h>
#include <qwidget.h>
#include <qstring.h>
#include <qpointarray.h>
#include <qmenubar.h>
#include <qslider.h>
extern "C"  {
    #include "glm.h"
}

class QMouseEvent;
class QResizeEvent;
class QPaintEvent;
class QToolButton;

//
// a Canvas is a QGLwidget that you can draw on
//
class Canvas : public QGLWidget
{
    Q_OBJECT

public:
    Canvas( QWidget *parent = 0, const char *name = 0 );

    //void save( const QString &filename, const QString &format );
    void load( const QString &filename );
    //void clear();
    //void fade();
    void makeCheckImage(void);

protected:
    void resizeGL (int w, int h);
    void initializeGL();
    void paintGL();

    virtual void mousePressEvent  ( QMouseEvent* event);
    virtual void mouseReleaseEvent( QMouseEvent* event);
    virtual void mouseMoveEvent   ( QMouseEvent* event);

    int x, y;

    bool mousePressed, loadPic;

    QImage buffer;

    GLMmodel* object;

    GLuint object_list;

    enum { X, Y, Z, W };
};

//
// The GLPaint object has the canvas, toolbar, etc.
//
class GLPaint : public QMainWindow
{
    Q_OBJECT

public:
    GLPaint( QWidget *parent = 0, const char *name = 0 );

protected:
    Canvas      *canvas;
    QToolButton	*bLoad, *bAbout; //*bSave, *bClear, *bFade;
    QPopupMenu	*file, *options, *help;
    QMenuBar	*menubar;
    QSlider     *focalLengthSlider, *eyeSlider;

protected slots:
    //void slotSave();
    void slotLoad();
    void slotAbout();
    //void slotClear();
    //void slotFade();
    void slotExit();
};

#endif
