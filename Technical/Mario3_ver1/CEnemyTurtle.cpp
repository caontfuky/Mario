#include "CEnemyTurtle.h"


CEnemyTurtle::CEnemyTurtle()
{
	Init();
}
CEnemyTurtle::CEnemyTurtle(Vector2 pos, int level)
{
	Init();
	this->m_Pos = pos;
	this->m_PosStart = this->m_Pos;
}

CEnemyTurtle::~CEnemyTurtle()
{
}

void CEnemyTurtle::Init()
{
	
	//khoi tao id de lay hinh anh
	this->m_Id = 102;
	this->m_IdType = 102;//id Image
	this->m_mang = 1;
	this->status = ENEMY_STATUS::ENEMY_MOVE;
	this->m_Tag = Tag::ENEMY;
	this->m_isLife = true;
	this->m_timeRemove = 0;
	this->isRemove = false;
	this->m_Dir = Direction::LEFT;
	this->m_Distance = 90;
	//khoi tao Animation
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.2f;
	this->m_increase = 1;
	this->m_totalFrame = 4;
	this->m_column = 4;

	//khoi tao di chuyen

	this->m_vx = -20;
	this->m_vy = 0;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;
	this->m_a = -300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	//this->m_Pos = Vector2(200, 50);
	
	this->m_Width = 18;
	this->m_Height = 26;
	this->m_isJumping = false;
	this->m_canJump = true;

}
void CEnemyTurtle::Update(float deltaTime)
{
	ChangeFrame(deltaTime);
	SetFrame(deltaTime);
	MoveUpdate(deltaTime);
	OnCollision(deltaTime);

	if (this->m_isLife)
	{
		if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
		{
			CMarioObject::GetInstance()->m_status = STATUS::DIE;
			CMarioObject::GetInstance()->m_vy = 120;
		}
	}
}
void CEnemyTurtle::SetFrame(float deltaTime)
{
	switch (this->status)
	{
	case ENEMY_STATUS::ENEMY_MOVE:
		this->m_startFrame = 2;
		this->m_endFrame = 3;
		break;
	case ENEMY_STATUS::ENEMY_DIE:
		this->m_startFrame = 0;
		this->m_endFrame = 1;
		break;
	default:
		break;
	}
}
void CEnemyTurtle::MoveUpdate(float deltaTime)
{
	
	if (this->status == ENEMY_STATUS::ENEMY_MOVE)
	{
		if (this->m_Pos.x < this->m_PosStart.x || this->m_Pos.x > this->m_PosStart.x + this->m_Distance)
		{				
			this->m_vx *= -1;
			if (this->m_vx > 0)
			{
				this->m_Dir = Direction::RIGHT;
			}
			else
			{
				this->m_Dir = Direction::LEFT;
			}
		}		
	}
	
	this->m_Pos.x += this->m_vx * deltaTime;
	this->m_vy += this->m_a *deltaTime;
	this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
	if (this->isGround == false)
	{
		this->m_a = -300;
	}
}
void CEnemyTurtle::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}
void CEnemyTurtle::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{
	//float normalX = 0;
	//float normalY = 0;
	//float moveX = 0.0f;
	//float moveY = 0.0f;
	//float timeCollision;
	//for (std::vector<CBaseGameObject*>::iterator it = listObjectCollision.begin(); it != listObjectCollision.end(); it++)
	//{
	//	CBaseGameObject* obj = *it;

	//	if (obj->GetTag() == Tag::BRICK)
	//	{
	//		if (obj->m_IdType == 201 && obj->m_isLife == false)//va cham voi con rua
	//		{
	//			if (CCollision::GetInstance()->Collision(obj, this))
	//			{
	//				this->m_vx *= -1;
	//			}
	//		}
	//	}
	//}
}
void CEnemyTurtle::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CEnemyTurtle::OnCollision(float deltaTime, std::vector<Ground> listGround)//va cham voi Ground
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
				if (normalY > 0)
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
			
		}
	}
}
bool isCollision = false;
void CEnemyTurtle::OnCollision(float deltaTime)//xet va cham voi Player
{
	float normalX = 0;
	float normalY = 0;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float timeCollision;
	timeCollision = CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this, normalX, normalY, moveX, moveY, deltaTime);

	if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
	{
		if (this->status == ENEMY_STATUS::ENEMY_DIE)
		{
			if (isCollision)
			{
				if (normalX != 0 && this->m_vy == 0)
				{
					if (CMarioObject::GetInstance()->m_Dir == Direction::LEFT)
					{
						this->m_vx = -100;
					}
					if (CMarioObject::GetInstance()->m_Dir == Direction::RIGHT)
					{
						this->m_vx = 100;
					}
				}
			}
		}
		if (this->status == ENEMY_STATUS::ENEMY_MOVE)
		{
			if (normalY > 0)
			{
				this->m_vx = 0;
				this->m_isLife = false;
				this->status = ENEMY_STATUS::ENEMY_DIE;
				CMarioObject::GetInstance()->m_vy *= -1;
			}
		}		
	}
	else
	{
		if (this->status == ENEMY_STATUS::ENEMY_DIE)
		{
			isCollision = true;
		}
	}
	
}

Box CEnemyTurtle::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height, this->m_vx, this->m_vy);
}
RECT* CEnemyTurtle::GetBound()
{
	return nullptr;
}
RECT* CEnemyTurtle::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}