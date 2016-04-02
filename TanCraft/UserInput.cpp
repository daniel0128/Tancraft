#include "stdafx.h"
#include "UserInput.h"
#include "TankManager.h"
#include "PlayerTank.h"
#include "InputHandler.h"
#include "Geometry.h"
#include "StaticObject.h"

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
	if(TankManager::gameRunning){
		hitBuff();
	
		if (mInputHandler->WasKeyDown(OIS::KC_W)){
			playerTank->tankMove(Tank::FOWARD,time);
			if(mTankManager->checkCollision())
			{playerTank->tankMove(Tank::FOWARD,-time);}
		}else if(mInputHandler->IsKeyDown(OIS::KC_S)){//back
			playerTank->tankMove(Tank::BACK,time);
			if(mTankManager->checkCollision())
			{playerTank->tankMove(Tank::BACK,-time);}
		}
		if(mInputHandler->IsKeyDown(OIS::KC_A)){//left
			playerTank->tankMove(Tank::LEFT,time);
			if(mTankManager->checkCollision())
			{playerTank->tankMove(Tank::LEFT,-time);}
		}else if(mInputHandler->IsKeyDown(OIS::KC_D)){//right
			playerTank->tankMove(Tank::RIGHT,time);
			if(mTankManager->checkCollision())
			{playerTank->tankMove(Tank::RIGHT,-time);}
		}

		if(mInputHandler->IsKeyDown(OIS::KC_SPACE)){
			playerTank->shake();
		}

		 //mouse control of camera and barrel (D Z)
		 playerTank->barrelRotate(Tank::ROLL, -time*mInputHandler->GetMouseState().Y.rel);
		 playerTank->barrelRotate(Tank::YAW,  -time*mInputHandler->GetMouseState().X.rel);
		 if(mInputHandler->IsMouseBtnDown(OIS::MB_Left)){
			 playerTank->fire();
		 }
		 float cd = playerTank->getFireCD();
		 playerTank->setFireCD(cd-time);
	}else{
		if(mInputHandler->IsKeyDown(OIS::KC_RETURN)){
			mTankManager->reset();
			TankManager::gameRunning=true;
		}
	}
}

void UserInput::addGeometry(Geometry* geo){
	mGeometry=geo;
}

void UserInput::hitBuff(){
	StaticObject* s;
	std::vector<StaticObject*> * buffList = mGeometry->getBuffList();
	for(size_t i=0; i<buffList->size();i++){
		s = (StaticObject* )(*buffList)[i];
		if(SWObject::Distance(  playerTank->getWorldPosition(),s->getWorldPosition())<15){
			playerTank->buffed(s->getType());
			delete (*buffList)[i];
			buffList->erase(buffList->begin()+i);
		}
	}
}