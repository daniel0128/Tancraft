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
	MovingObject *getBarrel(){return mBarrel;}

	void barrelRotate(Rotate way, float time);
	void tankMove(TankDirection way, float time);

	void fire();
	float getFireCD(){return fireCD;}
	bool isAlive(){return alive;}

	void setFireCD(float cd){fireCD=cd;}

	void setFulHP(int fhp){fullHP=fhp;}
	int getFullHP(){return fullHP;}

	void setHP(int hp){HP= hp;}
	int getHP(){return HP;}

	void setBulletPower(int bp){bulletPower = bp;}
	int getPower(){return bulletPower;}
	virtual void beHit(int){}
	virtual bool isPlayer(){return false;}

protected:
	MovingObject *mBarrel;
	MovingObject *mCar;

	ProjectileManager *mProjectileManager;
	float fireCD;
	MovingObject *mParent;
	bool alive;

	int fullHP;
	int HP;
	int bulletPower;

};

