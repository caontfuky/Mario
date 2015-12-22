#include "CMarioObject.h"
#include "CCamera.h"
float TPF = 0;
CMarioObject::CMarioObject()
{
	this->m_Id = 0;
	this->m_IdType = 1;
	this->level = 1;
	this->isInput = false;
	this->m_Dir = Direction::NONE_DIR;
	this->m_status = STATUS::NONE_STATUS;
	this->m_collision = COLLISION::NONE_COL;
	this->InitMove();
	this->InitAnimation();
}
void CMarioObject::InitAnimation()
{
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.1f;
	this->m_increase = 1;
	this->m_totalFrame = 4;
	this->m_column = 4;
}
void CMarioObject::InitMove()
{
	this->m_vx = 0;
	this->m_vy = 0;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;
	this->m_vxMax = 50;
	this->m_vyMax = -140;
	this->m_a = -300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Pos = Vector2(50, 200);
	this->m_Width = 16;
	this->m_Height = 16;
	this->m_isJumping = false;
	this->m_isGround = false;
	this->m_canJump = true;
	this->m_timeJumb = 0;
	
}

CMarioObject::~CMarioObject()
{
	delete this;
}
void CMarioObject::Update(float deltaTime)
{
	
	
	SetFrame(deltaTime);
	ChangeFrame(deltaTime);	
	MoveUpdate(deltaTime);
	if (this->m_status != STATUS::DIE)
	{		
		OnKeyDown(deltaTime);
		OnKeyUp(deltaTime);
	}
	
}
void CMarioObject::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{}
void CMarioObject::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{
	float normalX = 0;
	float normalY = 0;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float timeCollision;
	for (std::vector<CBaseGameObject*>::iterator it = listObjectCollision.begin(); it != listObjectCollision.end(); it++)
	{		
		CBaseGameObject* obj = *it;		
		
		if (obj->GetTag() == Tag::BRICK)
		{
			timeCollision = CCollision::GetInstance()->Collision(this, obj, normalX, normalY, moveX, moveY, deltaTime);

			if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				if (normalY > 0)
				{
					if (this->m_vy <= 0)
					{
						this->m_isGround = true;
						this->m_vy = 0;
						this->m_a = 0;
						this->m_canJump = false;
						this->m_collision = COLLISION::GROUND_COL;
					}
				}
				if (normalY < 0)
				{	/*
					if (this->m_vy <= 0)
					{*/
					this->m_isGround = true;
					this->m_vy = -75;
					this->m_a = 0;
					this->m_canJump = false;
					this->m_collision = COLLISION::GROUND_COL;
					//}
				}
				
				if (normalX < 0 && this->m_Dir == Direction::RIGHT && (this->m_Pos.y - this->m_Height / 2) < obj->m_Pos.y)
				{
					this->m_ax = 0;
					this->m_vx = 0;
					this->isInput = false;
				}
				if (normalX > 0 && this->m_Dir == Direction::LEFT && (this->m_Pos.y - this->m_Height / 2) < obj->m_Pos.y)
				{
					this->m_ax = 0;
					this->m_vx = 0;
					this->isInput = false;
				}
			}
			
		}
	}
}

void CMarioObject::OnCollision(float deltaTime, std::vector<Box> listBox)
{	
	
#pragma region Va cham k co van toc
	//this->m_isGround = false;
	//for (std::vector<Box>::iterator it = listBox.begin(); it != listBox.end(); it++)
	//{

	//	Box box = *it;
	//	
	//	if (this->m_isGround)
	//	{
	//		return;
	//	}
	//	

	//	if (CCollision::GetInstance()->Collision(this, box))
	//	{
	//		if (this->m_vy >= 0)
	//		{

	//			this->m_isGround = true;
	//			this->m_vy = 0;
	//			this->m_a = 0;
	//			this->m_canJump = false;
	//			this->m_collision = COLLISION::GROUND_COL;
	//		}
	//	}
	//	else
	//	{
	//		this->m_collision = COLLISION::NONE_COL;
	//		this->m_a = m_aDefault;
	//		//MessageBox(NULL, "Chua va cham", "Va cham", MB_OK);
	//		if (this->m_vy > 0)
	//		{
	//			this->m_isGround = false;
	//		}
	//	}
	//	
	//}
#pragma endregion
#pragma region Va cham co van toc
	float normalX = 0;
	float normalY = 0;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float timeCollision; 

	this->m_isGround = false;
	for (std::vector<Box>::iterator it = listBox.begin(); it != listBox.end(); it++)
	{
		Box box = *it;
		timeCollision = CCollision::GetInstance()->Collision(this, box, normalX, normalY, moveX, moveY, deltaTime);
		
		if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
		{			
			if (normalY < 0)
			{
				if (this->m_vy <= 0)
				{
					this->m_isGround = true;
					this->m_vy = 0;
					this->m_a = 0;
					this->m_canJump = false;
					this->m_collision = COLLISION::GROUND_COL;
				}
			}
			if (normalX != 0 && this->m_vy != 0)
			{
				if (normalX < 0 && this->m_Dir == Direction::RIGHT)
				{
					this->m_ax = 0;
					this->m_vx = 0;
					this->isInput = false;
				}
				if (normalX > 0 && this->m_Dir == Direction::LEFT)
				{
					this->m_ax = 0;
					this->m_vx = 0;
					this->isInput = false;
				}		
				//xu ly khong cho di chuyen qua
				//MessageBox(NULL, "Va cham theo chieu X", "COL", MB_OK);
			}
			
			/*if (normalX == 0)
			{
				if (this->m_status != STATUS::NONE_STATUS)
					this->isInput = true;
			}*/
		}
		
	}
#pragma endregion
}
void CMarioObject::OnCollision(float deltaTime, std::vector<Ground> listGround)
{
	if (this->m_status != STATUS::DIE)
	{

		float normalX = 0;
		float normalY = 0;
		float moveX = 0.0f;
		float moveY = 0.0f;
		float timeCollision;

		this->m_isGround = false;
		for (std::vector<Ground>::iterator it = listGround.begin(); it != listGround.end(); it++)
		{
			Ground ground = *it;
			Box box = ground.box;

			timeCollision = CCollision::GetInstance()->Collision(this, box, normalX, normalY, moveX, moveY, deltaTime);

			if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				if (ground.idGround == 702)
				{
					if (normalY > 0)
					{
						if (this->m_vy <= 0)
						{
							this->m_isGround = true;
							this->m_vy = 0;
							this->m_a = 0;
							this->m_canJump = false;
							this->m_collision = COLLISION::GROUND_COL;

							//neu 2 box va cham long nhau thi tach no ra
							float botMario = this->m_Pos.y - this->m_Height / 2.0;
							float topBox = box.y + box.h / 2.0;
							if (botMario < topBox)
							{
								this->m_Pos.y = topBox + this->m_Height / 2.0;
							}
						}
					}
					if (normalX != 0 && this->m_vy != 0)
					{
						if (normalX < 0 && this->m_Dir == Direction::RIGHT)
						{
							this->m_ax = 0;
							this->m_vx = 0;
							this->isInput = false;
						}
						if (normalX > 0 && this->m_Dir == Direction::LEFT)
						{
							this->m_ax = 0;
							this->m_vx = 0;
							this->isInput = false;
						}
						//xu ly khong cho di chuyen qua
						//MessageBox(NULL, "Va cham theo chieu X", "COL", MB_OK);
					}
				}
				if (ground.idGround == 701)
				{
					if (normalX != 0)
					{
						if (normalX < 0 && this->m_Dir == Direction::RIGHT)
						{
							this->m_ax = 0;
							this->m_vx = 0;
							this->isInput = false;
						}
						if (normalX > 0 && this->m_Dir == Direction::LEFT)
						{
							this->m_ax = 0;
							this->m_vx = 0;
							this->isInput = false;
						}
					}
				}
			}
		}
	}
}
void CMarioObject::OnCollision(float deltaTime, CBaseGameObject* Object)
{
	float normalX = 0;
	float normalY = 0;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float timeCollision;

	timeCollision = CCollision::GetInstance()->Collision(this, Object, normalX, normalY, moveX, moveY, deltaTime);
	if (CCollision::GetInstance()->Collision(this, Object))
	//if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
	//if (timeCollision == 1.0f)
	{
		//if (normalY < 0)
		//{
			//this->m_isGround = true;
			this->m_collision = COLLISION::GROUND_COL;
		//}
	}
	else
	{
		this->m_collision = COLLISION::NONE_COL;
		//MessageBox(NULL, "Chua va cham", "Va cham", MB_OK);
		if (this->m_vy >= 0)
		{
			this->m_isGround = false;
			
		}
	}
}
void CMarioObject::Collision(float deltaTime)
{
	switch (this->m_collision)
	{
		case COLLISION::NONE_COL:
			//if (this->m_vy > 0)
			//this->m_isGround = false;
			break;
		case COLLISION::ENEMY_COL:		
			break;
		case COLLISION::GROUND_COL:			
			break;
		case COLLISION::BULLET_COL:
			break;
		default:
			break;
	}

}
void CMarioObject::Gravity(float deltaTime)
{
	if (this->m_vy != 0)
	{
		this->m_isGround = false;
		this->m_collision = COLLISION::NONE_COL;
		this->m_a = this->m_aDefault;
	}
	if (!this->m_isGround)
	{
		this->m_a = this->m_aDefault;
	}
	this->m_vy += this->m_a *deltaTime;
	if (this->m_vy < 0)
	{
		this->m_canJump = true;
	}
	this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
}
//xu ly khi mario nhay, add them 1 luc
void CMarioObject::AddForce(float deltaTime)
{
	if (this->m_isJumping == true)
	{
		m_timeJumb += deltaTime;
		if (m_timeJumb < 0.2f)
		{
			
			this->m_vy = 100;
			this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
			//this->m_canJump = true;
		}
		if (m_timeJumb > 0.2f)
		{
			this->m_vy = 120;			
			this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
			
			//MessageBox(NULL, "Nhay cao", "Jumb", MB_OK);
		}
		if (this->m_timeJumb > 0.3f)
		{
			this->m_isJumping = false;
			//this->m_canJump = true;
		}
	}
	
}
//thay doi Frame
void CMarioObject::SetFrame(float deltaTime)
{
	if (this->level == 1)
	{
		if (this->m_status != STATUS::DIE)
		{

			if (this->m_collision == COLLISION::NONE_COL)
			{
				this->m_startFrame = 0;
				this->m_endFrame = 0;
			}
			else
			{

				switch (this->m_status)
				{
				case STATUS::NONE_STATUS:
					this->m_startFrame = 0;
					this->m_endFrame = 0;
					break;
				case STATUS::MOVE:
					this->m_startFrame = 0;
					this->m_endFrame = 1;
					break;
				case STATUS::JUMB:
					this->m_startFrame = 0;
					this->m_endFrame = 0;
					break;
				case STATUS::FLY:
					
					break;
				case STATUS::DIE:
					break;
				default:
					break;
				}
			}
		}
		else
		{
			this->m_startFrame = 0;
			this->m_endFrame = 0;
		}
	}
	if (this->level == 2)
	{
		
		if (this->m_collision == COLLISION::NONE_COL)
		{
			this->m_Width = 18;
			this->m_Height = 28;
			this->m_startFrame = 0;
			this->m_endFrame = 0;
		}
		else
		{
			this->m_Width = 17;
			this->m_Height = 28;

			switch (this->m_status)
			{
			case STATUS::NONE_STATUS:
				this->m_startFrame = 0;
				this->m_endFrame = 0;
				break;
			case STATUS::MOVE:
				this->m_startFrame = 1;
				this->m_endFrame = 2;
				break;
			case STATUS::JUMB:
				this->m_startFrame = 0;
				this->m_endFrame = 0;
				break;
			case STATUS::FLY:
				if (this->m_collision == COLLISION::NONE_COL)
				{
					this->m_startFrame = 3;
					this->m_endFrame = 3;
				}
				else
				{
					this->m_startFrame = 0;
					this->m_endFrame = 2;
				}
				break;
			case STATUS::DIE:
				break;
			default:
				break;
			}
		}
	}
	if (this->level == 3)
	{
		if (this->m_collision == COLLISION::NONE_COL)
		{
			this->m_startFrame = 0;
			this->m_endFrame = 0;
		}
		else
		{
			switch (this->m_status)
			{
			case STATUS::NONE_STATUS:
				this->m_startFrame = 0;
				this->m_endFrame = 0;
				break;
			case STATUS::MOVE:
				this->m_startFrame = 0;
				this->m_endFrame = 1;
				break;
			case STATUS::JUMB:
				this->m_startFrame = 0;
				this->m_endFrame = 0;
				break;
			case STATUS::FLY:
				if (this->m_collision == COLLISION::NONE_COL)
				{
					this->m_startFrame = 6;
					this->m_endFrame = 8;
				}
				else
				{
					this->m_startFrame = 0;
					this->m_endFrame = 2;
				}
				break;
			case STATUS::DIE:
				break;
			default:
				break;
			}
		}
	}
}
void CMarioObject::Move(float deltaTime)
{
	if (this->isInput)
	{
		if (this->m_Dir == Direction::LEFT)
		{
			this->m_ax = -70;
		}
		else
		{
			this->m_ax = 70;
		}
	}

	this->m_vx += this->m_ax *deltaTime;

	if (this->m_vx >= this->m_vxMax)
	{
		this->m_vx = this->m_vxMax;
	}
	else
	{
		if (this->m_vx <= -this->m_vxMax)
		{
			this->m_vx = -this->m_vxMax;
		}
	}

	this->m_Pos.x += this->m_vx * deltaTime + 0.5f * this->m_ax * deltaTime *deltaTime;

	
	if (this->m_vx * this->m_ax < 0)							//Ngăn gia tốc làm Mario quay lại
	{
		if (this->m_vx > -10 && this->m_vx < 10)
		{
			this->m_vx = 0;
			this->m_ax = 0;
		}
	}

	//thiet lap camera
	CCamera::GetInstance()->Update(this->m_Pos.x - __SCREEN_WIDTH / 2, 0);
}
void CMarioObject::MoveUpdate(float deltaTime)
{
	switch (this->m_status)
	{
		case STATUS::MOVE:
			//Move(deltaTime);
			break;
		case STATUS::FLY:
			break;
		case STATUS::JUMB:	
			break;
		case STATUS::DIE:
			break;
		case STATUS::NONE_STATUS:
			if (this->m_vx * this->m_ax < 0)							//Ngăn gia tốc làm Mario quay lại
			{				
				if (this->m_vx > -20 && this->m_vx < 20)
				{
					//MessageBox(NULL, "Vy Max", "VY", MB_OK);
					this->m_vx = 0;
					this->m_ax = 0;
				}
			}
			if (this->m_vx == 0)
			{
				this->m_ax = 0;
			}
			break;
		default:
			break;
	}
	//grafity
	Gravity(deltaTime);
	//nhay
	if (this->m_canJump == false)
		AddForce(deltaTime);
	//di chuyen cua mario
	Move(deltaTime);

}

void CMarioObject::SetAlive(bool islife)
{}
void CMarioObject::SetLeft(Direction left)
{}
Box CMarioObject::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height, this->m_vx, this->m_vy);
}
RECT* CMarioObject::GetBound()
{
	return nullptr;
}
RECT* CMarioObject::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}
void CMarioObject::OnKeyDown(float deltaTime)
{
	this->m_keyDown = CInput::GetInstance()->GetKeyDown();
	switch (this->m_keyDown)
	{
		case DIK_SPACE:
			if (this->m_isGround)
			{
				this->m_canJump = true;
				this->m_isJumping = true;
				this->m_isGround = false;				
			}			
			break;
		case DIK_X:
			break;
		case DIK_Z:
			break;
		case DIK_C:
			break;
		case DIK_LEFT:
			this->m_status = STATUS::MOVE;
			this->m_Dir = Direction::LEFT;	
			this->isInput = true;
			this->m_ax = -70;
			break;
		case DIK_RIGHT:
			this->m_status = STATUS::MOVE;
			this->m_Dir = Direction::RIGHT;	
			this->isInput = true;
			this->m_ax = 70;
			break;
		case DIK_UP:
			break;
		case DIK_DOWN:
			break;		
		default:
			break;
	}
}
void CMarioObject::OnKeyUp(float deltaTime)
{
	this->m_keyUp = CInput::GetInstance()->GetKeyUp();
	switch (this->m_keyUp)
	{
		case DIK_SPACE:
			this->m_isJumping = false;
			this->m_timeJumb = 0;
			this->m_a = m_aDefault;
			break;
		case DIK_X:
			break;
		case DIK_Z:
			break;
		case DIK_C:
			break;
		case DIK_LEFT:
			//MessageBox(NULL, "Da tha phim Left", "THA", MB_OK);
			this->m_status = STATUS::NONE_STATUS;
			this->isInput = false;
			this->m_ax = 100;
			break;
		case DIK_RIGHT:
			this->m_status = STATUS::NONE_STATUS;	
			this->isInput = false;
			this->m_ax = -100;
			break;
		case DIK_UP:
			break;
		case DIK_DOWN:
			break;
		default:
			break;
	}
}