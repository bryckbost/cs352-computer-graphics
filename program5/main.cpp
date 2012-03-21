#include <qapplication.h>
#include "Dungeon.h"

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    GLPaint paintwin;

    paintwin.resize( 1024, 580 );
    paintwin.setCaption("Ryckbost Design: Dungeons of Calvin");
    a.setMainWidget( &paintwin );
	paintwin.show();
    return a.exec();
}
