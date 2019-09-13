#include<glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include"Clipping.h"
#include"functions.h"
char* instr_Pz = "Use arrow keys to move white tile and form the image";
int Score;
//int id;
float x = 0;
int dir=1;
struct Pos
{
	int i, j;
	Pos(int x, int y)
	{
		i = x;
		j = y;
	}
};
class GameEngine
{
	int A[3][3] = { { 8,7,6 },{ 5,4,3 },{ 2,1,0 } };
	int steps = 0;
	struct Pos findZero()
	{
		int i, j;
		for (i = 0; i<3; i++)
			for (j = 0; j<3; j++)
				if (A[i][j] == 0)
				{
					struct Pos p=Pos(i,j);
					return p;
				}
		struct Pos p=Pos(-1,-1);
		return p;
	}
	void swap(Pos Old, Pos New)
	{
		int temp = A[Old.i][Old.j];
		A[Old.i][Old.j] = A[New.i][New.j];
		A[New.i][New.j] = temp;
	}
	public :void Randomize()
	{
		steps = 0;
		int i = 0, j = 0;
		for (i = 0; i<100; i++)
		{
			int r = rand() % 5;
			struct Pos posOld = findZero();
			if (posOld.i == -1 || posOld.j == -1)
			{
				printf("Unknown Error!! exiting the Game......");
				getchar();
				exit(1);
			}
			if (r == 1)
			{
				if (posOld.j - 1 >= 0)
				{
					struct Pos posNew = Pos(posOld.i, posOld.j - 1);
					swap(posOld,posNew);
				}
			}
			else if (r == 2)
			{
				if (posOld.j + 1 <= 2)
				{
					struct Pos posNew = Pos(posOld.i, posOld.j + 1);
					swap(posOld, posNew);
				}
			}
			else if (r == 3)
			{
				if (posOld.i - 1 >= 0)
				{
					Pos posNew = Pos(posOld.i - 1, posOld.j);
					swap(posOld,posNew);
				}
			}
			else if (r == 4)
			{
				if (posOld.i + 1 <= 2)
				{
					Pos posNew = Pos(posOld.i + 1, posOld.j);
					swap(posOld,posNew);
				}
			}
		}
	}
	public:int getSteps()
	{
		return steps;
	}
	public:void Move(char ans)
	{
		struct Pos posOld = findZero();
		if (ans == 'a')
		{
			if (posOld.j - 1 >= 0)
			{
				Pos posNew = Pos(posOld.i, posOld.j - 1);
				swap(posOld, posNew);
				PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				steps++;
			}
		}
		else if (ans == 'd')
		{
			if (posOld.j + 1 <= 2)
			{
				Pos posNew = Pos(posOld.i, posOld.j + 1);
				swap(posOld, posNew);
				PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				steps++;
			}
		}
		else if (ans == 's')
		{
			if (posOld.i + 1 <= 2)
			{
				Pos posNew = Pos(posOld.i + 1, posOld.j);
				swap(posOld, posNew);
				PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				steps++;
			}
		}
		else if (ans == 'w')
		{
			if (posOld.i - 1 >= 0)
			{
				Pos posNew = Pos(posOld.i - 1, posOld.j);
				swap(posOld, posNew);
				PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				steps++;
			}
		}
	}
	public:int isComplete()
	{
		if (A[0][0] == 1 && A[0][1] == 2 && A[0][2] == 3 && A[1][0] == 4 && A[1][1] == 5 && A[1][2] == 6 && A[1][2] == 6 && A[2][0] == 7 && A[2][1] == 8)
			return 1;
		else
			return 0;
	}
	public:int getArray(int i, int j)
	{
		return A[i][j];
	}
};
GameEngine Game;
struct Shape {
	float r, g, b;
	struct node* e = NULL;
	struct node* ec[10];

};
struct Shape Scanes[5][20];
int ShapeCount[5];
void Curve(int Scane,int Shape,float t, float x1, float y1, float x2, float y2, float x3, float y3)
{
	//[x, y] = (1–t)2P0 + 2(1–t)tP1 + t2P3
	float px = (1 - t)*(1 - t)*x1 + 2 * (1 - t)*t*x2 + t*t*x3;
	float py = (1 - t)*(1 - t)*y1 + 2 * (1 - t)*t*y2 + t*t*y3;
	//printf("%f  %f\n", px, py);
	Scanes[Scane][Shape].e =  insertFirst(Scanes[Scane][Shape].e,px, py);
}
void TreeBottom(int Scane,int Count,float x, float y)
{
	glColor3f(0.4, 0.2, 0.2);
	Scanes[0][Count].r = 0.4;
	Scanes[0][Count].g = 0.2;
	Scanes[0][Count].b = 0.2;	
	//glBegin(GL_POLYGON);
	Scanes[Scane][Count].e = insertFirst(Scanes[Scane][Count].e, 50 + x, 410 + y);
	Scanes[Scane][Count].e = insertFirst(Scanes[Scane][Count].e, 60 + x, 410 + y);
	Scanes[Scane][Count].e = insertFirst(Scanes[Scane][Count].e, 60 + x, 470 + y);
	Scanes[Scane][Count].e = insertFirst(Scanes[Scane][Count].e, 50 + x, 470 + y);
	glEnd();
}
void TreeTop(int Scane, int Count, float x, float y)
{
	//glColor3f(0, 1, 0);
	Scanes[0][Count].r = 0;
	Scanes[0][Count].g = 1;
	Scanes[0][Count].b = 0;
	//glBegin(GL_POLYGON);
	Scanes[Scane][Count].e = insertFirst(Scanes[Scane][Count].e, 20 + x, 470 + y);
	Scanes[Scane][Count].e = insertFirst(Scanes[Scane][Count].e, 90 + x, 470 + y);
	Scanes[Scane][Count].e = insertFirst(Scanes[Scane][Count].e, 55 + x, 570 + y);
	//glEnd();
}
void initScane1()
{
	int Count=0;
	Scanes[0][Count].r = 0;
	Scanes[0][Count].g = 0.5;
	Scanes[0][Count].b = 0.0;
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 0, 0);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 0, 900);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 900, 900);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 900, 0);
	Count++;
	//glColor3f(0, 0.9, 0.9);
	Scanes[0][Count].r = 0;
	Scanes[0][Count].g = 0.9;
	Scanes[0][Count].b = 0.9;
	//glBegin(GL_POLYGON);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e,0, 600);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e,0, 900);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e,900, 900);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e,900, 600);
	//glEnd();
	Count++;

	//glColor3f(1, 1, 0);
	Scanes[0][Count].r = 1;
	Scanes[0][Count].g = 1;
	Scanes[0][Count].b = 0;
	//glBegin(GL_POLYGON);
	Scanes[0][Count].e = drawElipse(Scanes[0][Count].e,300, 800, 100, 100);
	//glEnd();
	Count++;
	glColor3f(0.1, 1, 0.1);
	Scanes[0][Count].r = 0.1;
	Scanes[0][Count].g = 1;
	Scanes[0][Count].b = 0.1;

	//glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++)
	{
		float t = i / 300.0;
		Curve(0,Count,t, 0, 600, 150, 1100, 350, 600);
	}
	//glEnd();
	Count++;
	//glColor3f(0.1, 1, 0.1);
	Scanes[0][Count].r = 0.1;
	Scanes[0][Count].g = 1;
	Scanes[0][Count].b = 0.1;
	//glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++)
	{
		float t = i / 300.0;
		Curve(0,Count,t, 300, 600, 450, 1100, 650, 600);
	}
	//glEnd();
	Count++;
	Scanes[0][Count].r = 0.1;
	Scanes[0][Count].g = 1;
	Scanes[0][Count].b = 0.1;
	//glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++)
	{
		float t = i / 300.0;
		Curve(0,Count,t, 600, 600, 750, 1100, 900, 600);
	}
	//glEnd();
	Count++;
	glColor3f(0, 1, 1);
	Scanes[0][Count].r = 0;
	Scanes[0][Count].g = 1;
	Scanes[0][Count].b = 1;
	//glBegin(GL_POLYGON);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 0, 200);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 900, 150);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 900, 350);
	Scanes[0][Count].e = insertFirst(Scanes[0][Count].e, 0, 400);
	//glEnd();
	Count++;
	TreeBottom(0,Count,0, 0);
	Count++;
	TreeTop(0, Count, 0, 0);
	Count++;
	TreeBottom(0, Count, 300, 0);
	Count++;
	TreeTop(0, Count, 300, 0);
	Count++;
	//tree(300, 0);
	TreeBottom(0, Count, 600, 0);
	Count++;
	TreeTop(0, Count, 600, 0);
	Count++;
	TreeBottom(0, Count, 0, -400);
	Count++;
	TreeTop(0, Count, 0, -400);
	Count++;
	//tree(0, -400);
	TreeBottom(0, Count, 300, -400);
	Count++;
	TreeTop(0, Count, 300, -400);
	Count++;
	//tree(300, -400);
	TreeBottom(0, Count, 600, -400);
	Count++;
	TreeTop(0, Count, 600, -400);
	Count++;
	//tree(600, -400);
	ShapeCount[0] = Count;
	for (int i = 0; i < Count; i++)
	{
		Scanes[0][i].ec[1] = Clip(Scanes[0][i].e, 0, 300, 900, 600);
		Scanes[0][i].ec[2] = Clip(Scanes[0][i].e, 300, 600, 900, 600);
		Scanes[0][i].ec[3] = Clip(Scanes[0][i].e, 600, 900, 900, 600);
		Scanes[0][i].ec[4] = Clip(Scanes[0][i].e, 0, 300, 600, 300);
		Scanes[0][i].ec[5] = Clip(Scanes[0][i].e, 300, 600, 600, 300);
		Scanes[0][i].ec[6] = Clip(Scanes[0][i].e, 600, 900, 600, 300);
		Scanes[0][i].ec[7] = Clip(Scanes[0][i].e, 0, 300, 300, 0);
		Scanes[0][i].ec[8] = Clip(Scanes[0][i].e, 300, 600, 300, 0);
	}
}
/*void main()
{
	glutInitWindowSize(400, 400);
	initScane1();
	glutInitWindowPosition(80, 80);
	Game.Randomize();
	id = glutCreateWindow("Game");
	init();
	//glutIdleFunc(Idle);
	glutKeyboardFunc(keyFunc);
	glutSpecialFunc(keySpe);
	glutDisplayFunc(DisplayGame);
	glutMainLoop();
}*/
void DrawCurve(float t, float x1, float y1, float x2, float y2, float x3, float y3)
{
	//[x, y] = (1–t)2P0 + 2(1–t)tP1 + t2P3
		float px = (1 - t)*(1 - t)*x1 + 2 * (1 - t)*t*x2 + t*t*x3;
		float py = (1 - t)*(1 - t)*y1 + 2 * (1 - t)*t*y2 + t*t*y3;
	//	//printf("%f  %f\n", px, py);
		glVertex2f(px, py);
}
void keyFunc(unsigned char k, int x, int y)
{
	if (k == 'r' || k == 'R')
	{
		Game.Randomize();
	}
	Game.Move(k);
	if (Game.isComplete())
	{
		if (Game.getSteps() > 150)
		{
			Score = 200;
		}
		else
		{
			Score = (170 - Game.getSteps()) * 10;
		}
		init_Score1();
		glutDisplayFunc(displayScore1);
	}
	glutPostRedisplay();
}
void keySpe(int k, int x, int y)
{
	switch (k)
	{
	case GLUT_KEY_UP: Game.Move('s');
		break;
	case GLUT_KEY_DOWN: Game.Move('w');
		break;
	case GLUT_KEY_LEFT: Game.Move('d');
		break;
	case GLUT_KEY_RIGHT: Game.Move('a');
		break;
	}
	if (Game.isComplete())
	{
		if (Game.getSteps() > 150)
		{
			Score = 200;
		}
		else
		{
			Score = (170 - Game.getSteps()) * 10;
		}
		init_Score1();
		glutDisplayFunc(displayScore1);
	}
	//printf("\n%d\n", Game.isComplete());
	glutPostRedisplay();
}
void init_Pizzle()
{
	glMatrixMode(GL_MODELVIEW_MATRIX);
	//glLoadIdentity();
	//gluOrtho2D(-100,1300,-100,1000);
	glMatrixMode(GL_PROJECTION_MATRIX);
	//glLoadIdentity();
	Game.Randomize();
	glutKeyboardFunc(keyFunc);
	glutSpecialFunc(keySpe);
}
struct node* drawElipse(struct node* head, float xc, float yc, float x_len, float y_len)
{
	float x, y, step = 1;
	for (x = -x_len; x < x_len; x += step)
	{
		y = (y_len / x_len)*sqrt((x_len*x_len) - (x*x));
		head = insertFirst(head, x + xc, y + yc);
	}
	for (x = -x_len; x < x_len; x += step)
	{
		y = (y_len / x_len)*sqrt((x_len*x_len) - (x*x));
		head = insertFirst(head, xc - x, yc - y);
	}
	return head;
}
void printList(struct node* head) {
	struct node *ptr = head;
	printf("\n[ ");

	//start from the beginning
	while (ptr != NULL) {
		printf("(%f,%f) ", ptr->x, ptr->y);
		ptr = ptr->next;
	}

	printf(" ]");
}
void drawElipseNormal(float xc, float yc, float x_len, float y_len)
{
	float x, y;
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
}
void drawFrame()
{
	glColor3f(0.5, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(-50, 950);
	glVertex2f(-50, -45);
	glVertex2f(-45, -50);
	glVertex2f(950, -50);
	glVertex2f(950, 950);
	glEnd();
}
void DisplayGame()
{
	glClearColor(0.2, 0.1, 0.9, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	int no = 1;
	drawFrame();
	for(int k=0;k<ShapeCount[0];k++)
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int no = Game.getArray(i, j);

			if (no != 0)
			{
				//printf("%d %d %d %d %d\n", no,i,j, i * 300, (3 - j) * 300);
				//printList(ec[no]);
				glPushMatrix();
				glTranslatef(j * 300, (2 - i) * 300, 0);
				glBegin(GL_POLYGON);
				drawShape(0,k,Scanes[0][k].ec[no]);
				glEnd();
				glColor3f(0, 0, 0);
				glRasterPos2d(5, 250);
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, no + 48);
				glPopMatrix();
			}
			no++;
		}
	}
	drawPatch();
	glPushMatrix();
	glTranslatef(1000, 0, 0);
	glScalef(0.3, 0.3, 0);
	for (int k = 0; k < ShapeCount[0]; k++)
	{
		glBegin(GL_POLYGON);
		drawShape(0, k, Scanes[0][k].e);
		glEnd();
	}
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
	for(int k=0;Step[k]!='\0';k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Step[k]);
	int steps = Game.getSteps();
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
	for (int i = 0; instr_Pz[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, instr_Pz[i]);
	glFlush();
}
void drawShape(int Scane,int Count,struct node* head)
{
	glColor3f(Scanes[Scane][Count].r, Scanes[Scane][Count].g, Scanes[Scane][Count].b);
	struct node *ptr = head;

	while (ptr != NULL) {
		glVertex2f(ptr->x, ptr->y);
		ptr = ptr->next;
	}
}
void drawPatch()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int no = Game.getArray(i, j);

			if (no == 0)
			{
				glPushMatrix();
				glColor3f(1, 1, 1);
				glTranslatef(j * 300, (2 - i) * 300, 0);
				glBegin(GL_POLYGON);
				glVertex2f(0, 0);
				glVertex2f(0, 300);
				glVertex2f(300, 300);
				glVertex2f(300, 0);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(0, 0);
				glVertex2f(0, 300);
				glVertex2f(300, 300);
				glVertex2f(300, 0);
				glEnd();
				glPopMatrix();
			}
		//	no++;
		}
	}
}