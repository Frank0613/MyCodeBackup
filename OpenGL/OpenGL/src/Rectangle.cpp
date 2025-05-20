
#include <stdio.h>
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"

void ChangeSize(int, int);
void RenderScene(void);
void MenuFunction(int choice);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(600, 80);
    glutCreateWindow("Simple RECTANGLE"); // Window's name
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);

    // Add the MENU
    glutCreateMenu(MenuFunction);
    // Add the Options
    glutAddMenuEntry("smooth", 1);
    glutAddMenuEntry("flat", 2);
    // Add how to Click
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
void MenuFunction(int choice)
{
    switch (choice)
    {
    case 1:
        glShadeModel(GL_SMOOTH); // 會在物體的表面上創建平滑的色彩過渡
        break;
    case 2:
        glShadeModel(GL_FLAT); // 種模式會使用每個多邊形的法向量來定義整個多邊形的陰影，使多邊形的整個表面使用一種單一的顏色(看最後畫的點顏色決定)
        break;
    }
    glutPostRedisplay(); // 它通知 GLUT 主事件迴圈需要重新繪製畫面
}
void ChangeSize(int w, int h)
{
    printf("Window Size= %d X %d\n", w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void RenderScene(void)
{
    glClearColor(0, 0, 0, 1.0); // Background color (r,g,b,a)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10.0f, 0, 0, 0, 0, 1, 0);
    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex3f(5, 5, 0);
    glColor3f(0, 1, 0);
    glVertex3f(-5, 5, 0);
    glColor3f(0, 0, 1);
    glVertex3f(-5, -5, 0);
    glColor3f(0, 1, 1);
    glVertex3f(5, -5, 0);

    glEnd();
    glutSwapBuffers();
}