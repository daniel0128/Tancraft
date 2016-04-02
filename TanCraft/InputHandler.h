#ifndef __InputHandler_h_
#define __InputHandler_h_

#include <ois/ois.h>
#include <Ogre.h>
#include "OgreRenderWindow.h"

class World;
class TankCamera;
class InputHandler;


class InputHandler 
	//: public OIS::MouseListener, public OIS::KeyListener
{
public:

	InputHandler(Ogre::RenderWindow* win);
	~InputHandler();
	void Think(float time);

	bool IsKeyDown(OIS::KeyCode key);
	bool WasKeyDown(OIS::KeyCode key);
	void addKeyListener( OIS::KeyListener *keyListener );
    void addMouseListener( OIS::MouseListener *mouseListener );

	//mouse control
	bool IsMouseBtnDown(OIS::MouseButtonID button);
	//I am not sure why here Captain Letter is used, but I decided to follow. (D Z)
	OIS::MouseState GetMouseState();

protected:
	OIS::InputManager* mInputManager;
	Ogre::RenderWindow *mRenderWindow;
	OIS::Keyboard *mPreviousKeyboard;
	OIS::Keyboard *mCurrentKeyboard;
	OIS::Mouse *mMouse;
	OIS::MouseListener* mListener;
	OIS::KeyListener* kListener;
	OIS::Mouse *mCurrentMouse;
	OIS::Keyboard *mKeyboard;

	char mOldKeys[256];

};

#endif