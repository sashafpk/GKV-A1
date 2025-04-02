#include <GL/glut.h> 

void drawCircle(float radius, float xCenter, float yCenter) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f;  
        float x = xCenter + radius * cos(angle);  
        float y = yCenter + radius * sin(angle);  
        glVertex2f(x, y);  
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  

    glColor3f(1.0f, 1.0f, 0.0f);  
    drawCircle(0.2f, 0.0f, 0.0f);  

    glFlush();  
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);  
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(500, 500);  
    glutCreateWindow("Koin Kuning"); 
    
    init();  
    glutDisplayFunc(display);  

    glutMainLoop();  
    return 0;
}
