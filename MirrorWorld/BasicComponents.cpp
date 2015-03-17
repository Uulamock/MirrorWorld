#pragma once

#include "GameObject.h"
#include "World.h"


void mw::PhysicsComponent::updatePosition(mw::GameObject& object)
{
	myVelocity += myAcceleration + mw::Math::World::GRAVITY;

	//Apply Friction (note: only to X-axis since gravity only affects Y-axis)
	//myVelocity.x *= myFrictionRate;

	object.move(myVelocity.x, myVelocity.y);
}