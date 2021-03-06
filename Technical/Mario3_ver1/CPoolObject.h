#ifndef __CPOOL_OBJECT_H__
#define __CPOOL_OBJECT_H__
#pragma once

#include "CSingleton.h"
#include "CDrawObject.h"
#include "CBaseEnemy.h"
#include "CBackGround.h"
#include "CLoadGameObject.h"
#include "CBoxGround.h"
#include "CLoadObject.h"

//Enemy
#include "CEnemyRun.h"
#include "CEnemyTurtle.h"
#include "CEnemyTurtleFly.h"
#include "CEnemyFlower.h"
#include"CEnemyFlower2.h"
//Brick
#include "CBrick.h"
#include "CStone.h"
//Effect
#include "CCoin.h"
#include "CItem.h"

//Bullet
#include "CBullet.h"
class CPoolObject : public CSingleton<CPoolObject>
{
	friend class CSingleton<CPoolObject>;
public:
	CPoolObject();
	~CPoolObject();

	std::vector<CBaseGameObject*> listEnemy;
	std::vector<CBaseGameObject*> listEffect;

	std::vector<int> m_listIdObject;
public:
	CBaseEnemy *enemy;
	CBaseEnemy *enemy1;
	CBackGround *background;

	CEnemyRun *enemyRun1;

	CCoin *coin;

	CBullet *bullet;
	CStone *stone;
	CEnemyTurtleFly *fly;
	CItem *item;

	CEnemyFlower2 *enemyFlower2;

	std::hash_map<int, CBaseGameObject*> m_listObjectCurr;
public:
	void LoadBackGround();//load back ground
	void CreateEnemy(int count);
	void CreateBrick(int count);
	void Update(float deltaTime);

	void LoadListGameObject();
	void CreateGameObject();
public:
	void Draw();

	//Effect
public:
	void RenderCoin(Vector2 pos);
	void FireBullet(BULLET_DIR dir, Vector2 pos);
	void RenderItem(Vector2 pos, TYPE_ITEM type);
	void Collision(float deltaTime);
	void CheckEnemyTurtleFly();
	bool contains(std::vector<int> v, int x);
};
#endif

