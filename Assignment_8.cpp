#include <GL/glut.h>
#include <cmath>
float angle = 0.0f; // Current angle of the pendulum
float angleSpeed = 0.03f; // Angular speed
float maxAngle = 45.0f; // Maximum swing angle in degrees
void init() {
 glClearColor(1.0, 1.0, 1.0, 1.0); // Background color: white
 glColor3f(0.2, 0.2, 0.8); // Pendulum color
 glLineWidth(5.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-100, 100, -100, 100);
}
void drawPendulum(float angleDeg) {
 float length = 60.0f;
 float rad = angleDeg * 3.1415926f / 180.0f;
 float x = length * sin(rad);
 float y = -length * cos(rad);
 // Draw line (the rod)
 glBegin(GL_LINES);
 glVertex2f(0.0f, 0.0f); // origin
 glVertex2f(x, y);
 glEnd();
 // Draw the bob (as a circle)
 glPushMatrix();
 glTranslatef(x, y, 0);
 glColor3f(0.8, 0.1, 0.1);
 float radius = 8.0f;
 glBegin(GL_POLYGON);
 for (int i = 0; i < 100; ++i) {
 float theta = 2.0f * 3.1415926f * i / 100;
 glVertex2f(radius * cos(theta), radius * sin(theta));
 }
 glEnd();
 glPopMatrix();
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glPushMatrix();
 glTranslatef(0.0f, 50.0f, 0.0f); // Move pivot up
 drawPendulum(angle);
 glPopMatrix();
 glutSwapBuffers();
}
void update(int value) {
 // Easing with sine wave
 angle = maxAngle * sin(angleSpeed * glutGet(GLUT_ELAPSED_TIME) * 0.001f);
 glutPostRedisplay();
 glutTimerFunc(16, update, 0); // ~60 FPS
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(600, 600);
 glutCreateWindow("Animated Pendulum");
 init();
 glutDisplayFunc(display);
 glutTimerFunc(0, update, 0);
 glutMainLoop();
 return 0;
}
