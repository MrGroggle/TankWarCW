#ifndef ASTARTANK_H
#define ASTARTANK_H

#include <iostream>
#include "tank.h"

class AStarTank:public Tank
{
private:
	  // Conditions to help decision making
	  bool obstructed; // Tank has hit an obstacle/building/tank
	  bool targetSpotted; // Spotted an enemy building
	  bool enemySpotted; // Spotted the enemy
	  bool baseSpotted; // Spotted the home base
	  bool enemyBaseHit; // Enemy base hit - not implemented
	  bool enemyHit; // Enemy hit - not implemented
	  // Positional memory
	  float targetX, targetY;
	  float enemyX, enemyY;
	  float baseX, baseY;
   public:
      AStarTank(); // Construtor
      ~AStarTank(); // Destructor
	  // Reset tank position and other variables
	  void reset(float newX, float newY, float newTh, float newTurretTh);
	  // Functions to set information for the AI  
	  void collided(){obstructed = true;}
	  void markTarget(float x, float y){targetSpotted = true;targetX = x;targetY = y;}
	  void markEnemy(float x, float y){enemySpotted = true;enemyX = x;enemyY = y;}
	  void markBase(float x, float y){baseSpotted = true;baseX = x;baseY = y;}
	  // Modifiy the implementation of this so it returns true when you fire a shell
	  bool isFiring();

	  void fire(); // Fire shell - called by game object

	  // Empty function to put AI in
	  void move(); 
};
#endif