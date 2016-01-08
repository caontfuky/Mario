#pragma once
#include "CAnimation.h"
#include "CMove.h"
#include "CTexture.h"
#include "CSprite.h"
#include "CResourece.h"
#include "CGlobal.h"
#include "CInput.h"
class CMarioWorldMap: public CAnimation, public CMove
{
public:
	CMarioWorldMap();
	~CMarioWorldMap();
public:
	int m_keyDown;
	int m_keyUp;
	float m_Width;
	float m_Height;
	bool isMove;
	Note note;
	Vector2 pos;

	CTexture* m_imageCurr; //Lay texture trong bo dem, can dung lop managertexture
	CSprite* m_drawImg; //Dung de ve anh len man hinh, can dung lop managerSprite

	void Draw();
	
public:
	void SetFrame();
	void MoveUpdate(float deltaTime);
	void SetNote(Note _note);
	void Update(float deltaTime);
	void OnKeyDown(float deltaTime);
	void OnkeyUp(float deltaTime);
	void OnCollision(std::vector<Note> listNote);
	RECT *GetRectRS();
	Box GetBox();
};

