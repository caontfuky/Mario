#include "CBaseGameObject.h"
using namespace std;


CBaseGameObject::CBaseGameObject()
{
	this->m_Tag = Tag::NONE_TAG;
	this->m_Dir = Direction::NONE_DIR;
	this->m_Pos = Vector2(0, 0);
	this->m_isLife = true;
	this->m_Width = 0;
	this->m_Height = 0;
	this->m_RectRS = NULL;
	this->m_Hp = 0;	
}


CBaseGameObject::~CBaseGameObject()
{
}
void CBaseGameObject::Update(float deltaTime, std::vector<CBaseGameObject*>* listObjectCollision)
{

}

void CBaseGameObject::Update(float deltaTime)
{

}

void CBaseGameObject::SetPos(Vector2 pos)
{
	this->m_Pos = pos;
}

void CBaseGameObject::SetAlive(bool alive)
{
	this->m_isLife = alive;
}

void CBaseGameObject::SetLeft(Direction left)
{
	this->m_Dir = left;
}

//Dung de xet va cham + xen trong quad tree
Box CBaseGameObject::GetBox()
{
	return Box(this->m_Pos, this->m_Width, this->m_Height, 0, 0);
}

RECT* CBaseGameObject::GetBound()
{
	RECT* rect = new RECT();
	rect->top = this->m_Pos.y;
	rect->left = this->m_Pos.x;
	rect->bottom = rect->top + this->m_Height;
	rect->right = rect->left + this->m_Width;
	return rect;
}

RECT* CBaseGameObject::GetRectRS()
{
	return NULL;
}