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
	//Ogre::Matrix3 getOrientation() {return mOrientation;}
    //Ogre::Vector3 getPosition() {return mPosition;}

    //void setOrientation(Ogre::Matrix3 orientation); 
    //void setPosition(Ogre::Vector3 position); 

	//constructor and destructor
	MovingObject(Ogre::SceneManager *sceneManager, const char *meshName, MovingObject *parent);
	~MovingObject(void);

	//setter and getter
	void setSpeed(float speed){movingSpeed = speed;}
	void setPalstance(float palstance){this->palstance = palstance;}
	void setPosition(Ogre::Vector3);

	void setScale(Ogre::Vector3 newScale);

	Ogre::SceneNode *SceneNodeManager(){return mObjectSceneNode;}
    
	//ratate function
	void yaw(Ogre::Radian theta);
    void pitch(Ogre::Radian theta);
    void roll(Ogre::Radian theta);

	//move fuction
	void translate(Ogre::Vector3 deltaPosition,TransformSpace relateTo);

	//camera funtion
	void setCameraToLocal(Ogre::Camera *camera);
	
    //void setPositionFromWorldPosition(Ogre::Vector3 worldPosition);
    //void setOrentationFromWorldOrientation(Ogre::Matrix3 worldOrientation);
	
	//void translate(Ogre::Real x,Ogre::Real y,Ogre::Real z,Ogre::Node::TransformSpace node);
protected:

	//void GetWorldPositionAndOrientation(Ogre::Vector3 &position, Ogre::Matrix3 &orientation);
    //void SetGraphicPosition();

	float movingSpeed;
	float palstance;
    //Ogre::Matrix3 mOrientation;
    //Ogre::Vector3 mPosition;
    MovingObject *mParent;
    Ogre::SceneNode *mObjectSceneNode;
};
#endif
