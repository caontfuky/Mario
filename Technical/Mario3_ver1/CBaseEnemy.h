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
	ENEMY_DIE = 2
};
class CBaseEnemy: public CBaseGameObject
{
public:
	CBaseEnemy();
	~CBaseEnemy();

	int m_mang;
	ENEMY_STATUS status;
	//cac ham tu BasegameObject
public:
	virtual void Update(float deltaTime);//ham Update chinh cua game
	virtual void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	virtual void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	virtual void OnCollision(float deltaTime, CBaseGameObject* Object) = 0;//ham xet va cham
	virtual void OnCollision(float deltaTime) = 0;
	virtual Box GetBox();
	virtual RECT* GetBound();
	virtual RECT* GetRectRS();
};
#endif // !__CFILE_UTIL_H__

