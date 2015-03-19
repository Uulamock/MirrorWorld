/*

Class that handles animations in game

	-contains array (vector) of sprites that are run through whenever time reaches its tick.
	-Can manually move through each animation or can call update which will automatically update animation.

*/

#pragma once

#include <SFML/Graphics.hpp>

namespace mw
{


class Animation : public sf::Drawable
{
public:
	Animation()
	{
		myAnimationIndex = 0;
		myTick = 250;
	}
	Animation(double tick)
	{
		myAnimationIndex = 0;
		myTick = tick;
	}
	~Animation(){}

	//Use this method in loop and it will automatically update animation
	void update()
	{
		if(myClock.getElapsedTime().asMilliseconds() > myTick)
		{
			myAnimationIndex++;
			myClock.restart();
			if(myAnimationIndex >= mySprites.size())
			{
				myAnimationIndex = 0;
			}
		}
	}

	void next()
	{
		myAnimationIndex++;
		myClock.restart();
		if(myAnimationIndex >= mySprites.size())
		{
			myAnimationIndex = 0;
		}
	}

	void addAnimation(sf::Sprite newAnimation)
	{
		mySprites.push_back(newAnimation);
	}

private:
	std::vector<sf::Sprite> mySprites;

	sf::Clock myClock;

	double myTick;

	int myAnimationIndex;

private:
	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(mySprites[myAnimationIndex], states);
	}

};//end of class


}//end of namespace mw