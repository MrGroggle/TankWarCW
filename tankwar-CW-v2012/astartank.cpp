#include "AStarTank.h"

AStarTank::AStarTank() // Construtor
{
	reset(0.0, 0.0, 0.0, 0.0); // Reset tank
	colour = sf::Color(237,28,36);
	numberOfShells = 15;
	stop();
	stopTurret();
	rotDir = 0;
	rotateDir = 0;
}

AStarTank::~AStarTank(){} // Destructor

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
	travel();

	implementMove(); // Do the move
}

bool AStarTank::avoid( Shell& ){
	return false;
}

bool AStarTank::attackEnemy( Tank& ){

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

	if( edgeSpotted == true )
	{
		if(rotateDir == 0 )
			rotateDir = rand() % 1 + 2;

		if( ( pos.getTh()/360 > 0.125 && pos.getTh()/360 <= 0.250 ) ||
			( pos.getTh()/360 > 0.375 && pos.getTh()/360 <= 0.500 ) || 
			( pos.getTh()/360 > 0.625 && pos.getTh()/360 <= 0.750 ) ||
			( pos.getTh()/360 < 0.875 && pos.getTh()/360 <= 0.999 ) )
		//if(rotateDir == 1 )
			goLeft();
		else goRight();

		edgeSpotted = false;
	} else {
		rotateDir = 0;
	}
	



	if( obstructed == true )
	{
		goBackward();
		pos.set( pos.getX() , pos.getY() , pos.getTh() + 90 );
		//turretTh += 90;
		//int rotAngle = rand() % 180 - 360;
		//if( rotAngle < 0 ){ goLeft(); turretGoLeft(); }
		//else
		//if( rotAngle >= 0 ){ goRight(); turretGoRight(); }


		//pos.set( pos.getX() , pos.getY() , pos.getTh() + 45 );
		

		obstructed = false;

	} else
	goForward();
	
	
	// turret rotation
	if( ( turretTh > pos.getTh() + 45 ) && rotDir ) rotDir = false;
	else
	if( ( turretTh <  pos.getTh() - 45 ) && !rotDir ) rotDir = true;
	if( rotDir ) turretGoRight(); else turretGoLeft();
	

}