#include <GL/glut.h>
#include <iostream>
#include <cmath>
void drawLineDDA(int x1, int y1, int x2, int y2) {
 int dx = x2 - x1;
 int dy = y2 - y1;
 int steps = std::max(abs(dx), abs(dy));
 float xIncrement = dx / (float)steps;
 float yIncrement = dy / (float)steps;
 float x = x1;
 float y = y1;
 for (int i = 0; i <= steps; i++) {
 glBegin(GL_POINTS);
 glVertex2i(round(x), round(y));
 glEnd();
 x += xIncrement;
 y += yIncrement;
 }
}
void drawDottedLine(int x1, int y1, int x2, int y2) {
 int dx = x2 - x1;
 int dy = y2 - y1;
 int steps = std::max(abs(dx), abs(dy));
 float xIncrement = dx / (float)steps;
 float yIncrement = dy / (float)steps;
 float x = x1;
 float y = y1;
 for (int i = 0; i <= steps; i++) {
 if (i % 5 == 0) {
 glBegin(GL_POINTS);
 glVertex2i(round(x), round(y));
 glEnd();
 }
 x += xIncrement;
 y += yIncrement;
 }
}
void drawDashedLine(int x1, int y1, int x2, int y2) {
 int dx = x2 - x1;
 int dy = y2 - y1;
 int steps = std::max(abs(dx), abs(dy));
 float xIncrement = dx / (float)steps;
 float yIncrement = dy / (float)steps;
 float x = x1;
 float y = y1;
 for (int i = 0; i <= steps; i++) {
 if (i % 10 < 5) {
 glBegin(GL_POINTS);
 glVertex2i(round(x), round(y));
 glEnd();
 }
 x += xIncrement;
 y += yIncrement;
 }
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 1.0, 1.0);
 drawLineDDA(-200, -100, 200, 100);
 drawDottedLine(-200, 50, 200, 50);
 drawDashedLine(-200, 0, 200, 0);
 glFlush();
}
void init() {
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glColor3f(1.0, 1.0, 1.0);
 glPointSize(2.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-250, 250, -250, 250);
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Line Drawing Algorithms");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
