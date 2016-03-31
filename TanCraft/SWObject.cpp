#include "stdafx.h"
#include "SWObject.h"


SWObject::SWObject(Ogre::SceneManager *sceneManager, const char *meshName, SWObject* parent):mSceneManager(sceneManager),mParent(parent)
{
	if(mParent){
		mObjectSceneNode = mParent->mObjectSceneNode->createChildSceneNode();
	}else{
		mObjectSceneNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	}
	if(meshName){
		ent = sceneManager->createEntity(meshName);
		mObjectSceneNode->attachObject(ent);
	}else ent=NULL;
}

SWObject::~SWObject(void)
{
	mObjectSceneNode->detachAllObjects();
	if(ent!=NULL)
		mSceneManager->destroyEntity(ent);
	mSceneManager->destroySceneNode(mObjectSceneNode);
}

void SWObject::setPosition(Ogre::Vector3 position){
	mObjectSceneNode->setPosition(position);
}

Ogre::Vector3 SWObject::getWorldPosition(){
	return mObjectSceneNode->_getDerivedPosition();
}

void SWObject::setScale(Ogre::Vector3 newScale){
	mObjectSceneNode->setScale(newScale);
}

float
SWObject::Distance(SWObject* o1,SWObject* o2){
	Ogre::Vector3 p1=o1->getWorldPosition();
	Ogre::Vector3 p2=o2->getWorldPosition();
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}

float SWObject::Distance(Ogre::Vector3 v1, Ogre::Vector3 v2){
	return sqrt( (v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y)+(v1.z-v2.z)*(v1.z-v2.z));
}