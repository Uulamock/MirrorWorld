/*
	
	Class that will be the parent for any HudObject.

	This class will contain the basic functions that every HudObject should have
	
	Such as:
		-movement
		-transformations
		-color changes
		-etc
*/

#pragma once

#include "MW.h"

namespace sf 
{

namespace hud
{


class HudObject : public sf::Drawable
{
public:

	//constructor/destructor
	HudObject()
	{
		myPosition.x = 0;
		myPosition.y = 0;

		myAngle = 0;

		myColor = sf::Color(255, 255, 255, 255);
	}
	~HudObject(){}


public:
	//Common functions to be adapted by their children

	/*
		This function allows the object to move.
		I will move by x over and y up/down
	*/
	virtual void move(float x, float y) = 0;

	/*
		This function sets the position of the object.
	*/
	virtual void setPosition(float x, float y) = 0;

	/*
		This function sets the color of the object.
	*/
	virtual void setColor(sf::Color color) = 0;

	/*
		This function rotates the object.
	*/
	virtual void rotate(double degrees) = 0;

	/*
		This function sets the angle
	*/
	virtual void setAngle(double degrees) = 0;

private:
	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{

	}

public:

	sf::Vector2f getPosition()	{ return myPosition; }
	
	double getAngle()			{ return myAngle; }

	sf::Color getColor()		{ return myColor; }


protected:
	sf::Vector2f myPosition;

	double myAngle;

	sf::Color myColor;
};


}//end of namespace

}//end of namespace