#pragma once
#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISInputManager.h>
 
#include <OgreRenderWindow.h>
class InputManager
	:public OIS::KeyListener, public OIS::MouseListener
{
public:
	InputManager(void);
	~InputManager(void);
	bool keyPressed(const OIS::KeyEvent &ke);

	bool keyReleased(const OIS::KeyEvent &ke) ;

	bool mouseMoved(const OIS::MouseEvent &ke);

	bool mousePressed(const OIS::MouseEvent &me, OIS::MouseButtonID id);

	bool mouseReleased(const OIS::MouseEvent &me, OIS::MouseButtonID id);

	void addKeyListener( OIS::KeyListener *keyListener, const std::string& instanceName );
    void addMouseListener( OIS::MouseListener *mouseListener, const std::string& instanceName );
    void removeKeyListener( OIS::KeyListener *keyListener );
    void removeMouseListener( OIS::MouseListener *mouseListener );

protected:
	OIS::Keyboard *mKeyboard;
	OIS::Mouse *mMouse;

	// dispatcher never owns the pointer
	std::map<std::string, OIS::KeyListener*> mKeyListeners;
    std::map<std::string, OIS::MouseListener*> mMouseListeners;
    std::map<std::string, OIS::JoyStickListener*> mJoystickListeners;
 
    std::map<std::string, OIS::KeyListener*>::iterator itKeyListener;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListener;
    std::map<std::string, OIS::JoyStickListener*>::iterator itJoystickListener;
 
    std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd;
    std::map<std::string, OIS::JoyStickListener*>::iterator itJoystickListenerEnd;
};

