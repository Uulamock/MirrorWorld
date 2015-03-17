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

#pragma once

#include "Text.h"

namespace sf
{

namespace hud
{



class Button : public sf::Drawable
{
public:
	Button()
	: SHADE_DEFAULT(0, 0, 0, 0),
	SHADE_HIGHLIGHTED(255, 255, 255, 100),
	SHADE_HELD_DOWN(0, 0, 0, 100)
	{
		myIsPressed = false;
		myIsSelected = false;
	}
	~Button() {}

	//Important Function
	//Run this in the main loop to handle button effects/events
	//(12/1/14 - needs color code added)
	void handleEvents(sf::RenderWindow& screen, mw::EventList& events) 
	{
		//Handle "When-It-Happens" events

		for(int i = 0; i < events.size(); i++)
		{
			//if a mouse button was pressed...
			if(events[i].type == sf::Event::MouseButtonPressed)
			{
				//if it was the left mouse button...
				if(events[i].mouseButton.button == sf::Mouse::Left)
				{
					//If the mouse is on the button...
					if(sf::Mouse::getPosition(screen).x > myButton.getPosition().x && sf::Mouse::getPosition(screen).x < myButton.getPosition().x + myButton.getGlobalBounds().width &&
						sf::Mouse::getPosition(screen).y > myButton.getPosition().y && sf::Mouse::getPosition(screen).y < myButton.getPosition().y + myButton.getGlobalBounds().height)
					{
						//Then that means the button has been selected
						myIsSelected = true;
					}
				}
			}

			//if a mouse button was released...
			if(events[i].type == sf::Event::MouseButtonReleased)
			{
				if(events[i].mouseButton.button == sf::Mouse::Left)
				{
					//If the mouse is on the button...
					if(sf::Mouse::getPosition(screen).x > myButton.getPosition().x && sf::Mouse::getPosition(screen).x < myButton.getPosition().x + myButton.getGlobalBounds().width &&
						sf::Mouse::getPosition(screen).y > myButton.getPosition().y && sf::Mouse::getPosition(screen).y < myButton.getPosition().y + myButton.getGlobalBounds().height)
					{
						//Then that means the button has been pressed and is no longer selected
						if(myIsSelected)
						{
							myIsSelected = false;
							myIsPressed = true;
						}
					}

					//nothing is selected anymore...
					myIsSelected = false;
				}
			}
		}

		// Handle "Real-Time" events
		
		//If the mouse is on the button...
		if(sf::Mouse::getPosition(screen).x > myButton.getPosition().x && sf::Mouse::getPosition(screen).x < myButton.getPosition().x + myButton.getGlobalBounds().width &&
			sf::Mouse::getPosition(screen).y > myButton.getPosition().y && sf::Mouse::getPosition(screen).y < myButton.getPosition().y + myButton.getGlobalBounds().height)
		{
			//Then that means it is being highlighted

			//If it is selected, color should be darker to imply being pressed, otherwise highlight it normally
			if(myIsSelected == false)
			{
				//highlight normally
				myShade.setFillColor(SHADE_HIGHLIGHTED);
			}
			else
			{
				//highlight darker
				myShade.setFillColor(SHADE_HELD_DOWN);
			}
		}
		else
		{
			//The button should return be set to its normal colors.
			myShade.setFillColor(SHADE_DEFAULT);
		}

	}//end of HandleEvents()

	//Accessor methods

	/*
		returns if the button has been pressed
		when called, if true, it will set value back to false
	*/
	bool isPressed()
	{
		//If it is pressed, then set value to false and return true
		if(myIsPressed)
		{
			myIsPressed = false;
			return true;
		}
		else
			return myIsPressed;
	}

	//Returns value used to check if user clicked button, but didn't release
	bool isSelected() { return myIsSelected; }

	//returns the buttons location
	sf::Vector2f getPosition() { return myButton.getPosition(); }

	float getWidth() { return myButton.getGlobalBounds().width; }
	float getHeight() { return myButton.getGlobalBounds().height; }


	//Mutator methods

	//Sets the position of the button and properly alligns anything else
	void setPosition(float x, float y)
	{
		myButton.setPosition(x, y);
		myShade.setPosition(x, y);
	}

	void setTexture(const sf::Texture& texture)
	{
		myButton.setTexture(texture);
		
		//once given a texture, the button has a size, so set the shade to that size.
		myShade.setSize(sf::Vector2f(myButton.getGlobalBounds().width, myButton.getGlobalBounds().height));
	}

	//special mutator methods

	/*
		Method that moves Text by the given amount for x and y
	*/
	void move(float x, float y)
	{
		setPosition(this->myButton.getPosition().x + x, this->myButton.getPosition().y + y);
	}

private:
	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(myButton, states);
		target.draw(myShade, states);
	}

private:

	//To check if this button has been pressed
	//(ex: mouse pressed over button and was released over button)
	bool myIsPressed;
	
	//Checks if the button was pressed, but not released
	//When mouse button is released, this MUST be false.
	bool myIsSelected;

	//To make special highlighted affects.
	sf::RectangleShape myShade;

	//Constant colors for highlighting
	sf::Color const SHADE_HIGHLIGHTED;
	sf::Color const SHADE_HELD_DOWN;
	sf::Color const SHADE_DEFAULT;

	//Contains the image of the button.
	sf::Sprite myButton;



}; //end of class Button



}//end of namespace hud

} //end of namespace sf