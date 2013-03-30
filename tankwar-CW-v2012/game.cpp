#include "game.h"


Game::Game() // Constructor
{
  // Seed pseudorandom num gen
  srand ( time(NULL) );

  // Set debug mode to off
  debugMode = 0;

  // Borders
  obstacles.push_back(Obstacle(0,0,10,580,sf::Color(100,100,100)));
  obstacles.push_back(Obstacle(0,0,800,10,sf::Color(100,100,100)));
  obstacles.push_back(Obstacle(0,570,800,580,sf::Color(100,100,100)));
  obstacles.push_back(Obstacle(790,0,800,580,sf::Color(100,100,100)));

  int dx, dy;
  // Top right
  dx = rand() % 340 + 400;
  dy = rand() % 200 + 10;

  redBuildings.push_back(Obstacle(dx,dy,dx+20,dy+20,sf::Color(170,60,60)));
  redBuildings.push_back(Obstacle(dx+20,dy,dx+40,dy+20,sf::Color(170,40,40)));
  redBuildings.push_back(Obstacle(dx,dy+20,dx+20,dy+40,sf::Color(170,40,40)));
  redBuildings.push_back(Obstacle(dx+20,dy+20,dx+40,dy+40,sf::Color(170,60,60)));
  redBuildings.push_back(Obstacle(dx,dy+40,dx+20,dy+60,sf::Color(170,60,60)));
  redBuildings.push_back(Obstacle(dx+20,dy+40,dx+40,dy+60,sf::Color(170,40,40)));

  // Bottom right
  dx = rand() % 340 + 400;
  dy = rand() % 200 + 280;

  redBuildings.push_back(Obstacle(dx,dy,dx+20,dy+20,sf::Color(170,60,60)));
  redBuildings.push_back(Obstacle(dx+20,dy,dx+40,dy+20,sf::Color(170,40,40)));
  redBuildings.push_back(Obstacle(dx,dy+20,dx+20,dy+40,sf::Color(170,40,40)));
  redBuildings.push_back(Obstacle(dx+20,dy+20,dx+40,dy+40,sf::Color(170,60,60)));

    // Top left
  dx = rand() % 340 + 10;
  dy = rand() % 200 + 10;

  blueBuildings.push_back(Obstacle(dx,dy,dx+20,dy+20,sf::Color(60,60,170)));
  blueBuildings.push_back(Obstacle(dx+20,dy,dx+40,dy+20,sf::Color(40,40,170)));
  blueBuildings.push_back(Obstacle(dx,dy+20,dx+20,dy+40,sf::Color(40,40,170)));
  blueBuildings.push_back(Obstacle(dx+20,dy+20,dx+40,dy+40,sf::Color(60,60,170)));

  // Bottom left
  dx = rand() % 340 + 10;
  dy = rand() % 200 + 280;

  blueBuildings.push_back(Obstacle(dx,dy,dx+20,dy+20,sf::Color(60,60,170)));
  blueBuildings.push_back(Obstacle(dx+20,dy,dx+40,dy+20,sf::Color(40,40,170)));
  blueBuildings.push_back(Obstacle(dx,dy+20,dx+20,dy+40,sf::Color(40,40,170)));
  blueBuildings.push_back(Obstacle(dx+20,dy+20,dx+40,dy+40,sf::Color(60,60,170)));
  blueBuildings.push_back(Obstacle(dx,dy+40,dx+20,dy+60,sf::Color(60,60,170)));
  blueBuildings.push_back(Obstacle(dx+20,dy+40,dx+40,dy+60,sf::Color(40,40,170)));

  resetNpc();
  resetPlayer();

  redScore = 0;
  blueScore = 0;
}

Game::~Game(){}  // Destructor

// Set a random position which does not collide with anything
void Game::resetNpc()
{
	bool collision = true;
	while(collision)
	{
		float x = rand() % 360 + 400;
		float y = rand() % 580 + 10;
		float th = rand() % 359;
		float tth = th;
		npc.reset(x,y,th,tth);

		collision = false;
		for (list<Obstacle>::iterator it = obstacles.begin(); it != obstacles.end(); it++)
		{
			if(npc.bb.collision(it->bb))
			{
				collision = true;
				break;
			}
		}
		for (list<Obstacle>::iterator it = blueBuildings.begin(); it != blueBuildings.end(); it++)
		{
			if(npc.bb.collision(it->bb))
			{
				collision = true;
				break;
			}
		}
		for (list<Obstacle>::iterator it = redBuildings.begin(); it != redBuildings.end(); it++)
		{
			if(npc.bb.collision(it->bb))
			{
				collision = true;
				break;
			}
		}
		if(npc.bb.collision(player.bb)) collision = true;
	}
}

// Set a random position which does not collide with anything
void Game::resetPlayer()
{
	bool collision = true;
	while(collision)
	{
		float x = rand() % 380 + 10;
		float y = rand() % 580 + 10;
		float th = rand() % 359;
		float tth = th;
		player.reset(x,y,th,tth);

		collision = false;
		for (list<Obstacle>::iterator it = obstacles.begin(); it != obstacles.end(); it++)
		{
			if(player.bb.collision(it->bb))
			{
				collision = true;
				break;
			}
		}
		for (list<Obstacle>::iterator it = blueBuildings.begin(); it != blueBuildings.end(); it++)
		{
			if(player.bb.collision(it->bb))
			{
				collision = true;
				break;
			}
		}
		for (list<Obstacle>::iterator it = redBuildings.begin(); it != redBuildings.end(); it++)
		{
			if(player.bb.collision(it->bb))
			{
				collision = true;
				break;
			}
		}
		if(player.bb.collision(npc.bb)) collision = true;
	}
}

void Game::play()// Play the game for one timestep
{
	// Move tank
	player.markPos();
	player.move();

	// Check for collisions
	bool collision = false;
	for (list<Obstacle>::iterator it = obstacles.begin(); it != obstacles.end(); it++)
	{
		if(player.bb.collision(it->bb))
		{
			collision = true;
			break;
		}
	}
	for (list<Obstacle>::iterator it = blueBuildings.begin(); it != blueBuildings.end(); it++)
	{
		if(player.bb.collision(it->bb))
		{
			collision = true;
			break;
		}
	}
	for (list<Obstacle>::iterator it = redBuildings.begin(); it != redBuildings.end(); it++)
	{
		if(player.bb.collision(it->bb))
		{
			collision = true;
			break;
		}
	}
	if(player.bb.collision(npc.bb)) collision = true;

	if(collision)player.recallPos();


	// Move AI tank
	//**************************************************************************************************************
	//**************************************************************************************************************
	//**************************************************************************************************************
	// HERERERE
	//**************************************************************************************************************
	//**************************************************************************************************************
	//**************************************************************************************************************
	for (list<Obstacle>::iterator it = obstacles.begin(); it != obstacles.end(); it++)
	{
		if(npc.canSee( it->bb ) )
		{
			npc.markEdge( it->bb.getXc() , it->bb.getYc() );
		}
	}
	for (list<Obstacle>::iterator it = redBuildings.begin(); it != redBuildings.end(); it++)
	{
		if(npc.canSee( it->bb ) )
		{
			npc.markEdge( it->bb.getXc() , it->bb.getYc() );
		}
	}

	npc.markPos();
	npc.move();
	if(npc.isFiring()){fireShell(npc.firingPosition(), true);}

	// Check for collisions
	collision = false;
	for (list<Obstacle>::iterator it = obstacles.begin(); it != obstacles.end(); it++)
	{
		if(npc.bb.collision(it->bb))
		{
			collision = true;
			break;
		}
	}
	for (list<Obstacle>::iterator it = blueBuildings.begin(); it != blueBuildings.end(); it++)
	{
		if(npc.bb.collision(it->bb))
		{
			collision = true;
			break;
		}
	}
	for (list<Obstacle>::iterator it = redBuildings.begin(); it != redBuildings.end(); it++)
	{
		if(npc.bb.collision(it->bb))
		{
			collision = true;
			break;
		}
	}
	if(npc.bb.collision(player.bb)) collision = true;

	if(collision)
	{
		npc.recallPos();
		npc.collided();
	}

	// Check if AI Tank can see anything
    for (list<Obstacle>::iterator it = redBuildings.begin(); it != redBuildings.end(); it++)
    {
	  if(npc.canSee(it->bb)) npc.markBase((it->bb.getX1() + it->bb.getX2()) / 2.0, (it->bb.getY1() + it->bb.getY2()) / 2.0);
    }
    for (list<Obstacle>::iterator it = blueBuildings.begin(); it != blueBuildings.end(); it++)
    {
	  if(npc.canSee(it->bb)) npc.markTarget((it->bb.getX1() + it->bb.getX2()) / 2.0, (it->bb.getY1() + it->bb.getY2()) / 2.0);
    }
    if(npc.canSee(player.bb)) npc.markEnemy((player.bb.getX1() + player.bb.getX2()) / 2.0, (player.bb.getY1() + player.bb.getY2()) / 2.0 );

	// Move shells
	for (list<Shell>::iterator it = shells.begin(); it != shells.end(); it++){it->move();}

	// Check if shells have hit anything

	// Have shells hit edges
	for (list<Obstacle>::iterator it = obstacles.begin(); it != obstacles.end(); it++)
	{
		for (list<Shell>::iterator it2 = shells.begin(); it2 != shells.end(); it2++)
	    {
		  if(it->bb.collision(it2->bb))
		  {
			shells.erase(it2);
			break;
		  }
		}
	}

	// Have shells hit red buildings
	bool stop = false;
	list<Obstacle>::iterator it = redBuildings.begin();
	while (!(stop || it == redBuildings.end()))
	{
		
		list<Shell>::iterator it2 = shells.begin();
		while(!(stop || it2 == shells.end()))
		{
			if(it->bb.collision(it2->bb))
			{
				shells.erase(it2);
				redBuildings.erase(it);
				blueScore += 10;
				stop = true;
			}
			else it2++;
		}
		
		if(!stop)it++;
	}

	// Have shells hit blue buildings
	stop = false;
	it = blueBuildings.begin();
	while (!(stop || it == blueBuildings.end()))
	{

		list<Shell>::iterator it2 = shells.begin();
		while(!(stop || it2 == shells.end()))
		{
			if(it->bb.collision(it2->bb))
			{
				shells.erase(it2);
				blueBuildings.erase(it);
				redScore += 10;
				stop = true;
			}
			else it2++;
		}

		if(!stop)it++;
	}

	// Have shells hit red tank
	stop = false;
	list<Shell>::iterator it2 = shells.begin();
	while(!(stop || it2 == shells.end()))
	{
		if(it2->canSeeAi() && npc.bb.collision(it2->bb))
		{
			shells.erase(it2);
			resetNpc();
			blueScore += 25;
			stop = true;
		}
		else it2++;
	}


	// Have shells hit BLUE tank
	stop = false;

	it2 = shells.begin();
	while(!(stop || it2 == shells.end()))
	{
		if(it2->canSeeTank() && player.bb.collision(it2->bb))
		{
			shells.erase(it2);
			resetPlayer();
			redScore += 25;
			stop = true;
		}
		else it2++;
	}
	

}

void Game::fireShell(position fp, bool isNpc)
{
   position shellPos = fp;
   Shell newShell(fp);
   bool ai = false;
   bool tank = false;
  // Sort out opposition visibility
   if(isNpc)
   {
		if(npc.canSee(player.bb))
		{
			tank = true;
		}
   }
   else
   {
	   if(player.canSee(npc.bb))
		{
			ai = true;
		}
   }
   newShell.setOppositionVisability(tank,ai);
   shells.push_back(newShell);
}

void Game::draw()// Draw the game
{
  drawing.drawQuad(10, 10, 790, 580, sf::Color(40,70,20));

  // Draw shells
  for (list<Shell>::iterator it = shells.begin(); it != shells.end(); it++)
  {
	  it->draw(debugMode);
  }

  // Draw obstacles
  for (list<Obstacle>::iterator it = obstacles.begin(); it != obstacles.end(); it++) it->draw(debugMode);
  for (list<Obstacle>::iterator it = redBuildings.begin(); it != redBuildings.end(); it++)
  {
	  if(player.canSee(it->bb)) it->setVisible();
	  if(debugMode || it->isVisible()) it->draw(debugMode);
  }
  for (list<Obstacle>::iterator it = blueBuildings.begin(); it != blueBuildings.end(); it++)
  {
	  if(player.canSee(it->bb)) it->setVisible();
	  if(debugMode || it->isVisible()) it->draw(debugMode);
  }

   // Draw ammo area
  drawing.drawQuad(0, 580, 800, 600, sf::Color(140,90,60));

  // Draw AITank
  if(debugMode || player.canSee(npc.bb)) npc.draw(debugMode);

  // Draw Player
  player.draw(debugMode);

  // Draw ammo
  for(int i=0;i<player.getNumberOfShells();i++)
  {
	drawing.drawQuad(i*15+10, 585, (i+1)*15, 595, sf::Color(0,0,255));
  }

  for(int i=0;i<npc.getNumberOfShells();i++)
  {
	drawing.drawQuad(790-i*15, 585, 800-(i+1)*15, 595, sf::Color(255,0,0));
  }

  // Draw scores
  char msg[255];
  sprintf(msg,"%d", blueScore);
  drawing.drawString(250, 597, msg, sf::Color(255,255,255));

  sprintf(msg,"%d", redScore);
  drawing.drawString(550, 597, msg, sf::Color(255,255,255));

  // Draw game over
  if(gameOver())
  {
	  drawing.drawString(320, 140, "GAME OVER", sf::Color(255,255,255));
	  if(redScore > blueScore) drawing.drawString(320, 240, "RED WINS!", sf::Color(255,255,255));
	  if(redScore < blueScore) drawing.drawString(320, 240, "BLUE WINS!", sf::Color(255,255,255));
	  if(redScore == blueScore) drawing.drawString(320, 240, "MATCH DRAWN", sf::Color(255,255,255));
  }

}
     
void Game::keyPressed(sf::Key::Code key)
{
	switch(key)
	{
	   case	sf::Key::Tab :
		   if(debugMode) {debugMode = 0;}else{debugMode = 1;}
		   break;
	   case  sf::Key::W : 
		   player.goForward();
		   break;
	   case  sf::Key::A : 
		   player.goLeft();
		   break;
	   case  sf::Key::S : 
		   player.goBackward();
		   break;
	   case  sf::Key::D : 
		   player.goRight();
		   break;
	   case	sf::Key::Space :
		   if(player.canFire())
		   {
			player.fire();
			fireShell(player.firingPosition(), false);
		   }
		   break;
	   case  sf::Key::Left:
		   player.turretGoLeft();
		   break;
	   case  sf::Key::Right:
		   player.turretGoRight();
		   break;
	}
}

void Game::keyReleased(sf::Key::Code key)
{
	switch(key)
	{
	   case  sf::Key::W : 
		   player.stop();
		   break;
	   case  sf::Key::A : 
		   player.stop();
		   break;
	   case  sf::Key::S : 
		   player.stop();
		   break;
	   case  sf::Key::D : 
		   player.stop();
		   break;
	   case  sf::Key::Left:
		   player.stopTurret();
		   break;
	   case  sf::Key::Right:
		   player.stopTurret();
		   break;
	}
}

bool Game::gameOver()
{
	return numBlueBuildings() == 0 || numRedBuildings() == 0 || !(player.hasAmmo() || npc.hasAmmo());
}

int Game::numBlueBuildings()
{
	return blueBuildings.size();
}

int Game::numRedBuildings()
{
	return redBuildings.size();
}