#ifndef __World_h_
#define __World_h_

// Forward delcarations of Ogre classes.  Note the Ogre namespace!
namespace Ogre {
    class SceneNode;
    class SceneManager;
}

// Forward delcarations of our own classes
class PongCamera;
class InputHandler;
class Tank;


class World
{
public:
	
    World(Ogre::SceneManager *sceneManager, InputHandler *input);

    // You'll want various methods to access & change your world here
    
    void Think(float time);
	
	void addCamera(PongCamera *c) { mCamera = c; }

	Ogre::SceneManager *SceneManager() { return mSceneManager; }

	void setCameraToTank();

	//This is not neccesary if we do not allow user to control camera respectively (D Z)
	InputHandler *getHandler(){return mInputHandler;}
	
protected:

	Ogre::SceneManager *mSceneManager;

	InputHandler *mInputHandler;
	PongCamera *mCamera;
	Tank *playerTank;

	// Here is where you keep all your world data.
	//  You probably want to use containers (arrays / lists / classes / etc) to ogranize them, 
	//    instead of a whole list of variables.  

	Ogre::SceneNode *mTank;
	Ogre::SceneNode *mBattery;
	Ogre::SceneNode *mCar;
	
};

#endif