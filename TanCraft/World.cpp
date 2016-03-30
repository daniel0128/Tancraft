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
	//Ogre::ResourceManager::ResourceMapIterator iter = Ogre::FontManager::getSingleton().getResourceIterator();
	//while (iter.hasMoreElements()) 
	//{ 
	//	iter.getNext()->load(); 
	//}

	// Now we will show the sample overlay.  Look in the file Content/Overlays/Example to
	// see how this overlay is defined
	//Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	//Ogre::Overlay *overly = om.getByName("Sample");
	//overly->show();
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
	Display();
	//bullet2->getRigidBody()->translate(btVector3(0.0f,0.0f,0.02f));
	mProjectileManager ->Think(time);
	mTankManager->Think(time);


}



