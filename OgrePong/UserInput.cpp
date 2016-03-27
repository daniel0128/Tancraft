#include "stdafx.h"
#include "UserInput.h"
#include "TankManager.h"
#include "InputHandler.h"

UserInput::UserInput(InputHandler* input, TankManager* tManager, ProjectileManager* pManager)
	:mInputHandler(input),mTankManager(tManager),mProjectileManager(pManager)
{
	playerTank = mTankManager->getPlayerTank();
}


UserInput::~UserInput(void)
{
}

void
UserInput::Think(float time){
	bool collision = mTankManager->checkCollision();
	if (mInputHandler->WasKeyDown(OIS::KC_W)){//foward
		//playerTank->getRigidBody()->setLinearVelocity(btVector3(30,0,0));
		playerTank->tankMove(Tank::FOWARD,time);
		if(mTankManager->checkCollision())
		{playerTank->tankMove(Tank::FOWARD,-time);}
	}else if(mInputHandler->IsKeyDown(OIS::KC_S)){//back
		playerTank->tankMove(Tank::BACK,time);
		if(mTankManager->checkCollision())
		{playerTank->tankMove(Tank::BACK,-time);}
	}else if(mInputHandler->IsKeyDown(OIS::KC_A)){//left
		playerTank->tankMove(Tank::LEFT,time);
		if(mTankManager->checkCollision())
		{playerTank->tankMove(Tank::LEFT,-time);}
	}else if(mInputHandler->IsKeyDown(OIS::KC_D)){//right
		playerTank->tankMove(Tank::RIGHT,time);
		if(mTankManager->checkCollision())
		{playerTank->tankMove(Tank::RIGHT,-time);}
	}else if(mInputHandler->IsKeyDown(OIS::KC_W) && mInputHandler->IsKeyDown(OIS::KC_A)){
	}else if(mInputHandler->IsKeyDown(OIS::KC_W) && mInputHandler->IsKeyDown(OIS::KC_D)){
	}else if(mInputHandler->IsKeyDown(OIS::KC_S) && mInputHandler->IsKeyDown(OIS::KC_A)){
	}else if(mInputHandler->IsKeyDown(OIS::KC_S) && mInputHandler->IsKeyDown(OIS::KC_D)){
	}else{
		//playerTank->getRigidBody()->setLinearVelocity(btVector3(0,0,0));
		playerTank->tankMove(Tank::STOP, time);
	}

	 //Although mouse control is implemented, I still want to keep this (D Z)
	 if (mInputHandler->IsKeyDown(OIS::KC_LEFT))
	 {
		 playerTank->barrelRotate(Tank::YAW,time);
	 }else if(mInputHandler->IsKeyDown(OIS::KC_RIGHT))
	 {
		 playerTank->barrelRotate(Tank::YAW,-time);
	 }

	 if (mInputHandler->IsKeyDown(OIS::KC_UP))
	 {
		 playerTank->barrelRotate(Tank::ROLL,time);
	 }else if(mInputHandler->IsKeyDown(OIS::KC_DOWN))
	 {
		 playerTank->barrelRotate(Tank::ROLL,-time);
	 }

	 //mouse control of camera and barrel (D Z)
	 
	 playerTank->barrelRotate(Tank::ROLL, -time*mInputHandler->GetMouseState().Y.rel);
	 playerTank->barrelRotate(Tank::YAW,  -time*mInputHandler->GetMouseState().X.rel);
	 if(mInputHandler->IsMouseBtnDown(OIS::MB_Left)){
		 playerTank->fire();
	 }
	 float cd = playerTank->getFireCD();
	 playerTank->setFireCD(cd-time);
}