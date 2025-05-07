#include<iostream>
#include<GL/glut.h>
using namespace std;
void Init(){
glClearColor(0,0,0,0);
gluOrtho2D(0,640,0,480);
//glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
}
void draw(){
 glBegin(GL_POLYGON);
 glVertex2f(240, 150); // Bottom-left vertex of the house body
 glVertex2f(240, 250); // Top-left vertex of the house body
 glVertex2f(400, 250); // Top-right vertex of the house body
 glVertex2f(400, 150); // Bottom-right vertex of the house body
 glEnd();
 glColor3f(1, 0, 0); // Set drawing color to red for the roof
 glBegin(GL_TRIANGLES);
 glVertex2f(220, 250); // Left vertex of the roof (peak of the triangle)
 glVertex2f(420, 250); // Right vertex of the roof (peak of the triangle)
 glVertex2f(320, 350); // Top vertex of the roof (center of the triangle)
 glEnd();
 glColor3f(0.5, 0.25, 0); // Set drawing color to brown for the door
 glBegin(GL_POLYGON);
 glVertex2f(290, 150); // Bottom-left vertex of the door
 glVertex2f(290, 200); // Top-left vertex of the door
 glVertex2f(330, 200); // Top-right vertex of the door
 glVertex2f(330, 150); // Bottom-right vertex of the door
 glEnd();

glFlush();
}
int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(640,480);
glutCreateWindow("Polygon");
Init();
glutDisplayFunc(draw);
glutMainLoop();
return(0);
}
