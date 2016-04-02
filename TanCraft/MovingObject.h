#pragma once

#include "OgreMatrix3.h"
#include "OgreVector3.h"
#include "SWObject.h"
namespace Ogre{
	class SceneNode;
    class SceneManager;	
	class Node;
}
class TankCamera;

class MovingObject
	:public SWObject
{
public: 
	enum TransformSpace{
		TS_LOCAL,
		TS_PARENT,
		TS_WORLD,
	};

	//constructor and destructor
	MovingObject(Ogre::SceneManager *sceneManager, const char *meshName, MovingObject *parent);
	~MovingObject(void);

	//setter and getter
	void setSpeed(float speed){movingSpeed = speed;}
	void setPalstance(float palstance){this->palstance = palstance;}
	void setVelocity(Ogre::Vector3);

	Ogre::SceneNode *SceneNodeManager(){return mObjectSceneNode;}
	Ogre::SceneManager *getSceneManager(){return mSceneManager;}
	
	Ogre::Vector3 getVelocity(){return velocity;}

	//rotate function
	void yaw(Ogre::Radian theta);
    void pitch(Ogre::Radian theta);
    void roll(Ogre::Radian theta);

	//move fuction
	void translate(Ogre::Vector3 deltaPosition,TransformSpace relateTo);

	//camera funtion
	void setCameraToLocal(Ogre::Camera *camera);
	
protected:

	float movingSpeed;
	float palstance;
	Ogre::Vector3 velocity;
};

