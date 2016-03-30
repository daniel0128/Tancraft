#include "stdafx.h"
#include "PlayerTank.h"
#include "TankManager.h"

PlayerTank::PlayerTank(Ogre::SceneManager* sceneManager, ProjectileManager* pManager)
	:Tank(sceneManager, pManager, "Car.mesh", "Battery.mesh"),shakeAmplitude(Ogre::Math::PI/180),shakeTime(0)
{
	HP=100;
	bulletPower=10;
	setPosition(Ogre::Vector3(-40,7,0));
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
	mBarrel->SceneNodeManager()->attachObject(cam);
	cam->setPosition(0,300,0);
	cam->lookAt(0,0,0);
}

void PlayerTank::beHit(int power){
	HP-=power;
	if(HP<=0){
		alive=false;
		TankManager::gameRunning = false;
	}
}

void PlayerTank::shaking(float time){
	if(shakeTime>0){
		shakeAmplitude*=-1;
		SceneNodeManager()->pitch(Ogre::Radian(shakeAmplitude));
		shakeTime-=time;
	}else{
		SceneNodeManager()->setDirection(Ogre::Vector3(0,1,0),Ogre::Node::TS_LOCAL,Ogre::Vector3::UNIT_Y);
		SceneNodeManager()->setPosition(getWorldPosition().x,7,getWorldPosition().z);
	}
}

void PlayerTank::shake(){
	shakeTime=0.5;
}

void PlayerTank::reset(){
	setPosition(Ogre::Vector3(-40,7,0));
	HP= fullHP = 100;
	shakeTime = 0.;
}