#include "ProjectileManager.h"
#include "Projectile.h"
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
		if(collision){
			delete mProjectileList[i]; 
			mProjectileList.erase(mProjectileList.begin()+i);
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