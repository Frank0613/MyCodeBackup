#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"

void ChangeSize(int, int);
void RenderScene(void);
void ApplyRotation(float angle, float x, float y, float z);
void ApplyScale(float scaleX, float scaleY, float scaleZ);

void KeyboardFunc(unsigned char key, int x, int y);
float Translate_deltaX = 0.0f;
float Translate_deltaY = 0.0f;
float Translate_deltaZ = 0.0f;
float Scale_deltaX = 1;
float Scale_deltaY = 1;
float Scale_deltaZ = 1;
float Rotate_deltaX = 0.0f;
float Rotate_deltaY = 0.0f;
float Rotate_deltaZ = 0.0f;

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(600, 600);
   glutInitWindowPosition(600, 80);
   glutCreateWindow("Simple Triangle");

   glutReshapeFunc(ChangeSize);
   glutDisplayFunc(RenderScene);

   glutKeyboardFunc(KeyboardFunc); // 鍵盤
   glutMainLoop();
   return 0;
}
void KeyboardFunc(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 'a':
      Translate_deltaX -= 1.0f; // 向左移動
      break;
   case 'd':                    //
      Translate_deltaX += 1.0f; // 向右移動
      break;
   case 's':
      Translate_deltaY -= 1.0f; // 向上移動
      break;
   case 'w':
      Translate_deltaY += 1.0f; // 向下移動
      break;
   case 'q':
      Translate_deltaZ -= 1.0f; // 向後移動
      break;
   case 'e':
      Translate_deltaZ += 1.0f; // 向前移動
      break;
   case '6':
      Scale_deltaX -= .1f; // X軸變大
      break;
   case '4':
      Scale_deltaX += .1f; // X軸變小
      break;
   case '8':
      Scale_deltaY -= .1f; // Y軸變大
      break;
   case '5':
      Scale_deltaY += .1f; // Y軸變小
      break;
   case '9':
      Scale_deltaZ -= .1f; // Z軸變大
      break;
   case '7':
      Scale_deltaZ += .1f; // Z軸變小
      break;
   case 'j':               //
      Rotate_deltaY -= 10; // -YRotate
      break;
   case 'l':               //
      Rotate_deltaY += 10; // YRotate
      break;
   case 'i':               //
      Rotate_deltaX -= 10; // -XRotate
      break;
   case 'k':               //
      Rotate_deltaX += 10; // XRotate
      break;
   case 'u':               //
      Rotate_deltaZ -= 10; // -ZRotate
      break;
   case 'o':               //
      Rotate_deltaZ += 10; // ZRotate
      break;
   }
   glutPostRedisplay(); // 標記當前窗口需要被重新繪製
}

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
void ApplyRotation(float angle, float x, float y, float z)
{
   float c = cos(angle * M_PI / 180.0f); // 计算角度的余弦值
   float s = sin(angle * M_PI / 180.0f); // 计算角度的正弦值

   // 旋转矩阵的每一行都是旋转轴的方向乘以旋转角度的余弦值，以及与旋转轴垂直的两个方向乘以旋转角度的正弦值
   // 第一行
   float m0 = x * x * (1 - c) + c;
   float m1 = x * y * (1 - c) - z * s;
   float m2 = x * z * (1 - c) + y * s;
   // 第二行
   float m4 = y * x * (1 - c) + z * s;
   float m5 = y * y * (1 - c) + c;
   float m6 = y * z * (1 - c) - x * s;
   // 第三行
   float m8 = x * z * (1 - c) - y * s;
   float m9 = y * z * (1 - c) + x * s;
   float m10 = z * z * (1 - c) + c;

   float rotationMatrix[16] = {
       m0, m4, m8, 0,
       m1, m5, m9, 0,
       m2, m6, m10, 0,
       0, 0, 0, 1};

   glMatrixMode(GL_MODELVIEW);
   glMultMatrixf(rotationMatrix); // 将旋转矩阵乘以当前的模型视图矩阵
}
void ApplyScale(float scaleX, float scaleY, float scaleZ)
{
   float scaleMatrix[16] = {
       scaleX, 0, 0, 0,
       0, scaleY, 0, 0,
       0, 0, scaleZ, 0,
       0, 0, 0, 1};

   glMatrixMode(GL_MODELVIEW);
   glMultMatrixf(scaleMatrix); // 将缩放矩阵乘以当前的模型视图矩阵
}
void RenderScene(void)
{
   glClearColor(1, 1, 1, 1.0);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 0, 10.0f, 0, 0, 0, 0, 1, 0);
   glEnable(GL_DEPTH_TEST); // 深度開啟

   // X
   glBegin(GL_LINES);
   glColor3f(1, 0, 0);    // 設置線條顏色為紅色
   glVertex3f(-10, 0, 0); // 起點
   glVertex3f(10, 0, 0);  // 終點
   glEnd();

   // Y
   glBegin(GL_LINES);
   glColor3f(0, 1, 0);    // 設置線條顏色為紅色
   glVertex3f(0, -10, 0); // 起點
   glVertex3f(0, 10, 0);  // 終點
   glEnd();

   // Z
   glBegin(GL_LINES);
   glColor3f(0, 0, 1);    // 設置線條顏色為紅色
   glVertex3f(0, 0, -10); // 起點
   glVertex3f(0, 0, 10);  // 終點
   glEnd();

   float modelViewMatrix[16];
   glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMatrix);

   // 更新模型視圖矩陣中的平移部分
   modelViewMatrix[12] += Translate_deltaX;
   modelViewMatrix[13] += Translate_deltaY;
   modelViewMatrix[14] += Translate_deltaZ;

   // 將更新後的矩陣設置為當前的模型視圖矩陣
   glLoadMatrixf(modelViewMatrix);

   ApplyRotation(Rotate_deltaX, 1, 0, 0);
   ApplyRotation(Rotate_deltaY, 0, 1, 0);
   ApplyRotation(Rotate_deltaZ, 0, 0, 1);

   ApplyScale(Scale_deltaX, Scale_deltaY, Scale_deltaZ);

   // Back
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0);
   glVertex3f(0, 8, -5); //
   glColor3f(0, 0, 0);
   glVertex3f(-5, -5, -5); //
   glColor3f(0, 0, 0);
   glVertex3f(5, -5, -5); //
   // bott1
   glBegin(GL_TRIANGLES);
   glColor3f(0, 1, 1);
   glVertex3f(5, -5, -5); //
   glColor3f(0, 1, 1);
   glVertex3f(5, -5, 0); //
   glColor3f(0, 1, 1);
   glVertex3f(-5, -5, 0); //

   // bott2
   glBegin(GL_TRIANGLES);
   glColor3f(0, 1, 1);
   glVertex3f(5, -5, -5); //
   glColor3f(0, 1, 1);
   glVertex3f(-5, -5, -5); //
   glColor3f(0, 1, 1);
   glVertex3f(-5, -5, 0); //

   // Left1
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 8, 0); //
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 8, -5); //
   glColor3f(0, 0.5, 0);
   glVertex3f(5, -5, -5); //
   glEnd();
   // Left2
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0.5, 0);
   glVertex3f(0, 8, 0); //
   glColor3f(0, 0.5, 0);
   glVertex3f(5, -5, -5); //
   glColor3f(0, 0.5, 0);
   glVertex3f(5, -5, 0); //
   glEnd();

   // Right1
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 8, 0); //
   glColor3f(0, 0, 0.5);
   glVertex3f(-5, -5, -5); //
   glColor3f(0, 0, 0.5);
   glVertex3f(-5, -5, 0); //
   glEnd();
   // Right2
   glBegin(GL_TRIANGLES);
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 8, 0); //
   glColor3f(0, 0, 0.5);
   glVertex3f(0, 8, -5); //
   glColor3f(0, 0, 0.5);
   glVertex3f(-5, -5, -5); //
   glEnd();
   // Front
   glBegin(GL_TRIANGLES);
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(5, -5, 0); //
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(0, 8, 0); //
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f(-5, -5, 0); //
   glEnd();

   glutSwapBuffers();
}