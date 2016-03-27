#include "Projectile.h"
#include "OgreSceneNode.h"
#include "Physics.h"
#include "ProjectileManager.h"
#include "Tank.h"

Projectile::Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager,Ogre::Vector3 position)
	:MovingObject(sceneManager,"Cannon.mesh",NULL),bulletVelocity(Ogre::Vector3::ZERO),bulletRange(1000),mProjectileManager(pManager)
{
	this->setPosition(position);
	movingSpeed=1000;
	palstance=10;
	//movingShape = new btSphereShape(1.0f);
	//tankPhysics->getCollisionShapes()->push_back(movingShape);


	//btTransform startTransform;
	//startTransform.setIdentity();
	//startTransform.setRotation(btQuaternion(1.0f, 1.0f, 1.0f, 0));
 //
	////set the mass of the object. a mass of "0" means that it is an immovable object
	//btScalar mass = 0.1f;
	//btVector3 localInertia(0,0,0);
 //
	//startTransform.setOrigin(btVector3(position.x,position.y,position.z));
	//movingShape->calculateLocalInertia(mass, localInertia);
 //
	////actually contruvc the body and add it to the dynamics world
	//btDefaultMotionState *myMotionState = new btDefaultMotionState(startTransform);
 //
	//btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, movingShape, localInertia);
	//rBody= new btRigidBody(rbInfo);
	//rBody->setRestitution(1);
	//rBody->setUserPointer(SceneNodeManager());
	//tankPhysics->getDynamicsWorld()->addRigidBody(rBody);
	//tankPhysics->trackRigidBodyWithName(body, physicsCubeName);
}

Projectile::Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager,Ogre::Vector3 position, Ogre::Vector3 velocity)
	:MovingObject(sceneManager,"Cannon.mesh",NULL),mProjectileManager(pManager)
{
	this->setPosition(position);

	//bulletVelocity=velocity;
	movingSpeed=1000;
	palstance=10;//),movingSpeed(20)
	bulletVelocity = movingSpeed*velocity;
	

	//movingShape = new btSphereShape(1.0f);
	//tankPhysics->getCollisionShapes()->push_back(movingShape);


	//btTransform startTransform = this->transform;
	//startTransform.setIdentity();
	//startTransform.setRotation(btQuaternion(1.0f, 1.0f, 1.0f, 0));
 //
	////set the mass of the object. a mass of "0" means that it is an immovable object
	//btScalar mass = 1.0f;
	//btVector3 localInertia(0,0,0);
 //
	//startTransform.setOrigin(btVector3(position.x,position.y,position.z));
	//movingShape->calculateLocalInertia(mass, localInertia);
 //
	////actually contruvc the body and add it to the dynamics world
	//btDefaultMotionState *myMotionState = new btDefaultMotionState(startTransform);
 //
	//btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, movingShape, localInertia);
	//rBody = new btRigidBody(rbInfo);
	//rBody->setRestitution(1);
	//rBody->setUserPointer(SceneNodeManager());
	//rBody->setLinearVelocity(btVector3(bulletVelocity.x,bulletVelocity.y,bulletVelocity.z));
	//tankPhysics->getDynamicsWorld()->addRigidBody(rBody);

}

Projectile::Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager, Tank* fromTank)
	:MovingObject(sceneManager,"Cannon.mesh",NULL),mProjectileManager(pManager),mfromTank(fromTank)
{

	velocity=fromTank->getBarrel()->SceneNodeManager()->_getDerivedOrientation() * Ogre::Vector3(1,0,0);
	Ogre::Vector3 pos = fromTank->getBarrel()->getWorldPosition();
	this->setPosition(pos);

	//bulletVelocity=velocity;
	movingSpeed=1000;
	palstance=10;//),movingSpeed(20)
	bulletVelocity = movingSpeed*velocity;
}

Projectile::~Projectile(void)
{
}

void
Projectile::Think(float time){
	bulletRange-=time*movingSpeed;
	bulletVelocity-=time*Ogre::Vector3(0,50,0);
	translate(time*bulletVelocity,MovingObject::TS_WORLD);
}

bool
Projectile::fly(float time){
	bulletRange-=time*movingSpeed;
	bulletVelocity-=time*Ogre::Vector3(0,50,0);

	Ogre::Vector3 bulletPosition = mObjectSceneNode->getPosition();
	Ogre::Quaternion bulletOrientation = mObjectSceneNode->getOrientation();
	bulletPosition += bulletOrientation*bulletVelocity*time;
	mObjectSceneNode->setPosition(bulletPosition);
	//translate(time*bulletVelocity,MovingObject::TS_WORLD);

	Tank *hitedTank = mProjectileManager->checkCollision(this);

	if(bulletRange<0.000001||hitedTank!=NULL)
		return true;
	return false;
}

