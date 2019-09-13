#include<glut.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include"functions.h"
extern char* instr_S1;
char *Name_Score = "Mind Craker";
char *Score1 = "Score:";
int Round = 1;
extern int Score;
extern int hs1, hs2, hs3;
int Scoreint1 = 0;
void Write_HS();
void drawElipseLine(float xc, float yc, float x_len, float y_len);
void drawElipse_Menu(float xc, float yc, float x_len, float y_len);
void keysp_Score(int k, int x, int y)
{
	if (k == GLUT_KEY_RIGHT)
	{
		if (Round == 1)
		{
			init_Story3();
			glutDisplayFunc(displayStory3);
			glutPostRedisplay();
		}
		else
		{
			init_Story4();
			glutDisplayFunc(displayStory4);
			glutPostRedisplay();
		}
	}
	glutPostRedisplay();
}
void idle_Score()
{
	if (Scoreint1 < Score)
	{
		Scoreint1++;
	}
	else
	{
		glutIdleFunc(0);
	}
	glutPostRedisplay();
}
void key_Score(unsigned char k, int x, int y)
{
	if ((int)k == 13)
	{
		if (Round == 1)
		{
			init_Story3();
			glutDisplayFunc(displayStory3);
		}
	}
}
void init_Score1()
{
	Scoreint1 = 0;
	if (Score > hs1)
	{
		hs3 = hs2;
		hs2 = hs1;
		hs1 = Score;
		Write_HS();
	}
	else if (Score > hs2)
	{
		hs3 = hs2;
		hs2 = Score;
		Write_HS();
	}
	else if(Score>hs3)
	{
		hs3 = Score;
		Write_HS();
	}
	glutIdleFunc(idle_Score);
	glutSpecialFunc(keysp_Score);
	glutKeyboardFunc(key_Score);
	PlaySound(TEXT("Complete.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void displayScore1()
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
	for (int i = 0; Name_Score[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Name_Score[i]);
	glColor3f(0, 0, 1);
	glRasterPos2f(775, 575);
	for (int i = 0; Score1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, Score1[i]);
	glRasterPos2f(775, 475);
	int steps = Scoreint1;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 1000) + 48);
	steps %= 1000;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 100) + 48);
	steps %= 100;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 10) + 48);
	steps %= 10;
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, steps + 48);
	glColor3f(0, 0, 1);
	glRasterPos2f(0, -80);
	for (int i = 0; instr_S1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, instr_S1[i]);
	glFlush();
}
/*void drawElipse_Menu(float xc, float yc, float x_len, float y_len)
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
}*/
