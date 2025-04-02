#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float wingAngle = 0.0f;
int wingDirection = 1; // 1: naik, -1: turun

float cameraAzimuth = 0.0f;
float cameraElevation = 0.0f;
float cameraDistance = 5.0f;

void timer(int value) {
    if (wingAngle > 30.0f)
        wingDirection = -1;
    else if (wingAngle < -30.0f)
        wingDirection = 1;
    wingAngle += wingDirection * 1.0f; 

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); 
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.7f, 0.8f, 1.0f, 1.0f); // Latar belakang biru muda
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float radAzimuth = cameraAzimuth * M_PI / 180.0f;
    float radElevation = cameraElevation * M_PI / 180.0f;
    float eyeX = cameraDistance * cos(radElevation) * sin(radAzimuth);
    float eyeY = cameraDistance * sin(radElevation);
    float eyeZ = cameraDistance * cos(radElevation) * cos(radAzimuth);
    gluLookAt(eyeX, eyeY, eyeZ,  
              0.0, 0.0, 0.0,     
              0.0, 1.0, 0.0);    

    // Badan
    glPushMatrix();
      glColor3f(0.0f, 0.0f, 1.0f); 
      glScalef(1.0f, 0.6f, 0.8f);
      glutSolidCube(1.0);
    glPopMatrix();

    // Kepala
    glPushMatrix();
      glTranslatef(0.0f, 0.5f, 0.4f);
      glColor3f(0.0f, 1.0f, 0.0f); 
      glScalef(0.5f, 0.5f, 0.5f);
      glutSolidCube(1.0);
    
      // Mata kanan
      glPushMatrix();
         glTranslatef(0.1f, 0.05f, 0.45f);
         glColor3f(1.0f, 1.0f, 1.0f); 
         glScalef(0.2f, 0.2f, 0.1f);
         glutSolidCube(1.0);
         glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.1f);
            glColor3f(0.0f, 0.0f, 0.0f); 
            glScalef(0.5f, 0.5f, 0.5f);
            glutSolidCube(1.0);
         glPopMatrix();
      glPopMatrix();
      
      // Mata kiri
      glPushMatrix();
         glTranslatef(-0.1f, 0.05f, 0.45f);
         glColor3f(1.0f, 1.0f, 1.0f); 
         glScalef(0.2f, 0.2f, 0.1f);
         glutSolidCube(1.0);
         glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.1f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glScalef(0.5f, 0.5f, 0.5f);
            glutSolidCube(1.0);
         glPopMatrix();
      glPopMatrix();
    glPopMatrix();

    // Paruh
    glPushMatrix();
      glTranslatef(0.0f, 0.5f, 0.75f); 
      glColor3f(1.0f, 1.0f, 0.0f); 
      glScalef(0.2f, 0.2f, 0.5f);
      glutSolidCube(1.0);
    glPopMatrix();

    // Sayap
    // Sayap kiri
    glPushMatrix();
      glTranslatef(-0.5f, 0.0f, 0.0f);
      glRotatef(wingAngle, 0.0f, 0.0f, 1.0f);
      glTranslatef(-0.15f, 0.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 0.8f); 
      glScalef(0.2f, 0.6f, 0.8f);
      glutSolidCube(1.0);
    glPopMatrix();

    // Sayap kanan 
    glPushMatrix();
      glTranslatef(0.5f, 0.0f, 0.0f);
      glRotatef(-wingAngle, 0.0f, 0.0f, 1.0f);
      glTranslatef(0.15f, 0.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 0.8f);
      glScalef(0.2f, 0.6f, 0.8f);
      glutSolidCube(1.0);
    glPopMatrix();

    // Kaki
    // Kaki kiri
    glPushMatrix();
      glTranslatef(-0.2f, -0.5f, 0.0f);
      glColor3f(0.5f, 0.3f, 0.0f); 
      glScalef(0.2f, 0.5f, 0.2f);
      glutSolidCube(1.0);
    glPopMatrix();
    // Kaki kanan
    glPushMatrix();
      glTranslatef(0.2f, -0.5f, 0.0f);
      glColor3f(0.5f, 0.3f, 0.0f);
      glScalef(0.2f, 0.5f, 0.2f);
      glutSolidCube(1.0);
    glPopMatrix();

    // Jari Kaki
    // Jari kaki kiri 
    glPushMatrix();
      glTranslatef(-0.2f, -0.8f, 0.1f);
      glColor3f(0.5f, 0.3f, 0.0f);
      glScalef(0.1f, 0.1f, 0.3f);
      glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-0.2f, -0.8f, -0.1f);
      glColor3f(0.5f, 0.3f, 0.0f);
      glScalef(0.1f, 0.1f, 0.3f);
      glutSolidCube(1.0);
    glPopMatrix();
    // Jari kaki kanan 
    glPushMatrix();
      glTranslatef(0.2f, -0.8f, 0.1f);
      glColor3f(0.5f, 0.3f, 0.0f);
      glScalef(0.1f, 0.1f, 0.3f);
      glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.2f, -0.8f, -0.1f);
      glColor3f(0.5f, 0.3f, 0.0f);
      glScalef(0.1f, 0.1f, 0.3f);
      glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    if(h == 0) h = 1;
    float aspect = (float)w / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT:
            cameraAzimuth -= 5.0f;
            break;
        case GLUT_KEY_RIGHT:
            cameraAzimuth += 5.0f;
            break;
        case GLUT_KEY_UP:
            cameraElevation += 5.0f;
            if(cameraElevation > 89.0f)
                cameraElevation = 89.0f;
            break;
        case GLUT_KEY_DOWN:
            cameraElevation -= 5.0f;
            if(cameraElevation < -89.0f)
                cameraElevation = -89.0f;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("burung");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

