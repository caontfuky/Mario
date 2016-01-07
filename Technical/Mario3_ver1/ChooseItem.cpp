#include "ChooseItem.h"

#define CHOOSE_ITEM_ONE_PLAYER "..\\Resources\\Map\\choiseitem.PNG"
#define POSITION_X_CHOISE_ITEM 180
#define POSITION_Y_CHOISE_ITEM 325
//#define CHOOSE_ITEM_ONE_PLAYER "..\\Resources\\Map\\Quadtree\\Choise1player.PNG"

CChooseItem::CChooseItem()
{
	this->m_Pos = Vector2(180,325); // vi tri ban dau cua choise item
	this->m_imageCurr = new CTexture();
	this->m_drawImg = new CSprite();
	this->m_imageCurr->LoadImageFromFile(CHOOSE_ITEM_ONE_PLAYER, D3DCOLOR_XRGB(0, 255, 255));
	m_ChoiseID = 1;
}

void CChooseItem::Update(float deltaTime)
{
	
}

void CChooseItem::Draw()
{
#pragma region KHONG CO QUADTREE

	RECT *rectRS = new RECT();

	D3DXVECTOR3 pos;
	pos.x = this->m_Pos.x;
	pos.y = this->m_Pos.y;
	pos.z = 0;

	rectRS->left = 0;
	rectRS->top = 0;
	rectRS->right = m_imageCurr->GetImageWidth();
	rectRS->bottom = m_imageCurr->GetImageHeight();

	this->m_drawImg->draw(this->m_imageCurr, rectRS, pos, D3DCOLOR_XRGB(255, 255, 225), false);

#pragma endregion
}
void CChooseItem::OnCollision(float deltaTime, std::vector<CBaseGameObject*> listObjectCollision)
{}
void CChooseItem::OnCollision(float deltaTime, CBaseGameObject* Object)
{}
void CChooseItem::OnCollision(float deltaTime, std::vector<Ground> listGround)
{}
CChooseItem::~CChooseItem()
{
}
