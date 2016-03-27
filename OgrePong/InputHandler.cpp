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
	//mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true));
	//mKeyboard->setEventCallback(this);
	//I added mouse operation
	
	mCurrentMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject(OIS::OISMouse, false));
	//mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true));
	//mMouse->setEventCallback(this);
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
	mCurrentKeyboard->capture();//dont understand this so not sure whether mouse need similar operation (D Z)
	//mKeyboard->capture();
	//mouse capture (D Z)
	//mMouse->capture();
	mCurrentMouse->capture();
}


InputHandler::~InputHandler()
{
	mInputManager->destroyInputObject(mCurrentKeyboard);

	//so I need destroy mouse here
	mInputManager->destroyInputObject(mCurrentMouse);
}

//bool 
//InputHandler::mouseMoved(const OIS::MouseEvent &e){
//	std::for_each(mouseListeners.begin(),mouseListeners.end(),[&](OIS::MouseListener *il)
//	{
//		if(il){
//			il->mouseMoved(e);
//		}
//	});
//	return true;
//}    
//
//bool InputHandler::mousePressed(const OIS::MouseEvent &e,OIS::MouseButtonID id){
//	std::for_each(mouseListeners.begin(), mouseListeners.end(), [&](OIS::MouseListener *il)
//	{
//		if(il){
//			il->mouseReleased(e,id);
//		}
//	});
//	return true;
//}
//
//bool 
//InputHandler::mouseReleased(const OIS::MouseEvent &e,OIS::MouseButtonID id){
//	std::for_each(mouseListeners.begin(), mouseListeners.end(), [&](OIS::MouseListener *il)
//	{
//		if (il)
//		{
//			il->mouseReleased(e, id);
//		}
//	});
//	return true;
//}
//
//bool 
//InputHandler::keyPressed(const OIS::KeyEvent &e){
//	std::for_each(keyListeners.begin(),keyListeners.end(),[&](KeyListener *il){
//		if(il)
//			il->keyPressed(e);
//	});
//    return true;
//}
//
//bool 
//InputHandler::keyReleased(const OIS::KeyEvent &e){
//	std::for_each(keyListeners.begin(),keyListeners.end(),[&](KeyListener *il){
//		if(il)
//			il->keyReleased(e);
//	});
//    return true;
//}
//
//void
//InputHandler::addKeyListener( OIS::KeyListener *keyListener ){
//	this->keyListeners.push_back(keyListener);
//}
//void
//InputHandler::addMouseListener( OIS::MouseListener *mouseListener ){
//	this->mouseListeners.push_back(mouseListener);
//}