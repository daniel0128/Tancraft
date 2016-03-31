#include "Tank.h"
#include "OgreSceneManager.h"
#include "Projectile.h"
#include "ProjectileManager.h"
#include "OgreSceneNode.h"

Tank::Tank(Ogre::SceneManager *sceneManager, ProjectileManager* pManager, const char *carMesh, const char * barrelMesh)
	:MovingObject(sceneManager,NULL,NULL),mProjectileManager(pManager),alive(true)
{
	fireCD=float(rand()%20+1)/20;
	setScale(Ogre::Vector3(4,4,4));
	mCar = new MovingObject(sceneManager, carMesh, this);
	mBarrel = new MovingObject(sceneManager,barrelMesh,this);
	mBarrel ->SceneNodeManager()-> setPosition(Ogre::Vector3(0,1.5,0));
}

Tank::~Tank(void)
{
	//need destructor, but very wierd to code after such long experience of Java
	delete mCar;
	delete mBarrel;
}
void
Tank::tankMove(TankDirection way, float time){
	switch (way){
		//TODO: turn smoothly
		case FOWARD:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(-1,0,0),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			this->translate(Ogre::Vector3(time*movingSpeed,0,0), MovingObject::TS_LOCAL);
			break;
		case BACK:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(1,0,0),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			translate(Ogre::Vector3(-time * movingSpeed,0,0),MovingObject::TS_LOCAL);
			break;
		case RIGHT:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(0,0,-1),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			translate(Ogre::Vector3( 0,0,time*movingSpeed),MovingObject::TS_LOCAL);
			break;
		case LEFT:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(0,0,1),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			translate( Ogre::Vector3(0,0,-time * movingSpeed),MovingObject::TS_LOCAL);
			break;
			//TODO:finish this
		case FOR_LEFT:
			break;
		case FOR_RIGHT:
			break;
		case BACK_LEFT:
			break;
		case BACK_RIGHT:
			break;
		default:
			break;
	}
}
void Tank::barrelRotate(Rotate way, float time){
	switch (way)
	{
	case PITCH:
		//this may not neccessary
		break;
	case YAW:
		//mTank->
		yaw(Ogre::Radian(time * palstance));
		mCar->yaw(Ogre::Radian(-time * palstance));
		break;
	case ROLL:
		mBarrel->roll(Ogre::Radian(time*palstance));
		break;
	default:
		break;
	}
}
void
Tank::fire(){
	if(fireCD<0.000001){
		Projectile* bullet = new Projectile(getSceneManager(),mProjectileManager,this);
		mProjectileManager->getBulletList()->push_back(bullet);
		fireCD=1.0;
	}
}



