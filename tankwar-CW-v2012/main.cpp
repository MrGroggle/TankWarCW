#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"


int main()
{
    // Create main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "Tankwar");
 
	// Create a game
	Game game;
	
    // Create a clock for measuring the time elapsed
    sf::Clock Clock1;
	
	//some openGl necessities
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, 800, 600, 0); 

    // Start game loop
    while (App.IsOpened())
    {
		float delay=Clock1.GetElapsedTime();
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
           
			// Key press
			if (Event.Type == sf::Event::KeyPressed)
			{
				if(Event.Key.Code == sf::Key::Escape)// Escape key : exit
				{App.Close();}
				else // Pass key press to game
				{game.keyPressed(Event.Key.Code);}
			}
			// Key released
			if (Event.Type == sf::Event::KeyReleased)
			{
				game.keyReleased(Event.Key.Code);
			}
		}	
        // Adjust the viewport when the window is resized
        if (Event.Type == sf::Event::Resized)
            glViewport(0, 0, Event.Size.Width, Event.Size.Height);
			

		// Play the game every 0.05 seconds
		if(delay>0.05 && !game.gameOver()) {
			game.play();
			Clock1.Reset();
		}

		// Clear the window
	    glClear(GL_COLOR_BUFFER_BIT);

		//Draw the game
		game.draw();

        // Finally, display the rendered frame on screen
        App.Display();
    }
  

    return EXIT_SUCCESS;

}
