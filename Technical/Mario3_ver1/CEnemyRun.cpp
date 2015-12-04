#include "CEnemyRun.h"


CEnemyRun::CEnemyRun()
{
	Init();
}


CEnemyRun::~CEnemyRun()
{
}
void CEnemyRun::Init()
{
	//khoi tao id de lay hinh anh
	this->m_Id = 101;
	this->m_IdType = 101;//id Image
	this->m_mang = 1;
	this->status = ENEMY_STATUS::ENEMY_MOVE;
	this->m_Tag = Tag::ENEMY;
	this->m_isLife = true;
	this->m_timeRemove = 0;
	this->isRemove = false;

	//khoi tao Animation
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.1f;
	this->m_increase = 1;
	this->m_totalFrame = 3;
	this->m_column = 3;

	//khoi tao di chuyen

	this->m_vx = -40;
	this->m_vy = 0;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;	
	this->m_a = 300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Pos = Vector2(200, 410);
	this->m_Width = 20;
	this->m_Height = 16;
	this->m_isJumping = false;	
	this->m_canJump = true;
	this->m_elapseTimeChangeFrame = 0.2f;
}
void CEnemyRun::Update(float deltaTime)
{
	ChangeFrame(deltaTime);
	SetFrame(deltaTime);
	MoveUpdate(deltaTime);
	OnCollision(deltaTime);
}
void CEnemyRun::SetFrame(float deltaTime)
{
	switch (this->status)
	{
	case ENEMY_STATUS::ENEMY_MOVE:
		this->m_startFrame = 0;
		this->m_endFrame = 1;
		break;
	case ENEMY_STATUS::ENEMY_DIE:
		this->m_startFrame = 2;
		this->m_endFrame = 2;
		break;
	default:
		break;
	}
}
void CEnemyRun::MoveUpdate(float deltaTime)
{
	this->m_Pos.x += this->m_vx * deltaTime;
	if (this->m_Pos.x <= 0)
	{
		this->m_vx *= -1;
	}
	if (this->m_isLife == false)
	{
		this->m_timeRemove += deltaTime;
		if (this->m_timeRemove >= 0.5f)
		{
			this->isRemove = true;
		}
	}
}
void CEnemyRun::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}
void CEnemyRun::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CEnemyRun::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CEnemyRun::OnCollision(float deltaTime)//xet va cham voi Player
{
	float normalX = 0;
	float normalY = 0;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float timeCollision;
	timeCollision = CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this, normalX, normalY, moveX, moveY, deltaTime);

	if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
	{		
		
		if (normalY < 0)
		{
			this->m_vx = 0;
			this->m_isLife = false;
			this->status = ENEMY_STATUS::ENEMY_DIE;			
		}	
		
	}
	if (this->m_isLife)
	{
		if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
		{
			MessageBox(NULL, "Va cham theo  X", "VA CHam", MB_OK);
		}
	}
}

Box CEnemyRun::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 3, this->m_vx, this->m_vy);
}
RECT* CEnemyRun::GetBound()
{
	return nullptr;
}
RECT* CEnemyRun::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}