#include "Tank.h"
#include "OgreSceneManager.h"


Tank::Tank(Ogre::SceneManager *sceneManager,const char *carMesh, const char * barrelMesh):MovingObject(sceneManager,NULL,NULL)
{
	mTank = new MovingObject(sceneManager, NULL, NULL);
	mTank->setScale(Ogre::Vector3(5,5,5));
	mCar = new MovingObject(sceneManager, carMesh, mTank);
	mBarrel = new MovingObject(sceneManager,barrelMesh,mTank);
	mBarrel ->setPosition(Ogre::Vector3(0,1.6,0));
}

Tank::~Tank(void)
{
	//need destructor, but very wierd to code after such long experience of Java
}
void
Tank::tankMove(TankDirection way, float time){
	switch (way){
		case FOWARD:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(-1,0,0),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			mTank->translate(Ogre::Vector3(time*movingSpeed,0,0), MovingObject::TS_LOCAL);
			break;
		case BACK:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(1,0,0),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			mTank->translate(Ogre::Vector3(-time * movingSpeed,0,0),MovingObject::TS_LOCAL);
			break;
		case RIGHT:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(0,0,-1),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			mTank->translate(Ogre::Vector3( 0,0,time*movingSpeed),MovingObject::TS_LOCAL);
			break;
		case LEFT:
			mCar->SceneNodeManager()->setDirection(Ogre::Vector3(0,0,1),
				Ogre::Node::TS_PARENT,
				Ogre::Vector3::NEGATIVE_UNIT_X);
			mTank->translate( Ogre::Vector3(0,0,-time * movingSpeed),MovingObject::TS_LOCAL);
			break;
			//todo:finish this
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
		mTank->yaw(Ogre::Radian(time * palstance));
		mCar->yaw(Ogre::Radian(-time * palstance));
		break;
	case ROLL:
		mBarrel->roll(Ogre::Radian(time*palstance));
		break;
	default:
		break;
	}
}
