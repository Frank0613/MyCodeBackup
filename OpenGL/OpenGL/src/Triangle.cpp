
#include <stdio.h>
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"

void ChangeSize(int, int);
void RenderScene(void);

int main(int argc, char **argv)
{
   glutInit(&argc, argv);                       // 初始化glut庫，argc是要執行命令行參數的數量("&"讀取他們的位址)，argv是指向這些參數字符串的指標數組
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 設置顯示模式，使用雙緩衝和 RGB 顏色模式
   glutInitWindowSize(400, 400);                // 設置視窗的初始大小
   glutInitWindowPosition(600, 80);             // 設置視窗的初始位置
   glutCreateWindow("Simple Triangle");         // 設置視窗並命名

   glutReshapeFunc(ChangeSize);  // 設置視窗大小改變時調用的函式
   glutDisplayFunc(RenderScene); // 設置視窗的渲染函式
   glutMainLoop();               // 進入 GLUT 主事件迴圈，這個函式將持續運行，直到視窗被關閉。(這個要放最下面)
   return 0;
}
void ChangeSize(int w, int h) // 這個函式主要是在視窗大小改變時重新設置 OpenGL 的狀態
{
   printf("Window Size= %d X %d\n", w, h); // 顯示視窗大小
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);        // 函式設置當前矩陣堆棧的模式，這裡設置為投影矩陣模式。????????????
   glLoadIdentity();                   // 函式將當前矩陣設置為單位矩陣，這樣可以確保不受先前的矩陣狀態影響。???????????
   glOrtho(-10, 10, -10, 10, -10, 10); // 設置正射投影矩陣。分別是左、右、底、頂、近、遠(相機可以看到的空間)
   glMatrixMode(GL_MODELVIEW);         // 切換回模型視景矩陣堆棧模式。
   glLoadIdentity();                   // 重置當前的模型視景矩陣為單位矩陣。
}
void RenderScene(void)
{
   glClearColor(1.0, 1.0, 1.0, 1.0);                   // 背景顏色(r,g,b,a)
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除顏色緩衝區和深度緩衝區。這是在每一幀渲染前執行的操作
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 0, 10.0f, 0, 0, 0, 0, 1, 0); // 設置視點、觀察點和上方向，用於定義視圖矩陣。這裡相當於將相機位置設置在 (0, 0, 10.0f)、觀察點在 (0, 0, 0)、上方向為 Y 軸正方向。
   glBegin(GL_TRIANGLES);                    // 定義一個三角形，會搭配 glEnd()

   glColor3f(1, 0, 0);        // 點的顏色
   glVertex3f(8.6603, -5, 0); // 點的位置
   glColor3f(0, 1, 0);
   glVertex3f(0, 10, 0);
   glColor3f(0, 0, 1);
   glVertex3f(-8.6603, -5, 0);

   glEnd();
   glutSwapBuffers(); // 交換前後緩衝區，將渲染的結果顯示到視窗上。這是使用雙緩衝時常見的操作
}