#include <GL/glut.h>
#include <cmath>

float angle = 0.0;  
float tx = 0.0;     

void RodaMobil(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * 3.1415926 / 180;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

void Mobil() {
    glPushMatrix(); 
    glTranslatef(tx, 0, 0); 

    // badan mobil
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.4, 0.3);
    glVertex2f(-0.4, 0.3);
    glEnd();
    
    // jendela kiri
    glColor3f(0.6, 0.8, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.25, 0.1);
    glVertex2f(-0.05, 0.1);
    glVertex2f(-0.05, 0.25);
    glVertex2f(-0.25, 0.25);
    glEnd();

    // jendela kanan
    glBegin(GL_QUADS);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.25, 0.25);
    glVertex2f(0.05, 0.25);
    glEnd();

    // roda kiri
    glPushMatrix(); 
    glTranslatef(-0.3, -0.1, 0);
    glRotatef(angle, 0, 0, 1); 
    glColor3f(0.0, 0.0, 0.0);
    RodaMobil(0, 0, 0.1);
    glPopMatrix();

    // roda kanan
    glPushMatrix(); 
    glTranslatef(0.3, -0.1, 0);
    glRotatef(angle, 0, 0, 1);
    glColor3f(0.0, 0.0, 0.0);
    RodaMobil(0, 0, 0.1);
    glPopMatrix();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Mobil();
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("mobil");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

