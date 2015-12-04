#include "CBaseEnemy.h"


CBaseEnemy::CBaseEnemy()
{
	this->m_Id = 0;
	this->m_IdType = 2;
	this->m_Dir = Direction::NONE_DIR;
	this->m_Pos = Vector2(0, 300);
	this->m_Width = 100;
	this->m_Height = 100;
}


CBaseEnemy::~CBaseEnemy()
{
}

void CBaseEnemy::Update(float deltaTime)
{

}
void CBaseEnemy::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}
void CBaseEnemy::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CBaseEnemy::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
Box CBaseEnemy::GetBox()
{
	float x = this->m_Pos.x - this->m_Width / 2.0f;
	float y = this->m_Pos.y - this->m_Height / 2.0f;
	float w = this->m_Width;
	float h = this->m_Height;
	return Box(this->m_Pos.x, this->m_Pos.y, this->m_Width, this->m_Height);
	//return Box(x, y, w, h);
}
RECT* CBaseEnemy::GetBound()
{
	return nullptr;
}
RECT* CBaseEnemy::GetRectRS()
{

	RECT* rectRS = new RECT();

	rectRS->left = this->m_Pos.x;
	rectRS->right = this->m_Pos.x + this->m_Width;
	rectRS->top = this->m_Pos.y;
	rectRS->bottom = this->m_Pos.y + this->m_Height;

	return rectRS;
	//return this->UpdateRectResource(m_Height, m_Width);
}