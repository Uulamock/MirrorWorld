#pragma once

#include "GameObject.h"

namespace mw
{



/************************************************************
	Test GameObject

	- Used to test Physics, graphics, and other things
*************************************************************/

class TestPhysicsComponent : public PhysicsComponent
{
public:
	TestPhysicsComponent()
	{
		myMaxSpeed = 5;
		myAccelerationRate = 5;

		myAcceleration.x = 5;
	}
	virtual ~TestPhysicsComponent() {}

	virtual void receive(mw::Component::Message message); //found in Objects.cpp

	virtual void handleEvents(GameObject& object, mw::World& world, sf::RenderWindow& screen, mw::EventList& events); //found in Objects.cpp

	virtual void collide(){}
};

class TestGraphicsComponent : public GraphicsComponent
{
public:
	TestGraphicsComponent() {}
	virtual ~TestGraphicsComponent() {}

	virtual void handleEvents(GameObject& object, sf::RenderWindow& screen, mw::EventList& events);

	virtual void receive(mw::Component::Message message);
};

class TestInputComponent : public InputComponent 
{
public:
	TestInputComponent(){}
	virtual ~TestInputComponent(){}

	virtual void handleEvents(GameObject& object, sf::RenderWindow& screen, mw::EventList& events){}

	virtual void receive(mw::Component::Message message){}
};

static std::shared_ptr<mw::GameObject> createTestObject()
{
	TestPhysicsComponent *testers = new TestPhysicsComponent();
	std::shared_ptr<mw::TestInputComponent> input(new TestInputComponent());
	std::shared_ptr<mw::TestGraphicsComponent> graphics(new TestGraphicsComponent());
	std::shared_ptr<mw::TestPhysicsComponent> physics(new TestPhysicsComponent());
	std::shared_ptr<mw::GameObject> testObject(new GameObject(input, graphics, physics));
	//std::shared_ptr<mw::GameObject> testObject(new GameObject(std::make_shared<TestInputComponent>(), std::make_shared<TestGraphicsComponent>, std::make_shared<TestPhysicsComponent>()));

	return testObject;
}

//End of Test Object///////////////////////////////////////////////////////////////




}//end of namespace