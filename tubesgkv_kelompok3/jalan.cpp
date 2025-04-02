#include <GL/glut.h>  

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  

    glColor3f(0.0f, 0.0f, 0.0f);  
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.1f);  
    glVertex2f(1.0f, -0.1f);  
    glVertex2f(1.0f, 0.1f);    
    glVertex2f(-1.0f, 0.1f);   
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);  
    glBegin(GL_LINES);
    for (float i = -1.0f; i < 1.0f; i += 0.2f) {
        glVertex2f(i, 0.0f);        
        glVertex2f(i + 0.1f, 0.0f); 
    }
    glEnd();

    glFlush();  
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);  
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(500, 500);  
    glutCreateWindow("Jalan Raya Hitam");  
    
    init();  
    glutDisplayFunc(display);  

    glutMainLoop();  
    return 0;
}
