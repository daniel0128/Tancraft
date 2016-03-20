/**
* This is the file that code based on what Professor gave us. Instead implement the translate and rotate function, I am
* using the method that Ogre offered. I found there might be a easier way, but whatever, I made it work.
* By Daniel Zhang (D Z)
*/

#pragma once
#ifndef __MovingObject_h_
#define __MovingObject_h_
#include "OgreMatrix3.h"
#include "OgreVector3.h"
namespace Ogre{
	class SceneNode;
    class SceneManager;	
	class Node;
}
class PongCamera;

class MovingObject
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
	void setPosition(Ogre::Vector3);

	void setScale(Ogre::Vector3 newScale);

	Ogre::SceneNode *SceneNodeManager(){return mObjectSceneNode;}
    
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

    MovingObject *mParent;
    Ogre::SceneNode *mObjectSceneNode;
};
#endif
