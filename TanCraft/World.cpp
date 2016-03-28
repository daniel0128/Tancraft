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
//#include "Physics.h"

World::World(Ogre::SceneManager *sceneManager, InputHandler *input, ProjectileManager *projectileManager,TankManager *tManager) 
	: mSceneManager(sceneManager), mInputHandler(input), mProjectileManager(projectileManager),mTankManager(tManager)
{
	mSceneManager->setAmbientLight(Ogre::ColourValue(1,1,1));
	mSceneManager->setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_MODULATIVE);
	//sky
	mSceneManager->setSkyDome(true, "Examples/CloudySky", 5, 8);  
	//ground
	Ogre::Plane groundPlane; 
	groundPlane.normal = Ogre::Vector3::UNIT_Y; //the plane will face to
	groundPlane.d = -5; //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("Gplane",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, groundPlane,
		1000, 1000, 10, 10, true, 1, 5, 5, Ogre::Vector3::NEGATIVE_UNIT_Z); //when u face it , the up side 
	Ogre::Entity* gPlaneEnt = mSceneManager->createEntity( "GroundPlane", "Gplane" );
	mSceneManager->getRootSceneNode()->createChildSceneNode("GROUND",Ogre::Vector3(0,0,0))->attachObject(gPlaneEnt); 
	gPlaneEnt->setMaterialName("Examples/Floor");  
	//gPlaneEnt->setVisible(0);
	gPlaneEnt->setCastShadows(true);
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

void 
World::Think(float time)
{
	//bullet2->getRigidBody()->translate(btVector3(0.0f,0.0f,0.02f));
	mProjectileManager ->Think(time);
	mTankManager->Think(time);
}



