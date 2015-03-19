/*
	Class that handles anything Button related.

	Its handleEvents() will automatically handle:
		- being highlighted
		- being clicked
		- special coloring affects
		- etc

	contains boolean to tell if the Button was pressed and will stay true
	until it is checked.  This presumes buttons should generally only need
	to be clicked once.
*/

/*
Button has animation.  Animation will normally just be stationary and pressed

Button has text on it, though not always. (some textures might already have text embedded on them)


*/

#pragma once

#include "Text.h"

namespace sf
{

namespace hud
{


class Button : public sf::hud::HudObject
{
public:
	//HubObject Functions:
	virtual void move(float x, float y)
	{
		setPosition(myPosition.x + x, myPosition.y + y);
	}

	virtual void setPosition(float x, float y)
	{
		myPosition.x = x;
		myPosition.y = y;
	}

	virtual void setColor(sf::Color color)
	{
		myColor = color;
	}

	virtual void rotate(double degrees)
	{
		myAngle += (-1 * degrees);
	}

	virtual void setAngle(double degrees)
	{
		myAngle = -1 * degrees;
	}

private:


private:
	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		
	}

}; //end of class




}//end of namespace hud

} //end of namespace sf