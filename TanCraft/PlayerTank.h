#pragma once
#include "tank.h"
class PlayerTank :
	public Tank
{
public:
	PlayerTank(Ogre::SceneManager* sceneManager, ProjectileManager* pManager);
	~PlayerTank(void);

	bool isPlayer() {return true;}
	bool isShielded() {return shielded;}
	//bool hitBuff();

	void beHit(int);
	void setPlayerCamera(Ogre::Camera* cam);
	void setRadarCamera(Ogre::Camera* cam);
	void shaking(float time);
	void shake();
	void reset();
	void buffed(int);

protected:
	Ogre::Real shakeAmplitude;
	float shakeTime;
	bool shielded;
};

