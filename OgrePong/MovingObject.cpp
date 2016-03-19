#include "MovingObject.h"
#include "OgreSceneManager.h"
#include "OgreEntity.h"

MovingObject::
	MovingObject(Ogre::SceneManager *sceneManager, const char *meshName, MovingObject *parent) :mParent(parent)
{
	if(mParent)
		mObjectSceneNode = mParent->mObjectSceneNode->createChildSceneNode();
	else
		mObjectSceneNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	if(meshName){
		Ogre::Entity *ent1 = sceneManager->createEntity(meshName);
		mObjectSceneNode->attachObject(ent1);
	}
}

MovingObject::~MovingObject()
{
}
void 
MovingObject::setPosition(Ogre::Vector3 position)
{
	mObjectSceneNode->setPosition(position);
}