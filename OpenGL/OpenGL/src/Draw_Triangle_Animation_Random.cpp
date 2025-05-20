#include ".\\GL\\freeglut.h"
#include <GL/gl.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <array>
#include <cmath>
#include <queue>

using namespace std;

void ChangeSize(int w, int h);
void RenderScene(void);
void MenuFunction(int choice);
void MouseClick(int button, int state, int x, int y);
void DrawGrid(int dimensions);
void DrawSquare();
void DrawOriginal(float scale);
void FindBoundingBox(float &minX, float &minY, float &maxX, float &maxY);
bool IsPointInPolygon(float x, float y);
void FillPolygonArea();
void AnimatePolygonFill(int value);
void MidPointFunction(int x1, int y1, int x2, int y2, float color1[3], float color2[3]);
void findEdge(const vector<array<float, 2>> &vList, int &i, int n, int &y, array<float, 2> &d, array<float, 2> &e, int &rem);
void CrowFillCell(const vector<array<float, 2>> &gridPoint);

// Variables
float Dimensions = 10;
float MaxDimensions = 15;
float WholeGridScale = 15;
float EachGridLength = 0;

// For Draw Lines
float MouseClickPos_X[5] = {0};
float MouseClickPos_Y[5] = {0};
int ClickPosInGrid_X[5] = {0};
int ClickPosInGrid_Y[5] = {0};
float ClickPosColor[5][3] = {0};
// mouse click state
int ClickState = 0;

// Animation
int animationStep = 0;
bool animationInProgress = false;
const int animationDelay = 50;
vector<pair<int, int>> animationOrder;
queue<pair<int, int>> _waitToDraw;

vector<vector<pair<bool, array<float, 3>>>> grid(MaxDimensions * 2 + 1, vector<pair<bool, array<float, 3>>>(MaxDimensions * 2 + 1, {false, {0, 0, 0}}));

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(600, 80);
    glutCreateWindow("2D Grid");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutMouseFunc(MouseClick);

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
    grid.clear();
    grid.resize(MaxDimensions * 2 + 1, vector<pair<bool, array<float, 3>>>(MaxDimensions * 2 + 1, {false, {0, 0, 0}}));
    glutPostRedisplay();
}

void DrawGrid(float dimensions) {
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (float i = -WholeGridScale; i <= WholeGridScale; i += EachGridLength) {
        glVertex3f(-WholeGridScale, i, 0);
        glVertex3f(WholeGridScale, i, 0);

        glVertex3f(i, -WholeGridScale, 0);
        glVertex3f(i, WholeGridScale, 0);
    }
    glEnd();
}

void AnimatePolygonFill(int value) {
    if (animationInProgress && !_waitToDraw.empty()) {
        int i = _waitToDraw.front().first;
        int j = _waitToDraw.front().second;
        _waitToDraw.pop();

        float distances[5];
        float weights[5];
        float sumWeights = 0.0f;
        for (int k = 0; k < 5; k++) {
            float dx = (i * EachGridLength) - (ClickPosInGrid_X[k] * EachGridLength);
            float dy = (j * EachGridLength) - (ClickPosInGrid_Y[k] * EachGridLength);
            distances[k] = sqrt(dx * dx + dy * dy);
            weights[k] = 1.0f / (distances[k] * distances[k] + 1e-6); // Avoid division by zero
            sumWeights += weights[k];
        }

        float finalColor[3] = {0.0f, 0.0f, 0.0f};
        for (int k = 0; k < 5; k++) {
            finalColor[0] += weights[k] * ClickPosColor[k][0];
            finalColor[1] += weights[k] * ClickPosColor[k][1];
            finalColor[2] += weights[k] * ClickPosColor[k][2];
        }

        finalColor[0] /= sumWeights;
        finalColor[1] /= sumWeights;
        finalColor[2] /= sumWeights;

        grid[i + WholeGridScale][j + WholeGridScale].first = true;
        grid[i + WholeGridScale][j + WholeGridScale].second = {finalColor[0], finalColor[1], finalColor[2]};

        glutPostRedisplay();
        glutTimerFunc(animationDelay, AnimatePolygonFill, 0);
    } else {
        animationInProgress = false;
    }
}


void FindBoundingBox(float &minX, float &minY, float &maxX, float &maxY) {
    minX = *min_element(ClickPosInGrid_X, ClickPosInGrid_X + 5) - 4;
    maxX = *max_element(ClickPosInGrid_X, ClickPosInGrid_X + 5) + 4;
    minY = *min_element(ClickPosInGrid_Y, ClickPosInGrid_Y + 5) - 4;
    maxY = *max_element(ClickPosInGrid_Y, ClickPosInGrid_Y + 5) + 4;
}

bool IsPointInPolygon(float x, float y) {
    int crossingNumber = 0;
    for (int i = 0; i < 5; i++) {
        float x1 = ClickPosInGrid_X[i] * EachGridLength;
        float y1 = ClickPosInGrid_Y[i] * EachGridLength;
        float x2 = ClickPosInGrid_X[(i + 1) % 5] * EachGridLength;
        float y2 = ClickPosInGrid_Y[(i + 1) % 5] * EachGridLength;

        if ((y1 <= y && y < y2) || (y2 <= y && y < y1)) {
            float vt = (y - y1) / (y2 - y1);
            if (x < x1 + vt * (x2 - x1)) {
                crossingNumber++;
            }
        }
    }
    return (crossingNumber % 2 == 1);
}

void FillPolygonArea() {
    // Convert click positions to vector of points
    vector<array<float, 2>> gridPoints(5);
    for (int i = 0; i < 5; ++i) {
        gridPoints[i] = {static_cast<float>(ClickPosInGrid_X[i]), static_cast<float>(ClickPosInGrid_Y[i])};
    }

    // Fill the polygon using Crow's algorithm
    CrowFillCell(gridPoints);

    // Start the animation
    animationStep = 0;
    animationInProgress = true;
    glutTimerFunc(animationDelay, AnimatePolygonFill, 0);
}

void DrawSquare() {
    glBegin(GL_QUADS);
    for (int i = -WholeGridScale; i < WholeGridScale; i++) {
        for (int j = -WholeGridScale; j < WholeGridScale; j++) {
            if (grid[i + WholeGridScale][j + WholeGridScale].first) {
                float x1 = i * EachGridLength;
                float x2 = (i + 1) * EachGridLength;
                float y1 = j * EachGridLength;
                float y2 = (j + 1) * EachGridLength;
                glColor3f(
                    grid[i + WholeGridScale][j + WholeGridScale].second[0],
                    grid[i + WholeGridScale][j + WholeGridScale].second[1],
                    grid[i + WholeGridScale][j + WholeGridScale].second[2]
                );
                glVertex3f(x1, y1, 0);
                glVertex3f(x1, y2, 0);
                glVertex3f(x2, y2, 0);
                glVertex3f(x2, y1, 0);
            }
        }
    }
    glEnd();
}

void DrawOriginal(float scale) {
    glPointSize(scale);
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
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
            float color[3] = {
                static_cast<float>(rand()) / RAND_MAX,
                static_cast<float>(rand()) / RAND_MAX,
                static_cast<float>(rand()) / RAND_MAX
            };

            if (ClickState == 0) {
                grid.clear(); // clear all the elements in the grid vector
                grid.resize(MaxDimensions * 2 + 1, vector<pair<bool, array<float, 3>>>(MaxDimensions * 2 + 1, {false, {0, 0, 0}}));
                ClickPosInGrid_X[ClickState] = gridX;
                ClickPosInGrid_Y[ClickState] = gridY;
                MouseClickPos_X[ClickState] = openglX;
                MouseClickPos_Y[ClickState] = openglY;
                ClickPosColor[ClickState][0] = color[0];
                ClickPosColor[ClickState][1] = color[1];
                ClickPosColor[ClickState][2] = color[2];
                ClickState++;
            } else if (ClickState >= 1 && ClickState <= 3) {
                ClickPosInGrid_X[ClickState] = gridX;
                ClickPosInGrid_Y[ClickState] = gridY;
                MouseClickPos_X[ClickState] = openglX;
                MouseClickPos_Y[ClickState] = openglY;
                ClickPosColor[ClickState][0] = color[0];
                ClickPosColor[ClickState][1] = color[1];
                ClickPosColor[ClickState][2] = color[2];
                ClickState++;
            } else if (ClickState == 4) {
                ClickPosInGrid_X[ClickState] = gridX;
                ClickPosInGrid_Y[ClickState] = gridY;
                MouseClickPos_X[ClickState] = openglX;
                MouseClickPos_Y[ClickState] = openglY;
                ClickPosColor[ClickState][0] = color[0];
                ClickPosColor[ClickState][1] = color[1];
                ClickPosColor[ClickState][2] = color[2];
                MidPointFunction(ClickPosInGrid_X[0], ClickPosInGrid_Y[0], ClickPosInGrid_X[1], ClickPosInGrid_Y[1], ClickPosColor[0], ClickPosColor[1]);
                MidPointFunction(ClickPosInGrid_X[1], ClickPosInGrid_Y[1], ClickPosInGrid_X[2], ClickPosInGrid_Y[2], ClickPosColor[1], ClickPosColor[2]);
                MidPointFunction(ClickPosInGrid_X[2], ClickPosInGrid_Y[2], ClickPosInGrid_X[3], ClickPosInGrid_Y[3], ClickPosColor[2], ClickPosColor[3]);
                MidPointFunction(ClickPosInGrid_X[3], ClickPosInGrid_Y[3], ClickPosInGrid_X[4], ClickPosInGrid_Y[4], ClickPosColor[3], ClickPosColor[4]);
                MidPointFunction(ClickPosInGrid_X[4], ClickPosInGrid_Y[4], ClickPosInGrid_X[0], ClickPosInGrid_Y[0], ClickPosColor[4], ClickPosColor[0]);
                FillPolygonArea();
                ClickState = 0;
            }
        }
        glutPostRedisplay();
    }
}

void MidPointFunction(int x1, int y1, int x2, int y2, float color1[3], float color2[3]) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    int err = dx - dy;

    int steps = std::max(dx, dy);
    float rStep = (color2[0] - color1[0]) / steps;
    float gStep = (color2[1] - color1[1]) / steps;
    float bStep = (color2[2] - color1[2]) / steps;
    
    float r = color1[0];
    float g = color1[1];
    float b = color1[2];

    while (x1 != x2 || y1 != y2) {
        grid[x1 + WholeGridScale][y1 + WholeGridScale].first = true;
        grid[x1 + WholeGridScale][y1 + WholeGridScale].second = {r, g, b};

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
        
        r += rStep;
        g += gStep;
        b += bStep;
    }

    grid[x2 + WholeGridScale][y2 + WholeGridScale].first = true;
    grid[x2 + WholeGridScale][y2 + WholeGridScale].second = {color2[0], color2[1], color2[2]};
    glutPostRedisplay();
}

void findEdge(const vector<array<float, 2>> &vList, int &i, int n, int &y, array<float, 2> &d, array<float, 2> &e, int &rem,int L_R) {
   
    i = (i + L_R) % n;
    rem--;
    
    e = vList[i];
    int prev = (i + n - L_R) % n;
    d[0] = (vList[prev][0] - e[0]) / (vList[prev][1] - e[1]);
    d[1] = vList[prev][1] - e[1];
}

void CrowFillCell(const vector<array<float, 2>> &gridPoint) {
    int li, ri;                  // left & right upper endpoint indices
    float ly, ry;                // left & right upper endpoint y values
    float lx, rx;                // 当前ScanLine的左右点X位置
    array<float, 2> dl, dr;      // current left edge and delta
    array<float, 2> l, r;        // current left and right edge
    int rem;                     // number of remaining vertices
    int y;                       // current scanline
    int n = gridPoint.size();

    int minY_index = 0;
    int minx = gridPoint[0][0];
    int miny = gridPoint[0][1];
    for (int i = 0; i < n; i++) {
        if (miny > gridPoint[i][1]) {
            miny = gridPoint[i][1];
            minx = gridPoint[i][0];
            minY_index = i;
        }
    }

    li = ri = minY_index; //最小Y的index
    ly = ry = y = round(gridPoint[minY_index][1]); // 最小Y
    lx = rx = round(gridPoint[minY_index][0]); //最小Y
    rem = n;

    auto drawSpan = [&](int y, int xl, int xr) {
        // Drawing span from (xl, y) to (xr, y)
        for (int x = xl; x <= xr; ++x) {
            if (grid[x + WholeGridScale][y + WholeGridScale].first) {
                continue;
            }
            _waitToDraw.push({x, y});
        }
    };

    // Find the initial edges
    findEdge(gridPoint, li, n, y, dl, l, rem, 1);
    findEdge(gridPoint, ri, n, y, dr, r, rem, -1);

    while (rem > 0) {
        // Draw spans while both edges span the current scanline
        // If left edge is complete, find the next left edge
        if (round(l[1]) <= y) {
            findEdge(gridPoint, li, n, y, dl, l, rem, 1);
        }

        // If right edge is complete, find the next right edge
        if (round(r[1]) <= y) {
            findEdge(gridPoint, ri, n, y, dr, r, rem, -1);
        }

        while (round(l[1]) > y && round(r[1]) > y) {
            drawSpan(y, round(lx), round(rx));
            lx += dl[0];
            rx += dr[0];
            y++;
        }
    }
}

