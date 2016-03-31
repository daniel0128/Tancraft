#include "TankManager.h"
#include "AITank.h"
#include "PlayerTank.h"
#include "Geometry.h"
#include "StaticObject.h"


TankManager::TankManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager)
	:mSceneManager(sceneManager),mProjectileManager(pManager)
{
	playerTank = new PlayerTank(sceneManager, pManager);
	AIHP = AIBP = 5;
	enemyNum=0;
}

int TankManager::level=0;
bool TankManager::gameRunning = true;

TankManager::~TankManager(void)
{
}

void
TankManager::Think(float time){
	if(tankList.size()==0 && enemyNum==0){
		level++;
		if(level>10)
			level=1;
		mGeometry->creatBuff();
		enemyNum=level+3;
	}
	AIHP = AIBP= level*5;
	if(tankList.size()<5 && enemyNum>0){
		//TODO: set ai attributes based on level
		spawnTank(AIHP,AIBP);
		enemyNum--;
	}
	for(size_t i=0;i<tankList.size();i++){
		tankList[i]->Think(time);
		if(tankList[i]->getDisappear()<0.000001){
			delete tankList[i];
			tankList.erase(tankList.begin()+i);
		}
	}
}

bool 
TankManager::checkCollision(){
	StaticObject* so;
	Ogre::Vector3 pos;
	Ogre::Vector3 playerPos = playerTank->getWorldPosition();
	for(size_t i=0;i<tankList.size();i++){
		pos = tankList[i]->getWorldPosition();
		//enemy and player
		if(SWObject::Distance(tankList[i],playerTank)<15)
			return true;
		//enemy and enemy
		if (tankList.size()>2)		//enemyTank and enemyTank
		{
		   for(std::size_t j = i+1; j < tankList.size(); j++ )
			{
				if (SWObject::Distance( tankList[i] , tankList[j])<30)
					return true;
			}
		}
		//enemy and geometry
		std::vector<StaticObject* > *sObjs = mGeometry->getStaticObjects();
		for(size_t i =0;i<sObjs->size();i++){
			so = (StaticObject*)(*sObjs)[i];
			if(SWObject::Distance(pos,so->getWorldPosition())<30)
				return true;
		}

		//enemy and walls
		if(pos.x>490||pos.x<-490||pos.z>490||pos.z<-490)
			return true;

		//player and walls
		if(playerPos.x>490||playerPos.x<-490 || playerPos.z>490||playerPos.z<-490)
			return true;
		//player and geometry
			for(size_t i =0;i<sObjs->size();i++){
			so = (StaticObject*)(*sObjs)[i];
			if(SWObject::Distance(playerPos,so->getWorldPosition())<32){
				return true;
			}
		}
	}
	return false;
}

void TankManager::addGeometry(Geometry* geo){
	mGeometry = geo;
}

void TankManager::spawnTank(int hp, int bulletPower){
	AITank* aiTank;	
	aiTank = new AITank(mSceneManager,mProjectileManager,this,"Car.mesh","Battery.mesh");
	aiTank->setHP(hp);
	aiTank->setFulHP(hp);
	aiTank->setBulletPower(bulletPower);
	int x, z;
	//TODO: check the valid location
	x=Ogre::Math::RangeRandom(-400,400);
	z=Ogre::Math::RangeRandom(-400,400);
	aiTank->setPosition(Ogre::Vector3(x,7,z));

	tankList.push_back(aiTank);
}

void TankManager::reset(){
	for(int i=0;i<tankList.size();i++){
		delete tankList[i];
	}
	tankList.clear();
	playerTank->reset();
	level = 0;
}

bool TankManager::overlap(Ogre::Vector3 pos){
	StaticObject* s;
	std::vector<StaticObject*> *sl = mGeometry->getStaticObjects();

	if(SWObject::Distance(pos,playerTank->getWorldPosition())<30)
		return true;
	for(size_t i=0;i<sl->size();i++){
		s = (StaticObject*)(*sl)[i];
		if(SWObject::Distance( pos,s->getWorldPosition())<30)
			return true;
	}
	for(size_t i=0;i<tankList.size();i++){
		if(SWObject::Distance(pos,tankList[i]->getWorldPosition())<30)
			return true;
	}
	return false;
}