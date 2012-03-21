#include <qapplication.h>
#include "GLPaint.h"

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    GLPaint paintwin;

    paintwin.resize( 600, 600 );
    paintwin.setCaption("Ryckbost Design Virtual Trackball");
    a.setMainWidget( &paintwin );
	paintwin.show();
    return a.exec();
}
