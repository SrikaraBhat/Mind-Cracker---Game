#include<glut.h>
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include"functions.h"
int timeron = 0;
char* headding = "CG Mini Project";
char* ProjName = "Mind Cracker";
char* Name1 = "Aravinda B";
char* USN1 = "4SF15CS017";
char* Name2 = "Akshatha";
char* USN2 = "4SF15CS008";
int n;
void init()
{
	//glutInitDisplayMode(GLUT_DEPTH);
	//glEnable(GL_DEPTH_TEST);
	int a = rand();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,1300, -100, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Intro()
{
	glClearColor(0, 0, 0, 0);
	int n1 = 0, i;
	//int a = strlen(headding);
	glColor3f(1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(300, 700);
	for (i = 0; i < strlen(headding) && n1<n; i++, n1++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, headding[i]);
	if (i<strlen(headding))
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '|');
	glColor3f(0, 0, 1);
	glRasterPos2f(300, 600);
	for (i = 0; i < strlen(ProjName) && n1<n; i++, n1++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ProjName[i]);
	if (n>strlen(headding) && n<strlen(ProjName) + strlen(headding))
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '|');
	glRasterPos2f(600, 400);
	for (i = 0; i < strlen(Name1) && n1<n; i++, n1++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, Name1[i]);
	if (n>strlen(headding) + strlen(ProjName) && n<strlen(ProjName) + strlen(headding) + strlen(Name1))
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, '|');
	glRasterPos2f(600, 375);
	for (i = 0; i < strlen(USN1) && n1<n; i++, n1++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, USN1[i]);
	if (n>strlen(headding) + strlen(ProjName) + strlen(Name1) && n<strlen(ProjName) + strlen(headding) + strlen(Name1) + strlen(USN1))
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, '|');
	glRasterPos2f(600, 300);
	for (i = 0; i < strlen(Name2) && n1<n; i++, n1++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Name2[i]);
	if (n>strlen(headding) + strlen(ProjName) + strlen(Name1) + strlen(USN1) && n<strlen(ProjName) + strlen(headding) + strlen(Name1) + strlen(USN1) + strlen(Name2))
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, '|');
	glRasterPos2f(600, 275);
	for (i = 0; i < strlen(USN2) && n1<n; i++, n1++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, USN2[i]);
	if (n>strlen(headding) + strlen(ProjName) + strlen(Name1) + strlen(Name2) + strlen(USN1) && n<strlen(ProjName) + strlen(headding) + strlen(Name1) + strlen(USN1) + strlen(Name2) + strlen(USN2))
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, '|');
	glFlush();
}
void timer(int i)
{
	if (n < (strlen(headding) + strlen(ProjName) + strlen(Name1) + strlen(USN1) + strlen(Name2) + strlen(USN2)))
	{
		if(timeron==0)
			glutTimerFunc(200, timer, i + 1);
		PlaySound(TEXT("type.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	n = i;
	glutPostRedisplay();
}
void key(int k,int x,int y)
{
	if (k == 102)
	{
		timeron = 1;
		init_Menu();
		//init_Story4();
		glutDisplayFunc(displayMenu);
		glutPostRedisplay();
	}
}
void main(int argc, char** argv)
{
	int a;
	glutInit(&argc, argv);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(30, 30);
	initScane1();
	Load_HS();
	glutCreateWindow("Game");
	//scanf_s("%d",&a);
	init();
	glutTimerFunc(10000, timer, 0);
	glutDisplayFunc(Intro);
	glutSpecialFunc(key);
	glutMainLoop();
}