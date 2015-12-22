#include "CStone.h"


CStone::CStone()
{
	this->m_Id = 202;
	this->m_IdType = 202;//id Image
	this->m_Tag = Tag::BRICK;
	//
	this->m_Pos = Vector2(86, 32);
	this->m_Width = 16;
	this->m_Height = 16;
}


CStone::~CStone()
{
}
void CStone::Update(float deltaTime)
{
	//OnCollision(deltaTime);
}
void CStone::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{}
void CStone::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CStone::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CStone::OnCollision(float deltaTime, std::vector<Ground> listGround)
{}
void CStone::OnCollision(float deltaTime)
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
			//MessageBox(NULL, "Mario Va cham tu duoi len", "VA CHAM", MB_OK);
			CMarioObject::GetInstance()->m_isGround = true;
			CMarioObject::GetInstance()->m_vy = 0;
			CMarioObject::GetInstance()->m_a = 0;
			CMarioObject::GetInstance()->m_canJump = false;
			CMarioObject::GetInstance()->m_collision = COLLISION::GROUND_COL;
			CMarioObject::GetInstance()->isInput = false;

		}
		if (normalY < 0)
		{
			//MessageBox(NULL, "Mario Va cham tu duoi len", "VA CHAM", MB_OK);
			CMarioObject::GetInstance()->m_isGround = true;
			CMarioObject::GetInstance()->m_vy = 0;
			CMarioObject::GetInstance()->m_a = 0;
			CMarioObject::GetInstance()->m_canJump = false;
			CMarioObject::GetInstance()->m_collision = COLLISION::GROUND_COL;
			CMarioObject::GetInstance()->isInput = false;

		}
		if (normalX != 0)
		{
			//MessageBox(NULL, "Mario Va cham tu ben trai", "VA CHAM", MB_OK);
			CMarioObject::GetInstance()->m_vx = 0;
			CMarioObject::GetInstance()->m_ax = 0;
			CMarioObject::GetInstance()->isInput = false;
		}
	}
}
Box CStone::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height + 3, 0, 0);
}
RECT* CStone::GetBound()
{
	return nullptr;
}
RECT* CStone::GetRectRS()
{
	RECT* rectRS = new RECT();

	//cập nhật lại vị trí của Rect Resource
	rectRS->left = 0;
	rectRS->right =  m_Width;
	rectRS->top = 0;
	rectRS->bottom = m_Height;
	return rectRS;
}