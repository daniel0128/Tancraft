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

	//walls
	Ogre::Plane nWall; 
	nWall.normal = Ogre::Vector3::UNIT_Z; //the plane will face to
	nWall.d = 0.0;  //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("NWall",  
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, nWall,  
	1000, 500, 1, 1, true, 1, 5, 5, Ogre::Vector3::UNIT_Y); //when u face it , the up side 
	Ogre::Entity* nWallEnt = mSceneManager->createEntity( "NorthWall", "NWall" );  
	nWallEnt->setMaterialName("Examples/Rockwall");  
	nWallEnt->setCastShadows(false);  
	mSceneManager->getRootSceneNode()->createChildSceneNode("NWALL",Ogre::Vector3(0,100,-500))->attachObject(nWallEnt); 
	
	Ogre::Plane sWall; 
	sWall.normal = Ogre::Vector3::NEGATIVE_UNIT_Z; //the plane will face to
	sWall.d = 0.0;  //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("SWall",  
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, sWall,  
	1000, 500, 1, 1, true, 1, 5, 5, Ogre::Vector3::UNIT_Y); //when u face it , the up side 
	Ogre::Entity* sWallEnt = mSceneManager->createEntity( "SouthWall", "SWall" );  
	sWallEnt->setMaterialName("Examples/Rockwall");  
	sWallEnt->setCastShadows(false);  
	mSceneManager->getRootSceneNode()->createChildSceneNode("SWALL",Ogre::Vector3(0,100,500))->attachObject(sWallEnt); 
	
	Ogre::Plane eWall; 
	eWall.normal = Ogre::Vector3::NEGATIVE_UNIT_X; //the plane will face to
	eWall.d = 0.0;  //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("EWall",  
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, eWall,  
	1000, 500, 1, 1, true, 1, 5, 5, Ogre::Vector3::UNIT_Y); //when u face it , the up side 
	Ogre::Entity* eWallEnt = mSceneManager->createEntity( "EastWall", "EWall" );  
	eWallEnt->setMaterialName("Examples/Rockwall");  
	eWallEnt->setCastShadows(false);  
	mSceneManager->getRootSceneNode()->createChildSceneNode("EWALL",Ogre::Vector3(500,100,0))->attachObject(eWallEnt); 

	Ogre::Plane wWall; 
	wWall.normal = Ogre::Vector3::UNIT_X; //the plane will face to
	wWall.d = 0.0;  //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("WWall",  
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, wWall,  
	1000, 500, 1, 1, true, 1, 5, 5, Ogre::Vector3::UNIT_Y); //when u face it , the up side 
	Ogre::Entity* wWallEnt = mSceneManager->createEntity( "WestWall", "WWall" );  
	wWallEnt->setMaterialName("Examples/Rockwall");  
	wWallEnt->setCastShadows(false);  
	mSceneManager->getRootSceneNode()->createChildSceneNode("WWALL",Ogre::Vector3(-500,100,0))->attachObject(wWallEnt); 
	
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



