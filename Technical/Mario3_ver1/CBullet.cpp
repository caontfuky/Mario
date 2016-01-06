#include "CBullet.h"


CBullet::CBullet()
{
	Init();
}
CBullet::CBullet(Vector2 pos)
{
}
CBullet::CBullet(BULLET_DIR dir, Vector2 pos)
{
	Init();
	this->m_Pos = pos;
	this->dir = dir;
}


CBullet::~CBullet()
{
}
void CBullet::Init()
{
	//khoi tao thong so Object
	this->m_Id = 401;
	this->m_IdType = 401;//id Image	
	this->m_Tag = Tag::BULLET;
	this->m_isLife = true;
	this->m_timeRemove = 0;
	this->isRemove = false;
	this->m_Dir = Direction::RIGHT;
	this->m_rotation = 0;
	this->dir = BULLET_DIR::TOP_LEFT;

	//khoi tao thong so di chuyen
	this->m_vx = 0;
	this->m_vy = 0;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;
	this->m_a = 300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Pos = Vector2(200, 200);
	this->m_Width = 8;
	this->m_Height = 9;
	this->m_isJumping = false;
	this->m_canJump = true;
}
void CBullet::Update(float deltaTime)
{
	UpdateRotation(deltaTime);
	MoveUpdate(deltaTime);
	OnCollision(deltaTime);
}
void CBullet::OnCollision(float deltaTime, std::vector<Ground> listGround)
{}
float rotation = 0;
void CBullet::UpdateRotation(float deltaTime)
{	
	this->m_rotation -= 15 * deltaTime;	
}
void CBullet::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}
void CBullet::MoveUpdate(float deltaTime)
{
	switch (this->dir)
	{
	case BULLET_DIR::TOP_LEFT:
		this->m_vx = -40;
		this->m_vy = 30;
		break;
	case BULLET_DIR::TOP_RIGHT:
		this->m_vx = 40;
		this->m_vy = 30;
		break;
	case BULLET_DIR::DOWN_LEFT:
		this->m_vx = -40;
		this->m_vy = -30;
		break;
	case BULLET_DIR::DOWN_RIGHT:
		this->m_vx = 40;
		this->m_vy = -30;
		break;
	default:
		break;
	}
	this->m_Pos.x += this->m_vx * deltaTime;
	this->m_Pos.y += this->m_vy * deltaTime;
}
void CBullet::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CBullet::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CBullet::OnCollision(float deltaTime)//xet va cham voi Player
{
	if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
	{
		//MessageBox(NULL, "Bullet", "Game Over", MB_OK);
		CMarioObject::GetInstance()->MarioDie();
		//CMarioObject::GetInstance()->m_vy = 120;
		
	}
}

Box CBullet::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 3, this->m_vx, this->m_vy);
}
RECT* CBullet::GetBound()
{
	return nullptr;
}
RECT* CBullet::GetRectRS()
{
	RECT* rectRS = new RECT();
	
	//cập nhật lại vị trí của Rect Resource
	rectRS->left = 0;
	rectRS->right = m_Width;
	rectRS->top = 0;
	rectRS->bottom = m_Height;
	return rectRS;
}
