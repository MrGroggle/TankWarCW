#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include "drawing.h"
#include "boundingBox.h"

class Obstacle
{
private:
	  sf::Color colour;
	  Drawing drawing; // drawing tool
	  float xComp, yComp;
	  void pointDist();
	  bool visible;
public:
      Obstacle(); // Construtor
	  Obstacle(float x1, float y1, float x2, float y2, sf::Color c); // Construtor
      ~Obstacle(); // Destructor
      void draw(int debugMode); // Draw obstacle
	  BoundingBox bb;
	  void setPoint(float x, float y){xComp = x;yComp = y;pointDist();}
	  bool operator<(const Obstacle &other) {return dist < other.dist;}
	  float dist;
	  void setVisible(){visible = true;}
	  bool isVisible(){return visible;}
};
#endif