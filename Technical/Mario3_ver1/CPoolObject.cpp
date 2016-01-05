#include "CPoolObject.h"


CPoolObject::CPoolObject()
{
	this->listEnemy = std::vector<CBaseGameObject*>();
	//this->stone = new CStone();
	this->enemyFlower2 = new CEnemyFlower2(Vector2(50,50));

	//this->enemyRun1 = new CEnemyRun(Vector2(200, 50), LEVEL::LEVEL_0);
	this->coin = new CCoin();

	//this->listEnemy.push_back(new CEnemyTurtle(Vector2(50, 50), LEVEL::LEVEL_1));

	//this->listEnemy.push_back(this->stone);

	//LoadListGameObject();
	//CreateGameObject();
	//bullet 
	//this->bullet = new CBullet();
	this->fly = new	CEnemyTurtleFly();
	//this->item = new CItem(Vector2(100, 50), TYPE_ITEM::ITEM_MUSHROOM);
}


CPoolObject::~CPoolObject()
{
}
void CPoolObject::Draw()
{
	CDrawObject::GetInstance()->Draw(this->fly);
	if (this->item != NULL)
		CDrawObject::GetInstance()->Draw(this->item);
	//CDrawObject::GetInstance()->Draw(this->coin);
	CDrawObject::GetInstance()->Draw(this->stone);

	CDrawObject::GetInstance()->Draw(this->enemyFlower2);

	CLoadObject::GetInstance()->Draw();
	
	if (bullet != NULL)
	{
		if (CCamera::GetInstance()->CheckCollision(this->bullet))
		{
			CDrawObject::GetInstance()->Draw(this->bullet);
		}
	}
	//for (std::vector<CBaseGameObject*>::iterator it = listEnemy.begin(); it != listEnemy.end(); it++)
	//{
	//	CBaseGameObject* obj = *it;
	//	if (!obj->isRemove)
	//	{
	//		if (CCamera::GetInstance()->CheckCollision(obj))
	//		{
	//			CDrawObject::GetInstance()->Draw(obj);
	//		}
	//	}
	//	else
	//	{
	//		//listEnemy.erase(listEnemy.begin());
	//	}
	//}	
	for (std::vector<CBaseGameObject*>::iterator it = listEffect.begin(); it != listEffect.end(); it++)
	{
		CBaseGameObject* obj = *it;
		CDrawObject::GetInstance()->Draw(obj);
	}
}
void CPoolObject::LoadListGameObject()
{
	CLoadGameObject::GetInstance()->LoadObjectFromFile(FILE_LIST_OBJECT);
}
void CPoolObject::CreateGameObject()
{
#pragma region Load List Object 
	for (std::vector<ObjectInfo>::iterator it = CLoadGameObject::GetInstance()->m_listObject.begin(); it != CLoadGameObject::GetInstance()->m_listObject.end(); it++)
	{
		ObjectInfo obj = *it;
		switch (obj.m_idImage)
		{
		case 601://neu la Brick
			this->listEnemy.push_back(new CBrick(Vector2(obj.m_pos.x, obj.m_pos.y)));
			break;
		case 602://neu la Brick
			//this->listEnemy.push_back(new CBrick(Vector2(obj.m_pos.x, obj.m_pos.y)));
			break;
		case 603://neu la Brick
			this->listEnemy.push_back(new CCoin(Vector2(obj.m_pos.x, obj.m_pos.y),false));
			break;


			//ENEMY
		case 201://neu la Enemy Run
			//Vector2 newPos = Vector2(obj.m_pos.x, obj.m_pos.y);
			this->listEnemy.push_back(new CEnemyRun(obj.m_pos, LEVEL::LEVEL_0));
			break;
		case 202://neu la Enemy Run 2(nhay)
			this->listEnemy.push_back(new CEnemyRun(Vector2(obj.m_pos.x, obj.m_pos.y + 50), LEVEL::LEVEL_1));
			break;
		case 205://neu la Enemy rua di bt
			//MessageBox(NULL, "turtle", "ASDs",MB_OK);
			this->listEnemy.push_back(new CEnemyTurtle(Vector2(obj.m_pos.x, obj.m_pos.y), 0));
			break;
		case 204://neu la Enemy Flower
			this->listEnemy.push_back(new CEnemyFlower(Vector2(obj.m_pos.x, obj.m_pos.y)));
			
			break;
		default:
			break;
		}
	}
#pragma endregion 

#pragma region Load Object Quadtree


	//std::vector<int> m_oldListIdObject;
	//m_oldListIdObject.swap(this->m_listIdObject);
	//this->m_listIdObject.clear();

	///*CLoadGameObject::GetInstance()->m_quadTree->GetListObjectOnScreen(CCamera::GetInstance()->GetBound(),
	//	this->m_quadTree->GetRoot(),
	//	listIDObj);*/
	//CLoadGameObject::GetInstance()->m_quadTree->GetListObjectOnScreen(CCamera::GetInstance()->GetBound(),
	//	CLoadGameObject::GetInstance()->m_quadTree->GetRoot(), this->m_listIdObject);
	//if (this->m_listIdObject.size() != 0)
	//{
	//	vector<CBaseGameObject*>::iterator it;
	//	for (int j = 0; j < m_oldListIdObject.size(); j++)
	//	{
	//		/*if (!contains(m_listIdObject, m_oldListIdObject.at(j)))
	//		{*/
	//			for (it = listEnemy.begin(); it != listEnemy.end();)
	//			{
	//				if (*it == this->m_listObjectCurr.find(m_oldListIdObject.at(j))->second)
	//				{
	//					it = this->listEnemy.erase(it);
	//				}
	//				else
	//					++it;
	//			}
	//		//}
	//	}
	//	for (int i = 0; i < m_listIdObject.size(); i++)
	//	{
	//		if (!contains(m_oldListIdObject, m_listIdObject.at(i)))
	//		{
	//			//NO bo cho nay sau khi goi change map no trung doi tuong
	//			// Them doi tuong vao d/s
	//			if (this->m_listObjectCurr.find(m_listIdObject.at(i)) != this->m_listObjectCurr.end())
	//			{
	//				this->listEnemy.push_back(this->m_listObjectCurr.find(m_listIdObject.at(i))->second);

	//			}
	//			else
	//			{
	//				int count = 0;
	//			}
	//		}
	//	}

	//}
#pragma endregion
}
bool CPoolObject::contains(std::vector<int> v, int x)
{
	if (std::find(v.begin(), v.end(), x) != v.end()) {
		/* v contains x */
		return true;
	}
	else {
		/* v does not contain x */
		return false;
	}
}

void CPoolObject::Update(float deltaTime)
{
	//this->stone->Update(deltaTime);
	this->fly->Update(deltaTime);
	
	this->enemyFlower2->Update(deltaTime);

	if (this->item != NULL)
		this->item->Update(deltaTime);
	//this->coin->Update(deltaTime);
	//this->stone->Update(deltaTime);
	if (bullet != NULL)
		this->bullet->Update(deltaTime);
	for (std::vector<CBaseGameObject*>::iterator it = listEnemy.begin(); it != listEnemy.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (obj != NULL)
		if (CCamera::GetInstance()->CheckCollision(obj))
		{
			obj->Update(deltaTime);
		}
	}	
	
	for (std::vector<CBaseGameObject*>::iterator it = listEffect.begin(); it != listEffect.end();)
	{
		CBaseGameObject* obj = *it;
		if (obj != NULL && obj->isRemove == false)
			obj->Update(deltaTime);
		if (obj->isRemove)
		{
			it = listEffect.erase(it);
		}
		else
		{
			it++;
		}
			
	}
	
	
	CLoadObject::GetInstance()->Update(deltaTime);
	Collision(deltaTime);
}
void CPoolObject::Collision(float deltaTime)
{
	for (std::vector<CBaseGameObject*>::iterator it = listEnemy.begin(); it != listEnemy.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (obj != NULL)
		{
			obj->OnCollision(deltaTime, CBoxGround::GetInstance()->listGround);
		}
	}
	this->fly->OnCollision(deltaTime, CBoxGround::GetInstance()->listGround);
	if (this->item != NULL)
		this->item->OnCollision(deltaTime, CBoxGround::GetInstance()->listGround);
}
void CPoolObject::RenderCoin(Vector2 pos)
{
	this->listEffect.push_back(new CCoin(pos));
}
void CPoolObject::FireBullet(BULLET_DIR dir, Vector2 pos)
{
	bullet = new CBullet(dir, pos);	
}
void CPoolObject::RenderItem(Vector2 pos, TYPE_ITEM type)
{
	this->item = new CItem(pos, type);
}