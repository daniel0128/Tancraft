#ifndef __TanCraft_h_
#define __TanCraft_h_

// Including header files within header files is frowned upon,
// but this one is requried for Ogre Strings.
#include "OgrePrerequisites.h"
#include "OgreWindowEventUtilities.h"

namespace Ogre {
    class Root;
    class RenderWindow;
    class Camera;
    class SceneManager;
	class OverlaySystem;
}

class InputHandler;
class World;
class TankCamera;
class MainListener;
class Geometry;
class ProjectileManager;
class TankManager;
class UserInput;

class TanCraft :  public Ogre::WindowEventListener
{
public:
    TanCraft();
    ~TanCraft();

    // Do all the application setup
    bool setup(void);

    // Start runn
    void go(void);

	//level
	static int level;

protected:

    ///////////////////////////////////////////////////
    /// The following methods are all called by the public
    ///   setup method, to handle various initialization tasks
    //////////////////////////////////////////////////

    //  Load all the requrired resources (Mostly reading the file paths
    //  of various resources from the .cfg files)
    void setupResources(void);

    // Invoke the startup window for all of the Ogre settings (resolution, etc)
    bool configure(void);

    // Create all of the required classes and do setup for all non-rendering tasks
    void createScene(void);

    // Free up all memory & resources created in createScene
    void destroyScene(void);

    // Create the rendering camera (separate from the game camera -- the game camera
    //   contains the logic of how the camera should be moved, the rendering camera
    //   is used by the rendering system to render the scene.  So, the game camera 
    //   decides where the camera should be, and then makes calls to the rendering camera
    //   to move the camera
	void createCamera(void);

	void createViewports(void);

    // The FrameListener is what receives callbacks from the rendering loop to handle 
    //  game logic
	void createFrameListener(void);

	MainListener *mPongFrameListener;


	InputHandler *mInputHandler;
	World *mWorld;
    TankCamera *mTankCamera;

	//what I added (D Z)
	TankManager* mTankManager;
	ProjectileManager* mProjectileManager; 
	UserInput* mUserInput;
	Geometry* mGeometry;

    Ogre::Root *mRoot;
    Ogre::Camera* mCamera;
	Ogre::Camera* mapCamera;
    Ogre::SceneManager* mSceneMgr;
	Ogre::RenderWindow* mWindow;
    Ogre::String mResourcePath;
	Ogre::OverlaySystem *mOverlaySystem;

};

#endif // #ifndef __TanCraft_h_