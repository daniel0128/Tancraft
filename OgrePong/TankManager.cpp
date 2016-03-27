#include "TankManager.h"
#include "AITank.h"

TankManager::TankManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager)
	:mSceneManager(sceneManager),mProjectileManager(pManager)
{
	playerTank = new Tank(mSceneManager,mProjectileManager,"Car.mesh","Battery.mesh");
	playerTank->setPosition(Ogre::Vector3(-40,10,0));
	
	for(int i=0;i<3;i++){
		AITank *aiTank = new AITank(mSceneManager,mProjectileManager,this,"Car.mesh","Battery.mesh");
		int x, z;
		x=Ogre::Math::RangeRandom(-100,100);
		z=Ogre::Math::RangeRandom(-100,100);
		aiTank->setPosition(Ogre::Vector3(x,10,z));
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
	for(size_t i=0;i<tankList.size();i++){
		tankList[i]->Think(time);
	}
}

bool 
TankManager::checkCollision(){
	for(size_t i=0;i<tankList.size();i++){
		if(MovingObject::Distance(tankList[i],playerTank)<15)
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