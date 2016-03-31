#pragma once
class OBB;
class SWObject
{
public:
	SWObject(Ogre::SceneManager *sceneManager, const char *meshName, SWObject* mParent);
	~SWObject(void);
	static float Distance(SWObject* object1, SWObject* object2);
	static float Distance(Ogre::Vector3, Ogre::Vector3);

	//getter
	Ogre::Vector3 getWorldPosition();

	//setter
	void setPosition(Ogre::Vector3);
	void setScale(Ogre::Vector3);
	
protected:
	//for obb type collision checking
	OBB* obb;
	
	//necessary
	SWObject *mParent;
	Ogre::Entity* ent;
    Ogre::SceneNode *mObjectSceneNode;
	Ogre::SceneManager *mSceneManager;
};

