#include<glut.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include"functions.h"
extern char* instr_S1;
char *Dialogs3[10] = { "Thank you", "You fixed it.","There is one more problem.","I can't fly high.", "Can you help me find a way between these trees" };
int Dcount3 = 5, D3 = 0;
float trans3 = 0;
float flip3 = 0;
void drawElipseLine(float xc, float yc, float x_len, float y_len);
void drawElipse_Menu(float xc, float yc, float x_len, float y_len);
void curvePoints(float t, float x1, float y1, float x2, float y2, float x3, float y3);
void tree(float x, float y);
void keysp_Story3(int k, int x, int y)
{
	D3++;
	if (D3 >= Dcount3)
	{
		init_Maze();
		glutDisplayFunc(DisplayMaze);
		glutPostRedisplay();
		/*init_Story2();
		glutDisplayFunc(displayStory2);
		glutPostRedisplay();*/
	}
	glutPostRedisplay();
}
void idle_story3()
{
		trans3 += 1;
	if (trans3 > 600)
		trans3 = 0;
	flip3 += 0.01;
	if (flip3 > 2)
		flip3 = 0;
	glutPostRedisplay();
}
void init_Story3()
{
	D3 = 0;
	glutSpecialFunc(keysp_Story3);
	glutIdleFunc(idle_story3);
}
void displayStory3()
{
	glClearColor(0, 1, 0, 0);
	//	int n1 = 0, i;
	//int a = strlen(headding);
	glPushMatrix();
	glTranslatef(400, 400, 0);
	glTranslatef(trans3, flip3 * 100, 0);
	glScalef(0.5, 0.5, 1);
	glColor3f(1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-150, -330);
	glVertex2f(-250, -360);
	glVertex2f(-325, -380);
	glVertex2f(-325, -400);
	glVertex2f(-230, -380);
	glVertex2f(-230, -450);
	glVertex2f(-210, -450);
	glVertex2f(-230, -380);
	glVertex2f(-120, -350);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(150, -330);
	glVertex2f(250, -360);
	glVertex2f(325, -380);
	glVertex2f(325, -400);
	glVertex2f(230, -380);
	glVertex2f(230, -450);
	glVertex2f(210, -450);
	glVertex2f(230, -380);
	glVertex2f(120, -350);
	glEnd();
	glColor3f(0, 1, 1);
	if (flip3 < 1)
	{
		glPushMatrix();
		glTranslatef(250, -25, 0);
		glRotatef(70, 0, 0, 1);
		drawElipse_Menu(250, -25, 100, 250);
		glPopMatrix();
	}
	else
		drawElipse_Menu(250, -25, 100, 250);
	if (flip3 < 1)
	{
		glPushMatrix();
		glTranslatef(-250, -25, 0);
		glRotatef(-70, 0, 0, 1);
		drawElipse_Menu(-250, -25, 100, 250);
		glPopMatrix();
	}
	else
		drawElipse_Menu(-250, -25, 100, 250);
	glColor3f(0, 0, 0);
	if (flip3 < 1)
	{
		glPushMatrix();
		glTranslatef(250, -25, 0);
		glRotatef(70, 0, 0, 1);
		drawElipseLine(250, -25, 100, 250);
		glPopMatrix();
	}
	else
		drawElipseLine(250, -25, 100, 250);
	if (flip3 < 1)
	{
		glPushMatrix();
		glTranslatef(-250, -25, 0);
		glRotatef(-70, 0, 0, 1);
		drawElipseLine(-250, -25, 100, 250);
		glPopMatrix();
	}
	else
		drawElipseLine(-250, -25, 100, 250);
	glColor3f(0, 1, 1);
	drawElipse_Menu(0, 0, 300, 400);
	glColor3f(0, 0, 0);
	drawElipseLine(0, 0, 300, 400);
	glColor3f(1, 1, 1);
	drawElipse_Menu(-180, 250, 130, 160);
	drawElipse_Menu(180, 250, 130, 160);
	glColor3f(0, 0, 0);
	drawElipseLine(-180, 250, 130, 160);
	drawElipseLine(180, 250, 130, 160);
	glColor3f(0, 0, 0);
	drawElipse_Menu(-180, 250, 60, 90);
	drawElipse_Menu(180, 250, 60, 90);;
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-95, -25);
	glVertex2f(95, -25);
	//curvePoints(65, 75, 10);
	glVertex2f(0, -150);
	glEnd();
	glPopMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-100, 1000);
	glVertex2f(1300, 1000);
	glVertex2f(1200, 900);
	glVertex2f(0, 900);
	glEnd();
	glColor3f(0, 0, 1);
	glRasterPos2f(0, 920);
	for (int i = 0; Dialogs3[D3][i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, Dialogs3[D3][i]);
	glPushMatrix();
	glTranslatef(375, 125, 0);
	glTranslatef(trans3, flip3 * 100, 0);
	glScalef(0.2, 0.2, 1);
	//glTranslatef(trans, flip * 100, 0);
	glColor3f(0.5, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(-50, 950);
	glVertex2f(-50, -45);
	glVertex2f(-45, -50);
	glVertex2f(950, -50);
	glVertex2f(950, 950);
	glEnd();
	glColor3f(0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 900);
	glVertex2f(900, 900);
	glVertex2f(900, 0);
	glEnd();
	glColor3f(0, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex2f(0, 600);
	glVertex2f(0, 900);
	glVertex2f(900, 900);
	glVertex2f(900, 600);
	glEnd();
	glColor3f(1, 1, 0);
	drawElipse_Menu(300, 800, 100, 100);
	glColor3f(0.1, 1, 0.1);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++)
	{
		float t = i / 300.0;
		curvePoints(t, 0, 600, 150, 1100, 350, 600);
	}
	glEnd();
	glColor3f(0.1, 1, 0.1);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++)
	{
		float t = i / 300.0;
		curvePoints(t, 300, 600, 450, 1100, 650, 600);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++)
	{
		float t = i / 300.0;
		curvePoints(t, 600, 600, 750, 1100, 900, 600);
	}
	glEnd();
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 200);
	glVertex2f(900, 150);
	glVertex2f(900, 350);
	glVertex2f(0, 400);
	glEnd();

	tree(0, 0);
	tree(300, 0);
	tree(600, 0);
	tree(0, -400);
	tree(300, -400);
	tree(600, -400);
	glPopMatrix();
	glColor3f(0, 0, 1);
	glRasterPos2f(0, -80);
	for (int i = 0; instr_S1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, instr_S1[i]);
	glFlush();
}