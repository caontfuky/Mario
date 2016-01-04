#pragma once
#include "CAnimation.h"
#include "CBaseGameObject.h"
#include "CMarioObject.h"
#include "CMove.h"

enum TYPE_ITEM
{
	ITEM_NONE = 0,
	ITEM_MUSHROOM = 1,
	ITEM_FLY = 2,
};
class CItem :public CBaseGameObject, public CAnimation, public CMove
{
public:
	CItem();

	CItem(Vector2 pos, TYPE_ITEM _type);
	~CItem();
public:
	void Update(float deltaTime);//ham Update chinh cua game
	void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	void OnCollision(float deltaTime, CBaseGameObject* Object);//ham xet va cham
	void OnCollision(float deltaTime);//xet va cham voi Player
	void MoveUpdate(float deltaTime);
	void OnCollision(float deltaTime, std::vector<Ground> listGround);
	Box GetBox();
	RECT* GetBound();
	RECT* GetRectRS();
public:
	TYPE_ITEM type;
	void Init();
	bool isMove;
	bool isGround;
};

