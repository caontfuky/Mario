#ifndef __CBASE_ENEMY_H__
#define __CBASE_ENEMY_H__
#pragma once
#include "CBaseGameObject.h"
#include "CAnimation.h"
#include "CMove.h"
#include "CMarioObject.h"
enum ENEMY_STATUS
{
	ENEMY_NONE = 0,
	ENEMY_MOVE = 1,
	ENEMY_DIE = 2,
	ENEMY_ATTACK = 3
};
enum LEVEL
{
	LEVEL_0 = 0,
	LEVEL_1 = 1,
	LEVEL_2 = 2,
	LEVEL_3 = 3,
};
class CBaseEnemy: public CBaseGameObject
{
public:
	CBaseEnemy();
	~CBaseEnemy();

	int m_mang;
	ENEMY_STATUS status;
	LEVEL level;
	bool isGround;
	int lv;
	//cac ham tu BasegameObject
public:
	virtual void Update(float deltaTime);//ham Update chinh cua game
	virtual void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	virtual void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	virtual void OnCollision(float deltaTime, CBaseGameObject* Object) = 0;//ham xet va cham
	virtual void OnCollision(float deltaTime) = 0;
	virtual void OnCollision(float deltaTime, std::vector<Ground> listGround) = 0;
	virtual Box GetBox();
	virtual RECT* GetBound();
	virtual RECT* GetRectRS();
};
#endif // !__CFILE_UTIL_H__

