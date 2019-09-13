#include<glut.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include"functions.h"
char* instr_menu = "Press UP/Down key to navigate and Enter key to select";
char *Name = "Mind Cracker";
char *NewGame = "NEW GAME";
char *HS = "HIGH SCORE";
char *Quit = "Quit";
int option = 0;
extern int Round;
void drawElipseLine(float xc, float yc, float x_len, float y_len);
void drawElipse_Menu(float xc, float yc, float x_len, float y_len);
void keysp_Menu(int k,int x,int y)
{
	if (k == GLUT_KEY_UP)
	{
		option--;
		if (option < 0)
		{
			option = 0;
		}
		else
			PlaySound(TEXT("1.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	else if(k==GLUT_KEY_DOWN)
	{
		option++;
		if (option > 2)
		{
			option = 2;
		}
		else
			PlaySound(TEXT("1.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	glutPostRedisplay();
}
void key_Menu(unsigned char k,int x,int y)
{
	if ((int)k == 13)
	{
		if (option == 0)
		{
			init_Story1();
			glutDisplayFunc(displayStory1);
			glutPostRedisplay();
		}
		if (option == 1)
		{
			Load_HS();
			init_HS();
			glutDisplayFunc(displayHS);
			glutPostRedisplay();
		}
		if (option == 2)
		{
			exit(0);
		}
	}
}
void init_Menu()
{
	Round = 1;
	glutSpecialFunc(keysp_Menu);
	glutKeyboardFunc(key_Menu);
}
void displayMenu()
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
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(750, 550 - (option * 100), 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 100);
	glVertex2f(400, 100);
	glVertex2f(400, 0);
	glEnd();
	glPopMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(250, 1000);
	glVertex2f(350, 900);
	glVertex2f(850, 900);
	glVertex2f(950, 1000);
	glEnd();
	glColor3f(0, 0, 1);
	glRasterPos2f(370, 920);
	for (int i = 0; Name[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Name[i]);
	glColor3f(0, 0, 1);
	glRasterPos2f(775, 575);
	for (int i = 0; NewGame[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, NewGame[i]);
	glRasterPos2f(775, 475);
	for (int i = 0; HS[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, HS[i]);
	glRasterPos2f(775, 375);
	for (int i = 0; Quit[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, Quit[i]);
	glRasterPos2f(0, -80);
	for (int i = 0; instr_menu[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, instr_menu[i]);
	glFlush();
}
void drawElipse_Menu(float xc, float yc, float x_len, float y_len)
{
	float x, y;
	glBegin(GL_POLYGON);
	for (x = -x_len; x < x_len; x++)
	{
		y = (y_len / x_len)*sqrt((x_len*x_len) - (x*x));
		glVertex2f(xc + x, yc + y);
	}
	for (x = -x_len; x < x_len; x++)
	{
		y = (y_len / x_len)*sqrt((x_len*x_len) - (x*x));
		glVertex2f(xc - x, yc - y);
	}
	glEnd();
}
void drawElipseLine(float xc, float yc, float x_len, float y_len)
{
	float x, y;
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	for (x = -x_len; x < x_len; x++)
	{
		y = (y_len / x_len)*sqrt((x_len*x_len) - (x*x));
		glVertex2f(xc + x, yc + y);
	}
	for (x = -x_len; x < x_len; x++)
	{
		y = (y_len / x_len)*sqrt((x_len*x_len) - (x*x));
		glVertex2f(xc - x, yc - y);
	}
	glEnd();
}

void curvePoints(float t, float x1, float y1, float x2, float y2, float x3, float y3)
{
	//[x, y] = (1–t)2P0 + 2(1–t)tP1 + t2P3
	float px = (1 - t)*(1 - t)*x1 + 2 * (1 - t)*t*x2 + t*t*x3;
	float py = (1 - t)*(1 - t)*y1 + 2 * (1 - t)*t*y2 + t*t*y3;
	//printf("%f  %f\n", px, py);
	glVertex2f(px, py);
}
