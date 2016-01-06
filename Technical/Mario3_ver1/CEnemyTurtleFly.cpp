#include "CEnemyTurtleFly.h"


CEnemyTurtleFly::CEnemyTurtleFly()
{
	Init();
}
CEnemyTurtleFly::CEnemyTurtleFly(Vector2 pos)
{
	Init();
	this->m_Pos = pos;
}
CEnemyTurtleFly::CEnemyTurtleFly(Vector2 pos, ENEMY_STATUS lv)
{
	Init();
	this->m_Pos = pos;
	this->status = lv;
}

CEnemyTurtleFly::~CEnemyTurtleFly()
{
}

void CEnemyTurtleFly::Init()
{
	//khoi tao id de lay hinh anh
	this->m_Id = 106;
	this->m_IdType = 106;//id Image

	this->status = ENEMY_STATUS::ENEMY_ATTACK;
	this->m_Tag = Tag::ENEMY;
	this->m_isLife = true;
	this->m_timeRemove = 0;
	this->isRemove = false;
	this->m_Dir = Direction::LEFT;

	//khoi tao Animation
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.2f;
	this->m_increase = 1;
	this->m_totalFrame = 8;
	this->m_column = 8;

	//khoi tao di chuyen
	if (this->m_Dir == Direction::LEFT)
	{
		this->m_vx = -20;
	}
	else
	{
		this->m_vx = 20;
	}
	
	this->m_vy = 0;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;
	this->m_a = -300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Pos = Vector2(200, 50);

	this->m_Width = 16;
	this->m_Height = 27;
	this->m_isJumping = false;
	this->m_canJump = true;
	this->m_isMario = false;
}
void CEnemyTurtleFly::Update(float deltaTime)
{
	MoveUpdate(deltaTime);
	SetFrame(deltaTime);
	ChangeFrame(deltaTime);
	OnCollision(deltaTime);
	
}
void CEnemyTurtleFly::SetFrame(float deltaTime)
{
	
	switch (this->status)
	{
	case ENEMY_STATUS::ENEMY_ATTACK:
		this->m_startFrame = 5;
		this->m_endFrame = 7;
		break;
	case ENEMY_STATUS::ENEMY_MOVE:
		this->m_startFrame = 3;
		this->m_endFrame = 4;
		break;
	case ENEMY_STATUS::ENEMY_DIE:
		if (this->m_isMario == false)
		{
			this->m_startFrame = 0;
			this->m_endFrame = 2;
		}
		else
		{
			this->m_startFrame = 0;
			this->m_endFrame = 0;
		}
		break;
	default:
		break;
	}
}
bool isCheat = false;
bool isCam = false;
void CEnemyTurtleFly::MoveUpdate(float deltaTime)
{
	
	if (this->status != ENEMY_STATUS::ENEMY_DIE)
	{
		//this->m_vx = this->m_vxDefault;
		//this->m_Pos.x += this->m_vx * deltaTime;
		if (this->isGround == true && this->status == ENEMY_STATUS::ENEMY_ATTACK)
		{
			this->m_vy = 150;
		}
		else
		{
			this->m_a = this->m_aDefault;
		}
	}
	else
	{
		if (isCheat == false)
			this->m_vx = 0;
		else
		{
			if (this->m_Dir == Direction::LEFT && isCam == true)
			{
				this->m_vx = -150;

			}
			if (this->m_Dir == Direction::RIGHT && isCam == true)
			{
				this->m_vx = 150;
			}
			
		}
		if (this->m_isMario == true)
		{			
			if (CMarioObject::GetInstance()->m_isFly == true)
			{

				this->m_Pos.y = CMarioObject::GetInstance()->m_Pos.y + 4;
				isCam = true;
				if (CMarioObject::GetInstance()->m_Dir == Direction::LEFT)
				{
					this->m_Pos.x = CMarioObject::GetInstance()->m_Pos.x - 16;
					this->m_Dir = Direction::LEFT;

				}
				if (CMarioObject::GetInstance()->m_Dir == Direction::RIGHT)
				{
					this->m_Pos.x = CMarioObject::GetInstance()->m_Pos.x + 16;
					this->m_Dir = Direction::RIGHT;
				}
			}
		}
		if (this->m_isMario == true && CMarioObject::GetInstance()->m_isFly == false)
		{
			
			if (this->isGround == true)
			{
				
			}
			else
			{
				this->m_a = this->m_aDefault;
			}
			isCheat = true;
		}
		
	}
	if (this->isGround == true && this->status == ENEMY_STATUS::ENEMY_MOVE)
	{
		this->m_vy = 0;
		this->m_a = 0;
	}
	this->m_Pos.x += this->m_vx * deltaTime;
	this->m_vy += this->m_a *deltaTime;
	this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
}
void CEnemyTurtleFly::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}
void CEnemyTurtleFly::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{
}
void CEnemyTurtleFly::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CEnemyTurtleFly::OnCollision(float deltaTime, std::vector<Ground> listGround)//va cham voi Ground
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
			if (ground.idGround == 705 || ground.idGround == 701)
			{
				if (this->status == ENEMY_STATUS::ENEMY_MOVE)
				{
					/*if (this->m_Pos.x < this->m_PosStart.x || this->m_Pos.x > this->m_PosStart.x + this->m_Distance)
					{*/
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

				//}
			}

		}
	}
}
void CEnemyTurtleFly::OnCollision(float deltaTime)//xet va cham voi Player
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
			this->m_isLife = false;
			
			
			switch (this->status)
			{
			case ENEMY_STATUS::ENEMY_ATTACK:
				CMarioObject::GetInstance()->m_vy *= -1;
				this->m_vy *= -1;
				this->status = ENEMY_STATUS::ENEMY_MOVE;
				break;
			case ENEMY_STATUS::ENEMY_MOVE:
				CMarioObject::GetInstance()->m_vy *= -1;
				this->status = ENEMY_STATUS::ENEMY_DIE;
				break;
			case ENEMY_STATUS::ENEMY_DIE:
				break;
			default:
				break;
			}	
			
		}

	}
	
	if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
	{
		//MessageBox(NULL, "Bullet", "Game Over", MB_OK);

		if (this->status != ENEMY_STATUS::ENEMY_DIE)
		{
			CMarioObject::GetInstance()->MarioDie();
			
		}
		else
		{
			this->m_isMario = true;
		}
	}
	else
	{
		if (this->status == ENEMY_STATUS::ENEMY_DIE)
		{
			this->m_isMario = false;
		}

	}
	
}

Box CEnemyTurtleFly::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height, this->m_vx, this->m_vy);
}
RECT* CEnemyTurtleFly::GetBound()
{
	return nullptr;
}
RECT* CEnemyTurtleFly::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}
