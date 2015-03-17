///////////////////////////////////////////////////////////////////////////////////////////
// Abstract base class for all components.
//
// contains the virtual function receive() which makes the component receive a 
// message.  The Child class will determine what to do with it though.
//
///////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "MW.h"

namespace mw
{

class Component
{
public:
	//Any type of message that might be sent
	enum class Message { COLLISION = 0, MOVING_LEFT, MOVING_RIGHT, STOPPED };

	//Method that gets a message from another component and the child class
	//determines what to do with the message here.
	virtual void receive(mw::Component::Message message) {}

	Component() {}
	virtual ~Component() {}
protected:

};//end of class


} //end of namespace mw