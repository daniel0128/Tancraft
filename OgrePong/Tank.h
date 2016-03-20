#pragma once
#include "movingobject.h"
class Tank :
	public MovingObject
{
public:
	enum Rotate{
		PITCH,
		YAW,
		ROLL,
	};
	enum TankDirection{
		FOWARD,
		BACK,
		LEFT,
		RIGHT,
		BACK_LEFT,
		BACK_RIGHT,
		FOR_LEFT,
		FOR_RIGHT,
	};
	Tank(Ogre::SceneManager *sceneManager,const char *carMesh, const char * barrelMesh);
	~Tank(void);
	MovingObject *getTank(){return mTank;}
	MovingObject *getBarrel(){return mBarrel;}

	void barrelRotate(Rotate way, float time);
	void tankMove(TankDirection way, float time);
protected:
	MovingObject *mBarrel;
	MovingObject *mCar;
	MovingObject *mTank;

	MovingObject *mParent;
    Ogre::SceneNode *mObjectSceneNode;
};

