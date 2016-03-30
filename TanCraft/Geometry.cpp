#include "stdafx.h"
#include "Geometry.h"
#include "StaticObject.h"


Geometry::Geometry(Ogre::SceneManager* sceneManager):mSceneManager(sceneManager)
{
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
	mSceneManager->getRootSceneNode()->createChildSceneNode("NWALL",Ogre::Vector3(0,-100,-500))->attachObject(nWallEnt); 
	
	Ogre::Plane sWall; 
	sWall.normal = Ogre::Vector3::NEGATIVE_UNIT_Z; //the plane will face to
	sWall.d = 0.0;  //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("SWall",  
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, sWall,  
	1000, 500, 1, 1, true, 1, 5, 5, Ogre::Vector3::UNIT_Y); //when u face it , the up side 
	Ogre::Entity* sWallEnt = mSceneManager->createEntity( "SouthWall", "SWall" );  
	sWallEnt->setMaterialName("Examples/Rockwall");  
	sWallEnt->setCastShadows(false);  
	mSceneManager->getRootSceneNode()->createChildSceneNode("SWALL",Ogre::Vector3(0,-100,500))->attachObject(sWallEnt); 
	
	Ogre::Plane eWall; 
	eWall.normal = Ogre::Vector3::NEGATIVE_UNIT_X; //the plane will face to
	eWall.d = 0.0;  //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("EWall",  
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, eWall,  
	1000, 500, 1, 1, true, 1, 5, 5, Ogre::Vector3::UNIT_Y); //when u face it , the up side 
	Ogre::Entity* eWallEnt = mSceneManager->createEntity( "EastWall", "EWall" );  
	eWallEnt->setMaterialName("Examples/Rockwall");  
	eWallEnt->setCastShadows(false);  
	mSceneManager->getRootSceneNode()->createChildSceneNode("EWALL",Ogre::Vector3(500,-100,0))->attachObject(eWallEnt); 

	Ogre::Plane wWall; 
	wWall.normal = Ogre::Vector3::UNIT_X; //the plane will face to
	wWall.d = 0.0;  //It's basically the distance to move the plane along the given normal.
	Ogre::MeshManager::getSingleton().createPlane("WWall",  
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, wWall,  
	1000, 500, 1, 1, true, 1, 5, 5, Ogre::Vector3::UNIT_Y); //when u face it , the up side 
	Ogre::Entity* wWallEnt = mSceneManager->createEntity( "WestWall", "WWall" );  
	wWallEnt->setMaterialName("Examples/Rockwall");  
	wWallEnt->setCastShadows(false);  
	mSceneManager->getRootSceneNode()->createChildSceneNode("WWALL",Ogre::Vector3(-500,-100,0))->attachObject(wWallEnt); 
	
	StaticObject* box = new StaticObject(mSceneManager,"Box.mesh");
	box->setPosition(Ogre::Vector3(350,20,100));
	box->setScale(Ogre::Vector3(20,20,20));
	mStaticObjects.push_back(box);

}


Geometry::~Geometry(void)
{
}

std::vector<StaticObject*>*
Geometry::getStaticObjects(){
	return &mStaticObjects;
}
