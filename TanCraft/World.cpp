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
#include "PlayerTank.h"
#include "Projectile.h"
#include "Camera.h"
#include "InputHandler.h"
#include "ProjectileManager.h"
#include "TankManager.h"

World::World(Ogre::SceneManager *sceneManager, InputHandler *input, ProjectileManager *projectileManager,TankManager *tManager,Geometry* geometry) 
	: mSceneManager(sceneManager), mInputHandler(input), mProjectileManager(projectileManager),mTankManager(tManager),mGeometry(geometry)
{
	mSceneManager->setAmbientLight(Ogre::ColourValue(1,1,1));
	
	// Yeah, this should be done automatically for all fonts referenced in an overlay file.
	//  But there is a bug in the OGRE code so we need to do it manually.
	Ogre::ResourceManager::ResourceMapIterator iter = Ogre::FontManager::getSingleton().getResourceIterator();
	while (iter.hasMoreElements()) 
	{ 
		iter.getNext()->load(); 
	}

	// Now we will show the sample overlay.  Look in the file Content/Overlays/Example to
	// see how this overlay is defined
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	Ogre::Overlay *overlay = om.getByName("Sample");
	overlay->show();
}

void 
World::Think(float time)
{
	if(TankManager::gameRunning){
		//bullet2->getRigidBody()->translate(btVector3(0.0f,0.0f,0.02f));
	mProjectileManager ->Think(time);
	mTankManager->Think(time);

	std::string hudText6;
	hudText6 = Ogre::StringConverter::toString(mTankManager->enemyNum);
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	//Ogre::Overlay *overlay = om.getByName("Sample");
	//Ogre::TextAreaOverlayElement *hud6 = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Hud2/Panel/Text6");
	//overlay->setCaption("Enemy HP:  "+hudText6);


	Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Sample/Panel/Text1");

	te->setCaption(" level: "+Ogre::StringConverter::toString(TankManager::level)+
		"\n enemy: "+Ogre::StringConverter::toString(mTankManager->enemyNum)+
		"\n list: "+Ogre::StringConverter::toString(mTankManager->getTankList()->size())+
		"\n remain: "+Ogre::StringConverter::toString(mTankManager->getTankList()->size()+mTankManager->enemyNum)+
		"\n player HP: "+ Ogre::StringConverter::toString(mTankManager->getPlayerTank()->getHP())
		);
	}
	else{
		std::string hudText6;
	hudText6 = Ogre::StringConverter::toString(mTankManager->enemyNum);
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	//Ogre::Overlay *overlay = om.getByName("Sample");
	//Ogre::TextAreaOverlayElement *hud6 = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Hud2/Panel/Text6");
	//overlay->setCaption("Enemy HP:  "+hudText6);


	Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Sample/Panel/Text1");

	te->setCaption("Press ENTER to restart game");
	}
}



