#pragma once
#include "movingobject.h"
class Tank;
class ProjectileManager;
class Projectile :
	public MovingObject
{
public:

	Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager, Ogre::Vector3 position);
	Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager, Tank* fromTank);
	Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager, Ogre::Vector3 position, Ogre::Vector3 velocity);
	~Projectile(void);

	void Think(float time);
	bool fly(float time);
	float getRange(){return bulletRange;}
	Tank* getFrom(){return mfromTank;}

protected:
	float bulletRange;
	Tank* mfromTank;
	Ogre::Vector3 startPosition;
	Ogre::Vector3 bulletVelocity;
	ProjectileManager* mProjectileManager;
};

