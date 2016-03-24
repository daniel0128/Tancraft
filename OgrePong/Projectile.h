#pragma once
#include "movingobject.h"
class Tank;
class Projectile :
	public MovingObject
{
public:

	Projectile(Ogre::SceneManager *sceneManager, Ogre::Vector3 position);
	Projectile(Ogre::SceneManager *sceneManager, Tank* fromTank);
	Projectile::Projectile(Ogre::SceneManager *sceneManager, Ogre::Vector3 position, Ogre::Vector3 velocity);
	~Projectile(void);

	void Think(float time);
	bool fly(float time);
	float getRange(){return bulletRange;}

protected:
	float bulletRange;
	Tank* mfromTank;
	Ogre::Vector3 startPosition;
	Ogre::Vector3 bulletVelocity;
};

