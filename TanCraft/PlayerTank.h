#pragma once
#include "tank.h"
class PlayerTank :
	public Tank
{
public:
	PlayerTank(Ogre::SceneManager* sceneManager, ProjectileManager* pManager);
	~PlayerTank(void);

	bool isPlayer() {return true;}
	void beHit(int);
	void setPlayerCamera(Ogre::Camera* cam);
	void setRadarCamera(Ogre::Camera* cam);
	void shaking(float time);
	void shake();
	void reset();

protected:
	Ogre::Real shakeAmplitude;
	float shakeTime;
};

