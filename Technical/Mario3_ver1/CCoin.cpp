#include "CCoin.h"


CCoin::CCoin()
{
	Init();
	this->isRemove = false;
}

CCoin::CCoin(Vector2 pos)
{
	Init();
	this->m_Pos = pos;
}
CCoin::CCoin(Vector2 pos, bool _isCoin)
{
	Init();
	this->m_Pos = pos;
	this->isCoin = _isCoin;
}
CCoin::~CCoin()
{
}
void CCoin::Init()
{
	//khoi tao thong so Image
	this->m_Id = 301;
	this->m_IdType = 301;//id Image

	//khoi tao Animation
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.1f;
	this->m_increase = 1;
	this->m_totalFrame = 5;
	this->m_column = 5;

	this->m_startFrame = 0;
	this->m_endFrame = 4;

	//khoi tao thong so di chuyen
	this->m_vx = 0;
	this->m_vy = 100;

	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;
	this->m_a = -300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Pos = Vector2(200, 200);
	this->m_Width = 14;
	this->m_Height = 16;
	this->m_isJumping = false;
	this->m_canJump = true;
	
}
void CCoin::Update(float deltaTime)
{
	ChangeFrame(deltaTime);
	MoveUpdate(deltaTime);
	OnCollision(deltaTime);
	if (!this->isCoin)
	{
		this->timeActive += deltaTime;
		if (this->timeActive > 1)
		{
			this->isRemove = true;
		}
	}
}
void CCoin::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{}
void CCoin::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CCoin::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CCoin::OnCollision(float deltaTime, std::vector<Ground> listGround)
{}
void CCoin::OnCollision(float deltaTime)
{
	if (this->isCoin)
	{
		if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
		{
			//delete this;
			this->isRemove = true;
		}
	}
}
void CCoin::MoveUpdate(float deltaTime)
{
	if (!this->isCoin)
	{

		this->m_vy += this->m_a *deltaTime;
		this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
	}
}

Box CCoin::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 3, this->m_vx, this->m_vy);
}
RECT* CCoin::GetBound()
{
	return nullptr;
}
RECT* CCoin::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}