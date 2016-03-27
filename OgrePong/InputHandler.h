#ifndef __InputHandler_h_
#define __InputHandler_h_

#include <ois/ois.h>
#include <Ogre.h>
#include "OgreRenderWindow.h"

class World;
class PongCamera;
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
	
	//bool mouseMoved(const OIS::MouseEvent &) override;      

	//bool mousePressed(const OIS::MouseEvent &,OIS::MouseButtonID) override;

	//bool mouseReleased(const OIS::MouseEvent &,OIS::MouseButtonID)override;

	//bool keyPressed(const OIS::KeyEvent &) override;

	//bool keyReleased(const OIS::KeyEvent &) override;

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
	std::vector<OIS::KeyListener*> keyListeners;
	std::vector<OIS::MouseListener*> mouseListeners;

};

#endif