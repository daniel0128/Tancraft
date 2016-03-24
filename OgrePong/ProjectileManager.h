#pragma once
#ifndef __ProjectileManager_h_
#define __ProjectileManager_h_
#include "Ogre.h"

namespace Ogre{
	class SceneManager;
};

class Projectile;

class ProjectileManager
{
public:
	ProjectileManager(Ogre::SceneManager* sceneManager);
	~ProjectileManager(void);

	void Think(float time);
	void reset();
	std::vector<Projectile*> *getBulletList(){return &mProjectileList;}
protected:
	Ogre::SceneManager* mSceneManager;
	std::vector<Projectile*> mProjectileList;
};
#endif
