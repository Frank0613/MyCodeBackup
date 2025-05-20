#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"

void ChangeSize(int, int);
void RenderScene(void);
void KeyboardFunc(unsigned char key, int x, int y);  // Keyboard Input
void MouseFunc(int button, int state, int x, int y); // Mouse Input
void DrawTriangles();

float Rotate_delta = 0.0f;

int clickedX = 0;
int clickedY = 0;

int lineStartX = 0;
int lineEndX = 0;
int lineStartY = 0;
int lineEndY = 0;

bool isLineClicked = false;

int main(int argc, char **argv)
{
   // About Window
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(600, 80);
   glutCreateWindow("View");

   // About Function
   glutReshapeFunc(ChangeSize);
   glutDisplayFunc(RenderScene);
   glutKeyboardFunc(KeyboardFunc); // Keyboard Function
   glutMouseFunc(MouseFunc);       // Mouse Function

   glutMainLoop();
   return 0;
}

void KeyboardFunc(unsigned char key, int x, int y)
{
   // If 'r' is pressed and the line has been generated, add Rotate_delta.
   switch (key)
   {
   case 'r':
      if (isLineClicked)
      {
         Rotate_delta += 10;
      }
      break;
   }
   glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y)
{

   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
      if (!isLineClicked) // if click and the line doesn't exist, the click position is the start point of the line
      {
         lineStartX = x - glutGet(GLUT_WINDOW_WIDTH) / 2;
         lineStartY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
         printf("Line Start Point: (%d, %d)\n", lineStartX, lineStartY);
         isLineClicked = true;
      }
      else // if click and already have the start point, the click position is the end point of the line
      {
         lineEndX = x - glutGet(GLUT_WINDOW_WIDTH) / 2;
         lineEndY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
         printf("Line End Point: (%d, %d)\n", lineEndX, lineEndY);
         isLineClicked = false;
      }
      glutPostRedisplay();
   }
}

void ChangeSize(int w, int h)
{
   printf("Window Size= %d X %d\n", w, h);
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-w / 2, w / 2, -h / 2, h / 2, -100, 100); // The parameters specify the coordinates of the left, right, bottom, top, near, and far clipping planes
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void DrawTriangles()
{
   // X axis
   glBegin(GL_LINES);
   glColor3f(1, 0, 0);     // 設置線條顏色為紅色
   glVertex3f(-100, 0, 0); // 起點
   glVertex3f(100, 0, 0);  // 終點
   glEnd();

   // Y axis
   glBegin(GL_LINES);
   glColor3f(0, 1, 0);     // 設置線條顏色為綠色
   glVertex3f(0, -100, 0); // 起點
   glVertex3f(0, 100, 0);  // 終點
   glEnd();

   // Z axis
   glBegin(GL_LINES);
   glColor3f(0, 0, 1);     // 設置線條顏色為藍色
   glVertex3f(0, 0, -100); // 起點
   glVertex3f(0, 0, 100);  // 終點
   glEnd();

   // Back
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0);
   glVertex3f(0, 80, -50);
   glColor3f(0, 0, 0);
   glVertex3f(-50, -50, -50);
   glColor3f(0, 0, 0);
   glVertex3f(50, -50, -50);

   // bott1
   glBegin(GL_TRIANGLES);
   glColor3f(0, 1, 1);
   glVertex3f(50, -50, -50);
   glColor3f(0, 1, 1);
   glVertex3f(50, -50, 0);
   glColor3f(0, 1, 1);
   glVertex3f(-50, -50, 0);

   // bott2
   glBegin(GL_TRIANGLES);
   glColor3f(0, 1, 1);
   glVertex3f(50, -50, -50);
   glColor3f(0, 1, 1);
   glVertex3f(-50, -50, -50);
   glColor3f(0, 1, 1);
   glVertex3f(-50, -50, 0);

   // Left1
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 80, 0);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 80, -50);
   glColor3f(0, 0.5, 0);
   glVertex3f(50, -50, -50);
   glEnd();
   // Left2
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 80, 0);
   glColor3f(0, 0.5, 0);
   glVertex3f(50, -50, -50);
   glColor3f(0, 0.5, 0);
   glVertex3f(50, -50, 0);
   glEnd();

   // Right1
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 80, 0);
   glColor3f(0, 0, 0.5);
   glVertex3f(-50, -50, -50);
   glColor3f(0, 0, 0.5);
   glVertex3f(-50, -50, 0);
   glEnd();
   // Right2
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 80, 0);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 80, -50);
   glColor3f(0, 0, 0.5);
   glVertex3f(-50, -50, -50);
   glEnd();
   // Front
   glBegin(GL_TRIANGLES);
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(50, -50, 0);
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(0, 80, 0);
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(-50, -50, 0);
   glEnd();
}
void RenderScene(void)
{
   glClearColor(1, 1, 1, 1.0);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 0, 25.0f, 0, 0, 0, 0, 1, 0);

   glEnable(GL_DEPTH_TEST); // Depth mode enabled

   // 绘制点击的线段
   if (isLineClicked)
   {
      glBegin(GL_LINES);
      glColor3f(0, 0, 0);                    // 设置颜色为红色
      glVertex3f(lineStartX, lineStartY, 0); // 起点
      glVertex3f(lineEndX, lineEndY, 0);     // 终点
      glEnd();
   }

   // Calculate the rotation axis
   float dx = lineEndX - lineStartX;
   float dy = lineEndY - lineStartY;

   // Rotate the line with the rotation axis
   glRotatef(Rotate_delta, dx, dy, 0);
   DrawTriangles();

   glutSwapBuffers(); // 在繪製完成後交換前後緩衝區
}
