#include "InputHandler.h"
#include "Ogre.h"
#include "OgreStringConverter.h"
#include <OIS/OIS.h>

#include <stdio.h>

InputHandler::InputHandler(Ogre::RenderWindow *renderWindow) : 
	 mRenderWindow(renderWindow)
{
	OIS::ParamList pl;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;

	renderWindow->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

	mInputManager = OIS::InputManager::createInputSystem( pl );

	mCurrentKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, false /* not buffered */ ));
	
	mCurrentMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject(OIS::OISMouse, false));
}


bool
InputHandler::IsKeyDown(OIS::KeyCode key)
{
	return mCurrentKeyboard->isKeyDown(key);
}

bool
InputHandler::WasKeyDown(OIS::KeyCode key)
{
	return mOldKeys[key] != '\0';
}

bool 
InputHandler::IsMouseBtnDown(OIS::MouseButtonID button){
	return mCurrentMouse->getMouseState().buttonDown(button);
}

OIS::MouseState 
InputHandler::GetMouseState(){
	return mCurrentMouse->getMouseState();
}

void 
InputHandler::Think(float time)
{
	mCurrentKeyboard->copyKeyStates(mOldKeys);
	mCurrentKeyboard->capture();
	mCurrentMouse->capture();
}


InputHandler::~InputHandler()
{
	mInputManager->destroyInputObject(mCurrentKeyboard);

	//so I need destroy mouse here
	mInputManager->destroyInputObject(mCurrentMouse);
}
