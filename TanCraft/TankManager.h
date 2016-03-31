#pragma once
#ifndef __TankManager_h_
#define __TankManager_h_
#include "Tank.h"

class ProjectileManager;
class Tank;
class PlayerTank;
class AITank;
class Geometry;

class TankManager
{
public:
	TankManager(Ogre::SceneManager* sceneManager, ProjectileManager* pManager);
	~TankManager(void);
	void Think(float);
	//
	PlayerTank* getPlayerTank(){return playerTank;}
	std::vector<AITank*> *getTankList(){ return &tankList; }
	bool checkCollision();
	void addGeometry(Geometry* geo);

	int getRemaining() {return tankList.size()+enemyNum;}
	int getAIHP() {return AIHP;}
	int getAIBP() {return AIBP;}


	static int level;
	static bool gameRunning;

	void reset();
	
	int enemyNum;
protected:
	void spawnTank(int,int);
	void levelUp();
	//int enemyNum;

	PlayerTank* playerTank;
	Ogre::SceneManager* mSceneManager;
	ProjectileManager* mProjectileManager;
	std::vector<AITank*> tankList;
	Geometry* mGeometry;
	std::vector<Ogre::Vector3> levelCfg;

	//level
	int totalEnemyNum;
	int remainEnemyNum;
	int playerHP;
	int playerBP;
	int AIHP;
	int AIBP;
	bool overlap(Ogre::Vector3);

};
#endif