#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float cameraAzimuth = 45.0f;
float cameraElevation = 20.0f;
float cameraDistance = 8.0f;

void drawBlockyCloud() {
    glColor3f(1.0f, 1.0f, 1.0f); // Warna putih

    // Kubus pusat (bagian utama awan)
    glPushMatrix();
      glScalef(1.5f, 0.6f, 1.0f);
      glutSolidCube(1.0);
    glPopMatrix();

    // sisi kiri 
    glPushMatrix();
      glTranslatef(-0.75f, 0.0f, 0.0f);
      glScalef(1.0f, 0.6f, 1.0f);
      glutSolidCube(1.0);
    glPopMatrix();

    // sisi kanan
    glPushMatrix();
      glTranslatef(0.75f, 0.0f, 0.0f);
      glScalef(1.0f, 0.6f, 1.0f);
      glutSolidCube(1.0);
    glPopMatrix();

    // sisi atas
    glPushMatrix();
      glTranslatef(0.0f, 0.5f, 0.0f);
      glScalef(1.2f, 0.5f, 1.0f);
      glutSolidCube(1.0);
    glPopMatrix();

    // sisi bawah 
    glPushMatrix();
      glTranslatef(0.0f, -0.4f, 0.0f);
      glScalef(1.2f, 0.5f, 1.0f);
      glutSolidCube(1.0);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float radAzimuth = cameraAzimuth * M_PI / 180.0f;
    float radElevation = cameraElevation * M_PI / 180.0f;
    float eyeX = cameraDistance * cos(radElevation) * sin(radAzimuth);
    float eyeY = cameraDistance * sin(radElevation);
    float eyeZ = cameraDistance * cos(radElevation) * cos(radAzimuth);
    gluLookAt(eyeX, eyeY, eyeZ,   
              0.0, 0.0, 0.0,      
              0.0, 1.0, 0.0);     

    drawBlockyCloud();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0)
        h = 1;
    float aspect = (float)w / h;
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 50.0);
    
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
            if (cameraElevation > 89.0f) cameraElevation = 89.0f;
            break;
        case GLUT_KEY_DOWN:
            cameraElevation -= 5.0f;
            if (cameraElevation < -89.0f) cameraElevation = -89.0f;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("awan");
    
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Latar belakang biru langit
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    
    glutMainLoop();
    return 0;
}

