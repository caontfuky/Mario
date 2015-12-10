#include "CPoolObject.h"


CPoolObject::CPoolObject()
{

	this->stone = new CStone();

	this->enemyRun1 = new CEnemyRun();
	this->coin = new CCoin();

	this->listEnemy.push_back(this->enemyRun1);
	this->listEnemy.push_back(new CEnemyTurtle());
	this->listEnemy.push_back(new CEnemyFlower());


	this->listEnemy.push_back(new CBrick(Vector2(100, 370)));
	this->listEnemy.push_back(new CBrick(Vector2(116, 370)));

	this->listEnemy.push_back(new CBrick(Vector2(150, 330)));
	this->listEnemy.push_back(new CBrick(Vector2(166, 330)));
	this->listEnemy.push_back(this->stone);

	CreateGameObject();
	//bullet 
	//this->bullet = new CBullet();
}


CPoolObject::~CPoolObject()
{
}
void CPoolObject::Draw()
{
	//CDrawObject::GetInstance()->Draw(this->coin);
	//CDrawObject::GetInstance()->Draw(this->stone);

	for (std::vector<CBaseGameObject*>::iterator it = listEnemy.begin(); it != listEnemy.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (!obj->isRemove)
			CDrawObject::GetInstance()->Draw(obj);
	}	
	for (std::vector<CBaseGameObject*>::iterator it = listEffect.begin(); it != listEffect.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (!obj->isRemove)
			CDrawObject::GetInstance()->Draw(obj);
	}
}
void CPoolObject::LoadListGameObject()
{
	CLoadGameObject::GetInstance()->LoadObjectFromFile(FILE_LIST_OBJECT);
}
void CPoolObject::CreateGameObject()
{
	LoadListGameObject();
	for (std::vector<ObjectInfo>::iterator it = CLoadGameObject::GetInstance()->m_listObject.begin(); it != CLoadGameObject::GetInstance()->m_listObject.end(); it++)
	{
		ObjectInfo obj = *it;
		switch (obj.m_idImage)
		{
		case 601://neu la Brick
			this->listEnemy.push_back(new CBrick(Vector2(obj.m_pos.x, obj.m_pos.y)));
			break;
		default:
			break;
		}
	}
}
void CPoolObject::Update(float deltaTime)
{
	//this->coin->Update(deltaTime);
	//this->stone->Update(deltaTime);
	if (bullet != NULL)
		this->bullet->Update(deltaTime);
	for (std::vector<CBaseGameObject*>::iterator it = listEnemy.begin(); it != listEnemy.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (obj != NULL)
			obj->Update(deltaTime);
	}
	for (std::vector<CBaseGameObject*>::iterator it = listEffect.begin(); it != listEffect.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (obj != NULL)
			obj->Update(deltaTime);
	}
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
}
void CPoolObject::RenderCoin(Vector2 pos)
{
	this->listEffect.push_back(new CCoin(pos));
}
void CPoolObject::FireBullet(BULLET_DIR dir, Vector2 pos)
{
	bullet = new CBullet(dir, pos);
}