#include "StudentWorld.h"
#include "Squirt.h"
#include "GoldNugget.h"
#include <string>
#include "GraphObject.h"
#include <queue>
using namespace std;

StudentWorld* theWorld = nullptr;

StudentWorld* getWorld() {
	return theWorld;
}

GameWorld* createStudentWorld(string assetDir)
{
	theWorld = new StudentWorld(assetDir);
	return theWorld;
}
//
//bool StudentWorld::inBoulder(int x, int y) {
//	for (Actor* a : *actors) {
//		if (a->getID() == IID_BOULDER && sqrt(pow(x - a->getX(), 2) + pow(y - a->getY(), 2)) <= 3) {
//			return true;
//		}
//	}
//	return false;
//}
//
//// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
//
//void  StudentWorld::spawnSquirt(int x, int y, GraphObject::Direction d)
//{
//	for (Actor* a : *actors)
//	{
//		if (a->getID() == IID_PLAYER)
//		{
//			Squirt* b;
//			b->doSomething();
//		}
//	}
//}
//void  StudentWorld::revealArea(int x, int y)
//{
//	//need to add activatingobject class for usable things
//}
//void  StudentWorld::spawnNugget(int x, int y)
//{
//	for (Actor* a : *actors)
//	{
//		if (a->getID() == IID_PLAYER)
//		{
//			GoldNugget* c;
//			c->doSomething();
//		}
//	}
//}

//called by Boulder
bool  StudentWorld::isIce(int x, int y)
{
	for (Actor* a : *actors)
	{
		if (a->getID() == IID_ICE)
			return true;
	}
	return false;
//}
//Annoyable* StudentWorld::getNearbyAnnoyable(int x, int y, float dist) //What gets returned
//{
//	for (Actor* a : *actors)
//	{
//		for (Actor* b : *actors)
//		{
//			if (a->getID() == IID_WATER_SPURT)
//			{
//				int diff = b->getX() - x;
//				if (diff > dist)
//					return true; //what should be returned
//			}
//			else
//				return false;
//		}
//
//	}
//
//}
//
////called by Squirt
//Protester* StudentWorld::getNearbyProtester(int x, int y, float dist) //What gets returned
//{
//	for (Actor* a : *actors)
//	{
//		for (Actor* b : *actors)
//		{
//			if (a->getID() == IID_WATER_SPURT)
//			{
//				int diff = b->getX() - x;
//				if (diff > dist)
//					return true; //what should be returned
//			}
//			else
//				return false;
//		}
//
//	}
//}
//
//// called by Barrel 
//void  StudentWorld::pickUpBarrel(int id)
//{
//	for (Actor* a : *actors)
//	{
//		for (Actor* b : *actors)
//		{
//			if (a->getID() == IID_PLAYER)
//			{
//				if (b->getID() == IID_BARREL)
//				{
//					increaseScore(1000);
//
//					//need to make a isDead function
//				}
//			}
//		}
//	}
//
//}
//
//// called by Barrel AND GoldNugget
//bool  StudentWorld::nearIceman(int x, int y, float dist)
//{
//	GraphObject::setVisible;
//}
//void  StudentWorld::increaseScore(int amount)
//{
//	score += amount;
//}
Iceman* StudentWorld::getIceman()
{
	Iceman* d;
	return d;
}

////called by Protester
//std::vector<Coor>* StudentWorld::getPathToExit(int startX, int startY)
//{
//
//}

