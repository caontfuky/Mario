#include "CBrick.h"
#include "CPoolObject.h"

CBrick::CBrick()
{
	Init();
}
CBrick::CBrick(Vector2 pos)
{
	Init();
	this->m_Pos = pos;
}
void CBrick::Init()
{
	this->m_Id = 201;
	this->m_IdType = 201;//id Image
	this->status = BRICK_STATUS::BRICK_ITEM;
	this->m_Tag = Tag::BRICK;

	//khoi tao thong so Sprite
	this->m_currentTime = 0;
	this->m_currentFrame = 0;
	this->m_elapseTimeChangeFrame = 0.1f;
	this->m_increase = 1;
	this->m_totalFrame = 2;
	this->m_column = 2;

	//
	this->m_Pos = Vector2(100, 370);
	this->m_Width = 20;
	this->m_Height = 16;

}

CBrick::~CBrick()
{
}
void CBrick::Update(float deltaTime)
{
	ChangeFrame(deltaTime);
	if (status == BRICK_STATUS::BRICK_ITEM)
	{
		this->m_startFrame = 0;
		this->m_endFrame = 0;
	}
	else
	{
		this->m_startFrame = 1;
		this->m_endFrame = 1;
	}
	OnCollision(deltaTime);
}
void CBrick::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{}
void CBrick::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CBrick::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CBrick::OnCollision(float deltaTime)
{
	float normalX = 0;
	float normalY = 0;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float timeCollision;
	timeCollision = CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this, normalX, normalY, moveX, moveY, deltaTime);

	if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
	{
		if (normalY > 0 )
		{
			Vector2 pos = Vector2(this->m_Pos.x, this->m_Pos.y - this->m_Height);
			
			if (status != BRICK_STATUS::BRICK_NONE)
				CPoolObject::GetInstance()->RenderCoin(pos);
			status = BRICK_STATUS::BRICK_NONE;
			CMarioObject::GetInstance()->m_a = 0;
			CMarioObject::GetInstance()->m_vy = 0;			
			//CMarioObject::GetInstance()->m_a = CMarioObject::GetInstance()->m_aDefault;
			//MessageBox(NULL, "Va cham theo  Y Duoi len", "VA CHam", MB_OK);
		}

	}
	/*if (this->m_isLife)
	{
		if (CCollision::GetInstance()->Collision(CMarioObject::GetInstance(), this))
		{
			MessageBox(NULL, "Va cham theo  X", "VA CHam", MB_OK);
		}
	}*/
}
void CBrick::MoveUpdate(float deltaTime)
{}
Box CBrick::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 3, 0, 0);
}
RECT* CBrick::GetBound()
{
	return nullptr;
}
RECT* CBrick::GetRectRS()
{
	return this->UpdateRectResource(m_Height, m_Width);
}