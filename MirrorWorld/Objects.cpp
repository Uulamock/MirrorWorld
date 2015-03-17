#include "Objects.h"
#include "World.h"

void mw::TestPhysicsComponent::handleEvents(GameObject& object, mw::World& world, sf::RenderWindow& screen, mw::EventList& events)
{
	updatePosition(object);
	
}

void mw::TestPhysicsComponent::receive(mw::Component::Message message)
{
	switch (message)
	{
	case mw::Component::Message::MOVING_LEFT:
		myAcceleration.x = -5;
		break;
	case mw::Component::Message::MOVING_RIGHT:
		myAcceleration.x = 5;
		break;
	case mw::Component::Message::STOPPED:
		myAcceleration.x = 0;
		break;
	}
}

void mw::TestGraphicsComponent::handleEvents(GameObject& object, sf::RenderWindow& screen, mw::EventList& events){}

void mw::TestGraphicsComponent::receive(mw::Component::Message message){}