#include <GL/glut.h>
#include <cmath>  

void drawCircle(float radius, float xCenter, float yCenter) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f;  // Menghitung sudut dalam radian
        float x = xCenter + radius * cos(angle);  // Menghitung koordinat x
        float y = yCenter + radius * sin(angle);  // Menghitung koordinat y
        glVertex2f(x, y);  // Menambahkan titik ke lingkaran
    }
    glEnd();
}

// Fungsi untuk menggambar objek (koin)
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.2f, 0.0f, 0.0f);
    glFlush();
}

// Fungsi inisialisasi OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Gambar Koin Berwarna Kuning");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

