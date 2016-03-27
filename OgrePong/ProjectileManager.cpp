#include "ProjectileManager.h"
#include "Projectile.h"
#include "Tank.h"
#include "TankManager.h"
#include <iostream>

ProjectileManager::ProjectileManager(Ogre::SceneManager* sceneManager):mSceneManager(sceneManager)
{
	//Projectile* p = new Projectile(sceneManager,Ogre::Vector3(20,15,10),Ogre::Vector3(0,1,0));
	//mProjectileList.push_back(p);
}


ProjectileManager::~ProjectileManager(void)
{
}

void
ProjectileManager::Think(float time){

	bool collision = false;
	for(std::size_t i=0;i<mProjectileList.size();i++){
		//collision = mProjectileList[i]->fly(time);
		mProjectileList[i]->Think(time);
		Tank* t =checkCollision(mProjectileList[i]);
		if(t)
			t->roll(Ogre::Radian(1.57));
	}
}

void
ProjectileManager::reset()
{
	for (std::size_t i = 0; i < mProjectileList.size(); i++ )
   {
	   delete mProjectileList[i];
   }
	mProjectileList.clear();
}
Tank*
ProjectileManager::checkCollision(Projectile* p){
	if(!mTankManager||mTankManager->getTankList()->size()==0)
		return NULL;
	Tank *t;
	std::vector<Tank*> *tList = mTankManager->getTankList();
	for(size_t i=0;i<tList->size();i++){
		t=(*tList)[i];
		if(MovingObject::Distance(p,(MovingObject*)t)<5)
			return t;
	}
	Tank *pT = mTankManager->getPlayerTank();
	Tank *pF = p->getFrom();
	if(MovingObject::Distance( mTankManager->getPlayerTank(),p)<5 && pT != pF)
		return mTankManager->getPlayerTank();
	return NULL;
}