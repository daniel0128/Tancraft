#include "ProjectileManager.h"
#include "Projectile.h"
#include "Tank.h"
#include "AITank.h"
#include "TankManager.h"
#include "Explosion.h"

ProjectileManager::ProjectileManager(Ogre::SceneManager* sceneManager):mSceneManager(sceneManager)
{
}


ProjectileManager::~ProjectileManager(void)
{
}

void
ProjectileManager::Think(float time){

	//bool collision = false;
	Projectile* p;
	for(std::size_t i=0;i<mProjectileList.size();i++){
		//collision = mProjectileList[i]->fly(time);
		p=mProjectileList[i];
		p->Think(time);
		Ogre::Vector3 proPosition=p->getWorldPosition();
		Tank* t =checkCollision(mProjectileList[i]);
		if(t)
		{
			if(t==mTankManager->getPlayerTank()){

			}else
				t->beHitted();
		}
		if(p->getRange()<0||t||
			proPosition.y<0||proPosition.x>500||proPosition.x<-500||proPosition.z>500||proPosition.z<-500){
			explosion++;
			mExplosionList.push_back(new Explosion(mSceneManager, explosion, mProjectileList[i]->getWorldPosition()));
			delete mProjectileList[i];
			mProjectileList.erase(mProjectileList.begin()+i);
		}
	}
	if (explosion > 10000000)
		explosion = 0;
	for(size_t i =0;i<mExplosionList.size();i++){
		mExplosionList[i]->Think(time);
		if(mExplosionList[i]->getTime()<0){
			delete mExplosionList[i];
			mExplosionList.erase(mExplosionList.begin()+i);
		}
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
	Tank *pT = mTankManager->getPlayerTank();
	Tank *pF = p->getFrom();
	std::vector<AITank*> *tList = mTankManager->getTankList();
	for(size_t i=0;i<tList->size();i++){
		t=(AITank*)(*tList)[i];
		if(MovingObject::Distance(p,(MovingObject*)t)<10 && pT==pF)
		{return t;}
	}

	if(MovingObject::Distance( mTankManager->getPlayerTank(),p)<10 && pT != pF)
		return mTankManager->getPlayerTank();
	return NULL;
}