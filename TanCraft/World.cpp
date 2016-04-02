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
#include "Geometry.h"
#include "StaticObject.h"


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

	//player hp
	Ogre::Overlay *HP = om.getByName("Hp");
	hp = Ogre::StringConverter::toString(mTankManager->getPlayerTank()->getHP());
	Ogre::TextAreaOverlayElement *hpp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Hp/Panel/HPtext");
	hpp->setCaption("HP:  "+hp);
	
	//player bp
	Ogre::Overlay *BulletPower = om.getByName("BulletPower");
	bulletPower = Ogre::StringConverter::toString(mTankManager->getPlayerTank()->getPower());
	Ogre::TextAreaOverlayElement *bp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("BulletPower/Panel/BulletPowertext");
	bp->setCaption("BulletPower:   "+ bulletPower);

	//enemy 
	Ogre::Overlay *Enemy = om.getByName("Enemy");
	level = Ogre::StringConverter::toString(TankManager::level);
	Ogre::TextAreaOverlayElement *lv = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/level");
	lv->setCaption("Level: "+level);

	enemies = Ogre::StringConverter::toString(mTankManager->getRemaining());
	Ogre::TextAreaOverlayElement *es = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/enemies");
	es->setCaption("Enemies: "+enemies);

	enemyHP = Ogre::StringConverter::toString(mTankManager->getAIHP());
	Ogre::TextAreaOverlayElement *ehp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/eHP");
	ehp->setCaption("EnemyHP: "+enemyHP);

	enemyBulletPower = Ogre::StringConverter::toString(mTankManager->getAIBP());
	Ogre::TextAreaOverlayElement *ebp = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Enemy/Panel/eBP");
	ebp->setCaption("EnemyBulletPower: "+enemyBulletPower);

	HP->show();
	BulletPower->show();
	Enemy->show();

	Ogre::Overlay *gameover = om.getByName("GameOver");

	if(!TankManager::gameRunning)
		gameover->show();
	else
		gameover->hide();
}


void 
World::Think(float time)
{
	if(TankManager::gameRunning){
	
		mProjectileManager ->Think(time);
		mTankManager->Think(time);
		StaticObject *s;
		std::vector<StaticObject* > *list = mGeometry->getBuffList();
		for(size_t i=0;i<list->size();i++){
			s = (StaticObject*)(*list)[i];
			s->Think(time);
		}
	}
	Display();
	//else{
	//	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	//	Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("Sample/Panel/Text1");
	//	te->setCaption("Press ENTER to restart game");
	//	te->show();
	//}
}

