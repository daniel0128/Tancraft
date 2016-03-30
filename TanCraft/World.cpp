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
	
	mSoundEngine = createIrrKlangDevice();
	mSoundEngine->play2D("getout.ogg",true);



	// Yeah, this should be done automatically for all fonts referenced in an overlay file.
	//  But there is a bug in the OGRE code so we need to do it manually.
	Ogre::ResourceManager::ResourceMapIterator iter = Ogre::FontManager::getSingleton().getResourceIterator();
	while (iter.hasMoreElements()) 
	{ 
		iter.getNext()->load(); 
	}

}

//overlay
void
World::Display()
{

	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();

	Ogre::Overlay *HP = om.getByName("Hp");
	hp = Ogre::StringConverter::toString("100");
	Ogre::TextAreaOverlayElement *hpp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Hp/Panel/HPtext");
	hpp->setCaption("HP:  "+hp);
	
	Ogre::Overlay *BulletPower = om.getByName("BulletPower");
	bulletPower = Ogre::StringConverter::toString("10");
	Ogre::TextAreaOverlayElement *bp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("BulletPower/Panel/BulletPowertext");
	bp->setCaption("BulletPower:   "+ bulletPower);

	Ogre::Overlay *Enemy = om.getByName("Enemy");
	level = Ogre::StringConverter::toString("1");
	Ogre::TextAreaOverlayElement *lv = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/level");
	lv->setCaption("Level: "+level);

	enemies = Ogre::StringConverter::toString("3");
	Ogre::TextAreaOverlayElement *es = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/enemies");
	es->setCaption("Enemies: "+enemies);

	enemyHP = Ogre::StringConverter::toString("20");
	Ogre::TextAreaOverlayElement *ehp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/eHP");
	ehp->setCaption("EnemyHP: "+enemyHP);

	enemyBulletPower = Ogre::StringConverter::toString("50");
	Ogre::TextAreaOverlayElement *ebp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/eBP");
	ebp->setCaption("EnemyBulletPower: "+enemyBulletPower);


	HP->show();
	BulletPower->show();
	Enemy->show();

}

void 
World::Think(float time)
{
	if(TankManager::gameRunning){
		Display();
		mProjectileManager ->Think(time);
		mTankManager->Think(time);

	//std::string hudText6;
	//hudText6 = Ogre::StringConverter::toString(mTankManager->enemyNum);
	//Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	//Ogre::Overlay *overlay = om.getByName("Sample");
	//Ogre::TextAreaOverlayElement *hud6 = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Hud2/Panel/Text6");
	//overlay->setCaption("Enemy HP:  "+hudText6);
	//Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Sample/Panel/Text1");
	//te->setCaption(" level: "+Ogre::StringConverter::toString(TankManager::level)+
	//	"\n enemy: "+Ogre::StringConverter::toString(mTankManager->enemyNum)+
	//	"\n list: "+Ogre::StringConverter::toString(mTankManager->getTankList()->size())+
	//	"\n remain: "+Ogre::StringConverter::toString(mTankManager->getTankList()->size()+mTankManager->enemyNum)+
	//	"\n player HP: "+ Ogre::StringConverter::toString(mTankManager->getPlayerTank()->getHP())
	//	);
	}
	else{
		Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
		Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Sample/Panel/Text1");
		te->setCaption("Press ENTER to restart game");
	}
}

