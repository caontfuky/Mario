#pragma once
#include "CBaseEnemy.h"
#include "CAnimation.h"
#include "CMove.h"
class CEnemyTurtleFly : public CBaseEnemy, public CAnimation, public CMove
{
public:
	CEnemyTurtleFly();
	CEnemyTurtleFly(Vector2 pos);
	CEnemyTurtleFly(Vector2 pos, ENEMY_STATUS lv);
	~CEnemyTurtleFly();

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

private:
	float m_Distance;
	Vector2 m_PosStart;
	bool m_isMario;
	float timeReLoad;
};

