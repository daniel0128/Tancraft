#pragma once
#include "swobject.h"
class StaticObject :
	public SWObject
{
public:
	StaticObject(Ogre::SceneManager *sceneManager, const char *meshName);
	~StaticObject(void);
	void setType(int t){type =t;}
	int getType(){return type;}

	void Think(float);

	bool isBuff(){ return !(type==0); }
protected:
	int type;
};

