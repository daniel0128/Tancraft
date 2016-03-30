#include "stdafx.h"
#include "AITank.h"
#include "TankManager.h"


AITank::AITank(Ogre::SceneManager *sceneManager, ProjectileManager *pManager,TankManager* tManager,const char *carMesh, const char *barrelMesh)
	:Tank(sceneManager,pManager,carMesh,barrelMesh),mTankManager(tManager),operationTimer(0),operationCD(2.0)
{
	movingSpeed=5;
	disappearTimer = 1.0;
}


AITank::~AITank(void)
{
}

void
AITank::beHit(int demage){
	HP-=demage;
	if(HP<=0){
		alive=false;
		movingSpeed=0;
		SceneNodeManager()->setOrientation(Ogre::Quaternion(1,1,-1,1));
	}
}

void
AITank::Think(float time){
	if(alive){
		operationTimer-= time;

		if (operationTimer<=0)
		{
			operationTimer = operationCD;
			aiRotation = rand()%2+1;
			aiMove = rand()%4+1;
		}
	

		switch (aiRotation)
		{
		case 1:
			barrelRotate(YAW,-time*palstance);
			break;
		case 2:
			barrelRotate(YAW,time*palstance);
			break;
		default:
			break;
		}

		switch(aiMove)
		{
		case 1:
			tankMove(Tank::FOWARD,time*movingSpeed);
			if(mTankManager->checkCollision())
			{tankMove(Tank::FOWARD,-time*movingSpeed);}
			break;
		case 2:
			tankMove(Tank::BACK,time*movingSpeed);
			if(mTankManager->checkCollision())
			{tankMove(Tank::BACK,-time*movingSpeed);}
			break;
			
		case 3:
			tankMove(Tank::LEFT,time*movingSpeed);
			if(mTankManager->checkCollision())
			{tankMove(Tank::LEFT,-time*movingSpeed);}
			break;
		case 4:
			tankMove(Tank::RIGHT,time*movingSpeed);
			if(mTankManager->checkCollision())
			{tankMove(Tank::RIGHT,-time*movingSpeed);}
			break;
		default:
			break;		
		}	
		fireCD -= time;
		if (fireCD <= 0)
		{
			fire();
			fireCD = 2.0;	
		}
	}else{
		disappearTimer-=time;
	}
}