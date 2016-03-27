#pragma once
#include "movingobject.h"
class ProjectileManager;
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
		STOP,
	};
	Tank(Ogre::SceneManager *sceneManager, ProjectileManager *pManager, const char *carMesh, const char *barrelMesh);
	~Tank(void);
	//MovingObject *getTank(){return mTank;}
	MovingObject *getBarrel(){return mBarrel;}
	
	void barrelRotate(Rotate way, float time);
	void tankMove(TankDirection way, float time);
	void fire();
	float getFireCD(){return fireCD;}
	void setFireCD(float cd){fireCD=cd;}
	//virtual void Think(float time);
	void beHitted();

protected:
	MovingObject *mBarrel;
	MovingObject *mCar;
	//MovingObject *mTank;

	ProjectileManager *mProjectileManager;
	float fireCD;
	MovingObject *mParent;
	bool alive;
};

