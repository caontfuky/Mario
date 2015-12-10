#pragma once
#include "CBaseEnemy.h"
#include "CAnimation.h"
#include "CMove.h"
class CEnemyRun: public CBaseEnemy, public CAnimation, public CMove
{
public:
	CEnemyRun();
	CEnemyRun(Vector2 pos);
	CEnemyRun(Vector2 pos, LEVEL level);
	~CEnemyRun();

public:
	void Update(float deltaTime);//ham Update chinh cua game
	void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	void OnCollision(float deltaTime, CBaseGameObject* Object);//ham xet va cham
	void OnCollision(float deltaTime, std::vector<Ground> listGround);
	void OnCollision(float deltaTime);//xet va cham voi Player
	void MoveUpdate(float deltaTime);
	Box GetBox();
	RECT* GetBound();
	RECT* GetRectRS();
public:
	void Init();
	void SetFrame(float deltaTime);
};

