#include "Tank.h"
#include <iostream>

// Can the tank see the bounding box
bool Tank::canSee(BoundingBox other)
{

	float dx = other.getXc() - bb.getXc();
	float dy = other.getYc() - bb.getYc();
	float dist = sqrt( dx * dx + dy * dy );

	if(dist > 250.0) return false;
	if(dist < 120.0) return true;

	float angle = atan2(dy, dx);
	
	float thRad = DEG2RAD(turretTh);
	if(thRad > PI){thRad = thRad - 2.0 * PI;}
	float diff = angle - thRad;

	return fabs(diff) < 0.4;
}

// Position where the shell leaves the tank
position Tank::firingPosition()
{
	position fp;

	float thRad = DEG2RAD(turretTh);
	float fireX = cos(thRad) * 40.0 + pos.getX();
	float fireY = sin(thRad) * 40.0 + pos.getY();

	fp.set(fireX, fireY, turretTh);
	return fp;
}

void Tank::updateBb()
{
	float x,y;
	x = pos.getX();
	y = pos.getY();
	bb.set(x-28.0,y-28.0,x+28.0,y+28.0);
}

void Tank::implementMove()
{
	float x,y,th;
	x = pos.getX();
	y = pos.getY();
	th = pos.getTh();
	float thRad = DEG2RAD(th); // Heading in radians

	if(forward)
	{
		float dx = cos(thRad) * moveConst;
		float dy = sin(thRad) * moveConst;
		pos.set(x + dx, y + dy, th);
	}

	if(backward)
	{
		float dx = cos(thRad) * moveConst;
		float dy = sin(thRad) * moveConst;
		pos.set(x - dx, y - dy, th);
	}

    if(left)
	{
		float newTh = th-rotMoveConst;
		if(newTh < 0){newTh += 360.0;}
		pos.set(x, y, newTh);

		newTh = turretTh-rotMoveConst;
		if(newTh < 0){newTh += 360.0;}
		turretTh = newTh;
	}

	if(right)
	{
		float newTh = th+rotMoveConst;
		if(newTh > 360.0){newTh -= 360.0;}
		pos.set(x, y, newTh);

		newTh = turretTh+rotMoveConst;
		if(newTh > 360.0){newTh -= 360.0;}
		turretTh = newTh;
	}

	if(turretLeft)
	{
		float newTh = turretTh - turRotMoveConst;
		if(newTh < 0.0){newTh += 360.0;}
		turretTh = newTh;
	}

	if(turretRight)
	{
		float newTh = turretTh + turRotMoveConst;
		if(newTh > 360.0){newTh -= 360.0;}
		turretTh = newTh;
	}
	updateBb(); // Update the bounding box
	// Decrement fire counter
	if(fireCounter > 0) fireCounter--;
}

void Tank::clearMovement()
{
	forward = false;
	backward = false;
	left = false;
	right = false;
}

void Tank::goForward()
{
	clearMovement();
	forward = true;
}

void Tank::goBackward()
{
	clearMovement();
	backward = true;
}

void Tank::goLeft()
{
	clearMovement();
	left = true;
}

void Tank::goRight()
{
	clearMovement();
	right = true;
}

void Tank::turretGoLeft()
{
	turretLeft = true;
	turretRight = false;
}

void Tank::turretGoRight()
{
	turretLeft = false;
	turretRight = true;
}

void Tank::stopTurret()
{
	turretLeft = false;
	turretRight = false;
}

void Tank::draw(int debugMode) // Draw Tank
{
	if(debugMode)
	{
		float startAngle = (turretTh * (PI/180)) -0.4;
		float endAngle = (turretTh * (PI/180)) +0.4;
		sf::Color fovColour(127,127,127);
		float radius = 250.0;

		drawing.drawArc(pos.getX(), 
						pos.getY(), 
						radius,
						startAngle,
						endAngle,
						60,
						2.0,
						fovColour);

		drawing.drawLine(pos.getX(), pos.getY(), (cos(startAngle)*radius)+pos.getX(), (sin(startAngle)*radius)+pos.getY(), 2, fovColour);
		drawing.drawLine(pos.getX(), pos.getY(), (cos(endAngle)*radius)+pos.getX(), (sin(endAngle)*radius)+pos.getY(), 2, fovColour);
	}

	glPushMatrix();
	glTranslatef(pos.getX(),pos.getY(),0);
	glRotatef(pos.getTh()-90.0,0.0,0.0,1.0);

	// Main body
	glColor3f((float)colour.r / 255.0, (float)colour.g / 255.0, (float)colour.b / 255.0);
	glBegin(GL_QUADS);
	glVertex2d(-16,24);
	glVertex2d(16,24);
	glVertex2d(16,-24);
	glVertex2d(-16,-24);
	glEnd();

	// Left track
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(-24,22);
	glVertex2d(-17,22);
	glVertex2d(-17,-22);
	glVertex2d(-24,-22);
	glEnd();

	// Right track
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(24,22);
	glVertex2d(17,22);
	glVertex2d(17,-22);
	glVertex2d(24,-22);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pos.getX(),pos.getY(),0);
	glRotatef(turretTh-90.0,0.0,0.0,1.0);
	// Turret
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(-4,10);
	glVertex2d(4,10);
	glVertex2d(4,50);
	glVertex2d(-4,50);
	glEnd();

	glPopMatrix();

	drawing.drawArc(pos.getX(),pos.getY(),10.0,0,6.28,60,3.0,sf::Color(0,0,0));

	if(debugMode)bb.draw();
}




