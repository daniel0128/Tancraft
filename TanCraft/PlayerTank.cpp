#include "stdafx.h"
#include "PlayerTank.h"
#include "TankManager.h"
#include "StaticObject.h"
#include "Camera.h"

PlayerTank::PlayerTank(Ogre::SceneManager* sceneManager, ProjectileManager* pManager)
	:Tank(sceneManager, pManager, "Car.mesh", "Battery.mesh")//,shakeAmplitude(Ogre::Math::PI/45),shakeTime(0)
{
	HP=100;
	bulletPower=10;
	setPosition(Ogre::Vector3(-40,7,0));
	shielded = false;
}


PlayerTank::~PlayerTank(void)
{
}

void PlayerTank::setPlayerCamera(Ogre::Camera* cam){
	mBarrel->SceneNodeManager()->attachObject(cam);
	cam->setPosition(-70,20,0);
	cam->lookAt(10,25,0);
}

void PlayerTank::setRadarCamera(Ogre::Camera* cam){
	SceneNodeManager()->attachObject(cam);
	cam->setPosition(0,300,0);
	cam->lookAt(0,0,0);
}

void PlayerTank::beHit(int power){
	if(shielded){
		shielded = false;
	}else{
		HP-=power;
		if(HP<=0){
			alive=false;
			TankManager::gameRunning = false;
		}
	}
}

void PlayerTank::shake(){
	playerCamera->shake();
}

void PlayerTank::reset(){
	setPosition(Ogre::Vector3(-40,7,0));
	HP= fullHP = 100;
	bulletPower = 10;
}

void PlayerTank::buffed(int type){
	switch (type)
	{
	case 1:
		//hp+
		HP+=20;
		if(HP>100)
			HP=100;
		break;
	case 2:
		//bp+
		bulletPower+=10;
		break;
	case 3:
		//shielded
		shielded = true;
		break;
	default:
		break;
	}
}
