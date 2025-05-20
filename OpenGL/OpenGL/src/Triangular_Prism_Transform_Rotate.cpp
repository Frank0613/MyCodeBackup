
#include <stdio.h>
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"

void ChangeSize(int, int);
void RenderScene(void);

void KeyboardFunc(unsigned char key, int x, int y);
float Translate_deltaX = 0.0f;
float Translate_deltaY = 0.0f;
float Translate_deltaZ = 0.0f;
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
   case 'a':
      Translate_deltaX -= 1.0f; // X軸變大
      break;
   case 'd':                    
      Translate_deltaX += 1.0f; // X軸變小
      break;
   case 's':
      Translate_deltaY -= 1.0f; // Y軸變大
      break;
   case 'w':
      Translate_deltaY += 1.0f; // Y軸變小
      break;
   case 'q':
      Translate_deltaZ -= 1.0f; // Z軸變大
      break;
   case 'e':
      Translate_deltaZ += 1.0f; // Z軸變小
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

   glTranslatef(Translate_deltaX, Translate_deltaY, Translate_deltaZ); // 定義移動
   glRotatef(Rotate_deltaY, 0, 1, 0);
   glRotatef(Rotate_deltaX, 1, 0, 0);
   glRotatef(Rotate_deltaZ, 0, 0, 1);

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