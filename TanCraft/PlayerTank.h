#pragma once
#include "tank.h"
class TankCamera;
class PlayerTank :
	public Tank
{
public:
	PlayerTank(Ogre::SceneManager* sceneManager, ProjectileManager* pManager);
	~PlayerTank(void);

	bool isPlayer() {return true;}
	bool isShielded() {return shielded;}

	void beHit(int);
	void setPlayerCamera(Ogre::Camera* cam);
	void setRadarCamera(Ogre::Camera* cam);
	void shake();
	void reset();
	void buffed(int);
	void addCamera(TankCamera * cam) {playerCamera = cam;}

protected:
	TankCamera* playerCamera;
	bool shielded;
};

