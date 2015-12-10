#include "CEnemyRun.h"


CEnemyRun::CEnemyRun()
{
	Init();
	this->level = LEVEL::LEVEL_1;
	this->lv = 1;
}

CEnemyRun::CEnemyRun(Vector2 pos)
{
	Init();
	this->m_Pos = pos;
	this->level = LEVEL::LEVEL_0;
}
CEnemyRun::CEnemyRun(Vector2 pos, LEVEL _level)
{
	Init();
	this->m_Pos = pos;

	this->level = LEVEL::LEVEL_1;
	
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
	this->isGround = false;
	

	//khoi tao Animation
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.2f;
	this->m_increase = 1;
	this->m_totalFrame = 7;
	this->m_column = 7;

	//khoi tao di chuyen

	this->m_vx = -20;
	this->m_vy = 0;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;	
	this->m_a = -300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Pos = Vector2(200, 100);
	this->m_Width = 20;
	this->m_Height = 24;
	this->m_isJumping = false;	
	this->m_canJump = true;
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
	if (this->lv <= 0)
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
	if (this->lv == 1)
	{		
		this->m_startFrame = 3;
		this->m_endFrame = 6;
	}
}
int i = 0;
bool isMove = true;
float t = 0;
void CEnemyRun::MoveUpdate(float deltaTime)
{
	
	if (this->lv == 0 && this->isGround == true)
	{
		if (!this->isGround)
		{
			this->m_a = this->m_aDefault;
			this->m_vy *= -1;
		}
		if (this->isGround)
		{
			this->m_a = 0;
			this->m_vy = 0;
		}
		this->m_Pos.x += this->m_vx * deltaTime;
		if (this->m_Pos.x <= 0 || this->m_Pos.x >= 200)
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
	if (this->lv == 1)
	{
		if (!this->isGround)
		{
			this->m_a = this->m_aDefault;
		}
		this->m_Pos.x += this->m_vx * deltaTime;
		if (this->isGround)
		{			
			if (isMove)
			{
				i++;
				if (i % 4 == 1 || i % 4 == 2)
				{
					this->m_vy = 70;
				}
				if (i % 4 == 3)
				{
					this->m_vy = 150;
				}
				if (i % 4 == 0)
				{
					isMove = false;
				}
			}

		}
	}
	if (!isMove)
	{
		if (t >= 1)
		{
			isMove = true;
			t = 0;
		}
		t += deltaTime;
	}
	this->m_vy += this->m_a *deltaTime;
	this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
}
void CEnemyRun::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}
void CEnemyRun::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CEnemyRun::OnCollision(float deltaTime, CBaseGameObject* Object)
{}

void CEnemyRun::OnCollision(float deltaTime, std::vector<Ground> listGround)//va cham voi Ground
{
	float normalX = 0;
	float normalY = 0;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float timeCollision;
	this->isGround = false;
	for (std::vector<Ground>::iterator it = listGround.begin(); it != listGround.end(); it++)
	{
		Ground ground = *it;
		Box box = ground.box;

		timeCollision = CCollision::GetInstance()->Collision(this, box, normalX, normalY, moveX, moveY, deltaTime);

		if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
		{
			if (ground.idGround == 702)//va cham voi nen
			{
				if (normalY < 0)
				{
					if (this->m_vy <= 0)
					{						
						this->m_vy = 0;
						this->m_a = 0;
						this->m_canJump = false;
						this->isGround = true;
					}
				}
			}
			if (ground.idGround == 701)//va cham voi brich de quay dau lai
			{
				this->m_vx *= -1;
			}
		}
	}
}
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
		
		if (normalY > 0)
		{
			this->lv -= 1;
			CMarioObject::GetInstance()->m_vy *= -1;
			
			if (this->lv < 0)
			{
				this->m_vx = 0;
				this->m_isLife = false;
				this->status = ENEMY_STATUS::ENEMY_DIE;
			}
			
			
		}	
		
	}
	if (this->m_isLife)
	{

		if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this) && CMarioObject::GetInstance()->m_vy == 0)
		{
			//MessageBox(NULL, "Mario Die", "Game Over", MB_OK);
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