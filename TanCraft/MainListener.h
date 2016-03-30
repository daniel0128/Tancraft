#ifndef __MainListener_h_
#define __MainListener_h_

#include "Ogre.h"
#include "OgreFrameListener.h"


// Forward declaration of classes
namespace Ogre
{
	class RenderWindow;
}

class InputHandler;
class UserInput;
class World;
class TankCamera;
//class Physics;

class MainListener : public Ogre::FrameListener
{
public:
	MainListener(Ogre::RenderWindow *mainWindow, InputHandler *inputHandler, 
		UserInput *userInput, World *world, TankCamera *cam);

	bool frameStarted(const Ogre::FrameEvent &evt);


protected:
	InputHandler *mInputHandler;
	UserInput *mUserInput;
	//AIManager *mAIManager;
	World *mWorld;
    TankCamera *mTankCamera;
	Ogre::RenderWindow *mRenderWindow;
//	Physics *mPhysicsEngine;

	int x;
};

#endif