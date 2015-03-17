#pragma once

#include <SFML/Graphics.hpp>

namespace mw
{
	

	/*
		Class that Contains the information of a Tile

		This class will contain information such as if the Tile is
			collidable and its position/size.

		Its copy constructor and operator will keep its position the same as before
		so if you want it to change its position, you will have to explicitly do so.
	*/
	class Tile : public sf::Drawable
	{
	public:
		Tile()
			: Collidable(false){}
		Tile(const sf::Texture& texture, bool isCollidable = false, sf::Vector2f position = sf::Vector2f(0,0))
			: Collidable(isCollidable)
		{
			mySprite.setTexture(texture);
			mySprite.setPosition(position.x, position.y);
		}
		Tile(const sf::Texture& texture, sf::IntRect section, bool isCollidable = false, sf::Vector2f position = sf::Vector2f(0,0))
			: Collidable(isCollidable)
		{
			mySprite.setTexture(texture);
			mySprite.setPosition(position.x, position.y);
			mySprite.setTextureRect(section);
		}

		~Tile(){}

		public:

		bool isCollidable() { return Collidable; }

		void SetPosition(float x, float y)	{ mySprite.setPosition(x, y);}

		sf::Vector2f const GetPosition()	{ return mySprite.getPosition(); }

		sf::Vector2f const GetSize()		{ return sf::Vector2f(mySprite.getGlobalBounds().width, mySprite.getGlobalBounds().height); }

		Tile& Tile::operator= (const Tile &me) 
		{ 
			// check for self-assignment by comparing the address of the
			// implicit object and the parameter
			if (this == &me)
				return *this;
 
			// do the copy
			sf::Vector2f tempPosition = mySprite.getPosition();
			Collidable = me.Collidable;
			mySprite = me.mySprite;
			mySprite.setPosition(tempPosition);
 
			// return the existing object
			return *this;
		}

		//Copy Constructor
		Tile(const Tile& me) {
			sf::Vector2f tempPosition = me.mySprite.getPosition();
			Collidable = me.Collidable;
			mySprite = me.mySprite;
			mySprite.setPosition(tempPosition); }

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(mySprite, states);
		}//needed to make drawable

	private:
		sf::Sprite mySprite;

		bool Collidable;
	};


}//end of namespace mw