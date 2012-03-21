#ifndef DUNGEON_H
#define DUNGEON_H

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
#include <math.h>
#include <qdatetime.h>
#include <qlabel.h>
#include <qpushbutton.h>

extern "C"  {
#include "glm.h"
#include "texture.h"
}

class QMouseEvent;
class QResizeEvent;
class QPaintEvent;
class QToolButton;


struct Wall {
    GLfloat coords[4];
};

struct Door {
    GLfloat coords[4];
    std::string roomLocation;
    GLfloat eyep[3];
    GLfloat lookp[3];
};

//
// a Canvas is a QGLwidget that you can draw on
//
class Canvas : public QGLWidget
{
    Q_OBJECT

    public:
        Canvas( QWidget *parent = 0, const char *name = 0 );

        void makeCheckImage(void);
        void setFocalLength(int focal);
        void setEyeSep(int eye);
        void walkView(double orient, double locx, double locy, double locz);
        void read_room(char *room);

    protected:
        void resizeGL (int w, int h);
        void initializeGL();
        void paintGL();
        void pointVect(int x, int y, float v[3]);
        void normalize(GLfloat* n);
        void cross(GLfloat* u, GLfloat* v, GLfloat* n);


        virtual void mousePressEvent  ( QMouseEvent* event);
        virtual void mouseReleaseEvent( QMouseEvent* event);
        virtual void mouseMoveEvent   ( QMouseEvent* event);
        virtual void keyPressEvent ( QKeyEvent * event );

        int x, y, x2, y2, w, h;

        float v[3];

        bool mousePressed, mousePressedTwo, loadPic;

        QImage buffer;

        GLMmodel* object;

        GLuint theRoom;

        enum { X, Y, Z, W };

        QTime   time;
        int       tb_lasttime, seperation;
        GLfloat   tb_lastposition[3];

        GLfloat   tb_angle, focalLength;
        GLfloat   tb_axis[3];
        GLfloat   tb_transform[4][4];


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
        QToolButton	*bLoad, *bAbout; 
        QPopupMenu	*file, *help;
        QMenuBar	*menubar;
        QSlider     *focalLengthSlider, *eyeSlider;
        QLabel      *focalLabel, *eyeLabel;

    protected slots:
        void slotChangeFocal(int focal);
        void slotChangeEye(int eye);

        void slotAbout();
        void slotExit();
};

#endif
