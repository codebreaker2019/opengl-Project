#include<windows.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 20

void display();
void reshape_callback(int,int);
void timer_callback(int);

void init()
{
   glClearColor(1.0,1.0,0.0,1.0);
   initGrid(COLUMNS,ROWS);

}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //glutInitWindowPosition(700,700);
    glutInitWindowSize(500,500);
    glutCreateWindow("snakes game ");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    init();
    glutMainLoop();
    return 0;
}

int index=0;
void display()
{
    //glClearColor(1.0,1.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glRectd(index,20,index+2,22);
    index++;
    if(index>40)
    {
        index=0;
    }
    glutSwapBuffers();
}
void reshape_callback(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);

}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}
