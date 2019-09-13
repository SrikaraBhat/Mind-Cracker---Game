#include<glut.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include"functions.h"
char* instr_S1 = "Press Right arrow to continue";
char *Dialogs1[10] = { "Hi!! I am Chukki,", "Today is a special day do you know why?","It's my friends birthday.","I am going to gift this photo to him.","I don't like to be late for party so I should leave.", "Meet you on party" };
int Dcount = 6,D=0;
void drawElipseLine(float xc, float yc, float x_len, float y_len);
void drawElipse_Menu(float xc, float yc, float x_len, float y_len);
void curvePoints(float t, float x1, float y1, float x2, float y2, float x3, float y3);
void tree(float x, float y)
{
	glColor3f(0.4, 0.2, 0.2);	//Tree 1
	glBegin(GL_POLYGON);
	glVertex2f(50+x, 410+y);
	glVertex2f(60+x, 410+y);
	glVertex2f(60+x, 470+y);
	glVertex2f(50+x, 470+y);
	glEnd();
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(20+x, 470+y);
	glVertex2f(90+x, 470+y);
	glVertex2f(55+x, 570+y);
	glEnd();
}
void keysp_Story1(int k, int x, int y)
{
	D++;
	if (D >= Dcount)
	{
		/*init_Pizzle();
		glutDisplayFunc(DisplayGame);
		glutPostRedisplay();*/
		init_Story2();
		glutDisplayFunc(displayStory2);
		glutPostRedisplay();
	}
	glutPostRedisplay();
}
void init_Story1()
{
	D = 0;
	glutSpecialFunc(keysp_Story1);
}
void displayStory1()
{
	glClearColor(0, 1, 0, 0);
	int n1 = 0, i;
	//int a = strlen(headding);
	glPushMatrix();
	glTranslatef(400, 400, 0);
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
	drawElipse_Menu(250, -25, 100, 250);
	drawElipse_Menu(-250, -25, 100, 250);
	glColor3f(0, 0, 0);
	drawElipseLine(250, -25, 100, 250);
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
	for (int i = 0; Dialogs1[D][i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, Dialogs1[D][i]);
	glPushMatrix();
	glTranslatef(800, 200,0);
	glScalef(0.33, 0.33, 1);
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