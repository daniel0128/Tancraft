#pragma once
#ifndef __UserInput_h_
#define __UserInput_h_
class InputHandler;
class TankManager;
class ProjectileManager;
class Tank;

class UserInput
{
public:
	UserInput(InputHandler* input, TankManager* tManager, ProjectileManager* pManager);
	~UserInput(void);
	void Think(float time);
	//void setCameraToTank();
protected:
	TankManager* mTankManager;
	Tank* playerTank;
	InputHandler* mInputHandler;
	ProjectileManager* mProjectileManager;
};
#endif
