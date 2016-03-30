#include "MovingObject.h"
#include "SWObject.h"
#include "OgreSceneManager.h"
#include "OgreEntity.h"

MovingObject::
	MovingObject(Ogre::SceneManager *sceneManager, const char *meshName, MovingObject *parent) 
	:SWObject(sceneManager,meshName,parent), movingSpeed(50),palstance(0.5)
{
}

MovingObject::~MovingObject(){
}

void 
MovingObject::yaw(Ogre::Radian theta){
	mObjectSceneNode->yaw(theta);
}
void 
MovingObject::pitch(Ogre::Radian theta){
	mObjectSceneNode->pitch(theta);
}
void 
MovingObject::roll(Ogre::Radian theta){
	mObjectSceneNode->roll(theta);
}

//move fuction
void 
MovingObject::translate(Ogre::Vector3 deltaPosition,TransformSpace relateTo){
	if(relateTo==TS_LOCAL){
		mObjectSceneNode->translate(deltaPosition,Ogre::Node::TS_LOCAL);
	}else if(relateTo == TS_PARENT)
	{
		mObjectSceneNode->translate(deltaPosition,Ogre::Node::TS_PARENT);
	}else
	{
		mObjectSceneNode->translate(deltaPosition,Ogre::Node::TS_WORLD);
	}
}
