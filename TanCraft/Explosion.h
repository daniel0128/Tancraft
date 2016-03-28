#pragma once
class Explosion
{
public:
	Explosion(Ogre::SceneManager *sceneManager,int explosion, Ogre::Vector3 position);
	~Explosion(void);
	void Think(float);
	float getTime(){return mTime;}
protected:
	Ogre::SceneManager *mSceneManager;
	Ogre::ParticleSystem* ps;
	Ogre::SceneNode* sn;
	float mTime;
};

