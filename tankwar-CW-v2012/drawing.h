
#ifndef DRAWING_H
#define DRAWING_H
#include <SFML/Graphics.hpp>
#include "glut.h"

using namespace std;

class Drawing
{
private:
	float pi;
public:
	Drawing();
	void drawArc(float x, float y,float radius,float startAngle,float endAngle, int nSegments, float thickness,sf::Color colour);
	void drawFilledArc(float x, float y,float radius,float startAngle,float endAngle, int nSegments, sf::Color colour);
	void drawQuad(float x1, float y1, float x2, float y2, sf::Color colour);
	void drawLine(float x1, float y1, float x2, float y2, float thickness, sf::Color colour);
	void drawDot(float x, float y, float dotSize, sf::Color colour);
	void drawString(float x, float y,char * str, sf::Color colour);
	void drawTinyString(float x, float y,char * str, sf::Color colour);
};

#endif