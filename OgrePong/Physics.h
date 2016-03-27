#pragma once
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"


class Physics
{
public:
	Physics(void);
	~Physics(void);
	btDiscreteDynamicsWorld* getDynamicsWorld(){return dynamicsWorld;}
	int getCollisionObjectCount(){return dynamicsWorld->getNumCollisionObjects();}
	Physics* getPhysics(){return this;}
	std::vector<btCollisionShape* > *getCollisionShapes(){return &collisionShapes;}

protected:
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
	std::vector<btCollisionShape *> collisionShapes;
	std::map<std::string, btRigidBody *> physicsAccessors;
};

extern Physics* tankPhysics;