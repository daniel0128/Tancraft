#pragma once
#include "swobject.h"
class StaticObject :
	public SWObject
{
public:
	StaticObject(Ogre::SceneManager *sceneManager, const char *meshName);
	~StaticObject(void);
};

