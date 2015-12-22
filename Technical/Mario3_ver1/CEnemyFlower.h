#pragma once
#include "CBaseEnemy.h"
#include "CAnimation.h"
#include "CPoolObject.h"
#include "CBullet.h"
class CEnemyFlower: public CBaseEnemy, CAnimation
{
public:
	CEnemyFlower();
	CEnemyFlower(Vector2 pos);
	~CEnemyFlower();
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
public:
	void Init();
	void SetFrame(float deltaTime);
	BULLET_DIR GetDirEnemyFlower();
private:
	void Bullet(float deltaTime);
	
	float speed;
};

