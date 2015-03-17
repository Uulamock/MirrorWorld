/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Contains the base class of each branch of component
//
// All classes here are abstract
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Component.h"

namespace mw
{
	//Needed for parameters
		class GameObject;
		class World;
	///////////////////////
	
	class InputComponent : public mw::Component
	{
	public:
		virtual void handleEvents(GameObject& object, sf::RenderWindow& screen, mw::EventList& events) = 0;

		InputComponent() {}
		virtual ~InputComponent() {}

	}; //end of InputComponent class

	///////////////////////////////////////////////////////////////////////////////////

	class PhysicsComponent : public mw::Component
	{
	public:
		virtual void handleEvents(GameObject& object, mw::World& world, sf::RenderWindow& screen, mw::EventList& events) = 0;

		PhysicsComponent()
		{
			
		}
		virtual ~PhysicsComponent() {}

		// Mutator/Accessor methods

		void setAccelerationRate(float acceleration)	{ myAccelerationRate = acceleration; }
		void setMaxSpeed(float speed)					{ myMaxSpeed = speed; }

		float getAccelerationRate() { return myAccelerationRate; }
		float getMaxSpeed()			{ return myMaxSpeed; }

		/*
			Method that is called when objects collide

			The child class will override this method since everything collides slightly differently
		*/
		virtual void collide() = 0;

	protected:
		
		//Mathmatical functions for easier readability and debugging.

		/*
			Method that will update the object to its proper location based on its values
			and apply acceleration and other stats

			- It will do the basic math to update the objects position.  Anything extra
			  such as outside forces like wind or enhanced gravity not included
		*/
		void updatePosition(GameObject& object);

		/*
			Method that will check basic collision with this object to the world.
		*/
		void basicCollision(GameObject& object, World& world);

	protected:

		//Basic variables needed for physics

		//Single values are used to help determin vectors
		float myMaxSpeed;			 //used to limit acceleration race on velocity.
		float myAccelerationRate;	 //Used to determine how fast acceleration should be.

		//Vectors that affect object movement
		sf::Vector2f myVelocity;	 //Used to determine how far to move object
		sf::Vector2f myAcceleration; //Used to determine how much to increase velocity by.


	}; //end of InputComponent class


	///////////////////////////////////////////////////////////////////////////////////

	class GraphicsComponent : public mw::Component
	{
	public:
		virtual void handleEvents(GameObject& object, sf::RenderWindow& screen, mw::EventList& events) = 0;

		GraphicsComponent() {}
		virtual ~GraphicsComponent() {}

	}; //end of InputComponent class

}//end of namespace