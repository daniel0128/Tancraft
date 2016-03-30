#include "OgreCamera.h"
#include "Camera.h"
#include "TankManager.h"
#include "OgreVector3.h"
#include "PlayerTank.h"

#include "InputHandler.h"

TankCamera::TankCamera(Ogre::Camera *renderCamera,Ogre::Camera *mapCamera, TankManager *tManager) :
mRenderCamera(renderCamera), mTankManager(tManager)
{
	mRenderCamera->setNearClipDistance(2);
	//mTankManager->getPlayerTank()->getBarrel()->setCameraToLocal(mRenderCamera);
	mTankManager->getPlayerTank()->setPlayerCamera(mRenderCamera);


	mapCamera->setNearClipDistance(5);
	mTankManager->getPlayerTank()->setRadarCamera(mapCamera);
}

void
TankCamera::Think(float time)
{
	// Any code needed here to move the camera about per frame
	//  (use mRenderCamera to get the actual render camera, of course!)
}
