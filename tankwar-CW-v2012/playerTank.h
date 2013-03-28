#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include "tank.h"

class PlayerTank:public Tank
{
private:
	  //bool forward, backward, left, right, turretLeft, turretRight;
	 // void clearMovement();
public:
      PlayerTank(); // Construtor
      ~PlayerTank(); // Destructor
	  void reset(float newX, float newY, float newTh, float newTurretTh);

	  void move(); // Move tank
	  void fire(); // Fire shell
};
#endif