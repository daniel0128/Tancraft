#include "Projectile.h"
#include "OgreSceneNode.h"


Projectile::Projectile(Ogre::SceneManager *sceneManager,Ogre::Vector3 position)
	:MovingObject(sceneManager,"Cannon.mesh",NULL),bulletVelocity(Ogre::Vector3::ZERO),bulletRange(1000)
{
	this->setPosition(position);
	movingSpeed=1000;
	palstance=10;
}

Projectile::Projectile(Ogre::SceneManager *sceneManager,Ogre::Vector3 position, Ogre::Vector3 velocity)
	:MovingObject(sceneManager,"Cannon.mesh",NULL)
{
	this->setPosition(position);

	//bulletVelocity=velocity;
	movingSpeed=1000;
	bulletVelocity = movingSpeed*velocity;
	palstance=10;
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
	SceneNodeManager()->translate(time*bulletVelocity);
	if(bulletRange<0.000001)
		return true;
	return false;
}

