
#include "Actor.h"
#include "StudentWorld.h"
#include "StudentWorld.cpp"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;


Ice::Ice(int initialX, int initialY) : Actor(OBJ_PERMANENT, IID_ICE, initialX, initialY, right, .25, 3) {
	setVisible(true);
}

void Ice::doSomething() {
	//does nothing
}


Iceman::Iceman() : Actor(IID_PLAYER, 30, 60)
{
	hitpoints = 10;
	squirtUnits = 5;
	sonarCharge = 1;
	goldNuggets = 0;

	//might be an issue later-------------------------------------------------------------------------????????????????????
	setVisible(true);
}

void Iceman::doSomething() {
	if (hitpoints < 10) return;
	else {
		int ch;
		if (getWorld()->getKey(ch)) {
			switch (ch)
			{
			case KEY_PRESS_ESCAPE:
				hitpoints = 10;
				break;
			case KEY_PRESS_LEFT:
				newDirection(left);
				break;
			case KEY_PRESS_RIGHT:
				newDirection(right);
				break;
			case KEY_PRESS_UP:
				newDirection(up);
				break;
			case KEY_PRESS_DOWN:
				newDirection(down);
				break;
			case KEY_PRESS_SPACE:
				break;
			case KEY_PRESS_TAB:
				if (goldNuggets > 0) {
					goldNuggets--;
					getWorld()->spawnNugget(getX(), getY());
				}
				break;
			case 'Z':
			case 'z':
				if (sonarCharge > 0) {
					sonarCharge--;
					getWorld()->revealArea(getX(), getY());
				}
				break;
			}
		}
	}
}
//
//Barrel::Barrel(int id, int initialX, int initialY) : Actor(OBJ_OBTAINABLE, IID_BARREL, initialX, initialY, right, 1, 2) {
//	b_id = id;
//}
//
//void Barrel::doSomething() {
//	if (state != OBJ_DEAD) {
//		if (!isVisible() && getWorld()->nearIceman(getX(), getY(), 4)) {
//			setVisible(true);
//		}
//		else if (getWorld()->nearIceman(getX(), getY(), 3)) {
//			state = OBJ_DEAD;
//			getWorld()->increaseScore(1000);
//			getWorld()->pickUpBarrel(b_id);
//		}
//	}
//}
//
//int Barrel::getBarrelID() {
//	return b_id;
//}
//
//Boulder::Boulder(int initialX, int initialY) :Actor(BOULDER_STABLE, IID_BOULDER, initialX, initialY, down, 1, 1) {
//	setVisible(true);
//}
//
//void Boulder::doSomething() {
//	switch (state) {
//	case BOULDER_STABLE:
//		bool foundIce = false;
//		for (int i = 0; i < 4; i++) {
//			if (getWorld()->isIce(getX() + i, getY() - 1)) {
//				foundIce = true;
//				break;
//			}
//		}
//		if (!foundIce) {
//			state = BOULDER_WAITING;
//			ticksElapsed = 0;
//		}
//		break;
//	case BOULDER_WAITING:
//		if (ticksElapsed >= 30) {
//			state = BOULDER_FALLING;
//		}
//		else ticksElapsed++;
//		break;
//	case BOULDER_FALLING:
//		int newY = getY() - 1;
//		if (newY < 0 || getWorld()->inBoulder(getX(), getY() - 1) || getWorld()->isIce(getX(), getY() - 1)) {
//			state = OBJ_DEAD;
//			break;
//		}
//		Annoyable* annoyable = getWorld()->getNearbyAnnoyable(getX(), getY(), 3);
//		if (annoyable) {
//			annoyable->getAnnoyed(100);
//		}
//		break;
//	case OBJ_DEAD:
//		break;
//	}
//	return;
//}
//
//GoldNugget::GoldNugget(int initialX, int initialY, bool visible, bool pickUpBy, int objState) :Actor(objState, IID_GOLD, initialX, initialY, right, 1, 2) {
//	setVisible(visible);
//	this->pickUpBy = pickUpBy;
//	this->state = state;
//	if (state == OBJ_TEMPORARY) {
//		maxExistenceTicks = 100;
//		ticksElapsed = 0;
//	}
//}
//
//void GoldNugget::doSomething() {
//	if (state != OBJ_DEAD) {
//		if (!isVisible() && getWorld()->nearIceman(getX(), getY(), 4)) {
//			setVisible(true);
//		}
//		else if (pickUpBy == PICK_UP_ICEMAN && getWorld()->nearIceman(getX(), getY(), 3)) {
//			state = OBJ_DEAD;
//			getWorld()->increaseScore(10);
//			getWorld()->getIceman()->obtainGoldNugget();
//		}
//		else if (pickUpBy == PICK_UP_PROTESTER) {
//			Protester* nearbyP = getWorld()->getNearbyProtester(getX(), getY(), 3);
//			if (nearbyP) {
//				state = OBJ_DEAD;
//				nearbyP->obtainGoldNugget();
//				getWorld()->increaseScore(25);
//			}
//		}
//
//		if (state == OBJ_TEMPORARY) {
//			ticksElapsed++;
//			if (ticksElapsed >= maxExistenceTicks) {
//				state = OBJ_DEAD;
//			}
//		}
//	}
//}

//
//void Iceman::newDirection(Direction d) {
//	if (getDirection() != d) {
//		setDirection(d);
//	}
//	else {
//		int dx;
//		int dy;
//		switch (d) {
//		case right:
//			dx = 1;
//			break;
//		case left:
//			dx = -1;
//			break;
//		case up:
//			break;
//			dy = 1;
//		case down:
//			dy = -1;
//			break;
//		default:
//			dx = 0;
//			dy = 0;
//			cerr << "How did we get here?" << endl;
//			break;
//		}
//		int newX = getX() + dx;
//		int newY = getY() + dy;
//		if (0 <= newX && newX <= 60 && 0 <= newY && newY <= 60 && !(getWorld()->inBoulder(newX, newY))) {
//			moveTo(newX, newY);
//		}
//	}
//}
//
//void Iceman::getAnnoyed(int amount) {
//	hitpoints -= amount;
//}
//
//void Iceman::obtainGoldNugget() {
//	goldNuggets++;
//}
//
//void Iceman::obtainSonarKit() {
//	sonarCharge++;
//}
//
//void Iceman::refillSquirt() {
//	squirtUnits += 5;
//}
//
//Protester::Protester(int initialX, int initialY, int maxTravelDistance, int currentLevel) : Actor(PROTESTER_REST, IID_PROTESTER, initialX, initialY, left, 1, 0) {
//	setVisible(true);
//	this->maxTravelDistance = maxTravelDistance;
//	hitpoints = 5;
//	ticksNeededToMove = max(0, 3 - currentLevel / 4);
//	ticksElapsed = 0;
//}
//
//void Protester::doSomething() {
//	if (state != OBJ_DEAD) {
//		if (state == PROTESTER_REST) {
//			ticksElapsed++;
//			if (ticksElapsed >= ticksNeededToMove) {
//				state = PROTESTER_ACTIVATED;
//			}
//		}
//		else if (state == PROTESTER_LTOF) {
//			if (getX() == 60 && getY() == 60) {
//				state = OBJ_DEAD;
//			}
//		}
//	}
//}
//
//SonarKit::SonarKit(int initialX, int initialY, int currentLevel) : Actor(OBJ_OBTAINABLE, IID_SONAR, initialX, initialY, right, 1, 2) {
//	setVisible(true);
//	maxExistenceTicks = max(100, 300 - 10 * currentLevel);
//	ticksElapsed = 0;
//}
//
//void SonarKit::doSomething() {
//	if (state != OBJ_DEAD) {
//		if (getWorld()->nearIceman(getX(), getY(), 3)) {
//			state = OBJ_DEAD;
//			getWorld()->getIceman()->obtainSonarKit();
//			getWorld()->increaseScore(75);
//		}
//
//		ticksElapsed++;
//		if (ticksElapsed >= maxExistenceTicks) {
//			state = OBJ_DEAD;
//		}
//	}
//}
//
//#include "Squirt.h"
//#include "GraphObject.h"
//#include "StudentWorld.cpp"
//
//Squirt::Squirt(int initialX, int initialY, GraphObject::Direction dir) : Actor(OBJ_OBTAINABLE, IID_WATER_POOL, initialX, initialY, dir, 1, 1) {
//	maxTravelDis = 4;
//	disTraveled = 0;
//	setVisible(true);
//}
//
//void Squirt::doSomething() {
//	Protester* nearbyProtester = getWorld()->getNearbyProtester(getX(), getY(), 3);
//	if (nearbyProtester) {
//		nearbyProtester->getAnnoyed(2);
//		state = OBJ_DEAD;
//	}
//	else if (disTraveled >= maxTravelDis) {
//		state = OBJ_DEAD;
//	}
//	else {
//		int dx = 0;
//		int dy = 0;
//		switch (getDirection()) {
//		case up:
//			dy = 1;
//			break;
//		case down:
//			dy = -1;
//			break;
//		case right:
//			dx = 1;
//			break;
//		case left:
//			dx = -1;
//			break;
//		default:
//			cerr << "how did we get here in squirt?" << endl;
//			break;
//		}
//		int newX = getX() + dx;
//		int newY = getY() + dy;
//		if (getWorld()->inBoulder(newX, newY) || getWorld()->isIce(newX, newY)) {
//			state = OBJ_DEAD;
//		}
//		else {
//			moveTo(newX, newY);
//		}
//	}
//}
//
//WaterPool::WaterPool(int initialX, int initialY, int currentLevel) :Actor(OBJ_OBTAINABLE, IID_WATER_POOL, initialX, initialY, right, 1, 2) {
//	maxExistenceTick = max(100, 300 - 10 * currentLevel);
//	ticksElapsed = 0;
//	setVisible(true);
//}
//
//void WaterPool::doSomething() {
//	if (state != OBJ_DEAD) {
//		if (getWorld()->nearIceman(getX(), getY(), 3)) {
//			state = OBJ_DEAD;
//			getWorld()->getIceman()->refillSquirt();
//			getWorld()->increaseScore(100);
//		}
//		ticksElapsed++;
//		if (ticksElapsed >= maxExistenceTick) {
//			state = OBJ_DEAD;
//		}
//	}
//}
