#ifndef __CBACK_GROUND__H__
#define __CBACK_GROUND__H__
#pragma once
#include "CBaseGameObject.h"
class CBackGround: public CBaseGameObject
{
public:
	CBackGround();
	~CBackGround();
public :
	void Update(float deltaTime);//ham Update chinh cua game
	void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	void OnCollision(float deltaTime, CBaseGameObject* Object) ;//Test va cham voi 1 doi tuong
	Vector2 GetPos(){ return this->m_Pos; };//lay ra vi tri cua Doi tuong
	Tag GetTag(){ return this->m_Tag; };//lay ra tag loai nao
	void SetTag(Tag tag){ this->m_Tag = tag; };//set la loai doi tuong nao
	int GetID(){ return this->m_Id; };
	int GetIDType(){ return this->m_IdType; };
	Direction GetDirection(){ return this->m_Dir; };
	int GetWidth(){ return this->m_Width; };
	int GetHeight(){ return this->m_Height; };
	bool IsAlive(){ return this->m_isLife; };

	void SetPos(Vector2 pos);
	void SetAlive(bool islife);
	void SetLeft(Direction left);
	Box GetBox();
	RECT* GetBound();
	RECT* GetRectRS();
};
#endif 