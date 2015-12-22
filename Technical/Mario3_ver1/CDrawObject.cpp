#include "CDrawObject.h"
//#include "CManagementTexture.h"
#include "CTexture.h"
//#include "CCamera.h"
//#include "CHidenObject.h"
#include "CMarioObject.h"
CDrawObject::CDrawObject()
{
	this->m_draw = new CSprite();
	
}
CDrawObject::~CDrawObject()
{
	if (this->m_draw)
		delete this->m_draw;
}
void CDrawObject::Draw(CBaseGameObject* obj)
{
	//Kiem tra doi tuong khac null
	if (obj != nullptr)
	{
		int typeImage = obj->GetIDType();
		CTexture* texture = new CTexture();
		Vector3 pos = Vector3();

		pos = CCamera::GetInstance()->GetPointTransform(obj->GetPos().x, obj->GetPos().y);
		
		switch (typeImage)
		{
			case 0://eo co thang nao
				break;
			case 1://thang Mario
				if (CMarioObject::GetInstance()->level == 1)
				{

					if (CMarioObject::GetInstance()->m_status != STATUS::DIE)
					{

						if (CMarioObject::GetInstance()->m_collision == COLLISION::NONE_COL)//truong hop mario nhay
						{
							texture->LoadImageFromFile(MARIO_JUMB, D3DCOLOR_XRGB(255, 0, 255));

							if (obj->GetDirection() == Direction::RIGHT)
							{
								this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
							}
							else
							{
								this->m_draw->drawFlipX(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
							}
						}
						else
						{
							texture->LoadImageFromFile(MARIO_MOVE, D3DCOLOR_XRGB(255, 0, 255));
							if (obj->GetDirection() == Direction::RIGHT)
							{
								this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
							}
							else
							{
								this->m_draw->drawFlipX(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
							}
						}
					}
					else
					{
						texture->LoadImageFromFile(MARIO_DIE, D3DCOLOR_XRGB(255, 0, 255));
						this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);

					}
				}
				if (CMarioObject::GetInstance()->level == 2)
				{
					if (CMarioObject::GetInstance()->m_collision == COLLISION::NONE_COL)//truong hop mario nhay
					{
						texture->LoadImageFromFile(MARIO_JUMB_LV2, D3DCOLOR_XRGB(255, 0, 255));

						if (obj->GetDirection() == Direction::RIGHT)
						{
							this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
						else
						{
							this->m_draw->drawFlipX(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
					}
					else
					{
						texture->LoadImageFromFile(MARIO_MOVE_LV2, D3DCOLOR_XRGB(255, 0, 255));
						if (obj->GetDirection() == Direction::RIGHT)
						{
							this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
						else
						{
							this->m_draw->drawFlipX(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
					}
				}
				if (CMarioObject::GetInstance()->level == 3)
				{
					if (CMarioObject::GetInstance()->m_collision == COLLISION::NONE_COL)//truong hop mario nhay
					{
						texture->LoadImageFromFile(MARIO_JUMB_LV3, D3DCOLOR_XRGB(255, 0, 255));

						if (obj->GetDirection() == Direction::RIGHT)
						{
							this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
						else
						{
							this->m_draw->drawFlipX(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
					}
					else
					{
						texture->LoadImageFromFile(MARIO_MOVE_LV3, D3DCOLOR_XRGB(255, 0, 255));
						if (obj->GetDirection() == Direction::RIGHT)
						{
							this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
						else
						{
							this->m_draw->drawFlipX(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
						}
					}

				}
				break;
			case 2:
				texture->LoadImageFromFile(MARIO_MOVE, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				break; 
			case 3:
				texture->LoadImageFromFile(BACK_GROUND, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				break;

				//enemy
			case 101:
				texture->LoadImageFromFile(ENEMY_RUN_1, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				//this->m_draw->drawRotation(texture, obj->GetRectRS(), pos, 90, D3DCOLOR_XRGB(255, 255, 255), true);
				break;
			case 102:
				texture->LoadImageFromFile(ENEMY_TURTEL_1, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				if (obj->m_Dir == Direction::RIGHT)
				{
					this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				}
				else
				{
					this->m_draw->drawFlipX(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);

				}
				break;
			case 103:
				texture->LoadImageFromFile(ENEMY_3, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				//this->m_draw->drawRotation(texture, obj->GetRectRS(), pos, 90, D3DCOLOR_XRGB(255, 255, 255), true);
				break;
				//Brick
			case 201:
				texture->LoadImageFromFile(BRICK_1, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->adraw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				break;
			case 202:
				texture->LoadImageFromFile(STONE, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				break;
				//Effect
			case 301:
				texture->LoadImageFromFile(EFFECT_COIN, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				break;
				//Bullet
			case 401:
				texture->LoadImageFromFile(BULLET_ENEMY, D3DCOLOR_XRGB(255, 0, 255));
				//pos = Vector3(obj->GetPos().x, obj->GetPos().y, 0);
				//this->m_draw->draw(texture, obj->GetRectRS(), pos, D3DCOLOR_XRGB(255, 255, 255), true);
				this->m_draw->drawRotation(texture, obj->GetRectRS(), pos, obj->m_rotation, D3DCOLOR_XRGB(255, 255, 255), true);
				break;
			default:
				break;
		}
		
	}
}
void CDrawObject::Draw(CBaseGameObject*, D3DCOLOR)
{

}