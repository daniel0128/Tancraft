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
#include "Physics.h"

World::World(Ogre::SceneManager *sceneManager, InputHandler *input, ProjectileManager *projectileManager,TankManager *tManager) 
	: mSceneManager(sceneManager), mInputHandler(input), mProjectileManager(projectileManager),mTankManager(tManager)
{
	mSceneManager->setAmbientLight(Ogre::ColourValue(1,1,1));
	
	//a rigid plane
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshPtr planePtr = Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
	//Ogre::Entity *entGround = sceneManager->createEntity("GroundEntity", "ground");
	Ogre::SceneNode *groundNode = sceneManager->getRootSceneNode()->createChildSceneNode("groundNode");
	//groundNode->attachObject(entGround);

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(0, 0, 0));
 
	btScalar groundMass(0.); //the mass is 0, because the ground is immovable (static)
	btVector3 localGroundInertia(0, 0, 0);
 
	btCollisionShape *groundShape = new btStaticPlaneShape(btVector3(0,1,0),0);
		//btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));
	btDefaultMotionState *groundMotionState = new btDefaultMotionState(groundTransform);
 
	groundShape->calculateLocalInertia(groundMass, localGroundInertia);
 
	btRigidBody::btRigidBodyConstructionInfo groundRBInfo(groundMass, groundMotionState, groundShape, localGroundInertia);
	btRigidBody *groundBody = new btRigidBody(groundRBInfo);
 
	//add the body to the dynamics world
	tankPhysics->getDynamicsWorld()->addRigidBody(groundBody);




	//playerTank = new Tank(SceneManager(),mProjectileManager,"Car.mesh","Battery.mesh");

	bullet1 = new Projectile(SceneManager(),mProjectileManager,Ogre::Vector3(20,10,20),Ogre::Vector3(1,1,1));
	bullet2 =new Projectile(SceneManager(),mProjectileManager,Ogre::Vector3(-20,10,20));
	bullet3 =new Projectile(SceneManager(),mProjectileManager,Ogre::Vector3(-20,10,-20));
	bullet4 =new Projectile(SceneManager(),mProjectileManager,Ogre::Vector3(20,10,-20));

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
World::Think(float time)
{
	//bullet2->getRigidBody()->translate(btVector3(0.0f,0.0f,0.02f));
	mProjectileManager ->Think(time);
	mTankManager->Think(time);
}



