#ifndef GAME_H
#define GAME_H

#include "aitank.h"
#include "astartank.h"
#include "playerTank.h"
#include "obstacle.h"
#include "shell.h"
#include "drawing.h"
#include <list>

class Game
{
	private:
		unsigned short lives; // number of lives left
		short debugMode; // toggle for debug mode
		Drawing drawing; // drawing tool
		list<Obstacle> obstacles; // Obstacles in the tanks way
		list<Obstacle> blueBuildings;
		list<Obstacle> redBuildings;
		list<Shell> shells; // Shells fired from tanks
		void resetNpc();
		void resetPlayer();
		void fireShell(position fp, bool npc);
		int redScore; // Score of red tank
		int blueScore; // Score of blue tank
    public:
		Game(); // Constructor
		~Game(); // Destructor
		void draw(); // Draw the game
		void play(); // Play the game for one timestep
		AStarTank npc; // Red tank
		PlayerTank player; // Blue tank
		void keyPressed(sf::Key::Code key); // function for processing input
		void keyReleased(sf::Key::Code key); // function for processing input
		bool gameOver();
		int numBlueBuildings();
		int numRedBuildings();
};
#endif