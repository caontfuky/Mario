#include "CBackGround.h"


CBackGround::CBackGround()
{
	this->m_IdType = 3;
	this->m_Width = 624;
	this->m_Height = 432;
	this->m_Dir = Direction::NONE_DIR;
	this->m_Pos = Vector2(0, 0);
}


CBackGround::~CBackGround()
{
}
void CBackGround::Update(float deltaTime)
{}
void CBackGround::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{}
void CBackGround::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CBackGround::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CBackGround::SetPos(Vector2 pos)
{
	
}
void CBackGround::SetAlive(bool islife)
{}
void CBackGround::SetLeft(Direction left)
{}
Box CBackGround::GetBox()
{
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height);
}
RECT* CBackGround::GetBound()
{
	return nullptr;
}
RECT* CBackGround::GetRectRS()
{
	RECT* rectRS = new RECT();

	rectRS->left = this->m_Pos.x;
	rectRS->right = this->m_Pos.x + this->m_Width;
	rectRS->top = this->m_Pos.y;
	rectRS->bottom = this->m_Pos.y + this->m_Height;

	return nullptr;
}
