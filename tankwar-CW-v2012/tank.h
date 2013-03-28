#ifndef TANK_H
#define TANK_H

#define moveConst 3.5 // Total amount of movement allowed each timestep
#define rotMoveConst 2.5 // Total amount of rotational movement allowed each timestep for the tank
#define turRotMoveConst 1.5 // Total amount of rotational movement allowed each timestep for the turrent

#include "drawing.h"
#include "position.h"
#include "boundingBox.h"

class Tank
{
protected:
	  position pos, oldPos;
	  float turretTh;
	  Drawing drawing; // Drawing tool
	  bool forward, backward, left, right, turretLeft, turretRight;
	  void implementMove(); // Move tank
	  void clearMovement();
	  void updateBb();
	  sf::Color colour;
	  int numberOfShells;
	  short fireCounter; // Game tick counter for firing
public:
	  BoundingBox bb; // BB for collision detection
      void draw(int debugMode); // Draw Tank
	  	  // Movement methods
	  void goForward();
	  void goBackward();
	  void goLeft();
	  void goRight();
	  void turretGoLeft();
	  void turretGoRight();
	  void stop(){clearMovement();}
	  void stopTurret();
	  void markPos(){oldPos = pos;}
	  void recallPos(){pos = oldPos;updateBb();}

	  virtual void fire() = 0; // Implemented in child classes
	  virtual void move() = 0; // Implemented in child classes

	  position firingPosition();
	  float getX(){return pos.getX();}
	  float getY(){return pos.getY();}
	  int getNumberOfShells(){return numberOfShells;}
	  bool canSee(BoundingBox other);
	  bool canFire(){return numberOfShells > 0 && fireCounter == 0;}
	  bool hasAmmo(){return numberOfShells > 0;}
	  
};
#endif