#pragma once
class StaticObject;
class Geometry
{
public:
	Geometry(Ogre::SceneManager* sceneManager);
	~Geometry(void);
	std::vector<StaticObject*>* getStaticObjects();
	std::vector<StaticObject*>* getBuffList();
	void creatBuff();

protected:

	std::vector<StaticObject*> mBuffs;
	std::vector<StaticObject*> mStaticObjects;
	Ogre::SceneManager* mSceneManager;

	bool overlap(Ogre::Vector3);
};

