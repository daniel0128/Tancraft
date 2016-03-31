#include "stdafx.h"
#include "StaticObject.h"


StaticObject::StaticObject(Ogre::SceneManager *sceneManager, const char *meshName)
	:SWObject(sceneManager,meshName,NULL)
{
	type=0;
}


StaticObject::~StaticObject(void)
{
}

void StaticObject::Think(float time){
	mObjectSceneNode->yaw(Ogre::Radian(time));
}
