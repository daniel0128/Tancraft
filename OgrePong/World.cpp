// My header file.  This should go first!
#include "World.h"

// Ogre header files
#include "Ogre.h"
#include "OgreMath.h"
#include "OgreSceneManager.h"
#include "OgreSceneNode.h"
#include "OgreOverlayManager.h"
#include "OgreOverlay.h"
#include "OgreFontManager.h"
#include "OgreTextAreaOverlayElement.h"

// IOS (Input system) header files

#include <ois/ois.h>

// Other input files for my project
#include "Tank.h"
#include "Camera.h"
#include "InputHandler.h"


World::World(Ogre::SceneManager *sceneManager, InputHandler *input)   : mSceneManager(sceneManager), mInputHandler(input)
{
	mSceneManager->setAmbientLight(Ogre::ColourValue(1,1,1));

	playerTank = new Tank(SceneManager(),"Car.mesh","Battery.mesh");

	// Yeah, this should be done automatically for all fonts referenced in an overlay file.
	//  But there is a bug in the OGRE code so we need to do it manually.
	Ogre::ResourceManager::ResourceMapIterator iter = Ogre::FontManager::getSingleton().getResourceIterator();
	while (iter.hasMoreElements()) 
	{ 
		iter.getNext()->load(); 
	}

	// Now we will show the sample overlay.  Look in the file Content/Overlays/Example to
	// see how this overlay is defined
	//Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	//Ogre::Overlay *overly = om.getByName("Sample");
	//overly->show();
}

void
World::setCameraToTank(){
	if(playerTank)
		playerTank->getBarrel()->setCameraToLocal(mCamera->getCamera());
}

void 
World::Think(float time)
{

	// We can move the single object around using the input manager ...
	if (mInputHandler->IsKeyDown(OIS::KC_W)){//foward
		playerTank->tankMove(Tank::FOWARD,time);
	}else if(mInputHandler->IsKeyDown(OIS::KC_S)){//back
		playerTank->tankMove(Tank::BACK,time);
	}else if(mInputHandler->IsKeyDown(OIS::KC_A)){//left
		playerTank->tankMove(Tank::LEFT,time);
	}else if(mInputHandler->IsKeyDown(OIS::KC_D)){//right
		playerTank->tankMove(Tank::RIGHT,time);
	}else if(mInputHandler->IsKeyDown(OIS::KC_W) && mInputHandler->IsKeyDown(OIS::KC_A)){
	}else if(mInputHandler->IsKeyDown(OIS::KC_W) && mInputHandler->IsKeyDown(OIS::KC_D)){
	}else if(mInputHandler->IsKeyDown(OIS::KC_S) && mInputHandler->IsKeyDown(OIS::KC_A)){
	}else if(mInputHandler->IsKeyDown(OIS::KC_S) && mInputHandler->IsKeyDown(OIS::KC_D)){
	}

	 //Although mouse control is implemented, I still want to keep this (D Z)
	 if (mInputHandler->IsKeyDown(OIS::KC_LEFT))
	 {
		 playerTank->barrelRotate(Tank::YAW,time);
	 }else if(mInputHandler->IsKeyDown(OIS::KC_RIGHT))
	 {
		 playerTank->barrelRotate(Tank::YAW,-time);
	 }

	 if (mInputHandler->IsKeyDown(OIS::KC_UP))
	 {
		 playerTank->barrelRotate(Tank::ROLL,time);
	 }else if(mInputHandler->IsKeyDown(OIS::KC_DOWN))
	 {
		 playerTank->barrelRotate(Tank::ROLL,-time);
	 }

	 //mouse control of camera and barrel (D Z)
	 playerTank->barrelRotate(Tank::YAW,  -.1*mInputHandler->GetMouseState().X.rel);
	 playerTank->barrelRotate(Tank::ROLL, -.1*mInputHandler->GetMouseState().Y.rel);



	 // Some other fun stuff to try:
	 //mCoinNode->yaw(Ogre::Radian(time * RADIANS_PER_SECOND));
	 //mCoinNode->roll(Ogre::Radian(time * RADIANS_PER_SECOND));

	 //Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	 //Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Sample/Panel/Text1");
	 //te->setCaption("New Caption!");
}


