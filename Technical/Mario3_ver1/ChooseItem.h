#pragma once
#include"CBaseGameObject.h"
#include"CTexture.h"
#include"CSprite.h"
#include"CGlobal.h"
#include "CMove.h"
#include"CInput.h"
#include"CViewWindows.h"

enum directionItemChoisePlay
{
	UP =1,
	DOWN =2,
	DEFAULT = 3
};
class CChooseItem:public CBaseGameObject , CMove
{
public:
	CTexture* m_imageCurr; //Lay texture trong bo dem, can dung lop managertexture
	CSprite* m_drawImg; //Dung de ve anh len man hinh, can dung lop managerSprite
	int m_ChoiseID;
	directionItemChoisePlay direction;

	CInput *input;
public:
	CChooseItem();
	virtual void Update(float deltaTime);
	virtual void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision) ;//ham xet va cham
	virtual void OnCollision(float deltaTime, CBaseGameObject* Object) ;//Test va cham voi 1 doi tuong
	virtual void OnCollision(float deltaTime, std::vector<Ground> listGround);
	~CChooseItem();
	virtual void MoveUpdate(float deltaTime) ;
public:
	void Draw();
	int keyDown;
	void OnKeyDown(float deltaTime);
	void OnKeyUp(float deltaTime);


};

