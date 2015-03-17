///////////////////////////////////////////////////////////////////////////////////////////
// Class that contains the world and its objects
//
// The tile map shall have premade maps, just set it to those to save run time.
///////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "MW.h"
#include "GameObject.h"

namespace mw
{
	
	//For cleaner readability.
	//typedef sf::Sprite Tile;

/*
	Class that containes all the Tiles and handles any Tiles related stuff.

	It is important to note that the ALL the tiles are stored in one, linear array.
	This means that each tile can have a completely random location and its place in
	the array has no meaning to the Tile's place on the map.
*/
class Map : public sf::Drawable
{
public:
	//Accessor methods/////////////////////////////////////////////

	//returns the number of existant Tiles.
	int getSize() { return myTiles.size(); }

	//returns the chosen tile.  If tile does not exist, return will be empty
	mw::Tile& getTile(int index)
	{
		if(index < myTiles.size())
		{
			return myTiles[index];
		}
	}

	//returns the last added tile in the array
	mw::Tile& getLastTile()
	{
		return myTiles[myTiles.size()-1];
	}


	//Mutator methods//////////////////////////////////////////////

	/*
		Method that sets specified tile to a certain tile type.
	*/
	void setTileTexture(int index, Tile tileType) { myTiles[index] = tileType; }

	//Adds a given tile to the tile array)
	void addTile(Tile tile)
	{
		myTiles.push_back(tile);
	}

	Map()  {}
	~Map() {}

private:
	//A list of Tiles (sf::Sprites that may change to a new animatable class)
	//Designed with an x, y array system.
	std::vector<mw::Tile> myTiles;

private:
	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for(int x = 0; x < myTiles.size(); x++)
		{
			target.draw(myTiles[x], states);
		}
	}

}; //end of Map class


///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//World is the base class that will turn into child classes based on which level is selected.

class World : public sf::Drawable
{
public:

	World() {}
	virtual ~World() {}

	//Handles all of the GameObject events by calling their handleEvents() method
	void handleEvents(sf::RenderWindow& screen, mw::EventList& events)
	{

		//std::cout<<"X: " << myMap.getLastTile().GetPosition().x << " Y: " << myMap.getLastTile().GetPosition().y <<std::endl;
		for(int i = myObjects.size()-1; i >= 0; i--)
		{
			myObjects[i]->handleEvents(*this, screen, events);
		}

		screen.draw(*this);
	}

	//Copy operator
	World& World::operator= (const World &me) 
		{ 
			// check for self-assignment by comparing the address of the
			// implicit object and the parameter
			if (this == &me)
				return *this;
 
			// do the copy
			myMap = me.myMap;
			myObjects = me.myObjects;
 
			// return the existing object
			return *this;
		}

		//Copy Constructor
		World(const World& me) {
			myMap = me.myMap;
			myObjects = me.myObjects; }

protected:
	//The Map
	Map myMap;

	//A list of pointer to GameObjects
	std::vector<std::shared_ptr<mw::GameObject>> myObjects;


private:
	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(myMap, states);
	}

};//end of class


//Classes that contain the pre-made worlds to set world too
class World1 : public World
{
public:
	World1()
	{
		createWorld();
	}
	~World1(){}

private:

	//Method that will create the World.  Loads in all Tiles and Objects
	void createWorld()
	{
		//800, 600
		//place 6 tiles in line to the center 
		for(int i = 1; i <= 6; i++)
		{
			myMap.addTile(mw::Texture::World::TILE_BASIC_GRASS);
			myMap.getLastTile().SetPosition((400-32) + (32 * (i-3)), 600/2);
		}
		//loads 6 metals
		for(int i = 1; i <= 6; i++)
		{
			myMap.addTile(mw::Texture::World::TILE_BASIC_METAL);
			myMap.getLastTile().SetPosition((400-32) + (32 * (i-3)), 600/1.5f);
		}
	}
};

} //end of namespace mw