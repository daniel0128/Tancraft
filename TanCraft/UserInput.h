#pragma once
#ifndef __UserInput_h_
#define __UserInput_h_
class InputHandler;
class TankManager;
class ProjectileManager;
class Tank;
class PlayerTank;
class Geometry;

class UserInput
{
public:
	UserInput(InputHandler* input, TankManager* tManager, ProjectileManager* pManager);
	~UserInput(void);
	void Think(float time);
	void addGeometry(Geometry* geo);
	//void setCameraToTank();
protected:
	TankManager* mTankManager;
	PlayerTank* playerTank;
	InputHandler* mInputHandler;
	ProjectileManager* mProjectileManager;
	Geometry* mGeometry;

};
#endif

