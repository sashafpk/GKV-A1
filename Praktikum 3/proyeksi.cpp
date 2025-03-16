
#include <GL/glut.h>

static int shoulder = 0, elbow = 0, palm = 0, fingers[5] = {0, 0, 0, 0, 0};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int baseAngle) {
    glPushMatrix();
        glRotatef((GLfloat)baseAngle, 0.0, 0.0, 1.0);
        glTranslatef(0.3, 0.0, 0.0);
        glPushMatrix();
            glScalef(0.6, 0.1, 0.1);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)palm, 0.0, 0.0, 1.0);
        glTranslatef(0.5, 0.0, 0.0);
        glPushMatrix();
            glScalef(1.0, 0.4, 0.5);
            glutWireCube(1.0);
        glPopMatrix();

        for (int i = 0; i < 5; i++) {
            glPushMatrix();
                glTranslatef(0.5, 0.2 - i * 0.1, 0.0); 
                drawFinger(fingers[i]);
            glPopMatrix();
        }
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's': shoulder = (shoulder + 5) % 360; break;
    case 'S': shoulder = (shoulder - 5) % 360; break;
    case 'e': elbow = (elbow + 5) % 360; break;
    case 'E': elbow = (elbow - 5) % 360; break;
    case 'p': palm = (palm + 5) % 360; break;
    case 'P': palm = (palm - 5) % 360; break;
    case '1': fingers[0] = (fingers[0] + 5) % 360; break;
    case '2': fingers[1] = (fingers[1] + 5) % 360; break;
    case '3': fingers[2] = (fingers[2] + 5) % 360; break;
    case '4': fingers[3] = (fingers[3] + 5) % 360; break;
    case '5': fingers[4] = (fingers[4] + 5) % 360; break;
    case 27: exit(0); break;
    default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}



