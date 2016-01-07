#pragma once
#include"CBaseGameObject.h"
#include"CTexture.h"
#include"CSprite.h"
#include"CGlobal.h"
#include "CMove.h"

class CChooseItem:public CBaseGameObject 
{
public:
	CTexture* m_imageCurr; //Lay texture trong bo dem, can dung lop managertexture
	CSprite* m_drawImg; //Dung de ve anh len man hinh, can dung lop managerSprite
	int m_ChoiseID;
public:
	CChooseItem();
	virtual void Update(float deltaTime);
	virtual void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision) ;//ham xet va cham
	virtual void OnCollision(float deltaTime, CBaseGameObject* Object) ;//Test va cham voi 1 doi tuong
	virtual void OnCollision(float deltaTime, std::vector<Ground> listGround);
	~CChooseItem();

public:
	void Draw();
};

