#pragma once
class StaticObject;
class Geometry
{
public:
	Geometry(Ogre::SceneManager* sceneManager);
	~Geometry(void);
	std::vector<StaticObject*>* getStaticObjects();
protected:
	std::vector<StaticObject*> mStaticObjects;
	Ogre::SceneManager* mSceneManager;
};

