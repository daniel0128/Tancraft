#include "TankManager.h"


TankManager::TankManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager)
	:mSceneManager(sceneManager),mProjectileManager(pManager)
{
	playerTank = new Tank(mSceneManager,mProjectileManager,"Car.mesh","Battery.mesh");
}

TankManager::~TankManager(void)
{
}

void
TankManager::Think(float time){
}