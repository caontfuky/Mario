#include "CEnemyFlower.h"


CEnemyFlower::CEnemyFlower()
{
	Init();
}
CEnemyFlower::CEnemyFlower(Vector2 pos)
{
	Init();
	this->m_Pos = pos;
}
CEnemyFlower::CEnemyFlower(Vector2 pos, int lv)
{
	Init();
	this->m_Pos = pos;
	switch (lv)
	{
	case 0:
		
		break;
	case 1:
		this->m_Id = 103;
		this->m_IdType = 103;//id Image
		break;
	case 2:
		this->m_Id = 105;
		this->m_IdType = 105;//id Image
		break;
	default:
		break;
	}

}

CEnemyFlower::~CEnemyFlower()
{
}

void CEnemyFlower::Init()
{
	//khoi tao id de lay hinh anh
	this->m_Id = 103;
	this->m_IdType = 103;//id Image
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
	this->m_endFrame = 0;

	//khoi tao Texture
	this->m_Pos = Vector2(400, 350);
	this->m_Width = 16;
	this->m_Height = 0;
	this->speed = 15;
	
}
void CEnemyFlower::Update(float deltaTime)
{
	ChangeFrame(deltaTime);
	SetFrame(deltaTime);
	Bullet(deltaTime);
	OnCollision(deltaTime);
}
void CEnemyFlower::OnCollision(float deltaTime, std::vector<Ground> listGround)
{}
float timeAttack = 0;
void CEnemyFlower::Bullet(float deltaTime)
{
	if (this->status == ENEMY_STATUS::ENEMY_ATTACK)
	{		
		if (timeAttack > 2)
		{			
			this->status = ENEMY_STATUS::ENEMY_NONE;	
			timeAttack = 0;
		}
		timeAttack += deltaTime;
	}
}

void CEnemyFlower::SetFrame(float deltaTime)
{
	if (this->status != ENEMY_STATUS::ENEMY_NONE)
	{	
		if (this->m_Height <= 32)
		{
			this->m_Height += this->speed * deltaTime;		
			if (this->m_Height >= 32)
			{
				this->status = ENEMY_STATUS::ENEMY_ATTACK;
				
				CPoolObject::GetInstance()->FireBullet(GetDirEnemyFlower(), Vector2(this->m_Pos.x, this->m_Pos.y + this->m_Height / 2));
			}
		}
		
	}
	if (this->status == ENEMY_STATUS::ENEMY_NONE)
	{
		if(this->m_Height >= 0)
		{
			this->m_Height -= this->speed * deltaTime;
			if (this->m_Height <= 0)
			{
				this->status = ENEMY_STATUS::ENEMY_MOVE;
			}
		}
	}
}
BULLET_DIR CEnemyFlower::GetDirEnemyFlower()
{
	Vector2 pos = CMarioObject::GetInstance()->m_Pos;

	if (this->m_Pos.x > pos.x)
	{
		if (this->m_Pos.y > pos.y)
		{
			return BULLET_DIR::DOWN_LEFT;
		}
		else
		{
			return BULLET_DIR::TOP_LEFT;
		}
	}
	else
	{
		if (this->m_Pos.y > pos.y)
		{
			return BULLET_DIR::DOWN_RIGHT;
		}
		else
		{
			return BULLET_DIR::TOP_RIGHT;
		}
	}
	return BULLET_DIR::NONE;
}
void CEnemyFlower::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}
void CEnemyFlower::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CEnemyFlower::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CEnemyFlower::OnCollision(float deltaTime)//xet va cham voi Player
{
	if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
	{
		//MessageBox(NULL, "Mario Die", "Game Over", MB_OK);
		CMarioObject::GetInstance()->MarioDie();
		//CMarioObject::GetInstance()->m_vy = 120;
	}
}

Box CEnemyFlower::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 3, 0, 0);
}
RECT* CEnemyFlower::GetBound()
{
	return nullptr;
}
RECT* CEnemyFlower::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}