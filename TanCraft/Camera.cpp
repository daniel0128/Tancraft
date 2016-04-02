#include "OgreCamera.h"
#include "Camera.h"
#include "TankManager.h"
#include "OgreVector3.h"
#include "PlayerTank.h"

#include "InputHandler.h"

TankCamera::TankCamera(Ogre::Camera *renderCamera,Ogre::Camera *mapCamera, TankManager *tManager) :
	mRenderCamera(renderCamera), mTankManager(tManager),shakeTime(.0),shakeAmplitude(Ogre::Math::PI/180)
{
	mRenderCamera->setNearClipDistance(2);
	mTankManager->getPlayerTank()->setPlayerCamera(mRenderCamera);


	mapCamera->setNearClipDistance(5);
	mTankManager->getPlayerTank()->setRadarCamera(mapCamera);
}

void
TankCamera::Think(float time)
{
	if(shakeTime>0){
		shakeAmplitude*=-1;
		mRenderCamera->roll(Ogre::Radian(shakeAmplitude));
		shakeTime-=time;
	}
}

void TankCamera::shake(){
	shakeTime=.5;
}
