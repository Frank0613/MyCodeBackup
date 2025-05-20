
#include ".\\GL\\freeglut.h"
#include <GL/gl.h>
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

//Variables
float Dimensions = 10;      // How many grids in each Quadrant.
float WholeGridScale = 15;  // Total scale of the whole grid in widows.
float EachGridLength = 0;   // Each length of the small grid. (WholeGridScale/Dimensions)
int ClickPosInGrid_X1 = 0;    // Save the position of the mouse click.
int ClickPosInGrid_Y1 = 0;

bool Click_Out_Of_Range() {
  return !(ClickPosInGrid_X1 <= Dimensions && ClickPosInGrid_Y1 <= Dimensions &&
      ClickPosInGrid_X1 > -Dimensions &&
      ClickPosInGrid_Y1 > -Dimensions);
}

int main(int argc, char **argv){
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
void ChangeSize(int w, int h){
    printf("Window Size = %d X %d\n", w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void MenuFunction(int choice){
    switch (choice)
    {
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
    
    glutPostRedisplay();
}
// Draw the empty gird
void DrawGrid(float dimensions){
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
  if (!Click_Out_Of_Range()) {
        glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
        glVertex3f(EachGridLength*ClickPosInGrid_X1, EachGridLength*ClickPosInGrid_Y1, 0);
        glVertex3f(EachGridLength*ClickPosInGrid_X1, EachGridLength*(ClickPosInGrid_Y1-1), 0);
        glVertex3f(EachGridLength*(ClickPosInGrid_X1-1), EachGridLength*(ClickPosInGrid_Y1-1), 0);
        glVertex3f(EachGridLength*(ClickPosInGrid_X1-1), EachGridLength*ClickPosInGrid_Y1, 0);
        glEnd();
    
    }
}
void DrawOriginal(float scale) {
    glPointSize(scale);
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    glVertex3f(0,0,0);
    glEnd();
  
}
void RenderScene(){
    glClearColor(0, 0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10.0f, 0, 0, 0, 0, 1, 0);

    EachGridLength = WholeGridScale / Dimensions;
    DrawGrid(Dimensions);
    DrawSquare();
    DrawOriginal(8);

    glutSwapBuffers();
}
void MouseClick(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float normalizedX = (2 * (float(x)/800) -1) * 20;
        float normalizedY = (-2 * (float(y) / 800) + 1) * 20;
        
        ClickPosInGrid_X1 = std::ceil(normalizedX * (Dimensions / WholeGridScale));
        ClickPosInGrid_Y1 = std::ceil(normalizedY * (Dimensions / WholeGridScale));

        int Print_MouseClickPos_X = ClickPosInGrid_X1;
        int Print_MouseClickPos_Y = ClickPosInGrid_Y1;

        if (Print_MouseClickPos_X <= 0) {
            Print_MouseClickPos_X-=1;
        }
        if (Print_MouseClickPos_Y <= 0) {
            Print_MouseClickPos_Y-=1;
        }
        if (!Click_Out_Of_Range()) {
            printf("GridPos_X: %d, GridPos_Y: %d\n", Print_MouseClickPos_X, Print_MouseClickPos_Y); 
        }
    }
}