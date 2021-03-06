#pragma once
#include "CAnimation.h"
#include "CBaseGameObject.h"
#include "CMarioObject.h"
#include"CManageAudio.h"
enum BRICK_STATUS
{
	BRICK_NONE = 0,
	BRICK_ITEM = 1,
};
class CBrick:public CBaseGameObject, public CAnimation
{
public:
	CBrick();
	CBrick(Vector2 pos);
	CBrick(Vector2 pos, int _level);
	~CBrick();
	BRICK_STATUS status;
	int level;
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
	void Init();
};

