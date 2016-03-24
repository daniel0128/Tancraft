#pragma once
#include "tankmanager.h"
class AIManager :
	public TankManager
{
public:
	AIManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager);
	~AIManager(void);
	void Think(float time);
};

