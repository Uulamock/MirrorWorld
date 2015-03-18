//////////////////////////////////////////////////////////////////////////////////////////
// Director: Alex Downer
// Programmers: Alex Downer, Jeremy Downer
// Art: Mikayla Downer
// Music: David Downer
//
// Level design: Jeremy Downer with edits from everyone else
//
// Days edited:
//				Alex - 10/27/14
//				Alex - 11/8/14
//				Alex - 11/12/14
//				Alex - 11/20/14
//				Alex - 11/22/14
//				Alex - 11/29/14
//				Alex - 12/1/14
//				Alex - 12/10/14
//				Alex - 12/11/14
//				Alex - 12/18/14
//				Alex - 1/2/15
//				Alex - 1/20/15
//				Alex - 2/6/15
//
// Last edited: Alex - 2/6/15
//
// Mirror World: 
//	- A puzzle game where the world can flip at the users will
//	- There will be objects that the user can interact with:
//		- Flippable objects
//			- ball
//			- lever
//			- button
//			- etc
//		- Non-flippable objects
//			- ball
//			- weights
//			- etc
//
//	- Gameplay problems that must be solved:
//		- How to flip?
//		- How to render if the world is allowed to flip?
//			- ex: What if the player will get stuck in a wall if flipped?
//////////////////////////////////////////////////////////////////////////////////////////

/*
	Development note (11/8/14):

	main() method will handle the Menues.  As in, the start screen and level selection stuff.
	
	How to handle levels? ->
		1) have a World class that contains the tiles and GameObjects
		2) have premade tile layouts so all you have to do is have the tile map
			vector point to the current area you want it to be
		3) have an array of GameObjects and have a handleEvents() method for World class.
		4) Find a way to set up GameObjects for each level.
		5) The map is seperate from GameObjects, therefore you can check collision
			between the two.
	
	Develop Specific GameObjects after the World class has been developed.
*/

#include <iostream>
#include "Menus.h"
#include "World.h"


int main() 
{
	// Set up screen //////////////////////////////////////////////////////////////////////////////////////

		sf::RenderWindow screen;
		screen.create(sf::VideoMode(800, 600), "Mirror World", sf::Style::Close);

		//screen.setKeyRepeatEnabled(false); // Prevents key getting pressed over and over when held

		screen.setVerticalSyncEnabled(1);	 // Setting max framerate to 60 (Facultative)
		screen.setFramerateLimit(60);		 // Setting max framerate to 60 (Facultative)

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	//The World that you play on, contains the information of tiles, objects, the player, etc.
	mw::World world = mw::World1();
	mw::Menus::currentMenu = mw::Menus::Menu::MAIN_MENU;

	//Holds every event that happened so other components and run through them
	mw::EventList eventList;

	//Run game
	while(screen.isOpen())
	{
		//handle events
		sf::Event events;
		while(screen.pollEvent(events))
		{
			//Add the event to the list
			eventList.push_back(events);

			if (events.type == sf::Event::Closed)
			{
                screen.close();
			}

			mw::Input::Keyboard::checkInput(events);
		}

		

		// Run Object events here /////////////////
		

		///////////////////////////////////////////

		//Display Screen and draw images here
			screen.clear(sf::Color(155, 155, 255, 255));
		
			screen.setView(screen.getDefaultView());

			//If the main game is being played now....
			if(mw::Menus::currentMenu == mw::Menus::Menu::GAMEPLAY)
			{
				world.handleEvents(screen, eventList);

			} //otherwise we are in the menus...
			else
			{
				//Menus event handlers also draw to screen
				mw::Menus::handleMenuEvents(screen, eventList);
			}

			screen.display();
		//Done Displaying Screen

		//Clear The event list for speed and cleanliness
		eventList.clear();
	}

	return 0;
}
