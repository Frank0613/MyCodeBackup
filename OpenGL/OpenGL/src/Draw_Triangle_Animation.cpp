#include ".\\GL\\freeglut.h"
#include <GL/gl.h>
#include <cstdio>
#include <vector>
#include <iostream> 
using namespace std;

//void
void ChangeSize(int w, int h);
void RenderScene(void);
void MenuFunction(int choice);
void MouseClick(int button, int state, int x, int y);
void DrawGrid(int dimensions);
void DrawSquare();
void DrawOriginal(float scale);
void MidPointFunction(int x1, int y1, int x2, int y2);
void FindBoundingBox(float &minX, float &minY, float &maxX, float &maxY);
bool IsPointInTriangle(float x, float y);
void FillTriangleArea();
void DrawClickedLine();
void AnimateTriangleFill(int value);

// Variables
float Dimensions = 10; // How many grids in each Quadrant.
float MaxDimensions = 15; // Equal to the MaxDimensions that being set.
float WholeGridScale = 15;  // Total scale of the whole grid in widows.
float EachGridLength =0; // Each length of the small grid. (WholeGridScale/Dimensions)
// For Draw Lines
float MouseClickPos_X1 = 0;
float MouseClickPos_Y1 = 0;
float MouseClickPos_X2 = 0;
float MouseClickPos_Y2 = 0;
float MouseClickPos_X3 = 0;
float MouseClickPos_Y3 = 0;
// For Count points on grid
int ClickPosInGrid_X1 = 0;    
int ClickPosInGrid_Y1 = 0;
int ClickPosInGrid_X2 = 0;
int ClickPosInGrid_Y2 = 0;
int ClickPosInGrid_X3 = 0;
int ClickPosInGrid_Y3 = 0;
// mouth click state
int ClickState = 0;
// Animation
int animationStep = 0; // Current animation step
bool animationInProgress = false; // Is the animation playing?
const int animationDelay = 50; // animation delay time
vector<pair<int, int>> animationOrder; // point's drawing order which inside the triangle

// A 2D vector(size = (WholeGridScale * 2 + 1)**2), every unit included in a bool(IsColored?) and an array(Current Color)
vector<vector<pair<bool, array<float, 3>>>> grid(MaxDimensions * 2 + 1,vector<pair<bool, array<float, 3>>>(MaxDimensions * 2 + 1, {false,{0,0,0}}));


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(600, 80);
    glutCreateWindow("2D Grid");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutMouseFunc(MouseClick);
    
    // Add the menu with choices
    glutCreateMenu(MenuFunction);
    glutAddMenuEntry("-5 ~ 5", 1);
    glutAddMenuEntry("-10 ~ 10", 2);
    glutAddMenuEntry("-15 ~ 15", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
void ChangeSize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MenuFunction(int choice) {
    switch (choice) {
        case 1:
            Dimensions = 5;
            break;
        case 2:
            Dimensions = 10;
            break;
        case 3:
            Dimensions = 15;
            break;
    }
    grid.clear(); // clear all the elements in the grid vector
    grid.resize(MaxDimensions * 2 + 1,vector<pair<bool, array<float, 3>>>(MaxDimensions * 2 + 1, {false,{0,0,0}}));// resize the grid vector to fit the new dimensions
    glutPostRedisplay();
}

// Draw the empty gird
void DrawGrid(float dimensions) {
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (float i = -WholeGridScale; i <= WholeGridScale; i += EachGridLength) {
        // Draw the horizontal grid
        glVertex3f(-WholeGridScale, i, 0);
        glVertex3f(WholeGridScale, i, 0);

        // Draw the vertical grid
        glVertex3f(i, -WholeGridScale, 0);
        glVertex3f(i, WholeGridScale, 0);
    }
    glEnd();
}
void AnimateTriangleFill(int value) {
    // If animation is playing, and the current step < point's ordering array size
    if (animationInProgress && animationStep < animationOrder.size()) {
        // Get the index which wants to draw
        int i = animationOrder[animationStep].first;
        int j = animationOrder[animationStep].second;
        // Draw Function
        grid[i + WholeGridScale][j + WholeGridScale].first = true;
        grid[i + WholeGridScale][j + WholeGridScale].second = {1.0f, 1.0f, 0.0f};
        // Add the step to do the next point    
        animationStep++;
        glutPostRedisplay();
        glutTimerFunc(animationDelay, AnimateTriangleFill, 0);
    } else {
        animationInProgress = false;
    }
}
//Find the Bounding Box framing the triangle which been clicked
void FindBoundingBox(float &minX, float &minY, float &maxX, float &maxY) {
  minX = min(min(ClickPosInGrid_X1, ClickPosInGrid_X2), ClickPosInGrid_X3)-5;
  maxX = max(max(ClickPosInGrid_X1, ClickPosInGrid_X2),ClickPosInGrid_X3)+5;
  minY = min(min(ClickPosInGrid_Y1, ClickPosInGrid_Y2), ClickPosInGrid_Y3)-5;
  maxY = max(max(ClickPosInGrid_Y1, ClickPosInGrid_Y2),ClickPosInGrid_Y3)+5;
}

bool IsPointInTriangle(float x, float y) {
    // Get three points which been clicked.
    float x1 = ClickPosInGrid_X1 * EachGridLength;
    float y1 = ClickPosInGrid_Y1 * EachGridLength;
    float x2 = ClickPosInGrid_X2 * EachGridLength;
    float y2 = ClickPosInGrid_Y2 * EachGridLength;
    float x3 = ClickPosInGrid_X3 * EachGridLength;
    float y3 = ClickPosInGrid_Y3 * EachGridLength;

    // Calculate the directed area from a point to three vertices
    float d1 = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    float d2 = x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2);
    float d3 = x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y);
    float d4 = x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2); // Reverse of AB

    bool has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0) || (d4 <= 0); // All directed area is negative
    bool has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0) || (d4 >= 0); // All directed area is position

    return !(has_neg && has_pos); // If there exist neg and pos at the same time, return false
}
void FillTriangleArea() {
    float minX, minY, maxX, maxY;
    FindBoundingBox(minX, minY, maxX, maxY);
    animationOrder.clear();//Clear the ordering array
    for (int j = minY / EachGridLength; j <= maxY / EachGridLength; j++) {
        for (int i = minX / EachGridLength; i <= maxX / EachGridLength; i++) {
            float x = i * EachGridLength;
            float y = j * EachGridLength;
            if (IsPointInTriangle(x, y)) {
                animationOrder.emplace_back(i, j); // insert the point in the end of the ordering array
            }
        }
    }

    // Start animation
    animationStep = 0;
    animationInProgress = true;
    glutTimerFunc(animationDelay, AnimateTriangleFill, 0);
}
// Draw the color of the grid that mouse clicking.
void DrawSquare() {
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0); 
    for (int i = -WholeGridScale; i < WholeGridScale; i++) {
      for (int j = -WholeGridScale; j < WholeGridScale; j++) {
          if (grid[i + WholeGridScale][j + WholeGridScale].first ) { // If the grid.first(boolean) is true, then the grid need to be filled with the color.
            float x1 = i * EachGridLength;
            float x2 = (i + 1) * EachGridLength;
            float y1 = j * EachGridLength;
            float y2 = (j + 1) * EachGridLength;
            
            glColor3fv(grid[i + WholeGridScale][j + WholeGridScale].second.data()); //Get the grid.second(color) to fill with the color. 
            glVertex3f(x1, y1, 0); 
            glVertex3f(x1, y2, 0); 
            glVertex3f(x2, y2, 0); 
            glVertex3f(x2, y1, 0); 
          }
        }
    }
    
    glEnd();
}
void DrawClickedLine() {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // 白色直線
        glVertex2f(MouseClickPos_X1, MouseClickPos_Y1);
        glVertex2f(MouseClickPos_X2, MouseClickPos_Y2);
        glVertex2f(MouseClickPos_X3, MouseClickPos_Y3);
        glEnd();
    
}
// Draw the (0,0) point.
void DrawOriginal(float scale) {
    glPointSize(scale);
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0); // Draw a red point at the center
    glVertex3f(0,0,0);
    glEnd();
}

void RenderScene() {
    glClearColor(0, 0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10.0f, 0, 0, 0, 0, 1, 0);

    EachGridLength = WholeGridScale / Dimensions;
    DrawGrid(Dimensions);
    DrawOriginal(8);
    DrawSquare();
    glutSwapBuffers();
}

void MouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        int windowWidth = 800;
        int windowHeight = 800;

        float normalizedX = (2.0f * float(x) / windowWidth) - 1.0f;
        float normalizedY = 1.0f - 2.0f * float(y) / windowHeight;

        float openglX = normalizedX * 20.0f;
        float openglY = normalizedY * 20.0f;

        int gridX = std::floor(openglX / EachGridLength);
        int gridY = std::floor(openglY / EachGridLength);

        if (state == GLUT_DOWN) {
            //First click
            if (ClickState == 0) {
                grid.clear(); // clear all the elements in the grid vector
                grid.resize(MaxDimensions * 2 + 1,vector<pair<bool, array<float, 3>>>(MaxDimensions * 2 + 1, {false,{0,0,0}}));
                ClickPosInGrid_X1 = gridX;
                ClickPosInGrid_Y1 = gridY;
                MouseClickPos_X1 = openglX;
                MouseClickPos_Y1 = openglY;
                ClickState++;
            }
            //Second click
            else if (ClickState == 1) {
                ClickPosInGrid_X2 = gridX;
                ClickPosInGrid_Y2 = gridY;
                MouseClickPos_X2 = openglX;
                MouseClickPos_Y2 = openglY;
                ClickState ++; // Reset state after completing the operation
            }
            //Second click
            else if (ClickState == 2) {
                ClickPosInGrid_X3 = gridX;
                ClickPosInGrid_Y3 = gridY;
                MouseClickPos_X3 = openglX;
                MouseClickPos_Y3 = openglY;
                MidPointFunction(ClickPosInGrid_X1, ClickPosInGrid_Y1, ClickPosInGrid_X2, ClickPosInGrid_Y2);
                MidPointFunction(ClickPosInGrid_X2, ClickPosInGrid_Y2, ClickPosInGrid_X3, ClickPosInGrid_Y3);
                MidPointFunction(ClickPosInGrid_X3, ClickPosInGrid_Y3,ClickPosInGrid_X1, ClickPosInGrid_Y1);
                FillTriangleArea();
                ClickState = 0; // Reset state after completing the operation
            }
            
        }
        glutPostRedisplay(); // Request redraw
    }
}

void MidPointFunction(int x1, int y1, int x2, int y2) {
    //Count the delta of two points
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    //Count the direction of the lines
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    //計算誤差，當err的值大於某個閾值時,就需要調整方向
    int err = dx - dy;
    // First point has to be red.
    grid[x1 + WholeGridScale][y1 + WholeGridScale].second  = {1,0,0};
    // Traverse the line and mark the path
    while (x1 != x2 || y1 != y2) {
        grid[x1 + WholeGridScale][y1 + WholeGridScale].first = true; // Ensure the grid is marked
        int e2 = 2 * err;
        if (e2 > -dy) { 
            err -= dy;
            x1 += sx;
            grid[x1 + WholeGridScale][y1 + WholeGridScale].second = {0, 1, 0};
        }
        if (e2 < dx) { 
            err += dx;
            y1 += sy;
            grid[x1 + WholeGridScale][y1 + WholeGridScale].second = {0, 0, 1};
        }
    }
    
    grid[x2 + WholeGridScale][y2 + WholeGridScale].first = true; 
    grid[x1 + WholeGridScale][y1 + WholeGridScale].second  = {1,0,0};
    glutPostRedisplay(); 
}

