////////////////////////////////////////////////////////////////
// Contains basic information that needs to be shared with
// several other files.
////////////////////////////////////////////////////////////////
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "ConstructorTexture.h"
#include "Tile.h"

namespace mw
{
	typedef std::vector<sf::Event> EventList;

	//Namespace that contains booleans that check if keys are currently held
	namespace Input
	{
		namespace Keyboard
		{

			static bool leftArrow = false;
			static bool rightArrow = false;
			static bool upArrow = false;
			static bool downArrow = false;
			static bool w = false;
			static bool a = false;
			static bool s = false;
			static bool d = false;
			static bool space = false;

			static void checkInput(sf::Event events)
			{
				if (events.type == sf::Event::KeyPressed)
				{
					if(events.key.code == sf::Keyboard::Up)
					{
						upArrow = true;
					}
					else if(events.key.code == sf::Keyboard::Down)
					{
						downArrow = true;
					}
					else if(events.key.code == sf::Keyboard::Left)
					{
						leftArrow = true;
					}
					else if(events.key.code == sf::Keyboard::Right)
					{
						rightArrow = true;
					}
					else if(events.key.code == sf::Keyboard::W)
					{
						w = true;
					}
					else if(events.key.code == sf::Keyboard::A)
					{
						a = true;
					}
					else if(events.key.code == sf::Keyboard::S)
					{
						s = true;
					}
					else if(events.key.code == sf::Keyboard::D)
					{
						d = true;
					}
					else if(events.key.code == sf::Keyboard::Space)
					{
						space = true;
					}
				}
			}

		}//end of namespace Keyboard

	}//end of namespace Input

	//Namespace that contains constant math values such as gravity, screen size, etc
	namespace Math
	{

		namespace World
		{

			//Constant gravity for ALL objects
			static const sf::Vector2f GRAVITY(0, 5);		 //Used to apply Gravity

		}//end of namespace World

	}//end of namespace Math


	//Namespace that will contain all the constant textures
	namespace Texture
	{

		//To easily edit the file locations 
		static const std::string FILE_LOCATION = "C:/Users/Uulamock.Alex-PC/Pictures/TempGameArt/MirrorWorld/";

		namespace World
		{
			//Load textures that apply to the map here
			static const mw::Texture::ConstructorTexture TEXTURE_TILES(FILE_LOCATION + "tiles.png");

			//Basic tiles to easily and quickly transform tiles.
			static const mw::Tile TILE_BASIC_GRASS(TEXTURE_TILES, sf::IntRect(0, 0, 32, 32), true);
			static const mw::Tile TILE_BASIC_METAL(TEXTURE_TILES, sf::IntRect(32, 0, 32, 32), true);

		}//end of namespace World

		namespace hud
		{
			
			//constant textures
			static const mw::Texture::ConstructorTexture TEXTURE_TEXT(FILE_LOCATION + "text.png");

		}//end of namespace hud

	} //end of namespace Textures


}//end of namespace mw