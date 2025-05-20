#include ".\\GL\\freeglut.h"
#include <GL/gl.h>
#include <cmath>
#include <vector>

//void
void ChangeSize(int w, int h);
void RenderScene(void);
void MenuFunction(int choice);
void MouseClick(int button, int state, int x, int y);
void DrawGrid(int dimensions);
void DrawSquare();
void DrawOriginal(float scale);
bool Click_Out_Of_Range();
void DrawLine();
void HighlightLine(int x1, int y1, int x2, int y2);

//Variables
float Dimensions = 10;      // How many grids in each Quadrant.
float WholeGridScale = 15;  // Total scale of the whole grid in widows.
float EachGridLength = 0;   // Each length of the small grid.
                            // (WholeGridScale/Dimensions)
float MouseClickPos_X1 = 0;
float MouseClickPos_Y1 = 0;
float MouseClickPos_X2 = 0;
float MouseClickPos_Y2 =0;
int ClickPosInGrid_X1 = 0;    // Save the position of the mouse click.
int ClickPosInGrid_Y1 = 0;
int ClickPosInGrid_X2 = 0;    // Save the position of the mouse click.
int ClickPosInGrid_Y2 = 0;
int ClickState = 0;

std::vector<std::vector<bool>> grid(WholeGridScale * 2 + 1,std::vector<bool>(WholeGridScale * 2 + 1,false));
std::vector<std::vector<bool>> IsColored(WholeGridScale * 2 + 1,std::vector<bool>(WholeGridScale * 2 + 1, false));




bool Click_Out_Of_Range() {
  return !(ClickPosInGrid_X1 <= Dimensions && ClickPosInGrid_Y1 <= Dimensions &&
      ClickPosInGrid_X1 > -Dimensions &&
      ClickPosInGrid_Y1 > -Dimensions);
}

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
    glutAddMenuEntry("-10 ~ 10", 1);
    glutAddMenuEntry("-15 ~ 15", 2);
    glutAddMenuEntry("-20 ~ 20", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}

void ChangeSize(int w, int h) {
    printf("Window Size = %d X %d\n", w, h);
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
            Dimensions = 10;
            break;
        case 2:
            Dimensions = 15;
            break;
        case 3:
            Dimensions = 20;
            break;
    }
    grid.clear();
    grid.resize(WholeGridScale * 2 + 1, std::vector<bool>(WholeGridScale * 2 + 1, false));
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

// Draw the color of the grid that mouse clicking.
void DrawSquare() {
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0); 
    for (int i = -WholeGridScale; i < WholeGridScale; i++) {
      for (int j = -WholeGridScale; j < WholeGridScale; j++) {
          if (grid[i + WholeGridScale][j + WholeGridScale] && !IsColored[i + WholeGridScale][j + WholeGridScale]) { // 如果网格被标记
            float x1 = i * EachGridLength;
            float x2 = (i + 1) * EachGridLength;
            float y1 = j * EachGridLength;
            float y2 = (j + 1) * EachGridLength;
            
            if (i == ClickPosInGrid_X1 && j == ClickPosInGrid_Y1) {
              glColor3f(1, 0, 0); 
            }
            else if (i == ClickPosInGrid_X2 && j == ClickPosInGrid_Y2) {
              glColor3f(1, 0, 0); 
            }
            else if ((ClickPosInGrid_X2 - ClickPosInGrid_X1) * (j - ClickPosInGrid_Y1) > (ClickPosInGrid_Y2 - ClickPosInGrid_Y1) * (i - ClickPosInGrid_X1)) {
               glColor3f(0, 0, 1); 
            }
            else {
              glColor3f(0, 1, 0); 
            }
            IsColored[i + WholeGridScale][j + WholeGridScale] = true;  
            glVertex3f(x1, y1, 0); 
            glVertex3f(x1, y2, 0); 
            glVertex3f(x2, y2, 0); 
            glVertex3f(x2, y1, 0); 
          }
        }
            
      }
    glEnd();
}


void DrawLine() {
    if (ClickState == 1 || ClickState == 2) {
      // 如果 ClickState 為 1 或 2，則繪製直線
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // 白色直線
        glVertex2f(MouseClickPos_X1, MouseClickPos_Y1);
        glVertex2f(MouseClickPos_X2, MouseClickPos_Y2);
        glEnd();
    }
}

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

    //DrawLine();
    DrawSquare();
    DrawOriginal(8);

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
            if (ClickState == 0) {
                ClickPosInGrid_X1 = gridX;
                ClickPosInGrid_Y1 = gridY;
                MouseClickPos_X1 = openglX;
                MouseClickPos_Y1 = openglY;
                ClickState++;
            }
            else if (ClickState == 1) {
                ClickPosInGrid_X2 = gridX;
                ClickPosInGrid_Y2 = gridY;
                MouseClickPos_X2 = openglX;
                MouseClickPos_Y2 = openglY;
                ClickState++;
            }
        }

        // 只在鼠标左键松开后调用 HighlightLine
        if (state == GLUT_UP && ClickState >= 2) {
            ClickState = 0; // Reset state after completing the operation
        }
            HighlightLine(ClickPosInGrid_X1, ClickPosInGrid_Y1, ClickPosInGrid_X2, ClickPosInGrid_Y2);

        glutPostRedisplay(); // Request redraw
    }
}

void HighlightLine(int x1, int y1, int x2, int y2) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;

    int err = dx - dy;

    // Traverse the line and mark the path
    while (x1 != x2 || y1 != y2) { 
        grid[x1 + WholeGridScale][y1 + WholeGridScale] = true; // Ensure the grid is marked
        IsColored[x1 + WholeGridScale][y1 + WholeGridScale] = false; // Ensure the line path is not colored

        int e2 = 2 * err;

        if (e2 > -dy) { 
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) { 
            err += dx;
            y1 += sy;
        }
    }

    grid[x2 + WholeGridScale][y2 + WholeGridScale] = true; 
    IsColored[x2 + WholeGridScale][y2 + WholeGridScale] = false; 

    glutPostRedisplay(); 
}