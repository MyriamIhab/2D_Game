#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <glut.h>
#include <cmath>
#include <math.h>
#include <random>
#include <iostream>
#include <chrono>
#include <ctime>

int animY = -5;
bool up = false;
int currTime = 0;
int gameTime = 60;
int stopSpeed = 60;
int stopDoublePoints = 60;
bool win = false;
bool lose = false;
bool doublePoints = false;
bool speedUp = false;
int lives = 5;
int score = 0;
int speX = 500;
int speY = 300;
int ob1X = 300;
int ob1Y = 100;
int ob2X = 100;
int ob2Y = 400;
int ob3X = 500;
int ob3Y = 500;
int ob4X = 700;
int ob4Y = 200;
int ob5X = 800;
int ob5Y = 400;
int goalPos = 0;
int rotAngle = 0;
int scaleY = 1;
int scaleX = 1;
int randXcoll1 = 0;
int randYcoll1 = 0;
int randXcoll2 = 0;
int randYcoll2 = 0;
int randXcoll3 = 0;
int randYcoll3 = 0;
int randXcoll4 = 0;
int randYcoll4 = 0;
int randXcoll5 = 0;
int randYcoll5 = 0;
int randXpow1 = 0;
int randYpow1 = 0;
int randXpow2 = 0;
int randYpow2 = 0;
double pointRotate = 0;
//this is the method used to print text in OpenGL
//there are three parameters,
//the first two are the coordinates where the text is display,
//the third coordinate is the string containing the text to display
void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void PlayerLogo() {
	glPushMatrix();
	//glColor3f(0, speC, 1); //draws a blue pixel @ 10,220
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS); // the body of the mouse
	glVertex3f(-50.0f, -10.0f, 0.0f);
	glVertex3f(-30.0f, 10.0f, 0.0f);
	glVertex3f(20.0f, 10.0f, 0.0f);
	glVertex3f(50.0f, -10.0f, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP); // tail
	glVertex3f(-30.0f, 10.0f, 0.0f);
	glVertex3f(-50.0f, 20.0f, 0.0f);
	glVertex3f(-55.0f, 25.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES); // legs
	glVertex3f(-10.0f, -10.0f, 0.0f);
	glVertex3f(-30.0f, -20.0f, 0.0f);
	glVertex3f(10.0f, -10.0f, 0.0f);
	glVertex3f(30.0f, -20.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES); // ears
	glVertex3f(20.0f, 10.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(15.0f, 25.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);
	glVertex3f(5.0f, 25.0f, 0.0f);
	glEnd();



	glPopMatrix();
}
void Player() {
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(speX, speY, 0);
	glRotated(rotAngle, 0, 0, 1);
	glScaled(scaleX, scaleY, 0);
	glBegin(GL_QUADS); // the body of the mouse
	glVertex3f(-50.0f, -10.0f, 0.0f);
	glVertex3f(-30.0f, 10.0f, 0.0f);
	glVertex3f(20.0f, 10.0f, 0.0f);
	glVertex3f(50.0f, -10.0f, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP); // tail
	glVertex3f(-30.0f, 10.0f, 0.0f);
	glVertex3f(-50.0f, 20.0f, 0.0f);
	glVertex3f(-55.0f, 25.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES); // legs
	glVertex3f(-25.0f, -10.0f, 0.0f);
	glVertex3f(-30.0f, -15.0f, 0.0f);
	glVertex3f(-20.0f, -10.0f, 0.0f);
	glVertex3f(-25.0f, -15.0f, 0.0f);
	glVertex3f(10.0f, -10.0f, 0.0f);
	glVertex3f(15.0f, -15.0f, 0.0f);
	glVertex3f(15.0f, -10.0f, 0.0f);
	glVertex3f(20.0f, -15.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES); // ears
	glVertex3f(20.0f, 10.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(15.0f, 20.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);
	glVertex3f(5.0f, 20.0f, 0.0f);
	glEnd();

	glPushAttrib(GL_POINT_BIT);
	glPointSize(3);
	glBegin(GL_POINTS);  // eye and nose
	glColor3f(0, 1, 1);
	glVertex3f(20.0f, 2.0f, 0.0f);
	glColor3f(1, 0.5, 0.6);
	glVertex3f(47.0f, -9.0f, 0.0f);
	glEnd();
	glPopAttrib();
	glPopMatrix();
}
void Obstacle() {
	//randX = rand() % 50;
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	glVertex3f(-25.0f, -25.0f, 0.0f);
	glVertex3f(25.0f, -25.0f, 0.0f);
	glVertex3f(25.0f, 25.0f, 0.0f);
	glVertex3f(-25.0f, 25.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(-25.0f, -25.0f, 0.0f);
	glVertex3f(25.0f, -25.0f, 0.0f);
	glVertex3f(0.0f, 25.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex3f(0.0f, 15.0f, 0.0f);
	glVertex3f(0.0f, -5.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(-3.0f, -17.0f, 0.0f);
	glVertex3f(-3.0f, -11.0f, 0.0f);
	glVertex3f(3.0f, -11.0f, 0.0f);
	glVertex3f(3.0f, -17.0f, 0.0f);
	glEnd();


}
void Collectables() {
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.7, 0);
	glVertex3f(-20.0f, 5.0f, 0.0f);
	glVertex3f(20.0f, 5.0f, 0.0f);
	glVertex3f(15.0f, 20.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.6, 0);
	glVertex3f(-20.0f, 5.0f, 0.0f);
	glVertex3f(-20.0f, -20.0f, 0.0f);
	glVertex3f(20.0f, -20.0f, 0.0f);
	glVertex3f(20.0f, 5.0f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.5, 0);
	glVertex3f(-10.0f, 0.0f, 0.0f);
	glVertex3f(-15.0f, -5.0f, 0.0f);
	glVertex3f(-5.0f, -10.0f, 0.0f);
	glVertex3f(5.0f, -5.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.5, 0);
	glVertex3f(10.0f, -10.0f, 0.0f);
	glVertex3f(8.0f, -15.0f, 0.0f);
	glVertex3f(12.0f, -20.0f, 0.0f);
	glVertex3f(16.0f, -15.0f, 0.0f);
	glVertex3f(14.0f, -10.0f, 0.0f);
	glEnd();
}
void Goal() {
	glPushMatrix();
	glPushAttrib(GL_LINE_BIT);
	glLineWidth(5);
	glRotated(pointRotate, 0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 1, 0);
	glVertex3f(37.5f, 75.0f, 0.0f);
	glVertex3f(75.0f, 0.0f, 0.0f);
	glVertex3f(37.5f, -75.0f, 0.0f);
	glVertex3f(-37.5f, -75.0f, 0.0f);
	glVertex3f(-75.0f, 0.0f, 0.0f);
	glVertex3f(-37.5f, 75.0f, 0.0f);
	glEnd();
	glPopAttrib();
	glPopMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.8, 0.9);
	glVertex3f(-40.0f, 30.0f, 0.0f);
	glVertex3f(-40.0f, -50.0f, 0.0f);
	glVertex3f(40.0f, -50.0f, 0.0f);
	glVertex3f(40.0f, 30.0f, 0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.5, 0.6, 0.7);
	glVertex3f(20.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, 10.0f, 0.0f);
	glVertex3f(30.0f, 10.0f, 0.0f);
	glVertex3f(30.0f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.6, 0.7);
	glVertex3f(20.0f, -50.0f, 0.0f);
	glVertex3f(-20.0f, -50.0f, 0.0f);
	glVertex3f(-20.0f, -30.0f, 0.0f);
	glVertex3f(-10.0f, -10.0f, 0.0f);
	glVertex3f(10.0f, -10.0f, 0.0f);
	glVertex3f(20.0f, -30.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.2, 0.4, 0.6);
	glVertex3f(-15.0f, -30.0f, 0.0f);
	glVertex3f(-5.0f, -30.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.4, 0.6);
	glVertex3f(-40.0f, 30.0f, 0.0f);
	glVertex3f(40.0f, 30.0f, 0.0f);
	glVertex3f(0.0f, 65.0f, 0.0f);
	glEnd();
}
void VerticleBoarder() {
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glVertex3f(5.0f, 595.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(10.0f, 590.0f, 0.0f);
	glVertex3f(15.0f, 590.0f, 0.0f);
	glVertex3f(15.0f, 10.0f, 0.0f);
	glEnd();
}
void HorizontalBoarder() {
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glVertex3f(995.0f, 5.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(990.0f, 10.0f, 0.0f);
	glVertex3f(990.0f, 15.0f, 0.0f);
	glVertex3f(10.0f, 15.0f, 0.0f);
	glEnd();
}
void DoubleScorePwerUp() {
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(12.5f, 25.0f, 0.0f);
	glVertex3f(25.0f, 0.0f, 0.0f);
	glVertex3f(12.5f, -25.0f, 0.0f);
	glVertex3f(-12.5f, -25.0f, 0.0f);
	glVertex3f(-25.0f, 0.0f, 0.0f);
	glVertex3f(-12.5f, 25.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3f(12.5f, 25.0f, 0.0f);
	glVertex3f(25.0f, 0.0f, 0.0f);
	glVertex3f(12.5f, -25.0f, 0.0f);
	glVertex3f(-12.5f, -25.0f, 0.0f);
	glVertex3f(-25.0f, 0.0f, 0.0f);
	glVertex3f(-12.5f, 25.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.8, 0);
	glVertex3f(15.0f, 17.0f, 0.0f);
	glVertex3f(15.0f, -17.0f, 0.0f);
	glVertex3f(-15.0f, -17.0f, 0.0f);
	glVertex3f(-15.0f, 17.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-10.0f, 16.0f, 0.0f);
	glVertex3f(-5.0f, 16.0f, 0.0f);
	glVertex3f(-5.0f, 11.0f, 0.0f);
	glVertex3f(-10.0f, 11.0f, 0.0f);
	glVertex3f(-10.0f, 6.0f, 0.0f);
	glVertex3f(-5.0f, 6.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(0.0f, 16.0f, 0.0f);
	glVertex3f(5.0f, 6.0f, 0.0f);
	glVertex3f(5.0f, 16.0f, 0.0f);
	glVertex3f(0.0f, 6.0f, 0.0f);
	glEnd();
	glPushMatrix();
	glTranslated(0, -5, 0);
	glScaled(0.5, 0.5, 1);
	Collectables();
	glPopMatrix();

}
void SpeedUpPwerUp() {
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(12.5f, 25.0f, 0.0f);
	glVertex3f(25.0f, 0.0f, 0.0f);
	glVertex3f(12.5f, -25.0f, 0.0f);
	glVertex3f(-12.5f, -25.0f, 0.0f);
	glVertex3f(-25.0f, 0.0f, 0.0f);
	glVertex3f(-12.5f, 25.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3f(12.5f, 25.0f, 0.0f);
	glVertex3f(25.0f, 0.0f, 0.0f);
	glVertex3f(12.5f, -25.0f, 0.0f);
	glVertex3f(-12.5f, -25.0f, 0.0f);
	glVertex3f(-25.0f, 0.0f, 0.0f);
	glVertex3f(-12.5f, 25.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.8, 0);
	glVertex3f(15.0f, 17.0f, 0.0f);
	glVertex3f(15.0f, -17.0f, 0.0f);
	glVertex3f(-15.0f, -17.0f, 0.0f);
	glVertex3f(-15.0f, 17.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(-5.0f, 0.0f, 0.0f);
	glVertex3f(-25.0f, 0.0f, 0.0f);
	glVertex3f(-5.0f, 5.0f, 0.0f);
	glVertex3f(-20.0f, 5.0f, 0.0f);
	glVertex3f(-5.0f, -5.0f, 0.0f);
	glVertex3f(-20.0f, -5.0f, 0.0f);
	//glVertex3f(0.0f, 10.0f, 0.0f);
	//glVertex3f(-10.0f, 10.0f, 0.0f);
	//glVertex3f(0.0f, -10.0f, 0.0f);
	//glVertex3f(-10.0f, -10.0f, 0.0f);

	glEnd();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(10, 2, 0);
	glScaled(0.27, 0.27, 1);
	PlayerLogo();
	glPopMatrix();

}
void HealthBar(int value) {
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(20.0f, 550.0f, 0.0f);
	glVertex3f(20.0f, 540.0f, 0.0f);
	glVertex3f((value * 50) + 20.0f, 540.0f, 0.0f);
	glVertex3f((value * 50) + 20.0f, 550.0f, 0.0f);
	glEnd();
}
void Flower() {
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.7f, 0.8f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 0.0f);

	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -3.0f, 0.0f);

	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-3.0f, 0.0f, 0.0f);

	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 3.0f, 0.0f);
	glEnd();
}
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (win) {
		glColor3f(0, 0.5, 0);
		char* p01s[20];
		sprintf((char*)p01s, "HI WINNER.. GREAT JOB! ");
		print(400, 300, (char*)p01s);
	}
	else if (lose) {
		glColor3f(1, 0, 0);
		char* p01s[20];
		sprintf((char*)p01s, " GAME OVER!");
		print(450, 250, (char*)p01s);
	}
	else {
		glColor3f(1, 1, 1);
		char* p01s[20];
		sprintf((char*)p01s, "You have %d live(s) left! ", lives);
		print(20, 560, (char*)p01s);
		char* p02s[20];
		sprintf((char*)p02s, "Time left: %d sec! ", gameTime);
		print(800, 560, (char*)p02s);
	}
	glColor3f(1, 1, 1);
	char* p0s[20];
	sprintf((char*)p0s, "Score: %d", score);
	print(850, 535, (char*)p0s);

	glPushMatrix();
	glTranslated(500, 400, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(4, 4, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(400, 200, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(2, 2, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(300, 100, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(3, 3, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(100, 300, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(4, 4, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(200, 400, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(3, 3, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(300, 300, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(2, 2, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(600, 400, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(2, 2, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(700, 500, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(3, 3, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(800, 300, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(2, 2, 1);
	Flower();
	glPopMatrix();
	glPushMatrix();
	glTranslated(700, 100, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(4, 4, 1);
	Flower();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslated(200, 500, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(4, 4, 1);
	Flower();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslated(300, 200, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(3, 3, 1);
	Flower();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslated(400, 200, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(2, 2, 1);
	Flower();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslated(600, 100, 0);
	glRotated(pointRotate, 0, 0, 1);
	glScaled(4, 4, 1);
	Flower();
	glPopMatrix();

	glPushMatrix();
	Player();
	if (!win && !lose)
		HealthBar(lives);
	glPopMatrix();


	glPushMatrix();
	glTranslated(ob1X, ob1Y, 0);        // use to display in the center
	Obstacle();
	glPopMatrix();
	glPushMatrix();
	glTranslated(ob2X, ob2Y, 0);        // use to display in the center
	Obstacle();
	glPopMatrix();
	glPushMatrix();
	glTranslated(ob3X, ob3Y, 0);        // use to display in the center
	Obstacle();
	glPopMatrix();
	glPushMatrix();
	glTranslated(ob4X, ob4Y, 0);        // use to display in the center
	Obstacle();
	glPopMatrix();
	glPushMatrix();
	glTranslated(ob5X, ob5Y, 0);        // use to display in the center
	Obstacle();
	glPopMatrix();

	glPushMatrix();
	glTranslated(randXcoll1, randYcoll1, 0);        // use to display in the center
	glRotated(pointRotate, 0, 0, 1);
	Collectables();
	glPopMatrix();
	glPushMatrix();
	glTranslated(randXcoll2, randYcoll2, 0);        // use to display in the center
	glRotated(pointRotate, 0, 0, 1);
	Collectables();
	glPopMatrix();
	glPushMatrix();
	glTranslated(randXcoll3, randYcoll3, 0);        // use to display in the center
	glRotated(pointRotate, 0, 0, 1);
	Collectables();
	glPopMatrix();
	glPushMatrix();
	glTranslated(randXcoll4, randYcoll4, 0);        // use to display in the center
	glRotated(pointRotate, 0, 0, 1);
	Collectables();
	glPopMatrix();
	glPushMatrix();
	glTranslated(randXcoll5, randYcoll5, 0);        // use to display in the center
	glRotated(pointRotate, 0, 0, 1);
	Collectables();
	glPopMatrix();

	glPushMatrix();
	glTranslated(goalPos, goalPos, 0);
	glTranslated(75, 100, 0);        // use to display in the center
	Goal();
	glPopMatrix();

	glPushAttrib(GL_LINE_BIT);
	glLineWidth(2);
	glPushMatrix();
	VerticleBoarder();
	glTranslated(1000, 0, 0);
	glScaled(-1, 1, 1);
	VerticleBoarder();
	glPopMatrix();
	glPushMatrix();
	HorizontalBoarder();
	glTranslated(0, 600, 0);
	glScaled(1, -1, 1);
	HorizontalBoarder();
	glPopMatrix();
	glPopAttrib();

	glPushMatrix();
	glTranslated(0, animY, 0);
	glTranslated(randXpow1, randYpow1, 0);        // use to display in the center
	DoubleScorePwerUp();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, animY, 0);
	glTranslated(randXpow2, randYpow2, 0);        // use to display in the center
	SpeedUpPwerUp();
	glPopMatrix();

	//glVertex3f(20.0f, 20.0f, 0.0f);
	//glVertex3f(30.0f, 30.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(200.0f, 200.0f, 0.0f);
	glEnd();

	glFlush();
}

void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
{
	int addSpeX = 0;
	int addSpeY = 0;
	if (k == GLUT_KEY_RIGHT)//if the right arrow is pressed, then the object will be translated in the x axis by 10. (moving right)
	{
		if (speedUp && (gameTime > stopSpeed))
		{
			speX += 50;
			addSpeX = 50;
		}
		else
		{
			speX += 10;
			addSpeX = 10;
		}
		rotAngle = 0;
		scaleX = 1;
		scaleY = 1;
	}
	if (k == GLUT_KEY_LEFT)//if the left arrow is pressed, then the object will be translated in the x axis by -10. (moving left)
	{
		if (speedUp && (gameTime > stopSpeed))
		{
			speX -= 50;
			addSpeX = -50;
		}
		else
		{
			speX -= 10;
			addSpeX = -10;
		}
		rotAngle = 0;
		scaleX = -1;
		scaleY = 1;
	}
	if (k == GLUT_KEY_UP)//if the up arrow is pressed, then the object will be translated in the y axis by 10. (moving upwords)
	{
		if (speedUp && (gameTime > stopSpeed))
		{
			speY += 50;
			addSpeY = 50;
		}
		else
		{
			speY += 10;
			addSpeY = 10;
		}
		rotAngle = 90;
		scaleX = 1;
		scaleY = 1;
	}
	if (k == GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -10. (moving downwords)
	{
		if (speedUp && (gameTime > stopSpeed))
		{
			speY -= 50;
			addSpeY = -50;
		}
		else
		{
			speY -= 10;
			addSpeY = -10;
		}
		rotAngle = 90;
		scaleX = -1;
		scaleY = 1;
	}
	if (speX - 50 <= 10) {
		speX = 70;
		if (!win)
			lives -= 1;
	}
	if (speX + 50 >= 990) {
		speX = 930;
		if (!win)
			lives -= 1;
	}
	if (speY - 50 <= 10) {
		speY = 70;
		if (!win)
			lives -= 1;
	}
	if (speY + 50 >= 590) {
		speY = 530;
		if (!win)
			lives -= 1;
	}
	if ((rotAngle == 0 && ((speX + 50 >= randXcoll1 - 20 && speX + 50 <= randXcoll1 + 20)
		|| (speX - 50 >= randXcoll1 - 20 && speX - 50 <= randXcoll1 + 20))
		&& ((speY + 10 >= randYcoll1 - 20 && speY + 10 <= randYcoll1 + 20)
			|| (speY - 10 >= randYcoll1 - 20 && speY - 10 <= randYcoll1 + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= randXcoll1 - 20 && speX + 10 <= randXcoll1 + 20)
			|| (speX - 10 >= randXcoll1 - 20 && speX - 10 <= randXcoll1 + 20))
			&& ((speY + 50 >= randYcoll1 - 20 && speY + 50 <= randYcoll1 + 20)
				|| (speY - 50 >= randYcoll1 - 20 && speY - 50 <= randYcoll1 + 20)))) {
		if (doublePoints && (gameTime > stopDoublePoints))
			score += 10;
		score += 10;
		randXcoll1 = -20;
		randYcoll1 = -20;
	}
	if ((rotAngle == 0 && ((speX + 50 >= randXcoll2 - 20 && speX + 50 <= randXcoll2 + 20)
		|| (speX - 50 >= randXcoll2 - 20 && speX - 50 <= randXcoll2 + 20))
		&& ((speY + 10 >= randYcoll2 - 20 && speY + 10 <= randYcoll2 + 20)
			|| (speY - 10 >= randYcoll2 - 20 && speY - 10 <= randYcoll2 + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= randXcoll2 - 20 && speX + 10 <= randXcoll2 + 20)
			|| (speX - 10 >= randXcoll2 - 20 && speX - 10 <= randXcoll2 + 20))
			&& ((speY + 50 >= randYcoll2 - 20 && speY + 50 <= randYcoll2 + 20)
				|| (speY - 50 >= randYcoll2 - 20 && speY - 50 <= randYcoll2 + 20)))) {
		if (doublePoints && (gameTime > stopDoublePoints))
			score += 10;
		score += 10;
		randXcoll2 = -20;
		randYcoll2 = -20;
	}
	if ((rotAngle == 0 && ((speX + 50 >= randXcoll3 - 20 && speX + 50 <= randXcoll3 + 20)
		|| (speX - 50 >= randXcoll3 - 20 && speX - 50 <= randXcoll3 + 20))
		&& ((speY + 10 >= randYcoll3 - 20 && speY + 10 <= randYcoll3 + 20)
			|| (speY - 10 >= randYcoll3 - 20 && speY - 10 <= randYcoll3 + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= randXcoll3 - 20 && speX + 10 <= randXcoll3 + 20)
			|| (speX - 10 >= randXcoll3 - 20 && speX - 10 <= randXcoll3 + 20))
			&& ((speY + 50 >= randYcoll3 - 20 && speY + 50 <= randYcoll3 + 20)
				|| (speY - 50 >= randYcoll3 - 20 && speY - 50 <= randYcoll3 + 20)))) {
		if (doublePoints && (gameTime > stopDoublePoints))
			score += 10;
		score += 10;
		randXcoll3 = -20;
		randYcoll3 = -20;
	}
	if ((rotAngle == 0 && ((speX + 50 >= randXcoll4 - 20 && speX + 50 <= randXcoll4 + 20)
		|| (speX - 50 >= randXcoll4 - 20 && speX - 50 <= randXcoll4 + 20))
		&& ((speY + 10 >= randYcoll4 - 20 && speY + 10 <= randYcoll4 + 20)
			|| (speY - 10 >= randYcoll4 - 20 && speY - 10 <= randYcoll4 + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= randXcoll4 - 20 && speX + 10 <= randXcoll4 + 20)
			|| (speX - 10 >= randXcoll4 - 20 && speX - 10 <= randXcoll4 + 20))
			&& ((speY + 50 >= randYcoll4 - 20 && speY + 50 <= randYcoll4 + 20)
				|| (speY - 50 >= randYcoll4 - 20 && speY - 50 <= randYcoll4 + 20)))) {
		if (doublePoints && (gameTime > stopDoublePoints))
			score += 10;
		score += 10;
		randXcoll4 = -20;
		randYcoll4 = -20;
	}
	if ((rotAngle == 0 && ((speX + 50 >= randXcoll5 - 20 && speX + 50 <= randXcoll5 + 20)
		|| (speX - 50 >= randXcoll5 - 20 && speX - 50 <= randXcoll5 + 20))
		&& ((speY + 10 >= randYcoll5 - 20 && speY + 10 <= randYcoll5 + 20)
			|| (speY - 10 >= randYcoll5 - 20 && speY - 10 <= randYcoll5 + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= randXcoll5 - 20 && speX + 10 <= randXcoll5 + 20)
			|| (speX - 10 >= randXcoll5 - 20 && speX - 10 <= randXcoll5 + 20))
			&& ((speY + 50 >= randYcoll5 - 20 && speY + 50 <= randYcoll5 + 20)
				|| (speY - 50 >= randYcoll5 - 20 && speY - 50 <= randYcoll5 + 20)))) {
		if (doublePoints && (gameTime > stopDoublePoints))
			score += 10;
		score += 10;
		randXcoll5 = -20;
		randYcoll5 = -20;
	}
	if ((rotAngle == 0 && ((speX + 50 >= ob1X - 20 && speX + 50 <= ob1X + 20)
		|| (speX - 50 >= ob1X - 20 && speX - 50 <= ob1X + 20))
		&& ((speY + 10 >= ob1Y - 20 && speY + 10 <= ob1Y + 20)
			|| (speY - 10 >= ob1Y - 20 && speY - 10 <= ob1Y + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= ob1X - 20 && speX + 10 <= ob1X + 20)
			|| (speX - 10 >= ob1X - 20 && speX - 10 <= ob1X + 20))
			&& ((speY + 50 >= ob1Y - 20 && speY + 50 <= ob1Y + 20)
				|| (speY - 50 >= ob1Y - 20 && speY - 50 <= ob1Y + 20)))) {
		lives -= 1;
		speX = speX - addSpeX;
		speY = speY - addSpeY;
	}
	if ((rotAngle == 0 && ((speX + 50 >= ob2X - 20 && speX + 50 <= ob2X + 20)
		|| (speX - 50 >= ob2X - 20 && speX - 50 <= ob2X + 20))
		&& ((speY + 10 >= ob2Y - 20 && speY + 10 <= ob2Y + 20)
			|| (speY - 10 >= ob2Y - 20 && speY - 10 <= ob2Y + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= ob2X - 20 && speX + 10 <= ob2X + 20)
			|| (speX - 10 >= ob2X - 20 && speX - 10 <= ob2X + 20))
			&& ((speY + 50 >= ob2Y - 20 && speY + 50 <= ob2Y + 20)
				|| (speY - 50 >= ob2Y - 20 && speY - 50 <= ob2Y + 20)))) {
		lives -= 1;
		speX = speX - addSpeX;
		speY = speY - addSpeY;
	}
	if ((rotAngle == 0 && ((speX + 50 >= ob3X - 20 && speX + 50 <= ob3X + 20)
		|| (speX - 50 >= ob3X - 20 && speX - 50 <= ob3X + 20))
		&& ((speY + 10 >= ob3Y - 20 && speY + 10 <= ob3Y + 20)
			|| (speY - 10 >= ob3Y - 20 && speY - 10 <= ob3Y + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= ob3X - 20 && speX + 10 <= ob3X + 20)
			|| (speX - 10 >= ob3X - 20 && speX - 10 <= ob3X + 20))
			&& ((speY + 50 >= ob3Y - 20 && speY + 50 <= ob3Y + 20)
				|| (speY - 50 >= ob3Y - 20 && speY - 50 <= ob3Y + 20)))) {
		lives -= 1;
		speX = speX - addSpeX;
		speY = speY - addSpeY;
	}
	if ((rotAngle == 0 && ((speX + 50 >= ob4X - 20 && speX + 50 <= ob4X + 20)
		|| (speX - 50 >= ob4X - 20 && speX - 50 <= ob4X + 20))
		&& ((speY + 10 >= ob4Y - 20 && speY + 10 <= ob4Y + 20)
			|| (speY - 10 >= ob4Y - 20 && speY - 10 <= ob4Y + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= ob4X - 20 && speX + 10 <= ob4X + 20)
			|| (speX - 10 >= ob4X - 20 && speX - 10 <= ob4X + 20))
			&& ((speY + 50 >= ob4Y - 20 && speY + 50 <= ob4Y + 20)
				|| (speY - 50 >= ob4Y - 20 && speY - 50 <= ob4Y + 20)))) {
		lives -= 1;
		speX = speX - addSpeX;
		speY = speY - addSpeY;
	}
	if ((rotAngle == 0 && ((speX + 50 >= ob5X - 20 && speX + 50 <= ob5X + 20)
		|| (speX - 50 >= ob5X - 20 && speX - 50 <= ob5X + 20))
		&& ((speY + 10 >= ob5Y - 20 && speY + 10 <= ob5Y + 20)
			|| (speY - 10 >= ob5Y - 20 && speY - 10 <= ob5Y + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= ob5X - 20 && speX + 10 <= ob5X + 20)
			|| (speX - 10 >= ob5X - 20 && speX - 10 <= ob5X + 20))
			&& ((speY + 50 >= ob5Y - 20 && speY + 50 <= ob5Y + 20)
				|| (speY - 50 >= ob5Y - 20 && speY - 50 <= ob5Y + 20)))) {
		lives -= 1;
		speX = speX - addSpeX;
		speY = speY - addSpeY;
	}
	if ((rotAngle == 0 && ((speX + 50 >= randXpow2 - 20 && speX + 50 <= randXpow2 + 20)
		|| (speX - 50 >= randXpow2 - 20 && speX - 50 <= randXpow2 + 20))
		&& ((speY + 10 >= randYpow2 - 20 && speY + 10 <= randYpow2 + 20)
			|| (speY - 10 >= randYpow2 - 20 && speY - 10 <= randYpow2 + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= randXpow2 - 20 && speX + 10 <= randXpow2 + 20)
			|| (speX - 10 >= randXpow2 - 20 && speX - 10 <= randXpow2 + 20))
			&& ((speY + 50 >= randYpow2 - 20 && speY + 50 <= randYpow2 + 20)
				|| (speY - 50 >= randYpow2 - 20 && speY - 50 <= randYpow2 + 20)))) {
		randXpow2 = -20;
		randYpow2 = -20;
		speedUp = true;
		stopSpeed = gameTime - 10;
		//stopSpeed = clock() + 20;
	}
	if ((rotAngle == 0 && ((speX + 50 >= randXpow1 - 20 && speX + 50 <= randXpow1 + 20)
		|| (speX - 50 >= randXpow1 - 20 && speX - 50 <= randXpow1 + 20))
		&& ((speY + 10 >= randYpow1 - 20 && speY + 10 <= randYpow1 + 20)
			|| (speY - 10 >= randYpow1 - 20 && speY - 10 <= randYpow1 + 20)))
		|| (rotAngle == 90 && ((speX + 10 >= randXpow1 - 20 && speX + 10 <= randXpow1 + 20)
			|| (speX - 10 >= randXpow1 - 20 && speX - 10 <= randXpow1 + 20))
			&& ((speY + 50 >= randYpow1 - 20 && speY + 50 <= randYpow1 + 20)
				|| (speY - 50 >= randYpow1 - 20 && speY - 50 <= randYpow1 + 20)))) {
		randXpow1 = -20;
		randYpow1 = -20;
		doublePoints = true;
		stopDoublePoints = gameTime - 10;
	}
	if (((!lose) && (rotAngle == 0) && ((speX + 50 >= 50 && speX + 50 <= 125)
		|| (speX - 50 >= 125 && speX - 50 <= 50))
		&& ((speY + 10 >= 25 && speY + 10 <= 175)
			|| (speY - 10 >= 25 && speY - 10 <= 175)))
		|| (rotAngle == 90 && ((speX + 10 >= 25 && speX + 10 <= 125)
			|| (speX - 10 >= 25 && speX - 10 <= 125))
			&& ((speY + 50 >= 25 && speY + 50 <= 175)
				|| (speY - 50 >= 25 && speY - 50 <= 175)))) {
		randXpow1 = -20;
		randYpow1 = -20;
		if (!lose)
		{
			glClearColor(0.0f, 0.0f, 0.1f, 0.0f);
			win = true;
		}
		goalPos = -200;
		ob1X = -300;
		ob1Y = -100;
		ob2X = -100;
		ob2Y = -300;
		ob3X = -500;
		ob3Y = -500;
		ob4X = -700;
		ob4Y = -200;
		ob5X = -800;
		ob5Y = -400;
		randXcoll1 = -100;
		randYcoll1 = -100;
		randXcoll2 = -100;
		randYcoll2 = -100;
		randXcoll3 = -100;
		randYcoll3 = -100;
		randXcoll4 = -100;
		randYcoll4 = -100;
		randXcoll5 = -100;
		randYcoll5 = -100;
		randXpow1 = -100;
		randYpow1 = -100;
		randXpow2 = -100;
		randYpow2 = -100;

	}
	if (lives == 0)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		lose = true;
		goalPos = -300;
		ob1X = -300;
		ob1Y = -100;
		ob2X = -100;
		ob2Y = -300;
		ob3X = -500;
		ob3Y = -500;
		ob4X = -700;
		ob4Y = -200;
		ob5X = -800;
		ob5Y = -400;
		randXcoll1 = -100;
		randYcoll1 = -100;
		randXcoll2 = -100;
		randYcoll2 = -100;
		randXcoll3 = -100;
		randYcoll3 = -100;
		randXcoll4 = -100;
		randYcoll4 = -100;
		randXcoll5 = -100;
		randYcoll5 = -100;
		randXpow1 = -100;
		randYpow1 = -100;
		randXpow2 = -100;
		randYpow2 = -100;
	}
	/*if (k == GLUT_KEY_F1)//if the F1 key is pressed, then the object color will be changed
		speC = 1;*/
	glutPostRedisplay();//redisplay to update the screen with the changes
}
void Timer(int value) {
	// set the ball's Y coordinate to a random number between 10 and 780 (since the window's height is 800)
	currTime++;
	gameTime--;
	if (gameTime == 0)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		lose = true;
		goalPos = -300;
		ob1X = -300;
		ob1Y = -100;
		ob2X = -100;
		ob2Y = -300;
		ob3X = -500;
		ob3Y = -500;
		ob4X = -700;
		ob4Y = -200;
		ob5X = -800;
		ob5Y = -400;
		randXcoll1 = -100;
		randYcoll1 = -100;
		randXcoll2 = -100;
		randYcoll2 = -100;
		randXcoll3 = -100;
		randYcoll3 = -100;
		randXcoll4 = -100;
		randYcoll4 = -100;
		randXcoll5 = -100;
		randYcoll5 = -100;
		randXpow1 = -100;
		randYpow1 = -100;
		randXpow2 = -100;
		randYpow2 = -100;
	}

	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(1 * 1000, Timer, 0);
}
void AnimWithTime(int value) {
	if (up)
	{
		up = false;
		animY = -5;
	}
	else {
		up = true;
		animY = 5;
	}
	glutTimerFunc(0.5 * 1000, AnimWithTime, 0);

}
void Anim()
{
	pointRotate++;
	glutPostRedisplay();
}
void main(int argc, char** argr) {
	glutInit(&argc, argr);

	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("CHEESE");
	glutDisplayFunc(Display);
	glutIdleFunc(Anim);
	srand(static_cast<unsigned int>(time(0)));

	randXcoll1 = rand() % 800 + 100;
	randYcoll1 = rand() % 400 + 100;
	randXcoll2 = rand() % 800 + 100;
	randYcoll2 = rand() % 400 + 100;
	randXcoll3 = rand() % 800 + 100;
	randYcoll3 = rand() % 400 + 100;
	randXcoll4 = rand() % 800 + 100;
	randYcoll4 = rand() % 400 + 100;
	randXcoll5 = rand() % 800 + 100;
	randYcoll5 = rand() % 400 + 100;

	randXpow1 = rand() % 800 + 100;
	randYpow1 = rand() % 400 + 100;
	randXpow2 = rand() % 800 + 100;
	randYpow2 = rand() % 400 + 100;

	glutTimerFunc(0, Timer, 0);
	glutTimerFunc(0, AnimWithTime, 0);
	glutSpecialFunc(spe);			//call the keyboard special keys function
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.8f, 1.0f, 0.8f, 0.0f);
	gluOrtho2D(0.0, 1000, 0.0, 600);


	glutMainLoop();
}
