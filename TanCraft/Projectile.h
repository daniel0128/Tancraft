#pragma once
#include "movingobject.h"
class Tank;
class ProjectileManager;
class Projectile :
	public MovingObject
{
public:

	Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager, Tank* fromTank);
	~Projectile(void);

	void Think(float time);
	bool fly(float time);
	float getRange(){return bulletRange;}
	Tank* getFrom(){return mfromTank;}

	void setPower(int p){power = p;}
	int getPower(){return power;}

protected:
	float bulletRange;
	Tank* mfromTank;
	Ogre::Vector3 startPosition;
	Ogre::Vector3 bulletVelocity;
	ProjectileManager* mProjectileManager;
	int power;
};

