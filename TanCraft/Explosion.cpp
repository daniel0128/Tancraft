#include "stdafx.h"
#include "Explosion.h"


Explosion::	Explosion(Ogre::SceneManager *sceneManager, int explosion, Ogre::Vector3 position)
	:mSceneManager(sceneManager)
{
	ps = mSceneManager->createParticleSystem(Ogre::StringConverter::toString(explosion), "Examples/Explosion");
	sn = mSceneManager->getRootSceneNode()->createChildSceneNode(position);
	sn->attachObject(ps);
	mTime = 1.0;
}
Explosion::~Explosion(void)
{
	sn->detachAllObjects();
	mSceneManager->destroyParticleSystem(ps);
	mSceneManager->destroySceneNode(sn);
}
void
Explosion::Think(float time){
	mTime-=time;
}
