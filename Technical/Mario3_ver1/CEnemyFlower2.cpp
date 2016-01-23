#include "CEnemyFlower2.h"


CEnemyFlower2::CEnemyFlower2()
{
}

CEnemyFlower2::CEnemyFlower2(Vector2 pos)
{
	Init();
	this->m_Pos = pos;
}

void CEnemyFlower2::Init()
{
	//khoi tao id de lay hinh anh
	this->m_Id = 104;
	this->m_IdType = 104;//id Image
	this->m_mang = 1;
	this->status = ENEMY_STATUS::ENEMY_MOVE;
	this->m_Tag = Tag::ENEMY;
	this->m_isLife = true;
	this->m_timeRemove = 0;
	this->isRemove = false;
	this->m_Dir = Direction::RIGHT;

	//khoi tao Animation
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.2f;
	this->m_increase = 1;
	this->m_totalFrame = 2;
	this->m_column = 2;

	this->m_startFrame = 0;
	this->m_endFrame = 1;

	//khoi tao Texture
	this->m_Pos = Vector2(10, 100);
	this->m_Width = 16;
	this->m_Height = 12;
	this->speed = 15;

}

// update chinh 
void CEnemyFlower2::Update(float deltaTime)
{
	ChangeFrame(deltaTime);
	SetFrame(deltaTime);
	OnCollision(deltaTime);

	//MoveUpdate(deltaTime);
}
void CEnemyFlower2::MoveUpdate(float deltaTime)
{
	//this->m_Pos.x += 20 * deltaTime;
}
void CEnemyFlower2::OnCollision(float deltaTime, std::vector<Ground> listGround)
{}

void CEnemyFlower2::SetFrame(float deltaTime)
{
	if (this->status != ENEMY_STATUS::ENEMY_NONE)
	{
		if (this->m_Height <= 24)
		{
			this->m_Height += this->speed * deltaTime;
		}
		else
		{
			this->status = ENEMY_STATUS::ENEMY_NONE;
		}

	}
	if (this->status == ENEMY_STATUS::ENEMY_NONE)
	{
		if (this->m_Height >= 0)
		{
			this->m_Height -= this->speed * deltaTime;
			if (this->m_Height <= 0)
			{
				this->status = ENEMY_STATUS::ENEMY_MOVE;
			}
		}
	}
}

void CEnemyFlower2::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}

void CEnemyFlower2::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CEnemyFlower2::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CEnemyFlower2::OnCollision(float deltaTime)//xet va cham voi Player
{
	if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
	{
		//MessageBox(NULL, "Mario Die", "Game Over", MB_OK);
		if (this->m_Height > 0)
			CMarioObject::GetInstance()->MarioDie();
		//CMarioObject::GetInstance()->m_vy = 120;
	}
}

Box CEnemyFlower2::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 1, 0, 0);
}

RECT* CEnemyFlower2::GetBound()
{
	return nullptr;
}
RECT* CEnemyFlower2::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}

CEnemyFlower2::~CEnemyFlower2()
{
}
