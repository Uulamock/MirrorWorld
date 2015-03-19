/*////////////////////////////////////////////////////////////////////////////

	Contains the functions that will run the menus.

////////////////////////////////////////////////////////////////////////////*/

#pragma once

#include "Text.h"
#include "Button.h"

namespace mw
{

	namespace Menus
	{

		//Note that GAMEPLAY means that the menus are no longer running.
		enum class Menu { GAMEPLAY = -1, MAIN_MENU = 0, HELP_MENU,  };

		Menu currentMenu = Menu::MAIN_MENU;

		namespace Explicit
		{
			void handleMainMenuEvents(sf::RenderWindow& screen, mw::EventList& events);
		} //end of namespace Explicit

		/*
			These functions also draw to screen.
		*/
		void handleMenuEvents(sf::RenderWindow& screen, mw::EventList& events)
		{
			//Make seperate functions that handle the events for a specific menu
			switch (currentMenu)
			{
			case Menu::MAIN_MENU :
				Explicit::handleMainMenuEvents(screen, events);
				break;
			case Menu::HELP_MENU :
				break;
			}
		}

		namespace Explicit
		{
			//Namespace Explicit for specific inner functions
			//These functions should normally not be called outside of file
			//	but may be if neccessary

			//Handles the MAIN_MENU events and draws it to screen.
			void handleMainMenuEvents(sf::RenderWindow& screen, mw::EventList& events)
			{
				//Object delcarations//////////////////////////////////////////
				//Declare all objects here//
					sf::hud::Text txtMainMenu;
					txtMainMenu.setFontSize(50);
					txtMainMenu = "ABC\ncba";
					txtMainMenu.setPosition(200, 200);
					txtMainMenu.setAngle(45);
					//txtMainMenu.setPosition(screen.getSize().x /2 - txtMainMenu.getWidth() / 2, 32);

					sf::hud::Button btnStart;
					btnStart.setTexture(mw::Texture::hud::TEXTURE_TEXT);
					btnStart.setPosition(300, 300);
				///////////////////////////////////////////////////////////////

				//Handle Events here///////////////////////////////////////////
					btnStart.handleEvents(screen, events);

					if(btnStart.isPressed())
					{
						//what do if btn is pressed?
					}
				///////////////////////////////////////////////////////////////

				//Draw everything to screen here///////////////////////////////
					screen.draw(txtMainMenu);
					screen.draw(btnStart);
				///////////////////////////////////////////////////////////////
				
			}

			void handleHelpMenuEvents(sf::RenderWindow& screen, mw::EventList& events)
			{
				
			}

		} //end of namespace explicit

	} //end of namespace menus

} //end of namespace mw