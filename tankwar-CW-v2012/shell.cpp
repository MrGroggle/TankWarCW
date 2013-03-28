#include "shell.h"

Shell::Shell(position startPos) // Constructor
{
	pos.set(startPos.getX(), startPos.getY(), startPos.getTh());
	seeTank = false;
	seeAi = false;
	float x,y;
	x = pos.getX();
	y = pos.getY();
	updateBb();
}

void Shell::move() // Move Shell
{
	float moveConst = 5.5f;
	
	float x,y,th;
	x = pos.getX();
	y = pos.getY();
	th = pos.getTh();
	float thRad = DEG2RAD(th); // Heading in radians

	float dx = cos(thRad) * moveConst;
	float dy = sin(thRad) * moveConst;
	pos.set(x + dx, y + dy, th);

	updateBb();
}

void Shell::updateBb()
{
	float x,y;
	x = pos.getX();
	y = pos.getY();
	bb.set(x-7.0,y-7.0,x+7.0,y+7.0);
}

void Shell::draw(int debugMode) // Draw Shell
{
	glPushMatrix();
	glTranslatef(pos.getX(),pos.getY(),0);
	glRotatef(pos.getTh()-90.0,0.0,0.0,1.0);

	glColor3f(0.35, 0.35, 0.35);
	glBegin(GL_QUADS);
	glVertex2d(-3,6);
	glVertex2d(3,6);
	glVertex2d(3,-6);
	glVertex2d(-3,-6);
	glEnd();
	glPopMatrix();

	if(debugMode)bb.draw();
}

