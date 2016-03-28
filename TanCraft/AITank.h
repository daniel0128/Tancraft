#pragma once
#include "tank.h"
class ProjectileManager;
class TankManager;

class AITank :
	public Tank
{
public:
	//Tank(Ogre::SceneManager *sceneManager, ProjectileManager *pManager, const char *carMesh, const char *barrelMesh);
	AITank(Ogre::SceneManager *sceneManager, ProjectileManager *pManager,TankManager* tManager,const char *carMesh, const char *barrelMesh);
	~AITank(void);
	void Think(float);
protected:
	TankManager* mTankManager;
	float operationCD;
	float operationTimer;
	//operation typpe
	int aiRotation;
	int aiMove;
	
};

