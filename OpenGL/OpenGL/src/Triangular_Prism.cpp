
#include <stdio.h>
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"

void ChangeSize(int, int);
void RenderScene(void);
float rotationAngle = 0.0f;

// Rotation Animate
void update(int value)
{
   rotationAngle += 1.0f; // 每一幀旋轉1度

   glutPostRedisplay(); // 通知 GLUT 重新繪製

   glutTimerFunc(16, update, 0); // 設置下一次定時器
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(600, 600);
   glutInitWindowPosition(600, 80);
   glutCreateWindow("Simple Triangle");

   glutReshapeFunc(ChangeSize);
   glutTimerFunc(25, update, 0);
   glutDisplayFunc(RenderScene);
   glutMainLoop();
   return 0;
}

// Windows Size
void ChangeSize(int w, int h)
{
   printf("Window Size= %d X %d\n", w, h);
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10, 10, -10, 10, -10, 50);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void RenderScene(void)
{
   glClearColor(1, 1, 1, 1.0);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 0, 10.0f, 0, 0, 0, 0, 1, 0);
   glEnable(GL_DEPTH_TEST); // 深度開啟

   // Rotation Animate
   glRotatef(rotationAngle, 0, 1, 0);
   glRotatef(10, 1, 0, 0);

   // Back
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0);
   glVertex3f(0, 8, -5);
   glColor3f(0, 0, 0);
   glVertex3f(-5, -5, -5);
   glColor3f(0, 0, 0);
   glVertex3f(5, -5, -5);

   // bottom
   glBegin(GL_TRIANGLES);
   glColor3f(0, 1, 1);
   glVertex3f(5, -5, -5);
   glColor3f(0, 1, 1);
   glVertex3f(5, -5, 0);
   glColor3f(0, 1, 1);
   glVertex3f(-5, -5, 0);
   //=======================
   glBegin(GL_TRIANGLES);
   glColor3f(0, 1, 1);
   glVertex3f(5, -5, -5);
   glColor3f(0, 1, 1);
   glVertex3f(-5, -5, -5);
   glColor3f(0, 1, 1);
   glVertex3f(-5, -5, 0);

   // Left
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 8, 0);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 8, -5);
   glColor3f(0, 0.5, 0);
   glVertex3f(5, -5, -5);
   glEnd();
   // =======================
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 8, 0);
   glColor3f(0, 0.5, 0);
   glVertex3f(5, -5, -5);
   glColor3f(0, 0.5, 0);
   glVertex3f(5, -5, 0);
   glEnd();

   // Right
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 8, 0);
   glColor3f(0, 0, 0.5);
   glVertex3f(-5, -5, -5);
   glColor3f(0, 0, 0.5);
   glVertex3f(-5, -5, 0);
   glEnd();
   // =======================
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 8, 0);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 8, -5);
   glColor3f(0, 0, 0.5);
   glVertex3f(-5, -5, -5);
   glEnd();

   // Front
   glBegin(GL_TRIANGLES);
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(5, -5, 0);
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(0, 8, 0);
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(-5, -5, 0);
   glEnd();

   glutSwapBuffers();
}