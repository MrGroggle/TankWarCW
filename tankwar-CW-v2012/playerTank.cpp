#include "PlayerTank.h"
#include <iostream>
PlayerTank::PlayerTank() // Construtor
{
	clearMovement();
	turretLeft = false;
	turretRight = false;
	colour = sf::Color(0,0,255);
	numberOfShells = 15;
}

PlayerTank::~PlayerTank(){} // Destructor

void PlayerTank::reset(float newX, float newY, float newTh, float newTurretTh)
{
	pos.set(newX,newY,newTh);
	turretTh = newTurretTh;

	fireCounter = 0;
	updateBb();
}

void PlayerTank::move()
{	
	implementMove();
}

void PlayerTank::fire()
{
	// Set fire counter
	fireCounter = 12;
	// Decrement ammo
	numberOfShells--;
}