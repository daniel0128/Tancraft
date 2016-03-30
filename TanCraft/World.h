#ifndef __World_h_
#define __World_h_

// Forward delcarations of Ogre classes.  Note the Ogre namespace!
namespace Ogre {
    class SceneNode;
    class SceneManager;
}

// Forward delcarations of our own classes
class TankCamera;
class InputHandler;
class Tank;
class Projectile;
class ProjectileManager;
class TankManager;
class Geometry;

class World
{
public:
	
	World(Ogre::SceneManager *sceneManager, InputHandler *input, ProjectileManager *projectileManager,TankManager *tankManager,Geometry* geometry);

    // You'll want various methods to access & change your world here
    
    void Think(float time);
	
	void addCamera(TankCamera *c) { mCamera = c; }

	Ogre::SceneManager *SceneManager() { return mSceneManager; }

	//void setCameraToTank();

	//This is not neccesary if we do not allow user to control camera respectively (D Z)
	InputHandler *getHandler(){return mInputHandler;}
	void setInfoStr(std::string info){infoStr = info;}
	
protected:

	Ogre::SceneManager *mSceneManager;

	InputHandler *mInputHandler;
	TankCamera *mCamera;
	ProjectileManager *mProjectileManager;
	TankManager* mTankManager;
	Geometry* mGeometry;
	

	// Here is where you keep all your world data.
	//  You probably want to use containers (arrays / lists / classes / etc) to ogranize them, 
	//    instead of a whole list of variables.  


	std::string infoStr;
};

#endif