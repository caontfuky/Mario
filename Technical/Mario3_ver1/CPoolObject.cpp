#include "CPoolObject.h"


CPoolObject::CPoolObject()
{
	
	this->background = new CBackGround();

	this->enemyRun1 = new CEnemyRun();
	this->coin = new CCoin();

	this->listEnemy.push_back(this->enemyRun1);
	this->listEnemy.push_back(new CBrick(Vector2(100, 370)));
	this->listEnemy.push_back(new CBrick(Vector2(116, 370)));

	this->listEnemy.push_back(new CBrick(Vector2(150, 330)));
	this->listEnemy.push_back(new CBrick(Vector2(166, 330)));
}


CPoolObject::~CPoolObject()
{
}
void CPoolObject::Draw()
{
	//CDrawObject::GetInstance()->Draw(this->coin);
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

void CPoolObject::Update(float deltaTime)
{
	//this->coin->Update(deltaTime);
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
}

void CPoolObject::RenderCoin(Vector2 pos)
{
	this->listEffect.push_back(new CCoin(pos));
}