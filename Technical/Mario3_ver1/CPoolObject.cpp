#include "CPoolObject.h"


CPoolObject::CPoolObject()
{
	
	this->background = new CBackGround();

	this->enemyRun1 = new CEnemyRun();
	this->listEnemy.push_back(this->enemyRun1);
	this->listEnemy.push_back(new CBrick());
}


CPoolObject::~CPoolObject()
{
}
void CPoolObject::Draw()
{
	for (std::vector<CBaseGameObject*>::iterator it = listEnemy.begin(); it != listEnemy.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (!obj->isRemove)
			CDrawObject::GetInstance()->Draw(obj);
	}	
}

void CPoolObject::Update(float deltaTime)
{
	for (std::vector<CBaseGameObject*>::iterator it = listEnemy.begin(); it != listEnemy.end(); it++)
	{
		CBaseGameObject* obj = *it;
		if (obj != NULL)
			obj->Update(deltaTime);
	}
	
}

