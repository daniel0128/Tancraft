#ifndef __Camera_h_
#define __Camera_h_


namespace Ogre
{
    class Camera;
    class Vector3;
}
class TankManager;


class TankCamera
{

public:
    TankCamera(Ogre::Camera *renderCamera, Ogre::Camera *mapCamera, TankManager* tManager); 
	Ogre::Camera *getCamera(){return mRenderCamera;}
    void Think(float time);
    // If you have a different cameras, you'll want some acessor methods here.
    //  If your camera always stays still, you could remove this class entirely

protected:

    Ogre::Camera *mRenderCamera; 
    TankManager *mTankManager;

};

#endif