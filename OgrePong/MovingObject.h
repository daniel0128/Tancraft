#pragma once
#ifndef _MovingObject_h_
#define __Tank_h_
namespace Ogre{
	class SceneNode;
    class SceneManager;
}

class MovingObject
{
public:
	MovingObject(Ogre::SceneManager *sceneManager, const char *meshName, MovingObject *parent);
	~MovingObject(void);
	void MovingObject::setPosition(Ogre::Vector3 position);
protected:
	MovingObject *mParent;
    Ogre::SceneNode *mObjectSceneNode;
};
#endif
