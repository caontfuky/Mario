#ifndef __CBASEGAMEOBJECT__H__
#define __CBASEGAMEOBJECT__H__
#include "CGlobal.h"
enum Tag
{
	NONE_TAG = 0,
	PLAYER = 1,
	ENEMY = 2,
	BRICK = 3,
	BULLET = 4,
	GROUND = 5

};
enum Direction
{
	NONE_DIR = 0,
	LEFT = 1,
	RIGHT = 2,
};

class CBaseGameObject
{
public:
	int m_Id;// id cua Object. dung de load hinh anh
	int m_IdType;//thuoc loai doi tuong nao
	Vector2 m_Pos;//vi tri
	Tag m_Tag;//
	Direction m_Dir;//dang huong ve phia nao
	bool m_isLife;//life or die
	float m_Width;//chieu rong cua hinh
	float m_Height;//chieu cao cua hinh
	RECT *m_RectRS;//de xet va cham
	RECT m_Rect;//xet quadtree
	int m_Hp;//mau cua doi tuong
	float m_rotation;
public:
	float m_timeRemove;
	bool isRemove;
public:
	CBaseGameObject();
	~CBaseGameObject();

	virtual void Update(float deltaTime);//ham Update chinh cua game
	virtual void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	virtual void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision) = 0;//ham xet va cham
	virtual void OnCollision(float deltaTime, CBaseGameObject* Object) = 0;//Test va cham voi 1 doi tuong
	virtual void OnCollision(float deltaTime, std::vector<Ground> listGround) = 0;
	virtual Vector2 GetPos(){ return this->m_Pos; };//lay ra vi tri cua Doi tuong
	virtual Tag GetTag(){ return this->m_Tag; };//lay ra tag loai nao
	virtual void SetTag(Tag tag){ this->m_Tag = tag; };//set la loai doi tuong nao

	int GetID(){ return this->m_Id; };
	int GetIDType(){ return this->m_IdType; };
	Direction GetDirection(){ return this->m_Dir; };
	int GetWidth(){ return this->m_Width; };
	int GetHeight(){ return this->m_Height; };
	bool IsAlive(){ return this->m_isLife; };
	
	virtual void SetPos(Vector2 pos);
	virtual void SetAlive(bool islife);
	virtual void SetLeft(Direction left);
	virtual Box GetBox();
	virtual RECT* GetBound();
	virtual RECT* GetRectRS();
};
#endif // !__OBJECT_GAME__H__

