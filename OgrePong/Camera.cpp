#include "OgreCamera.h"
#include "Camera.h"
#include "TankManager.h"
#include "OgreVector3.h"

#include "InputHandler.h"

PongCamera::PongCamera(Ogre::Camera *renderCamera, TankManager *tManager) :
mRenderCamera(renderCamera), mTankManager(tManager)
{
	mRenderCamera->setNearClipDistance(2);
	mTankManager->getPlayerTank()->getBarrel()->setCameraToLocal(mRenderCamera);
}

void
PongCamera::Think(float time)
{
	// Any code needed here to move the camera about per frame
	//  (use mRenderCamera to get the actual render camera, of course!)
}
