#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "drawing.h"

class BoundingBox
{
private:
	  float x1,x2,y1,y2;
	  Drawing drawing; // drawing tool
public:
      BoundingBox(); // Construtor
      ~BoundingBox(); // Destructor
      void draw(); // Draw BB
	  void set(float xa, float ya, float xb, float yb);
	  float getX1(){return x1;}
	  float getY1(){return y1;}
	  float getX2(){return x2;}
	  float getY2(){return y2;}
	  float getXc(){return (x1 + x2) / 2.0;}
	  float getYc(){return (y1 + y2) / 2.0;}
	  bool collision(BoundingBox otherBb);
	  bool lineCollision(float x1, float y1, float x2, float y2);
};
#endif