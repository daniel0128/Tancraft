#include "stdafx.h"
#include "AIManager.h"


AIManager::AIManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager)
	:TankManager(sceneManager,pManager)
{
}


AIManager::~AIManager(void)
{
}

void
AIManager::Think(float time){
}
