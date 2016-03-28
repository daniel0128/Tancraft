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
class PongCamera;
//class Physics;

class MainListener : public Ogre::FrameListener
{
public:
	MainListener(Ogre::RenderWindow *mainWindow, InputHandler *inputHandler, 
		UserInput *userInput, World *world, PongCamera *cam);

	bool frameStarted(const Ogre::FrameEvent &evt);


protected:
	InputHandler *mInputHandler;
	UserInput *mUserInput;
	//AIManager *mAIManager;
	World *mWorld;
    PongCamera *mPongCamera;
	Ogre::RenderWindow *mRenderWindow;
//	Physics *mPhysicsEngine;

	int x;
};

#endif