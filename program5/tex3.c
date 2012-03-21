/* tex2.c -- show a coupla polygons with different textures. */
#include <GL/glut.h>
#include "texture.h"
#include <stdlib.h>
GLubyte *image;
GLuint texName[50];

void myinit(void) {    
    int width, height, comp;

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glGenTextures(50,texName);
    glBindTexture(GL_TEXTURE_2D, texName[0]);
    image = (GLubyte *) read_texture("anna.sgi", &width, &height, &comp);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, 
        GL_UNSIGNED_BYTE, image);
    free(image);

    glBindTexture(GL_TEXTURE_2D, texName[1]);
    image = (GLubyte *) read_texture("wall1.sgi", &width, &height, &comp);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, 
        GL_UNSIGNED_BYTE, image);
    free(image);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, texName[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texName[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
    glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);		//no texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.41421, -1.0, -3.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.41421, 1.0, -3.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 1.0, -1.0);
    glEnd();

    glutSwapBuffers();
}

void myReshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.6);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("tex2");
    myinit();
    glutReshapeFunc (myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;            
}
