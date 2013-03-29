#include "AStarTank.h"

AStarTank::AStarTank() // Construtor
{
	reset(0.0, 0.0, 0.0, 0.0); // Reset tank
	colour = sf::Color(237,28,36);
	numberOfShells = 15;
	stop();
	stopTurret();
	rotDir = 0;
}

AStarTank::~AStarTank(){} // Destructor

void AStarTank::reset(float newX, float newY, float newTh, float newTurretTh)
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

void AStarTank::move() //  AI
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
	if( !avoid() )
		if( !attackEnemy() )
			if( !attackBuilding() )
				travel();

	implementMove(); // Do the move
}

bool AStarTank::isFiring()
{
	return false;
	// Return true when firing a shell
}

void AStarTank::fire() // You shouldn't need to touch this, can alter the sense reset if you wish
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

bool AStarTank::avoid( ){

	return false;
}

bool AStarTank::attackEnemy(){

	if( enemySpotted == true )
	{
		if( canFire() ) fire();
		enemySpotted = false;
		return true;
	} else return false;
}

bool AStarTank::attackBuilding(){
	if( baseSpotted == true )
	{
		if( canFire() ) fire();
		baseSpotted = false;

		return true;
	} else return false;

	return false;
}

void AStarTank::travel(){

	if( obstructed == true )
	{
		goBackward();
		pos.set( pos.getX() , pos.getY() , pos.getTh() + 90 );

		//int rotAngle = rand() % 180 - 360;
		//if( rotAngle < 0 ){ goLeft(); turretGoLeft(); }
		//else
		//if( rotAngle >= 0 ){ goRight(); turretGoRight(); }


		//pos.set( pos.getX() , pos.getY() , pos.getTh() + 45 );
		//turretTh += 45;

		obstructed = false;
	} else
	goForward();
	
	
	// turret rotation
	if( ( turretTh > pos.getTh() + 90 ) && rotDir ) rotDir = false;
	else
	if( ( turretTh <  pos.getTh() - 90 ) && !rotDir ) rotDir = true;
	if( rotDir ) turretGoRight(); else turretGoLeft();
	
}


