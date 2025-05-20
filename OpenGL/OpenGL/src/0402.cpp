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

int LlineStartX = 0;
int LlineEndX = 0;
int LlineStartY = 0;
int LlineEndY = 0;

int RlineStartX = 0;
int RlineEndX = 0;
int RlineStartY = 0;
int RlineEndY = 0;

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
         LlineStartX = (x - glutGet(GLUT_WINDOW_WIDTH) / 2) + 120;
         LlineStartY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
         printf("Line Start Point: (%d, %d)\n", LlineStartX, LlineStartY);
         isLineClicked = true;
      }
      else // if click and already have the start point, the click position is the end point of the line
      {
         LlineEndX = (x - glutGet(GLUT_WINDOW_WIDTH) / 2) + 120;
         LlineEndY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
         printf("Line End Point: (%d, %d)\n", LlineEndX, LlineEndY);
         isLineClicked = false;
      }
      glutPostRedisplay();
   }
   if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
   {

      if (!isLineClicked) // if click and the line doesn't exist, the click position is the start point of the line
      {
         RlineStartX = (x - glutGet(GLUT_WINDOW_WIDTH) / 2) - 120;
         RlineStartY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
         printf("Line Start Point: (%d, %d)\n", RlineStartX, RlineStartY);
         isLineClicked = true;
      }
      else // if click and already have the start point, the click position is the end point of the line
      {
         RlineEndX = (x - glutGet(GLUT_WINDOW_WIDTH) / 2) - 120;
         RlineEndY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
         printf("Line End Point: (%d, %d)\n", RlineEndX, RlineEndY);
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
   glViewport(0, 0, 400, 600);

   // 绘制点击的线段
   if (isLineClicked)
   {
      glBegin(GL_LINES);
      glColor3f(0, 0, 0);                      // 设置颜色为红色
      glVertex3f(LlineStartX, LlineStartY, 0); // 起点
      glVertex3f(LlineEndX, LlineEndY, 0);     // 终点
      glEnd();
   }

   // Calculate the rotation axis
   float dxl = LlineEndX - LlineStartX;
   float dyl = LlineEndY - LlineStartY;

   // Rotate the line with the rotation axis
   glRotatef(Rotate_delta, dxl, dyl, 0);
   DrawTriangles();

   glViewport(400, 0, 400, 600);
   glRotatef(-Rotate_delta, dxl, dyl, 0);
   if (isLineClicked)
   {
      glBegin(GL_LINES);
      glColor3f(0, 0, 0);                      // 设置颜色为红色
      glVertex3f(RlineStartX, RlineStartY, 0); // 起点
      glVertex3f(RlineEndX, RlineEndY, 0);     // 终点
      glEnd();
   }

   // Calculate the rotation axis
   float dxR = RlineEndX - RlineStartX;
   float dyR = RlineEndY - RlineStartY;

   // Rotate the line with the rotation axis
   glRotatef(Rotate_delta, dxR, dyR, 0);
   DrawTriangles();
   glutSwapBuffers(); // 在繪製完成後交換前後緩衝區
}
