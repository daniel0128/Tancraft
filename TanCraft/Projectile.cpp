#include "Projectile.h"
#include "OgreSceneNode.h"
//#include "Physics.h"
#include "ProjectileManager.h"
#include "Tank.h"

Projectile::Projectile(Ogre::SceneManager *sceneManager,ProjectileManager* pManager, Tank* fromTank)
	:MovingObject(sceneManager,"Cannon.mesh",NULL),mProjectileManager(pManager),mfromTank(fromTank),bulletRange(1000)
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
	bulletVelocity-=time*Ogre::Vector3(0,20,0);
	translate(time*bulletVelocity,MovingObject::TS_WORLD);
}


