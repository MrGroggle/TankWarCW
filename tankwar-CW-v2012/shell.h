#ifndef SHELL_H
#define SHELL_H

#include "drawing.h"
#include "position.h"
#include "boundingBox.h"

class Shell
{
protected:
	  position pos;
	  bool seeTank; // Could the AI see the player when the shell was fired?
	  bool seeAi; // Could the player see the AI when the shell was fired?
	  Drawing drawing; // Drawing tool
	  void updateBb();
public:
	  Shell(position pos);
	  BoundingBox bb; // BB for collision detection
      void draw(int debugMode); // Draw Shell
	  void move(); // Move Shell
	  float getX(){return pos.getX();}
	  float getY(){return pos.getY();}
	  void setOppositionVisability(bool tank, bool ai){seeTank = tank;seeAi = ai;};
	  bool canSeeTank(){return seeTank;}
	  bool canSeeAi(){return seeAi;}
};
#endif