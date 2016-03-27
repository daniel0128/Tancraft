#include "MovingObject.h"
#include "OgreSceneManager.h"
#include "OgreEntity.h"
#include "Physics.h"

MovingObject::
	MovingObject(Ogre::SceneManager *sceneManager, const char *meshName, MovingObject *parent) 
	:mParent(parent),mSceneManager(sceneManager), movingSpeed(30),palstance(0.5)
{
	if(mParent)
		mObjectSceneNode = mParent->mObjectSceneNode->createChildSceneNode();
	else
		mObjectSceneNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	if(meshName){
		Ogre::Entity *ent1 = sceneManager->createEntity(meshName);
		mObjectSceneNode->attachObject(ent1);
	}
	rBody=NULL;
	movingShape=NULL;
}

MovingObject::~MovingObject(){
	mObjectSceneNode->detachAllObjects();
	mSceneManager->destroySceneNode(mObjectSceneNode);
}

void MovingObject::setCameraToLocal(Ogre::Camera *camera){
	mObjectSceneNode->attachObject(camera);
	camera->setPosition(-30,15,0);
	camera->lookAt(10,10,0);
}

void 
MovingObject::setScale(Ogre::Vector3 newScale){
	mObjectSceneNode->scale(newScale.x,newScale.y,newScale.z);
}
void 
MovingObject::setPosition(Ogre::Vector3 pos){
	if(rBody && rBody->getMotionState()){
		btTransform trans = rBody->getWorldTransform();
		trans.setOrigin(btVector3(pos.x,pos.y,pos.z));
		rBody->setWorldTransform(trans);
	}else
		mObjectSceneNode->setPosition(pos);
}

void 
MovingObject::yaw(Ogre::Radian theta){
	if(rBody && rBody->getMotionState()){
		btQuaternion deltaQ;
		deltaQ = btQuaternion(btVector3(0,1,0),theta.valueRadians());
		
		btTransform tr=rBody->getCenterOfMassTransform();
		//rBody->getMotionState()->getWorldTransform(tr);
		//tr.setIdentity();
		btQuaternion orientation = tr.getRotation();
		orientation = deltaQ*orientation;
		tr.setRotation(orientation);
		rBody->setCenterOfMassTransform(tr);
	}else
		mObjectSceneNode->yaw(theta);
}
void 
MovingObject::pitch(Ogre::Radian theta){
	mObjectSceneNode->pitch(theta);
}
void 
MovingObject::roll(Ogre::Radian theta){
	if(rBody){
		btQuaternion deltaQ;
		deltaQ = btQuaternion(btVector3(0,0,1),theta.valueRadians());
		btTransform tr;
		rBody->getMotionState()->getWorldTransform(tr);
		btQuaternion orientation = tr.getRotation();
		orientation = orientation*deltaQ;
		tr.setRotation(orientation);
		rBody->setWorldTransform(tr);
	}
	else
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

float 
MovingObject::Distance(MovingObject* o1,MovingObject* o2){
	Ogre::Vector3 p1=o1->getWorldPosition();
	Ogre::Vector3 p2=o2->getWorldPosition();
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}