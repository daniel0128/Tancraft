#include "TankManager.h"


TankManager::TankManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager)
	:mSceneManager(sceneManager),mProjectileManager(pManager)
{
	playerTank = new Tank(mSceneManager,mProjectileManager,"Car.mesh","Battery.mesh");
	playerTank->setPosition(Ogre::Vector3(-40,6,0));
	
	for(int i=0;i<3;i++){
		Tank *aiTank = new Tank(mSceneManager,mProjectileManager,"Car.mesh","Battery.mesh");
		aiTank->setPosition(Ogre::Vector3(30,10,i*30-30));
		tankList.push_back(aiTank);
	}
	//trying code
	//tankList[2]->getRigidBody()->setAngularVelocity(btVector3(0,2,0));
//	tankList[2]->getRigidBody()->setAngularVelocity(btVector3(0,10,0));
}

TankManager::~TankManager(void)
{
}

void
TankManager::Think(float time){
	checkCollision();
}

bool 
TankManager::checkCollision(){
	for(size_t i=0;i<tankList.size();i++){
		if(MovingObject::Distance(tankList[i],playerTank)<30)
			return true;
		if (tankList.size()>2)		//enemyTank and enemyTank
		{
		   for(std::size_t j = i+1; j < tankList.size(); j++ )
			{
				if (MovingObject::Distance( tankList[i] , tankList[j])<30)
					return true;
			}
		}
	}
	return false;
}