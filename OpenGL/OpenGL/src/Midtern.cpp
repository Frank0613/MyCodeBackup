#include ".\\GL\\freeglut.h"
#include <GL/gl.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
class ObjLoader
{
public:
    ObjLoader() {} // 空構造函數

    void LoadObj(const std::string &filename); // 加載檔案
    void Draw();
    void Get_Faces_And_Vertex();
    void Axis(float length = 10);
    std::vector<std::vector<float>> vertices;
    std::vector<std::vector<int>> faces;
    float modelWidth, modelHeight, modelDepth;
    float maxDimension;

    float Translate_deltaX = 0.0f;
    float Translate_deltaY = 0.0f;
    float Translate_deltaZ = 0.0f;
    float Rotate_deltaX = 0.0f;
    float Rotate_deltaY = 0.0f;
    float Rotate_deltaZ = 0.0f;
    float Customize_Rotate_delta = 0.0f;
    float Scale_deltaX = 1;
    float Scale_deltaY = 1;
    float Scale_deltaZ = 1;

    float mouseX1 = 0.0f;
    float mouseY1 = 0.0f;
    float mouseX2 = 0.0f;
    float mouseY2 = 0.0f;
    int ClickState = 0; // 添加一個狀態變量，用於跟蹤是否是第一次點擊

    float Cam_Rotate_deltaX = 0.0f;
    float Cam_Rotate_deltaY = 0.0f;
    float Cam_Rotate_deltaZ = 0.0f;

    bool RandomColor =false;

};

struct MenuItem
{
    std::string label;
    std::string filename;
};

std::vector<MenuItem> menuItems;

// 添加一個全局變量，表示當前的繪製模式
GLenum drawMode = GL_TRIANGLES;

void ObjLoader::LoadObj(const std::string &filename){
    // 清除舊數據
    vertices.clear();
    faces.clear();

    // 重置模型尺寸相關變量
    modelWidth = 0.0f;
    modelHeight = 0.0f;
    modelDepth = 0.0f;
    maxDimension = 0.0f;

    std::ifstream file(filename);
    std::string line;
    while (getline(file, line))
    {
        if (line.substr(0, 1) == "v")
        {
            std::vector<float> vertex;
            float x, y, z;

            std::istringstream s(line.substr(2));
            s >> x;
            s >> y;
            s >> z;
            vertex.push_back(x);
            vertex.push_back(y);
            vertex.push_back(z);
            vertices.push_back(vertex);

            // 更新模型尺寸
            modelWidth = std::max(modelWidth, x);
            modelHeight = std::max(modelHeight, y);
            modelDepth = std::max(modelDepth, z);
        }
        else if (line.substr(0, 1) == "f")
        {
            std::vector<int> vertexIndices;
            int u, v, w;
            std::istringstream vtns(line.substr(2));
            vtns >> u;
            vtns >> v;
            vtns >> w;
            vertexIndices.push_back(u - 1);
            vertexIndices.push_back(v - 1);
            vertexIndices.push_back(w - 1);
            faces.push_back(vertexIndices);
        }
    }
    file.close();
    // 找到模型最大的尺寸維度
    maxDimension = std::max(modelWidth, std::max(modelHeight, modelDepth));
}
void ObjLoader::Get_Faces_And_Vertex() {
    glBegin(drawMode);
    for (size_t i = 0; i < faces.size(); ++i)
    {
        for (size_t j = 0; j < faces[i].size(); ++j)
        {
          int vertexIndex = faces[i][j];
            // 生成隨機顏色，範圍在0到1之間
          if (!RandomColor) {
                glColor3f(1, 1, 1);
          } else {
                float r = static_cast<float>(rand()) / RAND_MAX;
                float g = static_cast<float>(rand()) / RAND_MAX;
                float b = static_cast<float>(rand()) / RAND_MAX;
                glColor3f(r, g, b);
          }
            glVertex3fv(vertices[vertexIndex].data());
        }
        if (drawMode == GL_LINES) {
            int firstVertexIndex = faces[i][0];
            glVertex3fv(vertices[firstVertexIndex].data());
        }
    }
    glEnd();
}
void ObjLoader::Axis(float length){
    // X
   glBegin(GL_LINES);
   glColor3f(1, 0, 0);    // 設置線條顏色為紅色
   glVertex3f(-length, 0, 0); // 起點
   glVertex3f(length, 0, 0);  // 終點
   glEnd();

   // Y
   glBegin(GL_LINES);
   glColor3f(0, 1, 0);    // 設置線條顏色為綠色
   glVertex3f(0, -length, 0); // 起點
   glVertex3f(0, length, 0);  // 終點
   glEnd();

   // Z
   glBegin(GL_LINES);
   glColor3f(0, 0, 1);    // 設置線條顏色為藍色
   glVertex3f(0, 0, -length); // 起點
   glVertex3f(0, 0, length);  // 終點
   glEnd();
}
void ObjLoader::Draw(){
    if (ClickState == 1 || ClickState == 2) {
        // 如果 ClickState 為 1 或 2，則繪製直線
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // 白色直線
        glVertex2f(mouseX1, mouseY1);
        glVertex2f(mouseX2, mouseY2);
        glEnd();
    }
    float dx = mouseX1 - mouseX2;
    float dy = mouseY1 - mouseY2;
    // 計算縮放因子
    float scaleFactor = 1.0f;
    if (maxDimension > 0.0f)
    {
        scaleFactor = 0.8f / maxDimension;
    }

    // 設置當前縮放因子
    glScalef(scaleFactor, scaleFactor, scaleFactor);


    Axis(300);


    
    glTranslatef(Translate_deltaX, Translate_deltaY,Translate_deltaZ); // 定義移動
    glScalef(Scale_deltaX, Scale_deltaY, Scale_deltaZ);
    glRotatef(Rotate_deltaY, 0, 1, 0);
    glRotatef(Rotate_deltaX, 1, 0, 0);
    glRotatef(Rotate_deltaZ, 0, 0, 1);
        // Rotate the line with the rotation axis
    glRotatef(Customize_Rotate_delta, dx, dy, 0);


    Get_Faces_And_Vertex();
}

ObjLoader objLoader; // 定義全局的 ObjLoader 物件




void KeyboardFunc(unsigned char key, int x, int y) {
switch (key)
   {
   case 'a':
        objLoader.Translate_deltaX -= 0.1f; // 向左移動
      break;
   case 'd':                    
        objLoader.Translate_deltaX += 0.1f; // 向右移動
      break;
   case 's':
        objLoader.Translate_deltaY -= 0.1f; // 向下移動
      break;
   case 'w':
        objLoader.Translate_deltaY += 0.1f; // 向上移動
      break;
   case 'q':
        objLoader.Translate_deltaZ -= 1; // 向後移動
      break;
   case 'e':
        objLoader.Translate_deltaZ += 1; // 向前移動
      break;
   case 'h':
        objLoader.Scale_deltaX -= 0.1f; // X軸變大
      break;
   case 'f':                    
        objLoader.Scale_deltaX += 0.1f; // X軸變小
      break;
   case 't':
        objLoader.Scale_deltaY -= 0.1f; // Y軸變大
      break;
   case 'g':
        objLoader.Scale_deltaY += 0.1f; // Y軸變小
      break;
   case 'y':
        objLoader.Scale_deltaZ -= 1; // Z軸變大
      break;
   case 'r':
        objLoader.Scale_deltaZ += 1; // Z軸變小
      break;

   case 'j':               //
        objLoader.Rotate_deltaY -= 5; // -YRotate
      break;
   case 'l':               //
        objLoader.Rotate_deltaY += 5; // YRotate
      break;
   case 'k':               //
        objLoader.Rotate_deltaX -= 5; // -XRotate
      break;
   case 'i':               //
        objLoader.Rotate_deltaX += 5; // XRotate
      break;
   case 'u':               //
        objLoader.Rotate_deltaZ -= 5; // -ZRotate
      break;
   case 'o':               //
        objLoader.Rotate_deltaZ += 5; // ZRotate
        break;
   case ' ':               //
        objLoader.Translate_deltaX = 0.0f;
        objLoader.Translate_deltaY = 0.0f;
        objLoader.Translate_deltaZ = 0.0f;
        objLoader.Rotate_deltaX = 0.0f;
        objLoader.Rotate_deltaY = 0.0f;
        objLoader.Rotate_deltaZ = 0.0f;
        objLoader.Scale_deltaX = 1;
        objLoader.Scale_deltaY = 1;
        objLoader.Scale_deltaZ = 1;
        break;
    case '2':
        objLoader.Customize_Rotate_delta += 5;
        break;
    case '1':
        objLoader.Customize_Rotate_delta -= 5;
        break;
    case '6':
        objLoader.Cam_Rotate_deltaX += 0.1;
        break;
    case '4':
        objLoader.Cam_Rotate_deltaX -= 0.1;
        break;
    case '8':
        objLoader.Cam_Rotate_deltaY += 0.1;
        break;
    case '5':
        objLoader.Cam_Rotate_deltaY -= 0.1;
        break;
    case '9':
        objLoader.Cam_Rotate_deltaZ += 0.1;
        break;
    case '7':
        objLoader.Cam_Rotate_deltaZ -= 0.1;
        break;  
   }
   glutPostRedisplay(); // 標記當前窗口需要被重新繪製
};
void MouseFunc(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (objLoader.ClickState == 0) {
            // 將屏幕坐標轉換為OpenGL視口坐標，記錄第一個點
            objLoader.mouseX1 = 2.0f * x / glutGet(GLUT_WINDOW_WIDTH) - 1.0f;
            objLoader.mouseY1 = 1.0f - 2.0f * y / glutGet(GLUT_WINDOW_HEIGHT);
            objLoader.ClickState ++;
        } else if(objLoader.ClickState == 1){
            // 將屏幕坐標轉換為OpenGL視口坐標，記錄第二個點並繪製直線
            objLoader.mouseX2 = 2.0f * x / glutGet(GLUT_WINDOW_WIDTH) - 1.0f;
            objLoader.mouseY2 = 1.0f - 2.0f * y / glutGet(GLUT_WINDOW_HEIGHT);
            glutPostRedisplay(); // 通知窗口需要重新繪製
            objLoader.ClickState ++; // 恢復為第一次點擊的狀態
            
        }
  }
   if (objLoader.ClickState >= 2) {
     objLoader.ClickState = 0;
     
    }
}
// 視窗初始化
void init_Window(int w, int h){
    glClearColor(0, 0, 0, 1.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -10., 50.);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST); // 啟用深度測試
}

// 渲染函式
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    glRotatef(objLoader.Cam_Rotate_deltaX, 1.0f, 0.0f, 0.0f);
    glRotatef(objLoader.Cam_Rotate_deltaY, 0.0f, 1.0f, 0.0f);
    glRotatef(objLoader.Cam_Rotate_deltaZ, 0.0f, 0.0f, 1.0f);
    gluLookAt(0.0, 0.0, 10.0,  // 相機位置
              0.0, 0.0, 0.0,   // 目標位置
              0.0, 1.0, 0.0);  // 上方向向量

    objLoader.Draw(); // 將縮放因子傳遞給 Draw 函式
    
    
    
    
    glutSwapBuffers();
}

// 菜單功能
void FileMenuFunction(int options){
    if (options < menuItems.size())
    {
        objLoader.LoadObj(menuItems[options].filename);
        glutPostRedisplay(); // 通知 GLUT 主事件迴圈需要重新繪製畫面
    }
}

void StyleMenuFunction(int options){
    switch (options)
    {
    case 1:
        glPointSize(3);
        drawMode = GL_POINTS;
        break;
    case 2:
        drawMode = GL_LINES;
        break;
    case 3:
        drawMode = GL_TRIANGLES;
        break;
    }
    glutPostRedisplay(); // 重新繪製畫面
}

void ColorMenuFunction(int options){
    switch (options)
    {
    case 1:
      
        objLoader.RandomColor=false;
        break;
    case 2:
      
        objLoader.RandomColor=true;
        break;
    }
    glutPostRedisplay(); // 重新繪製畫面
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OBJ Model");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(init_Window);
    glutKeyboardFunc(KeyboardFunc);
    glutMouseFunc(MouseFunc); // 註冊滑鼠回調函式

    // 添加菜單項目
    fs::path objFolderPath = "../OBJ_File";
    for (const auto &entry : fs::directory_iterator(objFolderPath))
    {
        if (entry.path().extension() == ".obj")
        {
            std::string filename = entry.path().string();
            std::string label = entry.path().stem().string(); // 使用文件名作為菜單標籤，去掉擴展名
            menuItems.push_back({label, filename});
        }
    }

    // 創建菜單
    int mainMenu = glutCreateMenu(FileMenuFunction);
    for (size_t i = 0; i < menuItems.size(); ++i)
    {
        glutAddMenuEntry(menuItems[i].label.c_str(), i);
    }
    int color = glutCreateMenu(ColorMenuFunction);
    glutAddMenuEntry("Single Color", 1);
    glutAddMenuEntry("Random Color", 2);
    int style = glutCreateMenu(StyleMenuFunction);
    glutAddMenuEntry("Point", 1);
    glutAddMenuEntry("Line", 2);
    glutAddMenuEntry("Face", 3);
    // 創建 File 菜單
    int fileMenu = glutCreateMenu(FileMenuFunction);
    glutSetMenu(fileMenu);
    glutAddSubMenu("OBJ_File", mainMenu);
    glutAddSubMenu("Style", style);
    glutAddSubMenu("Color", color);
    // 指定右鍵點擊觸發
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
