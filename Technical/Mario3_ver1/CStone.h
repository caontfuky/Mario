#pragma once
#include "CBaseGameObject.h"
#include "CCollision.h"
#include "CMarioObject.h"
class CStone:public CBaseGameObject
{
public:
	CStone();
	~CStone();
public:
	void Update(float deltaTime);//ham Update chinh cua game
	void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	void OnCollision(float deltaTime, CBaseGameObject* Object);//ham xet va cham
	void OnCollision(float deltaTime);//xet va cham voi Player
	void OnCollision(float deltaTime, std::vector<Ground> listGround);
	Box GetBox();
	RECT* GetBound();
	RECT* GetRectRS();
};

