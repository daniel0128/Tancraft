#include "stdafx.h"
#include "StaticObject.h"


StaticObject::StaticObject(Ogre::SceneManager *sceneManager, const char *meshName)
	:SWObject(sceneManager,meshName,NULL)
{
}


StaticObject::~StaticObject(void)
{
}
