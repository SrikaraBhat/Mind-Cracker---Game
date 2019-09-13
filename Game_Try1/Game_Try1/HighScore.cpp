#include<glut.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include"functions.h"
char* instr_HS = "Press Right key to go back";
char *Name_HS = "Mind Cracker";
char *HS_HS = "HIGH SCORE";
int hs1=0, hs2=0, hs3=0;
void drawElipseLine(float xc, float yc, float x_len, float y_len);
void drawElipse_Menu(float xc, float yc, float x_len, float y_len);
void keysp_HS(int k, int x, int y)
{
	if (k == GLUT_KEY_LEFT)
	{
		init_Menu();
		glutDisplayFunc(displayMenu);
		glutPostRedisplay();
	}
	else if (k == GLUT_KEY_DOWN)
	{
		
	}
	glutPostRedisplay();
}
void key_HS(unsigned char k, int x, int y)
{
	if ((int)k == 8|| (int)k == 27)
	{
		init_Menu();
		glutDisplayFunc(displayMenu);
		glutPostRedisplay();
	}
}
void Write_HS()
{
	FILE *HS_FILE;
	fopen_s(&HS_FILE, "HS.txt", "w");
	fprintf_s(HS_FILE, "%d\n%d\n%d", hs1, hs2, hs3);
	fclose(HS_FILE);
}
void Load_HS()
{
	FILE *HS_FILE;
	fopen_s(&HS_FILE,"HS.txt", "r");
	if (HS_FILE!=NULL)
	{
		fscanf_s(HS_FILE, "%d%d%d", &hs1, &hs2, &hs3);
	}
	else
	{
		fopen_s(&HS_FILE,"HS.txt", "w");
		fprintf_s(HS_FILE, "%d\n%d\n%d", hs1, hs2, hs3);
	}
	if(HS_FILE!=NULL)
		fclose(HS_FILE);
}
void init_HS()
{
	glutSpecialFunc(keysp_HS);
	glutKeyboardFunc(key_HS);
}
void displayHS()
{
	glClearColor(0, 1, 0, 0);
	//int a = strlen(headding);
	glPushMatrix();
	glTranslatef(300, 400, 0);
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
	glVertex2f(700, 700);
	glVertex2f(700, 300);
	glVertex2f(1200, 300);
	glVertex2f(1200, 700);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(250, 1000);
	glVertex2f(350, 900);
	glVertex2f(850, 900);
	glVertex2f(950, 1000);
	glEnd();
	glColor3f(0, 0, 1);
	glRasterPos2f(370, 920);
	for (int i = 0; Name_HS[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Name_HS[i]);
	glColor3f(0, 0, 1);
	glRasterPos2f(775, 575);
	int steps = hs1;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 1000) + 48);
	steps %= 1000;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 100) + 48);
	steps %= 100;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps/10) + 48);
	steps %= 10;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps ) + 48);
	glRasterPos2f(775, 475);
	steps = hs2;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 1000) + 48);
	steps %= 1000;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 100) + 48);
	steps %= 100;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 10) + 48);
	steps %= 10;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, steps + 48);
	glRasterPos2f(775, 375);
	steps = hs3;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 1000) + 48);
	steps %= 1000;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 100) + 48);
	steps %= 100;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps/10) + 48);
	steps %= 10;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps) + 48);
	glRasterPos2f(0, -80);
	for (int i = 0; instr_HS[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, instr_HS[i]);
	glFlush();
}