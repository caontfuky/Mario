#ifndef __CPOOL_OBJECT_H__
#define __CPOOL_OBJECT_H__
#pragma once

#include "CSingleton.h"
#include "CDrawObject.h"
#include "CBaseEnemy.h"
#include "CBackGround.h"

//Enemy
#include "CEnemyRun.h"

//Brick
#include "CBrick.h"
class CPoolObject : public CSingleton<CPoolObject>
{
	friend class CSingleton<CPoolObject>;
public:
	CPoolObject();
	~CPoolObject();

	std::vector<CBaseGameObject*> listEnemy;
	std::vector<CBaseGameObject*> listBrick;
public:
	CBaseEnemy *enemy;
	CBaseEnemy *enemy1;
	CBackGround *background;

	CEnemyRun *enemyRun1;


public:
	void LoadBackGround();//load back ground
	void CreateEnemy(int count);
	void CreateBrick(int count);

	void Update(float deltaTime);

public:
	void Draw();
};
#endif

