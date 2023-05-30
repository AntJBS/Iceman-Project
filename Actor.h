#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

const int OBJ_DEAD = 0;
const int OBJ_TEMPORARY = 1;
const int OBJ_PERMANENT = 2;
const int OBJ_OBTAINABLE = 3;
const int BOULDER_STABLE = 10;
const int BOULDER_WAITING = 11;
const int BOULDER_FALLING = 12;
const int PROTESTER_LTOF = 20;
const int PROTESTER_REST = 21;
const int PROTESTER_ACTIVATED = 22;

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public GraphObject {
public:
	Actor(int objState, int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) : GraphObject(imageID, startX, startY, dir, size, depth) {
		state = objState;
	}

	virtual void doSomething() = 0;


protected:
	int state;
};


class Ice : public Actor {

public:
	Ice(int initialX, int initialY);
	~Ice() {}

	void doSomething();
};

class Iceman : public Actor/* Annoyable*/
{
private:
	int hitpoints;
	int squirtUnits;
	int sonarCharge;
	int goldNuggets;

public:
	Iceman();
	~Iceman() {}
	void doSomething();
	//void newDirection(Direction d);
	//void getAnnoyed(int amount);
	////called by GoldNugget
	//void obtainGoldNugget();
	////called by SonarKit
	//void obtainSonarKit();
	////called by WaterPool();
	//void refillSquirt();
};
//
//class Squirt : Actor {
//private:
//	int maxTravelDis;
//	int disTraveled;
//public:
//	Squirt(int initialX, int initialY, GraphObject::Direction dir);
//	~Squirt() {}
//	void doSomething();
//};
//class Annoyable {
//public:
//	virtual void getAnnoyed(int amount);
//};
//
//class Barrel : public Actor {
//private:
//	int b_id;
//public:
//	Barrel(int id, int initialX, int initialY);
//	~Barrel() {};
//	void doSomething();
//
//	int getBarrelID();
//};
//
//class Boulder :public Actor {
//public:
//	Boulder(int initialX, int initialY);
//	~Boulder() {}
//
//	void doSomething();
//
//private:
//	int ticksElapsed;
//};
//
//const bool PICK_UP_ICEMAN = true;
//const bool PICK_UP_PROTESTER = false;
//
//class GoldNugget : public Actor {
//public:
//	GoldNugget(int initialX, int initialY, bool visible, bool pickUpBy, int objState);
//	~GoldNugget() {}
//	void doSomething();
//
//private:
//	bool pickUpBy;
//	int maxExistenceTicks;
//	int ticksElapsed;
//};
//
//#include "GameConstants.h"
//#include "Actor.h"

//
//class Protester :public Actor, Annoyable {
//public:
//	Protester(int initialX, int initialY, int maxTravelDistance, int currentLevel);
//	void doSomething();
//	void getAnnoyed(int amount);
//	//called by GoldNugget
//	void obtainGoldNugget();
//
//private:
//	int hitpoints;
//	int maxTravelDistance;
//	int ticksNeededToMove;
//	int ticksElapsed;
//};
//
//class SonarKit :public Actor {
//public:
//	SonarKit(int initialX, int initialY, int maxExistence);
//	~SonarKit() {}
//	void doSomething();
//
//private:
//	int maxExistenceTicks;
//	int ticksElapsed;
//};
//
//class WaterPool :public Actor {
//public:
//	WaterPool(int initialX, int initialY, int currentLevel);
//	~WaterPool() {}
//	void doSomething();

private:
	int maxExistenceTick;
	int ticksElapsed;
};
#endif // ACTOR_H_

