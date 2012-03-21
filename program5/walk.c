/* walk.c -- walk around in a room. */

//
// This is starting code for the Dungeons of Calvin program.
// Modify it to add texture mapping, improved navigation, walls, doors, etc.
//
// Note that the projection is set up in such a way that Z is up
// and the floor is the XY-plane.
//
// This program will open a crml file specified on the command line, if one
// is given; else it will default to a given file.
//
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <assert.h>
using namespace std;

double locx=10.0, locy=5.0, locz=6.0;		//location of viewer
double orient;					//orientation of viewer
						// 0 is "North" (+Y)
GLuint theRoom;
int winwidth=800, winheight=400;		//initial window size
const double PI=3.1415926535;
const double MAXSTEP=2, MAXROT = 1.0/6.0*PI;	//maximum step, turn
const double FOV=75.0;
char ROOM[120]="/home/hplantin/public/crml/2007/hall.crml";	//default starting room

void walkView(double orient, double locx, double locy, double locz);

//
// The read-room function only reads the faces and face colors.
// You should make it read in walls and doors and handle texture mapping.
//
void read_room(char *room) 
{
    theRoom = glGenLists(1);

    //open the filename we are given
    cout << "Opening " << ROOM << endl;
    ifstream fin(ROOM);
    assert(fin.is_open());

    GLfloat lookx, looky, lookz;
    string keyword;
   
    //
    // note that if you are coming to this room from
    // another room, you should use the eyep and lookp from
    // the door you just went through, not these values.
    //
    fin >> keyword >> locx >> locy >> locz;
    fin >> keyword >> lookx >> looky >> lookz;
    orient = atan2(looky-locy, lookx-locx);
    walkView(orient, locx, locy, locz);		//set up viewing transformation

    int numFaces;
    fin >> keyword >> numFaces;
    cout << numFaces << " faces" << endl;
    GLfloat red, green, blue, x, y, z;

    glNewList(theRoom, GL_COMPILE);		//store room in display list
    glBegin(GL_QUADS);

    for (int i=0; i<numFaces; i++)		//read in and draw each face
    {
      fin >> keyword >> red >> green >> blue;
      glColor3f(red, green, blue);
      fin >> keyword >> keyword >> keyword;
      for (int i=0; i<4; i++)
      {
        fin >> x >> y >> z;
        glVertex3f(x, y, z);
      }
    }

    glEnd();
    glEndList();
}    


void init(void) 
{    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    read_room(ROOM);
}


//
// all display has to do is clear the screen and draw the display list.
//
void display(void) 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glCallList(theRoom);
  glutSwapBuffers();
}


//
// given a viewing direction and location, this function sets the
// viewing parameters appropriately.
//
void walkView(double orient, double locx, double locy, double locz) 
{
    cout << "walkView:\tx="<<locx << "\ty="<<locy << "\tz="<<locz 
         << "\torient="<<orient*180/PI << endl; 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOV, 1.0*winwidth/winheight, 0.5, 10000.0);
    gluLookAt(locx, locy, locz, locx+sin(orient), locy+cos(orient), locz, 0.0, 0.0, 1.0);
    glutPostRedisplay();
}


void reshape(int w, int h) {
    winwidth=w; winheight=h; 
    glViewport(0, 0, w, h);
    walkView(orient, locx, locy, locz);
}


//
// handle mouse clicks: click above center move ahead, below move back.
// click on the left side turn left, right right.
//
void mouse(int button, int state, int x, int y) 
{
    if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
    {
	orient += MAXROT * (2.0*x/winwidth - 1.0);
	float step = MAXSTEP * (2.0 * y / winheight - 1.0);
	locx -= step *  sin(orient);	// subtract because we're really
	locy -= step *  cos(orient);	// moving the world, not the viewer
	walkView(orient, locx, locy, locz);
    }
}


//
// you may wish to add key commands for navigation, for 
// turning on/off texture mapping, etc.
//
void keyboard(unsigned char key, int x, int y)
{
    cout << "Got a " << int(key) << " character.\n";

    if (key == 'w' ) { //forward
        orient += 0;
	float step = MAXSTEP;
	locx += step *  sin(orient);	// subtract because we're really
	locy += step *  cos(orient);	// moving the world, not the viewer
	walkView(orient, locx, locy, locz);
    } else if (key == 'a') { //left
        orient += -.33;
	float step = 0;
	locx -= step *  sin(orient);	// subtract because we're really
	locy -= step *  cos(orient);	// moving the world, not the viewer
	walkView(orient, locx, locy, locz);
    } else if (key == 's') { //backward
        orient += 0;
	float step = MAXSTEP;
	locx -= step *  sin(orient);	// subtract because we're really
	locy -= step *  cos(orient);	// moving the world, not the viewer
	walkView(orient, locx, locy, locz);
    } else if (key == 'd') {  //right
        orient += .33;
	float step = 0;
	locx -= step *  sin(orient);	// subtract because we're really
	locy -= step *  cos(orient);	// moving the world, not the viewer
	walkView(orient, locx, locy, locz);
    } else if(key == 27) 
		exit(0);
}

//
//main is pretty standard -- open window, set up callbacks, start.
//
int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    if (argc > 1) 
	strcpy(ROOM, argv[1]);		// open command-line CRML file
  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (winwidth, winheight); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc (mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;            
}

