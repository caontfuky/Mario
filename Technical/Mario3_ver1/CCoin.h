#pragma once

#include "CBaseGameObject.h"
#include "CAnimation.h"
#include "CMove.h"
#include "CCollision.h"
#include "CMarioObject.h"
class CCoin: public CBaseGameObject, public CAnimation, public CMove
{
public:
	CCoin();
	CCoin(Vector2 pos);
	CCoin(Vector2 pos, bool _isCoin);
	~CCoin();
	float timeActive;
	bool isCoin;
public:
	void Update(float deltaTime);
	void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	void OnCollision(float deltaTime, CBaseGameObject* Object);//Test va cham voi 1 doi tuong
	void OnCollision(float deltaTime, std::vector<Ground> listGround);
	void OnCollision(float deltaTime);
	void MoveUpdate(float deltaTime);
	void Init();
	Box GetBox();
	RECT* GetBound();
	RECT* GetRectRS();
};

