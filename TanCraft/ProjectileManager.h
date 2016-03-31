#pragma once
#ifndef __ProjectileManager_h_
#define __ProjectileManager_h_
#include "Ogre.h"

namespace Ogre{
	class SceneManager;
};

class Projectile;
class TankManager;
class Tank;
class Explosion;
class Geometry;
class StaticObject;

class ProjectileManager
{
public:
	ProjectileManager(Ogre::SceneManager* sceneManager);
	~ProjectileManager(void);

	void Think(float time);
	void reset();
	std::vector<Projectile*> *getBulletList(){return &mProjectileList;}
	void addTankManager(TankManager* tManager){mTankManager=tManager;}
	Tank* checkCollision(Projectile* pro);
	StaticObject* hitGeo(Projectile* pro);

	void addGeometry(Geometry* geo);

protected:
	Ogre::SceneManager* mSceneManager;
	std::vector<Projectile*> mProjectileList;
	TankManager* mTankManager;
	int explosion;
	std::vector<Explosion* > mExplosionList;
	Geometry* mGeometry;
};
#endif
