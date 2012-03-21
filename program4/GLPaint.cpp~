// GLPaint: starter code for CS 352 program 3 -- an image
// processing program based on OpenGL under QT.
//
#include "GLPaint.h"
#include <qapplication.h>
#include <qevent.h>
#include <qpainter.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qtooltip.h>
#include <qpoint.h>
#include <qfiledialog.h>
#include <qimage.h>
#include <stdlib.h>
#include <qmessagebox.h>
#include <qslider.h>

Canvas::Canvas( QWidget *parent, const char *name ) : QGLWidget(parent, name)
{
    setCaption("QT/OpenGL Virtual Trackball");
}

//
// load loads the specified image into buffer and calls paintGL 
// to display it.
//
void Canvas::load( const QString &filename )
{
    GLfloat dimensions[3];
    
    object = glmReadOBJ((char*) filename.ascii());
    glmUnitize(object);
    glmScale(object, 7.0);
    glmDimensions(object, dimensions);
    
    //normalize object centered on origin
    glmFacetNormals(object);
    glmVertexNormals(object, (GLfloat)90);
    object->position[X] = 0;
    object->position[Y] = 0;
    object->position[Z] = 0;
    
    //read object into display list
    object_list = glmList(object, GLM_SMOOTH | GLM_COLOR);    
    
    //buffer.load( filename );
    //loadPic=true;
    updateGL();
}


// 
// Remember mouse coords. Actual drawing is done in the
// paintGL function.
//
void Canvas::mousePressEvent( QMouseEvent *e )
{
    mousePressed = true;
    x = e->x();
    y = height() - e->y();
    updateGL();
}

void Canvas::mouseReleaseEvent( QMouseEvent * )
{
    mousePressed = false;
}

void Canvas::mouseMoveEvent( QMouseEvent *e )
{
    if ( mousePressed ) {
        x = e->x();
        y = height() - e->y();
        updateGL();
    }
}

void Canvas::initializeGL()
{
    qglClearColor(white);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(6);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glBlendFunc(GL_ZERO, GL_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_CULL_FACE);

    glClearStencil(0);
}


//
// when the canvas is resized, this function stretches or shrinks the
// image to fit. You can change the behavior if you like, but the 
// current image shouldn't be lost.
//
void Canvas::resizeGL( int w, int h )
{
    /*glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, (GLint) w, (GLint) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -2, 2);*/
    
    glViewport(0, 0, w, h);
  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)h / (GLfloat)w, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //translates the object and then rotates it
    glTranslatef(0.0, 0.0, -20.0);
    glRotatef(20.0, 1.0, 0.0, 0.0);

    //buffer = buffer.scale(w, h);
    //loadPic = true;
    updateGL();
}


//
// paintGL has two modes:  drawing dots or displaying the pixmap 
// stored in buffer.  Since we can't add any parameters to the 
// function call, communication is through a class variable. 
// This function will display the pixmap stored in buffer if 
// loadPic is true.
//
void Canvas::paintGL( )
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    //object_list = glmList(object, GLM_SMOOTH | GLM_COLOR);
    
    //display list
    glCallList(object_list);
}

//------------------------------------------------------
//     General (non-OpenGL) widget stuff
//------------------------------------------------------
GLPaint::GLPaint( QWidget *parent, const char *name )
    : QMainWindow( parent, name )
{
    canvas = new Canvas( this );
    setCentralWidget( canvas );

    //
    // make a toolbar
    //
    QToolBar *tools = new QToolBar( this );

    bLoad = new QToolButton(QPixmap(), "Load OBJ object", "Load", this, SLOT(slotLoad()), tools);
    bLoad->setText( "Load" );
    tools->addSeparator();
    
    focalLengthSlider = new QSlider(Horizontal, tools, "Focal Length" );
    tools->addSeparator();
    
    eyeSlider = new QSlider(Horizontal, tools, "Eye Seperation" );
    tools->addSeparator();

    //
    // make a menubar
    //
    file = new QPopupMenu();
    file->insertItem ("&Open", this, SLOT( slotLoad() ) );
    file->insertItem ("E&xit", this, SLOT( slotExit() ), CTRL+Key_Q );

    options = new QPopupMenu();

    help = new QPopupMenu();
    help->insertItem ("&About", this, SLOT( slotAbout() ) );

    menubar = new QMenuBar( this );
    menubar->insertItem( "&File", file);
    menubar->insertItem( "&Options", options);
    menubar->insertItem( "&Help", help);
    
}

void GLPaint::slotLoad()
{
    QString filename = QFileDialog::getOpenFileName( ".", "*.obj", this);
    if ( !filename.isEmpty() )
        canvas->load( filename );
}

void GLPaint::slotAbout()
{
    QMessageBox::information(this, "Ryckbost Design", "Author:\tBrian Ryckbost\nVersion:\t0.4.5\nPurpose:\tCreate a trackball program using UpenGL and QT.\n  Ryckbost Design is proud to offer you the highest quality software available.\n  This trackball program is truly one of a kind!\n" );
}

void GLPaint::slotExit()
{
    exit(0);
}
