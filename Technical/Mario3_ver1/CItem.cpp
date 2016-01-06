#include "CItem.h"


CItem::CItem()
{
	//Init();
}
CItem::CItem(Vector2 pos, TYPE_ITEM _type)
{
	Init();
	this->m_Pos = pos;
	this->type = _type;
	//khoi tao thong so Sprite
	switch (this->type)
	{
	case TYPE_ITEM::ITEM_MUSHROOM:
		this->m_Id = 203;
		this->m_IdType = 203;//id Image
		this->m_Width = 16;
		this->m_Height = 0;

		this->m_currentTime = 0;
		this->m_currentFrame = 0;
		this->m_elapseTimeChangeFrame = 0.1f;
		this->m_increase = 1;
		this->m_totalFrame = 2;
		this->m_column = 2;
		break;
	case TYPE_ITEM::ITEM_FLY:
		this->m_Id = 204;
		this->m_IdType = 204;//id Image
		this->m_Width = 16;
		this->m_Height = 16;
		this->m_currentTime = 0;
		this->m_currentFrame = 0;
		this->m_elapseTimeChangeFrame = 0.1f;
		this->m_increase = 1;
		this->m_totalFrame = 2;
		this->m_column = 2;
		break;
	default:
		break;
	}
}

CItem::~CItem()
{
}
void CItem::Init()
{
	//this->m_Id = 203;
	//this->m_IdType = 203;//id Image
	
	this->m_isLife = true;
	//
	this->m_vx = 20;
	this->m_vy = 0;
	this->m_vxDefault = this->m_vx;
	this->m_vyDefault = this->m_vy;
	this->m_a = -300;
	this->m_aDefault = this->m_a;
	this->m_ax = 0;
	this->m_Pos = Vector2(100, 50);

	//this->m_Width = 16;
	//this->m_Height = 16;

	this->m_startFrame = 0;
	this->m_endFrame = 0;
	this->isMove = false;
	this->isGround = false;
}
void CItem::Update(float deltaTime)
{
	MoveUpdate(deltaTime);
	ChangeFrame(deltaTime);
	OnCollision(deltaTime);
}
void CItem::OnCollision(float deltaTime, std::vector<Ground> listGround)
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
		this->isGround = false;
		if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
		{
			//MessageBox(NULL, "ASDsa", "ASDsad", MB_OK);
			if (ground.idGround == 702)//va cham voi nen
			{
				this->m_vy = 0;
				this->m_a = 0;						
				this->isGround = true;
				this->m_Pos.y = box.y + 6;
			}

		}
	}
}
void CItem::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{}
void CItem::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{
}
void CItem::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CItem::OnCollision(float deltaTime)
{
	if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
	{

		this->m_Pos = Vector2(-50, -50);
		int lv = CMarioObject::GetInstance()->level;
		
		switch (lv)
		{
		case 1:
			CMarioObject::GetInstance()->m_Pos.y = CMarioObject::GetInstance()->m_Pos.y + CMarioObject::GetInstance()->m_Height/2;
			CMarioObject::GetInstance()->level = 2;
			
			break;
		case 2:
			//CMarioObject::GetInstance()->m_Pos.y = CMarioObject::GetInstance()->m_Pos.y + CMarioObject::GetInstance()->m_Height / 2;
			CMarioObject::GetInstance()->level = 3;
			break;
		case 3:
			break;
		default:
			break;
		}
		CMarioObject::GetInstance()->m_isUndying = true;
		
	}
}

void CItem::MoveUpdate(float deltaTime)
{
	switch (this->type)
	{
	case TYPE_ITEM::ITEM_MUSHROOM:
		//Update
		if (this->isMove == false)//bat dau xuat hien
		{
			this->m_Height += 15 * deltaTime;
			if (this->m_Height >= 16)
			{
				this->isMove = true;
			}
		}
		else
		{			
			if (this->isGround == false)
			{
				//this->m_a = this->m_aDefault;
				this->m_vy += this->m_a *deltaTime;
				this->m_Pos.y += this->m_vy*deltaTime + 0.5 * this->m_a * deltaTime *deltaTime;
			}
			else
			{
				this->m_a = 0;
				this->m_vy = 0;
			}
			this->m_Pos.x -= this->m_vx * deltaTime;
					
		}
		break;
	case TYPE_ITEM::ITEM_FLY:
		this->m_Pos.x -= this->m_vx * deltaTime;
	default:
		break;
	}
	
}
Box CItem::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 3, 0, 0);
}
RECT* CItem::GetBound()
{
	return nullptr;
}
RECT* CItem::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}