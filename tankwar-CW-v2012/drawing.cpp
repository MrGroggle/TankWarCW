#include "drawing.h"


Drawing::Drawing()
{
	pi = 3.1415; // Approx value for pi
}

/* 
Generic function for drawing an arc

x - x value of the centre of the arc
y - y value of the centre of the arc
radius - radius of the arc
startAngle - the start angle of the arc in radians
endAngle - the end angle of the arc in radians
nSegments - the number segments that make up the arc
thickness - thickness of the arc line in pixels
colour - colour of the arc

Draws nSegments lines each made up of two consectutive points in the arc  
*/

void Drawing::drawArc(float x, float y,float radius,float startAngle,float endAngle, int nSegments, float thickness, sf::Color colour)
{
	int i = 0; // counter
	float deltaAngle = (endAngle - startAngle) / float(nSegments); // change in angle (radians) per segment
	float currentAngle = startAngle; // Initialise the angle
	float x1 = 0, y1 = 0, x2 = 0, y2 = 0; // co-ords for the two other point in each triangle

	glColor3f((float)colour.r/255.0, (float)colour.g/255.0, (float)colour.b/255.0); // Set drawing colour
	glLineWidth(thickness); // Set line thickness
	glBegin(GL_LINE_STRIP); // Draw connected straight lines
	for(i=0;i<nSegments;i++)
	{
      x1 = cos(currentAngle)*radius + x; // Calculate the first point in the arc
      y1 = sin(currentAngle)*radius + y;
      
      currentAngle = currentAngle + deltaAngle; // Increment the point in the arc
      x2 = cos(currentAngle)*radius + x; // Calculate the second point in the arc
      y2 = sin(currentAngle)*radius + y;
      
      glVertex3f( x1, y1, 0.0f); // draw the line
      glVertex3f( x2, y2, 0.0f);
    }
	glEnd(); // Stop drawing
}

/* 
Generic function for drawing a filled arc

x - x value of the centre of the arc
y - y value of the centre of the arc
radius - radius of the arc
startAngle - the start angle of the arc in radians
endAngle - the end angle of the arc in radians
nSegments - the number segments that make up the arc
colour - colour of the arc

Draws nSegments triangles each made up of the centre of the 
arc and two consectutive points in the arc  
*/
void Drawing::drawFilledArc(float x, float y,float radius,float startAngle,float endAngle, int nSegments, sf::Color colour)
{
	int i = 0; // counter
	float deltaAngle = (endAngle - startAngle) / float(nSegments); // change in angle (radians) per segment
	float currentAngle = startAngle; // Initialise the angle
	float x1 = 0, y1 = 0, x2 = 0, y2 = 0; // co-ords for the two other point in each triangle

	glColor3f((float)colour.r/255.0, (float)colour.g/255.0, (float)colour.b/255.0); // Set drawing colour
	for(i=0;i<nSegments;i++)
	{
      x1 = cos(currentAngle)*radius + x; // Calculate the first point in the arc
      y1 = sin(currentAngle)*radius + y;
      
      currentAngle = currentAngle + deltaAngle; // Increment the point in the arc
      x2 = cos(currentAngle)*radius + x; // Calculate the second point in the arc
      y2 = sin(currentAngle)*radius + y;
      
      glBegin(GL_TRIANGLES); // Draw the triangle 
      glVertex3f( x, y, 0.0f);
      glVertex3f( x1, y1, 0.0f);
      glVertex3f( x2, y2, 0.0f);
      glEnd(); // Stop drawing
    }
}

/* 
Generic function for drawing a filled quad

x1 - x value of the top left point in the quad
y1 - y value of the top left point in the quad
x2 - x value of the bottom right point in the quad
y2 - y value of the bottom right point in the quad
colour - colour of the quad

Draws a quad made up of four points; (x1,y1), (x2,y1), (x2,y2) and (x1,y2)
*/
void Drawing::drawQuad(float x1, float y1, float x2, float y2, sf::Color colour)
{
	glColor3f((float)colour.r/255.0, (float)colour.g/255.0, (float)colour.b/255.0);
	glBegin(GL_QUADS);
	glVertex2d(x1,y1);
	glVertex2d(x2,y1);
	glVertex2d(x2,y2);
	glVertex2d(x1,y2);
	glEnd();
}

/* 
Generic function for drawing a line

x1 - x value of the first point in the line
y1 - y value of the first point in the line
x2 - x value of the second point in the line
y2 - y value of the second right point in the line
thickness - thickness of the line in pixels
colour - colour of the line

Draws a lines made up of two points
*/
void Drawing::drawLine(float x1, float y1, float x2, float y2, float thickness, sf::Color colour)
{
	glColor3f((float)colour.r/255.0, (float)colour.g/255.0, (float)colour.b/255.0);
	glLineWidth(thickness);
	glBegin(GL_LINES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glEnd();
}

/* 
Generic function for drawing a dot

x - x value of the dot
y - y value of the dot
dotSize - size of the size in pixels
colour - colour of the dot

Draws a dot at (x,y)
*/
void Drawing::drawDot(float x, float y, float dotSize, sf::Color colour)
{
	glPointSize(dotSize);
	glColor3f((float)colour.r/255.0, (float)colour.g/255.0, (float)colour.b/255.0);
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}

/* 
Generic function for drawing a string

x - x position of the string
y - y position of the stringt
str - C string of text
colour - colour of the drawn text

Draws text at (x,y)
*/
void Drawing::drawString(float x, float y,char * str, sf::Color colour)
{
	glColor3f((float)colour.r/255.0, (float)colour.g/255.0, (float)colour.b/255.0);
	glRasterPos2f(x, y);

	int len = strlen(str);
	for (int i = 0;i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)str[i]);
	}
}


/* 
Generic function for drawing a small string

x - x position of the string
y - y position of the stringt
str - C string of text
colour - colour of the drawn text

Draws text at (x,y)
*/
void Drawing::drawTinyString(float x, float y,char * str, sf::Color colour)
{
	glColor3f((float)colour.r/255.0, (float)colour.g/255.0, (float)colour.b/255.0);
	glRasterPos2f(x, y);

	int len = strlen(str);
	for (int i = 0;i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int)str[i]);
	}
}