#pragma once
#include "CBaseEnemy.h"
#include "CAnimation.h"

class CEnemyFlower2 :public CAnimation ,public CBaseEnemy,public CMove
{
private:
	// van toc di chuyen len xuong
	float speed;
public:
	CEnemyFlower2();
	CEnemyFlower2(Vector2 pos);
	~CEnemyFlower2();
public:
	void Update(float deltaTime);//ham Update chinh cua game
	void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	void OnCollision(float deltaTime, CBaseGameObject* Object);//ham xet va cham
	void OnCollision(float deltaTime);
	void OnCollision(float deltaTime, std::vector<Ground> listGround);
	void  MoveUpdate(float deltaTime);
	Box GetBox();
	RECT* GetBound();
	RECT* GetRectRS();

	void Init();
	void SetFrame(float deltaTime);
};

