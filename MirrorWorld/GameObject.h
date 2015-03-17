/////////////////////////////////////////////////////////////////////////////////////////
// The most basic/used class in the entire program
//
// This is what every object in the game will be.
// Every player, enemy, interactable, etc will be a GameObject
/////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <memory>
#include "BasicComponents.h"

namespace mw
{
	
	class GameObject
	{
	public:

		//Method the runs all the components handleEvents() method
		//Be sure to keep them in the proper order.
		void handleEvents(mw::World& world, sf::RenderWindow& screen, mw::EventList& events) 
		{
			myInput->handleEvents(*this, screen, events);
			myPhysics->handleEvents(*this, world, screen, events);
			myGraphics->handleEvents(*this, screen, events);
		}

		// Constructors / Destructor
		GameObject() {}
		GameObject(std::shared_ptr<InputComponent> input,
				std::shared_ptr<GraphicsComponent> graphics,
				std::shared_ptr<PhysicsComponent> physics )
		:	myInput(input),
			myGraphics(graphics),
			myPhysics(physics)
		{myPosition.x = 0;
		myPosition.y = 0;}
		virtual ~GameObject() {}

	private:
		//Components
		std::shared_ptr<mw::InputComponent> myInput;
		std::shared_ptr<mw::PhysicsComponent> myPhysics;
		std::shared_ptr<mw::GraphicsComponent> myGraphics;

		//Variables that should be available to more than just 1 component
		sf::Vector2f myPosition;
		sf::Vector2f mySize;

		//Physics elements (declared here because they must be accessable outside of object)
		sf::Vector2f myVelocity;
		sf::Vector2f myAcceloration;

	public:
		//Sends message to other components
		void sendMessage(mw::Component::Message message)
		{
			if(myInput != NULL)
			{
				myInput->receive(message);
			}

			if(myGraphics != NULL)
			{
				myGraphics->receive(message);
			}

			if(myPhysics != NULL)
			{
				myPhysics->receive(message);
			}
		}

		//Basic Accessor/Mutator methods
		void setPosition(float x, float y)	{ myPosition.x = x; myPosition.y = y; }
		void setSize(float x, float y)		{ mySize.x = x; mySize.y = y; }

		sf::Vector2f const getPosition()	{ return myPosition; }
		sf::Vector2f const getSize()		{ return mySize; }

		void move(float x, float y)			{ setPosition(getPosition().x + x, getPosition().y + y); }

	};

}//end of namespace