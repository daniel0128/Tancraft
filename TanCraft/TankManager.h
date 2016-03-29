#pragma once
#ifndef __TankManager_h_
#define __TankManager_h_
#include "Tank.h"

class ProjectileManager;
class Tank;
class AITank;
class Geometry;

class TankManager
{
public:
	TankManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager);
	~TankManager(void);
	void Think(float);
	//
	Tank* getPlayerTank(){return playerTank;}
	std::vector<AITank*> *getTankList(){ return &tankList; }
	bool checkCollision();
	void addGeometry(Geometry* geo);
	
protected:

	Tank* playerTank;
	Ogre::SceneManager* mSceneManager;
	ProjectileManager* mProjectileManager;
	std::vector<AITank*> tankList;
	Geometry* mGeometry;

};
#endif