};
#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include "GraphObject.h"
#include "Annoyable.h"
#include "Iceman.h"
#include "Protester.h"
#include "Coor.h"
#include <vector>
#include <string>
#include <cmath>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{

public:
	StudentWorld(std::string assetDir)
		: GameWorld(assetDir)
	{
	}

	virtual int init()
	{
		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move()
	{
		// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
		// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
		decLives();
		return GWSTATUS_PLAYER_DIED;
	}

	virtual void cleanUp()
	{
	}

	const std::vector<Actor*>* getActors() {
		return actors;
	}

	////called by Iceman
	//bool inBoulder(int x, int y);
	//void spawnSquirt(int x, int y, GraphObject::Direction d);
	//void revealArea(int x, int y);
	//void spawnNugget(int x, int y);

	////called by Boulder
	//bool isIce(int x, int y);
	//Annoyable* getNearbyAnnoyable(int x, int y, float dist);

	////called by Squirt
	//Protester* getNearbyProtester(int x, int y, float dist);

	//// called by Barrel 
	//void pickUpBarrel(int id);

	//// called by Barrel AND GoldNugget
	//bool nearIceman(int x, int y, float dist);
	//void increaseScore(int amount);
	Iceman* getIceman();

	////called by Protester
	//std::vector<Coor>* getPathToExit(int startX, int startY);

private:
	std::vector<Actor*>* actors;
	Iceman* iceman;
	/*std::vector<Protester*>* protesters;*/
	int score;
	/*std::vector<bool>* barrelPickedUp;*/
};

#endif // STUDENTWORLD_H_

