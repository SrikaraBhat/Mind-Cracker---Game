#include<glut.h>
#include<string.h>
#include<Windows.h>
#include"functions.h"
char* instr_Maze = "Use Arrow kets to move the Bird";
extern int Score;
extern int Round;
class GameMaze
{
	int A[12][12] = { { 1,1,1,1,1,1,1,1,1,1,1,1 },
					  { 1,0,0,0,0,0,0,0,0,0,0,1 },
					  { 1,1,1,1,1,0,1,1,1,1,0,1 },
					  { 1,0,0,0,1,0,0,1,1,1,0,1 },
					  { 1,0,1,0,1,1,1,1,1,1,0,1 },
					  { 1,0,1,0,0,0,0,0,0,0,0,1 },
					  { 1,0,1,1,1,1,1,1,1,1,0,1 },
					  { 1,0,1,0,0,0,0,0,0,1,0,1 },
					  { 1,0,0,0,1,0,0,1,0,1,0,1 },
					  { 1,0,1,1,1,1,1,1,0,1,1,1 },
					  { 1,0,0,0,0,0,1,1,0,0,0,1 },
					  { 1,1,1,1,1,1,1,1,1,1,1,1 }};
	int steps = 0;
	int posx=1, posy=1;
	public:int getSteps()
	{
		return steps;
	}
	public:void Move(char ans)
	{
		if (ans == 'a')
		{
			int a = A[posx - 1][posy];
			if (posx - 1 >= 0 && A[posy][posx-1] != 1)
			{
				posx = posx - 1;
				steps++;
			}
		}
		else if (ans == 'd')
		{
			int a = A[posy][posx+1];
			if (posx + 1 <= 12 && A[posy][posx + 1] != 1)
			{
				posx = posx + 1;
				steps++;
			}
		}
		else if (ans == 's')
		{
			int a = A[posy+1][posx+1];
			if (posy + 1 <= 12 && A[posy + 1][posx] != 1)
			{
				posy = posy + 1;
				steps++;
			}
		}
		else if (ans == 'w')
		{	
			int a = A[posy-1][posx];
			if (posy - 1 >= 0 && A[posy-1][posx] != 1)
			{
				posy = posy - 1;
				steps++;
			}
		}
	}
	public:int isComplete()
	{
		if (posx==10&&posy==10)
			return 1;
		else
			return 0;
	}
	public:void reset()
	{
		posx = 1;
		posy = 1;
		steps = 0;
	}
	public:int getArray(int i, int j)
	{
		return A[i][j];
	}
	public:int getPosx()
	{
		return posx;
	}
	public:int getPosy()
	{
		return posy;
	}
};
GameMaze Mazeobj;
void drawElipseLine(float xc, float yc, float x_len, float y_len);
void drawElipse_Menu(float xc, float yc, float x_len, float y_len);
void drawFrameMaze()
{
	/*glColor3f(1, 1, 1);
	for (int i = -4; i <= 44; i++)
	{
		for (int j = -4; j < 40; j++)
		{
			glBegin(GL_LINE_LOOP);
			drawElipse_Menu(i * 30, j * 30, 15, 15);
			glEnd();
		}
	}*/
	glColor3f(0.5, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(-50, 950);
	glVertex2f(-50, -45);
	glVertex2f(-45, -50);
	glVertex2f(950, -50);
	glVertex2f(950, 950);
	glEnd();
	glColor3f(0.5, 0.8, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(0, 900);
	glVertex2f(900, 900);
	glVertex2f(900, 0);
	glVertex2f(0, 0);
	glEnd();
}
float flipMaze = 0;
void idle_Maze()
{
	flipMaze += 0.01;
	if (flipMaze > 2)
		flipMaze = 0;
	glutPostRedisplay();
}
void keyFunc_Maze(unsigned char k, int x, int y)
{
	Mazeobj.Move(k);
	if (Mazeobj.isComplete())
	{
		Round = 2;
		if (Mazeobj.getSteps() > 150)
		{
			Score += 200;
		}
		else
		{
			Score += (170 - Mazeobj.getSteps()) * 10;
		}
		init_Score1();
		glutDisplayFunc(displayScore1);
	}
	glutPostRedisplay();
}
void keySpe_Maze(int k, int x, int y)
{
	switch (k)
	{
	case GLUT_KEY_UP: Mazeobj.Move('w');
		break;
	case GLUT_KEY_DOWN: Mazeobj.Move('s');
		break;
	case GLUT_KEY_LEFT: Mazeobj.Move('a');
		break;
	case GLUT_KEY_RIGHT: Mazeobj.Move('d');
		break;
	}
	if (Mazeobj.isComplete())
	{
		Round = 2;
		if (Mazeobj.getSteps() > 150)
		{
			Score += 200;
		}
		else
		{
			Score += (170 - Mazeobj.getSteps()) * 10;
		}
		init_Score1();
		glutDisplayFunc(displayScore1);
	}
	//printf("\n%d\n", Game.isComplete());
	glutPostRedisplay();
}
void init_Maze()
{
	Mazeobj.reset();
	glutKeyboardFunc(keyFunc_Maze);
	glutSpecialFunc(keySpe_Maze);
	glutIdleFunc(idle_Maze);
}
void DisplayMaze()
{
	glClearColor(0.2, 0.1, 0.9, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	int no = 1;
	drawFrameMaze();
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
		{
			if (Mazeobj.getArray(i, j) == 1)
			{
				glPushMatrix();
				glTranslatef((j) * 75, (11 - i) * 75, 0);
				glColor3f(0, 1, 0);
				glBegin(GL_POLYGON);
				glVertex2f(5, 30);
				glVertex2f(70, 30);
				glVertex2f(37.5, 75);
				glEnd();
				glColor3f(0.4, 0.2, 0.2);
				glBegin(GL_POLYGON);
				glVertex2f(32.5, 30);
				glVertex2f(37.5, 30);
				glVertex2f(37.5, 0);
				glVertex2f(32.5, 0);
				glEnd();
				glPopMatrix();
				
			}
			else
			{
				/*glColor3f(0, 0.5, 0);
				glPushMatrix();
				glTranslatef((j) * 75, (11 - i) * 75, 0);
				glBegin(GL_POLYGON);
				glVertex2f(0, 0);
				glVertex2f(0, 75);
				glVertex2f(75, 75);
				glVertex2f(75, 0);
				glEnd();
				glPopMatrix();*/
			}
		}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(((Mazeobj.getPosx()) * 75)+32.5, ((11 - Mazeobj.getPosy()) * 75)+32.5, 0);
	glScalef(75.0 / 1000.0, 75 / 1000.0, 1);
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
	if (flipMaze < 1)
	{
		glPushMatrix();
		glTranslatef(250, -25, 0);
		glRotatef(70, 0, 0, 1);
		drawElipse_Menu(250, -25, 100, 250);
		glPopMatrix();
	}
	else
		drawElipse_Menu(250, -25, 100, 250);
	if (flipMaze < 1)
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
	if (flipMaze < 1)
	{
		glPushMatrix();
		glTranslatef(250, -25, 0);
		glRotatef(70, 0, 0, 1);
		drawElipseLine(250, -25, 100, 250);
		glPopMatrix();
	}
	else
		drawElipseLine(250, -25, 100, 250);
	if (flipMaze < 1)
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
	glPushMatrix();
	glTranslatef(750, 75, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.2, 0.3);
	glVertex2f(0, 40);
	glVertex2f(75, 40);
	glVertex2f(32.5, 75);
	glEnd();
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 40);
	glVertex2f(65, 40);
	glVertex2f(65, 0);
	glVertex2f(10, 0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1000, 0, 0);
	glColor3f(0, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(0, 400);
	glVertex2f(250, 400);
	glVertex2f(250, 800);
	glVertex2f(0, 800);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 400);
	glVertex2f(250, 400);
	glVertex2f(250, 800);
	glVertex2f(0, 800);
	glEnd();
	char * Step = "Steps:";
	glRasterPos2d(0, 750);
	for (int k = 0; Step[k] != '\0'; k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Step[k]);
	int steps = Mazeobj.getSteps();
	//steps = reverseInt(steps);
	glRasterPos2d(0, 700);
	//while (steps > 0)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 100) + 48);
		steps %= 100;
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (steps / 10) + 48);
		steps %= 10;
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, steps + 48);
	}
	glPopMatrix();
	glColor3f(0, 1, 0);
	glRasterPos2f(0, -80);
	for (int i = 0; instr_Maze[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, instr_Maze[i]);
	glFlush();
}
