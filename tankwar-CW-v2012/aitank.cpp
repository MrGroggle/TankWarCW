#include "AITank.h"

AITank::AITank() // Construtor
{
	reset(0.0, 0.0, 0.0, 0.0); // Reset tank
	colour = sf::Color(237,28,36);
	numberOfShells = 15;
	stop();
	stopTurret();
}

AITank::~AITank(){} // Destructor

void AITank::reset(float newX, float newY, float newTh, float newTurretTh)
{
	// Init conditions
	obstructed = false; // Tank has hit an obstacle/building/tank
	targetSpotted = false; // Spotted an enemy building
	enemySpotted = false; // Spotted the enemy
	baseSpotted = false; // Spotted the home base
	enemyBaseHit = false; // Enemy base hit
	enemyHit = false; // Enemy hit

	pos.set(newX,newY,newTh);  // Move to assigned position
	turretTh = newTurretTh;

	fireCounter = 0; // Reset fire counter
	updateBb();
}

void AITank::move() //  AI
{
	// Add AI code to control the tank
	/* use the following methods to get the tank to move:
	 goForward();
	 goBackward();
	 goLeft();
	 goRight();
	 turretGoLeft();
	 turretGoRight();
	 stop();
	 stopTurret();
	 */
	// You must leave in the line below or nothing will happen
	implementMove(); // Do the move
}

bool AITank::isFiring()
{
	return false;
	// Return true when firing a shell
}

void AITank::fire() // You shouldn't need to touch this, can alter the sense reset if you wish
{
	// Firing - called by game object when IsFiring returns true
	if(canFire())
	{
	  // Decrement ammo
	  numberOfShells--;
	  // Set firecounter
	  fireCounter = 12;
	  // Reset to senses
	  enemySpotted = false;
	  targetSpotted = false;
	}
	else
	{
	  // Reset the senses
	  enemySpotted = false;
	  targetSpotted = false;
	}
}





