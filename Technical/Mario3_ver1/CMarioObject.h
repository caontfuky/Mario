#ifndef __CMARIO_OBJECT_H__
#define __CMARIO_OBJECT_H__

#include "CBaseGameObject.h"
#include "CAnimation.h"
#include "CSingleton.h"
#include "CMove.h"
#include "CInput.h"
#include "CCollision.h"

enum STATUS
{
	NONE_STATUS = 0,
	MOVE = 1,
	JUMB = 2,
	FLY = 3,
	DIE = 4
};
enum STAGE
{
	NONE_STAGE = 0,
	NORMAL = 1,
	BIG = 2
};
enum COLLISION
{
	NONE_COL= 0,
	ENEMY_COL = 1,
	BULLET_COL = 2,
	GROUND_COL = 3
};
class CMarioObject : public CBaseGameObject, public CAnimation, public CMove, public CSingleton<CMarioObject>
{
	friend class CSingleton<CMarioObject>;

public:
	CMarioObject();
	~CMarioObject();
	//cac ham ke thua tu BaseGameObject
public:
	void Update(float deltaTime);//ham Update chinh cua game
	void Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision);//ham Update de xe va cham
	void OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision);//ham xet va cham
	void OnCollision(float deltaTime, CBaseGameObject* Object);//ham xet va cham
	void OnCollision(float deltaTime, std::vector<Box> listBox);
	void OnCollision(float deltaTime, std::vector<Ground> listGround);
	Vector2 GetPos(){ return this->m_Pos; };//lay ra vi tri cua Doi tuong
	Tag GetTag(){ return this->m_Tag; };//lay ra tag loai nao
	void SetTag(Tag tag){ this->m_Tag = tag; };//set la loai doi tuong nao
	void SetAlive(bool islife);
	void SetLeft(Direction left);
	Box GetBox();
	RECT* GetBound();
	RECT* GetRectRS();
	//cac ham ke thua tu Animation
public:
	void SetFrame(float deltaTime);		// ham chuyen frame.
	//virtual RECT*& UpdateRectResource(int rsHeight, int rsWidth);	//cap nhat lai vi tri rect resources.
	//cac ham ke thua tu Move
public :
	virtual void MoveUpdate(float deltaTime);
	//xu ly Input
	void OnKeyDown(float deltaTime);
	void OnKeyUp(float deltaTime);
	void MarioDie();
	//cac thong so ve Mario
public:
	int m_keyDown;
	int m_keyUp;
	STATUS m_status;
	COLLISION m_collision;
	bool isInput;
	bool m_isGround;
	int level;
	bool m_isFly;
	bool m_isJumbFly;
	bool m_isCanJumbFly;
	bool m_isUndying;
	bool m_isRender;
	
private:
	float m_timeJumb = 10;//thoi gian addFore
	
	float m_vxMax;
	float m_vyMax;
	
private:
	void InitAnimation();//khoi tao cac thong so cua Mario
	void InitMove();//khoi tao cac thong so chuyen dong cua Mario
	void Collision(float deltaTime);//cac trang thai khi va cham vao doi tuong khac
	void Gravity(float deltaTime);
	void AddForce(float deltaTime);//mario nhay
	void Move(float deltaTime);

};
#endif // !__CCONTRA_H__

