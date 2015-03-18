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

	static enum class LetterValue { UNKNOWN = -1, A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
									ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO, QUESTION_MARK, EXCLAMATION_MARK,
									PERIOD, COMMA};

	static int convertCharToLetterValue(char letter)
	{
		int value = (int)LetterValue::UNKNOWN;

		if(letter == 'a' || letter == 'A')
		{
			value = (int)LetterValue::A;
		}
		else if(letter == 'b' || letter == 'B')
		{
			value = (int)LetterValue::B;
		}
		else if(letter == 'c' || letter == 'C')
		{
			value = (int)LetterValue::C;
		}
		else if(letter == 'd' || letter == 'D')
		{
			value = (int)LetterValue::D;
		}
		else if(letter == 'e' || letter == 'E')
		{
			value = (int)LetterValue::E;
		}
		else if(letter == 'f' || letter == 'F')
		{
			value = (int)LetterValue::F;
		}
		else if(letter == 'g' || letter == 'G')
		{
			value = (int)LetterValue::G;
		}
		else if(letter == 'h' || letter == 'H')
		{
			value = (int)LetterValue::H;
		}
		else if(letter == 'i' || letter == 'I')
		{
			value = (int)LetterValue::I;
		}
		else if(letter == 'j' || letter == 'J')
		{
			value = (int)LetterValue::J;
		}
		else if(letter == 'k' || letter == 'K')
		{
			value = (int)LetterValue::K;
		}
		else if(letter == 'l' || letter == 'L')
		{
			value = (int)LetterValue::L;
		}
		else if(letter == 'm' || letter == 'M')
		{
			value = (int)LetterValue::M;
		}
		else if(letter == 'n' || letter == 'N')
		{
			value = (int)LetterValue::N;
		}
		else if(letter == 'o' || letter == 'O')
		{
			value = (int)LetterValue::O;
		}
		else if(letter == 'p' || letter == 'P')
		{
			value = (int)LetterValue::P;
		}
		else if(letter == 'q' || letter == 'Q')
		{
			value = (int)LetterValue::Q;
		}
		else if(letter == 'r' || letter == 'R')
		{
			value = (int)LetterValue::R;
		}
		else if(letter == 's' || letter == 'S')
		{
			value = (int)LetterValue::S;
		}
		else if(letter == 't' || letter == 'T')
		{
			value = (int)LetterValue::T;
		}
		else if(letter == 'u' || letter == 'U')
		{
			value = (int)LetterValue::U;
		}
		else if(letter == 'v' || letter == 'V')
		{
			value = (int)LetterValue::V;
		}
		else if(letter == 'w' || letter == 'W')
		{
			value = (int)LetterValue::W;
		}
		else if(letter == 'x' || letter == 'X')
		{
			value = (int)LetterValue::X;
		}
		else if(letter == 'y' || letter == 'Y')
		{
			value = (int)LetterValue::Y;
		}
		else if(letter == 'z' || letter == 'Z')
		{
			value = (int)LetterValue::Z;
		}
		else if(letter == '1')
		{
			value = (int)LetterValue::ONE;
		}
		else if(letter == '2')
		{
			value = (int)LetterValue::TWO;
		}
		else if(letter == '3')
		{
			value = (int)LetterValue::THREE;
		}
		else if(letter == '4')
		{
			value = (int)LetterValue::FOUR;
		}
		else if(letter == '5')
		{
			value = (int)LetterValue::FIVE;
		}
		else if(letter == '6')
		{
			value = (int)LetterValue::SIX;
		}
		else if(letter == '7')
		{
			value = (int)LetterValue::SEVEN;
		}
		else if(letter == '8')
		{
			value = (int)LetterValue::EIGHT;
		}
		else if(letter == '9')
		{
			value = (int)LetterValue::NINE;
		}
		else if(letter == '0')
		{
			value = (int)LetterValue::ZERO;
		}
		else if(letter == '?')
		{
			value = (int)LetterValue::QUESTION_MARK;
		}
		else if(letter == '!')
		{
			value = (int)LetterValue::EXCLAMATION_MARK;
		}
		else if(letter == '.')
		{
			value = (int)LetterValue::PERIOD;
		}
		else if(letter == ',')
		{
			value = (int)LetterValue::COMMA;
		}

		return value;
	}

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

		static const double PI = 3.1415926;

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
		static const std::string FILE_LOCATION = "C:/MirrorWorldFiles/Textures/";

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