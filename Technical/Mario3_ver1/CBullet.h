#pragma once
#include "CMove.h"
#include "CBaseGameObject.h"
#include "CCollision.h"
#include "CMarioObject.h"
enum BULLET_DIR
{
	NONE = 0,
	TOP_LEFT = 1,
	TOP_RIGHT = 2,
	DOWN_LEFT = 3,
	DOWN_RIGHT = 4
};
class CBullet:public CBaseGameObject, public CMove
{
public:
	CBullet();
	CBullet(Vector2 pos);
	CBullet(BULLET_DIR dir, Vector2 pos);
	~CBullet();

	BULLET_DIR dir;
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
	void UpdateRotation(float deltaTime);
};

